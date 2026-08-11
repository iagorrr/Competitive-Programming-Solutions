/*
- outra idéia:
  - processa na ordem do toposort
  e quando estiver processando o nó pega todas as
  arestas que tem ligada nele
  e faz ela apontar pra fora dele
  - motivação: se to processando ele significa
  que não tem mais nenhum nó querendo chegar
  em mim então só propaga mesmo
  - guloso demais


- como faz um check ?
  -  tenho um grafo direcionado e quero saber
  se algumas restrições são atendidas
  - acho que esse check é impossível tão genérico
  - se tenho só N arestas é mais safe ?
  - eu poderia reduzir para um DAG né

- os ciclos é foda-se
  - direciona de maneira que fique o ciclo o que importa
  é a aresta que liga no ciclo, se tiver alguem
  de fora do ciclo que precisa ser atendido ela vai ser
  apontando pro ciclo caso contrario para fora do ciclo

- Resolvido o ciclo é varios dagzinhos estranhos
- Esses dag's são uns bamboo então dá pra saber
pra que lado cada aresta precisa ficar
- muito trolha de codar teria que ir imporndo
a direcao esquerda ou direita
depois sair checando


não é um bamboo tbm...


a pika é checar

esse -1 é trivial de checar ?
  - se tiver em componentes diferentes vapo

- com hld é fazível ?
  - para cada componente conexo
    - gero a versão dele que aponta para o ciclo
    - e a versão que foge do ciclo
      - depois para cada restrição eu vejo
      em qual das versões eles se conectam
        - com isso eu tenho que marcar
        que aquelas arestas entre os dois
        precisam ter direção X
        - se em algum momento eu tentar
        colocar direção em uma aresta
        que já foi direcionada é -1
        caso contrário é só torar tudo

        - esse check é no final, tem que
        passar aresta por aresta
        e ver se alguma delas foi
        marcada pelas duas sol
        - nem precia da seg né
        - bomba do krl

ESSA FUNFA:
- Gera os dois grafos funcionais
  - para cada restrição
    - se não se ligar em nenhum dos grafos é loss
    - verifica em qual dos grafos ele se liga
    - para aquele grafo faz a travessia pelas arestas
    e marca a direção delas
    - se passar por uma aresta que já foi marcada é loss
    - tem que fazer meio que offiline essas marcações
    ai mas dá
    - tipo, estou em i, e tenho que propagar a'te tal...
    - se não tiver nada pra propagar só parar
    - teria de processar na ordem do toposort

criar um nó virtual para os ciclos
- se uma restrição é de um nó para um nó que esteja no ciclo
eu preciso saber qual o root daquele ciclo para aquele nó
e daí ele tem que ligar até aquele root
- então eu tenho que fazer um functional graph ignorando
esses ciclos
- na verdade os dois

quando eles estão separados por um ciclo tem que entrar pelo de entrada e sair
pelo de saida isso é um cu de codar puta que pariu

estados :
  1. no mesmo ciclo
  2. na mesma branch
  3. em branchs diferentes
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif

vector<int> toposort(const vector<vector<pair<int, int>>> &g) {

  const int n = g.size();

  vector<int> inDg(n);
  for (auto &e : g) {
    for (auto &x : e)
      inDg[x.second]++;
  }

  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (inDg[i] == 1) {
      q.push(i);
    }
  }

  vector<int> order;
  while (not q.empty()) {
    int u = q.front();
    q.pop();
    order.push_back(u);

    for (auto &[_, v] : g[u]) {
      inDg[v]--;
      if (inDg[v] == 1) {
        q.push(v);
      }
    }
  }

  return order;
}

vector<int> buildFunGraph(const vector<int> &order,
                          const vector<vector<pair<int, int>>> &g) {
  const int n = g.size();
  vector<int> fun(n, -1);
  vector<int> m(n), vis(n);

  for (auto u : order) {
    vis[u] = 1;
    for (auto &[i, v] : g[u]) {
      if (m[i])
        continue;
      m[i] = true;
      assert(fun[u] == -1);
      fun[u] = v;
    }
  }

  for (int u = 0; u < n; u++) {
    if (vis[u])
      continue;

    int x = u;
    while (!vis[x]) {
      vis[x] = 1;
      int nx = -1;
      for (auto &[_, v] : g[x]) {
        if (vis[v])
          continue;
        nx = v;
        break;
      }
      fun[x] = nx == -1 ? u : nx;
      x = nx == -1 ? x : nx;
    }
  }

  return fun;
}

struct FunctionalGraph {
  int n;
  vector<int> next;
  vector<int> cycleIds;
  vector<int> cycleSizes;
  vector<int> distanceToCycle;
  vector<int> cyclePos;
  vector<int> rootCycle;
  vector<vector<int>> succ;

  FunctionalGraph(const vector<int> &next) : n(next.size()), next(next) {
    cycleIds.assign(n, 0);
    distanceToCycle.assign(n, 0);
    cyclePos.assign(n, -1);
    rootCycle.assign(n, -1);

    vector<int> inDegree(n, 0);
    for (int i = 0; i < n; i++) {
      inDegree[next[i]]++;
    }

    queue<int> q;
    for (int u = 0; u < n; u++) {
      if (inDegree[u] == 0)
        q.push(u);
    }

    vector<int> topologicOrder;
    topologicOrder.reserve(n);

    while (not q.empty()) {
      int curNode = q.front();
      q.pop();

      topologicOrder.push_back(curNode);

      int nextNode = next[curNode];
      inDegree[nextNode]--;

      if (inDegree[nextNode] == 0)
        q.push(nextNode);
    }

    for (int u = 0; u < n; u++) {
      if (inDegree[u] == 0)
        continue;

      int curNode = u;
      int cycleSize = 0;

      while (inDegree[curNode] != 0) {
        inDegree[curNode] = 0;

        distanceToCycle[curNode] = 0;
        cycleIds[curNode] = (int)cycleSizes.size();
        cyclePos[curNode] = cycleSize;
        cycleSize++;

        curNode = next[curNode];
      }

      cycleSizes.push_back(cycleSize);
    }

    for (auto v : ranges::views::reverse(topologicOrder)) {
      int nv = next[v];
      cycleIds[v] = cycleIds[nv];
      distanceToCycle[v] = distanceToCycle[nv] + 1;
      rootCycle[v] = rootCycle[nv] == -1 ? nv : rootCycle[nv];
    }
  }

  void buildBinaryLifting() {
    if (!succ.empty())
      return;

    int maxLog = __lg(n) + 1;
    succ.assign(maxLog, vector<int>(n));
    succ[0] = next;

    for (int k = 1; k < maxLog; k++) {
      for (int i = 0; i < n; i++) {
        succ[k][i] = succ[k - 1][succ[k - 1][i]];
      }
    }
  }

  int kth(int u, ll k) const {
    if (k <= 0)
      return u;

    // Fast-forward huge K by reaching the cycle and applying modulo
    if (k > distanceToCycle[u]) {
      ll distToC = distanceToCycle[u];
      k -= distToC;

      int maxLog = succ.size();
      for (int i = 0; i < maxLog; i++) {
        if ((1ll << i) & distToC)
          u = succ[i][u];
      }

      k %= cycleSizes[cycleIds[u]];
    }

    // Advance the remaining K <= N steps
    int maxLog = succ.size();
    for (int i = 0; i < maxLog; i++) {
      if ((1ll << i) & k)
        u = succ[i][u];
    }

    return u;
  }

  int dist(int u, int v) const {
    if (cycleIds[u] != cycleIds[v])
      return -1;

    // Check if v is an ancestor of u in the tree paths
    if (distanceToCycle[u] >= distanceToCycle[v]) {
      int diff = distanceToCycle[u] - distanceToCycle[v];
      if (kth(u, diff) == v)
        return diff;
    }

    // If v is in the cycle, u can definitely reach it
    if (distanceToCycle[v] == 0) {
      int u_entry = kth(u, distanceToCycle[u]);
      int cSize = cycleSizes[cycleIds[u]];

      // O(1) distance inside the cycle using positions
      int distInCycle = (cyclePos[v] - cyclePos[u_entry] + cSize) % cSize;
      return distanceToCycle[u] + distInCycle;
    }

    return -1;
  }

  // Requires that buildBinaryLifting was called
  int midpoint(int u, int v) const {
    // If they don't point to the same cycle
    // there is no midpoint for them
    if (cycleIds[u] != cycleIds[v]) {
      return -1;
    }

    // Make u the farthest node from the cycle
    if (distanceToCycle[u] < distanceToCycle[v])
      swap(u, v);

    // Put them at the same distance from the cycle
    u = kth(u, distanceToCycle[u] - distanceToCycle[v]);

    // u was an ancestor of v
    if (u == v)
      return v;

    // find their "closest common ancestor"
    for (int i = succ.size() - 1; i >= 0; i--) {
      if (succ[i][u] != succ[i][v]) {
        u = succ[i][u];
        v = succ[i][v];
      }
    }

    return succ[0][u];
  }
};

FunctionalGraph removeInCycleNonRoots(FunctionalGraph &fg) {
  vector<int> nx = fg.next;
  const int n = nx.size();

  vector<int> isSomeRoot(n);
  for (int i = 0; i < n; i++) {
    if (fg.rootCycle[i] != -1)
      isSomeRoot[fg.rootCycle[i]] = 1;
  }

  for (int i = 0; i < n; i++) {
    if (fg.distanceToCycle[i] == 0 and !isSomeRoot[i]) {
      nx[i] = i;
    }
  }
  return FunctionalGraph(nx);
}

signed main() {
  ios_base::sync_with_stdio(!cin.tie(0));
  int n;
  cin >> n;

  vector<int> originalEdges(n);
  for (int i = 0; i < n; i++) {
    cin >> originalEdges[i];
    originalEdges[i]--;
  }

  int m;
  cin >> m;
  vector<pair<int, int>> restrictions(m);
  for (auto &[u, v] : restrictions) {
    cin >> u >> v;
    u--, v--;
  }

  vector<vector<pair<int, int>>> nonD(n);
  for (int u = 0; u < n; u++) {
    int v = originalEdges[u];
    nonD[u].emplace_back(u, v);
    nonD[v].emplace_back(u, u);
  }

  vector<int> initialToposort = toposort(nonD);
  auto fg = FunctionalGraph(buildFunGraph(initialToposort, nonD));
  fg.buildBinaryLifting();

  // da pra isso ficar n^2 ?? da ne
  // é só marcar o mais longe de cada 1
  // toma tle primeiro
  vector<set<pair<int, int>>> marks(n);

  for (auto &[u, v] : restrictions) {
    // foda-se
    if (u == v)
      continue;

    // estão no mesmo ciclo e estão dentro do ciclo
    if (fg.distanceToCycle[u] == 0 and fg.distanceToCycle[v] == 0 and
        fg.cycleIds[u] == fg.cycleIds[v])
      continue;

    // se u já liga em v no grafo que a gente gerou
    // marco que tem um caminho que começa em u termina em v e tem
    // que manter as aresas
    if (fg.dist(u, v) != -1) {
      marks[u].emplace(0, v);
      continue;
    }

    // se for o contrário v liga em u, eu sei que tem que o caminho
    // de v até u tem que ser revertido
    if (fg.dist(v, u) != -1) {
      marks[v].emplace(1 /* tem que ser revertido */, u);
      continue;
    }

    // se não é um ancnestral do outro e apontam
    // para ciclos diferentes fudeu, não tem como
    if (fg.cycleIds[u] != fg.cycleIds[v]) {
      cout << -1 << endl;
      return 0;
    }

    // esse l é tipo o lca deles, é um nó
    // que está no caminho de u para v, é o "turnpoint"
    int l = fg.midpoint(u, v);

    // se for um nó dentro do ciclo
    // eu não posso mudar o estado das arestas do ciclo
    // então tem que ir de u até o root do ciclo dele sem reverter
    // e depois do root do ciclo de v até revertendo as arestas
    if (fg.distanceToCycle[l] == 0) {
      int ru = fg.rootCycle[u];
      int rv = fg.rootCycle[v];

      marks[u].emplace(0, ru);
      marks[v].emplace(1, rv);

      continue;
    }

    // se for só um nó no meio dos dois
    // eu vou de u até l sem reverter
    // depois de v até l revertendo
    marks[u].emplace(0, l);
    marks[v].emplace(1, l);
  }

  dbg(marks);
  multiset<pair<int, int>> mst;
  for (int u : initialToposort) {
    int v = fg.next[u];
    if (v == u)
      continue;

    int x = -1;
    for (auto [r, ev] : marks[u]) {
      if (x == -1)
        x = r;
      if (x != r) {
        cout << -1 << endl;
        return 0;
      }

      if (ev != v) {
        marks[v].emplace(r, ev);
      }
    }

    if (x == -1) {
    } else if (x == 0) {
      mst.emplace(u, v);
    } else if (x == 1) {
      mst.emplace(v, u);
    }
  }

  vector<int> vis(n);
  for (int i = 0; i < n; i++) {
    int cur = i;
    while (not vis[cur] and fg.distanceToCycle[cur] == 0) {
      vis[cur] = 1;
      mst.emplace(cur, fg.next[cur]);
      cur = fg.next[cur];
    }
  }

  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    int j = originalEdges[i];
    if (mst.count({i, j})) {
      ans[i] = 0;
      mst.erase({i, j});
    } else {
      ans[i] = 1;
      mst.erase({j, i});
    }
  }

  for (auto i : ans)
    cout << i << ' ';
  cout << '\n';
}
