/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
/*#define endl '\n'*/
#define fastio                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
#define int long long
#define all(j) j.begin(), j.end()
#define rall(j) j.rbegin(), j.rend()
#define len(j) (int)j.size()
#define rep(i, a, b)                           \
  for (common_type_t<decltype(a), decltype(b)> \
           i = (a);                            \
       i < (b); i++)
#define rrep(i, a, b)                          \
  for (common_type_t<decltype(a), decltype(b)> \
           i = (a);                            \
       i > (b); i--)
#define trav(a, x) for (auto &a : x)
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define emp emplace
#define ins insert
#define divc(a, b) ((a) + (b)-1ll) / (b)
using str = string;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vc = vector<char>;
using vs = vector<str>;
template <typename T>
using pqmn =
    priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using pqmx = priority_queue<T, vector<T>>;
template <typename T, typename U>
inline bool chmax(T &a, U const &b) {
  return (a < b ? a = b, 1 : 0);
}
template <typename T, typename U>
inline bool chmin(T &a, U const &b) {
  return (a > b ? a = b, 1 : 0);
}

/*8<============~ END TEMPLATE ~============}>8*/
void run();

int32_t main() {
#ifndef LOCAL
  fastio;
#endif

  int T = 1;

  cin >> T;

  rep(t, 0, T) {
    dbg(t);
    run();
  }
}

/*8<
 * n^4 ent da pra fazer quadratico
 * recebo o grafo
 * escolho quem vou jogar
 * e jogo
 * condições pra existir um tripartite matching?
 * a lice pode sempre escolher duas cores iguais
 * dai seria forçando a achar um biaprtite
 * se sobrar um nó com duas arestas e esas
 * duas arestas liga nós de cores distintas
 * bob perde, que é o caso de teste um
 *
 * tenho um nó C que liga em A e B,
 * tal que A liga em B, ent A != B, C != A !=B
 * dai so sobra uma cor, se alice quiser e vapo
 *
 * so essa condição pra jogar com a alice?
 *
 * por enquanto sim
 *
 * estrategia otima dela é dar qualqeur coias
 * até que esse miniciclo ai seja escolhido
 * ai so fazer a maldade
 *
 * e pro bob ?
 *
 * so sair colocando onde da ?
 * nao
 * 1 -> 2 -> 3
 * se 1 for A e 3 for B
 * bob perde pq alice pode forçar o 2 ser um A
 *
 * ou um B
 *
 * colca sempre perto de um nó, faz um dfszinha
 * coloca na ordem da dfs tree ?
 *
 * nao garante
 * pode dar a volta contrária no ciclo
 * e ai torou-se tudo
 *
 * tem que ser um grafo 'bi-partido' em alguma
 * cor
 *
 * nao da pra ter 1->2->3 e 1 e 3 terem cores
 * distintas se não o 2 vai rodar
 *
 * jogar com o bob e hard hein
 *
 * ciclo de tamanho impar é um problema ?
 * um grafo é bipartido se e somente se
 * ele não tem ciclo de tamanho impar !
 *
 * jogando com a alice da qualquer coisa
 * até que tiver um nó tal que duas
 * adjacencias dele ja possua cor
 * dai da as cores dessas duas adjacencias
 *
 *
 * ok
 *
 * e o bob so ganha num grafo bipartido
 *
 * ent ele vai dar duas cores
 *
 * nunca da pra remvoer duas cores
 *
 * ent da pra pintar bipartido
 *
 * coloco uma das duas em uma das cores
 *
 * do grafo
 *
 *
 * coloco uma das duas no outro lado
 *
 * um lado vai ser só de C1 e C2, e o outro so
 * de c2
 *
 * ou remove C1 ou remove C2 dai colcoo
 * no lado que nao removeu
 *
 * se ficar de graça e ja tiver preenchido
 * um dos lados pode por mais de uma
 * cor no lado que falta
>8*/

vi2d bipartite_graph(vi2d &adj) {
  int n = len(adj);
  vi side(n, -1);
  vi2d ret(2);
  rep(u, 0, n) {
    if (side[u] == -1) {
      queue<int> q;
      q.emp(u);
      side[u] = 0;
      ret[0].eb(u);
      while (len(q)) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
          if (side[v] == -1) {
            side[v] = side[u] ^ 1;
            ret[side[v]].eb(v);
            q.push(v);
          } else if (side[u] == side[v])
            return {};
        }
      }
    }
  }
  return ret;
}

pii get() {
  int a, b;
  cin >> a;
  if (~a)
    cin >> b;
  else
    exit(0);
  return {a, b};
}

void answer(int a, int b) {
  cout << a << ' ' << b << endl;
}

void playa(int n) {
  cout << "Alice" << endl;
  int c1 = 1, c2 = 2;
  answer(c1, c2);
  int a, b;
  tie(a, b) = get();
  /*if (a == 1 || b == 1) c1 = 3;*/
  /*if (a == 2 || b == 2) c2 = 3;*/
  rep(i, 0, n - 1) { answer(c1, c2), get(); }
}

void playb(vi left, vi right) {
  cout << "Bob" << endl;
  int a, b;
  tie(a, b) = get();
  int c1 = a, c2 = b;
  if (len(left) && len(right)) do {
      if (a == c1 or b == c1) {
        answer(left.back() + 1, c1);
        left.ppb();
      } else {
        answer(right.back() + 1, c2);
        right.ppb();
      }
      tie(a, b) = get();
    } while (len(left) && len(right));

  if (len(left)) do {
      if (a != c2) {
        answer(left.back() + 1, a);
      } else {
        answer(left.back() + 1, b);
      }
      left.ppb();
      if (len(left)) tie(a, b) = get();
    } while (len(left));

  if (len(right)) do {
      if (a != c1) {
        answer(right.back() + 1, a);
      } else {
        answer(right.back() + 1, b);
      }
      right.ppb();
      if (len(right)) tie(a, b) = get();
    } while (len(right));
}

void run() {
  int N, M;
  cin >> N >> M;
  vi2d ADJ(N);
  dbg(N, M);
  rep(i, 0, M) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    ADJ[a].eb(b);
    ADJ[b].eb(a);
  }

  auto bi = bipartite_graph(ADJ);

  if (!len(bi)) {
    playa(N);
  } else
    playb(bi[0], bi[1]);
}

// AC, contructive algorithsm, dfs and similar,
// graphs, greedy interactive
