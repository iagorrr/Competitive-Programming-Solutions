/*
- Se i liga em i ele está inserido em um ciclo
? Daria pra fazer o processo reverso da multiplicação de matriz
e saber uma matriz M que  M^oo resulta na matriz final ?
- Se a gente fizer um grafo com todas as arestas a gente
tem um superset das arestas originais, se a partir dela a gente conseguir
ir tirando até ter somente n-1 tá safe
- Essa parada do ciclo é mentira todo nó meio que já liga nele mesmo.
- Qual o critério para remover uma aresta:
        - Depois de removida a matriz de conectividade não muda
        ? Tem como se arrepender de ter removido uma aresta ?
        - Acho que não né, se eu removi (u, v) é por que todos os caminhos que
        (u,v) gerava, outra aresta já gerava
- Como removeria arestas:
        - 500^3 pra remover não daria pra ir de 1 em
        - Daria pra remover por cada SCC ?
        - Acho que nem tem como ter SCC na verdade
        - As conectividades geradas pelo direcionamento de uma árvore são
limitados
        - cada nó tem um único pai, essa aresta do pai pode:
                1. Se eu apontar pra ele eu ganho todas as
                conexões dele
                2. Se ela apontar pro filho o pai ganha as conexões dele
- Um nó que só liga nele mesmo era uma folha cujo aresta (pai, folha) foi
direcionado pra ele logo não ganhou nada
        - não necessariamente a raiz pode ter saída 0 e não ser uma folha
        na árvore original

? > Sempre tem alguém que aponta só pra si ?
        - Acho que sim, por que se a gente for direcionando a árvore e disser
        que todo mundo aponta pelo menos pra 1 entra em contradição
        - Pra esse nó que todo mundo chega nele da pra fazer um bem bolado
        - Seja ele o nó F, se u->f e v->f e v->u tira essa aresta v->u
- Sempre que eu comparo dois U e V tal que U->V, a gente pode fazer um xor deles
em U, e tirar de U todos os nós que V e U tem em comum ?
        N^2 pra todos os pares serem feitos e + N pra remover o que tiverem em
comum


???? quando que é No ?


como faz pra continuar dizendo que é uma árvore ?
        se eu tirar as direções cada nó só é achado uma única vez se eu eleger
uma raiz




*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
        int n;
        cin >> n;

        vector<string> go(n);
        for (auto &gi : go) cin >> gi;

        auto g = go;

        for (int u = 0; u < n; u++) {
                for (int v = 0; v < n; v++) {
                        if (v == u) continue;

                        if (go[u][v] == '1') {
                                for (int i = 0; i < n; i++) {
                                        if (go[u][i] == '1' and
                                            go[v][i] == '1' and i != v and
                                            i != u) {
                                                g[u][i] = '0';
                                        }
                                }
                        }
                }
        }

        vector<vector<int>> adj(n);
        int tot = 0;
        for (int u = 0; u < n; u++) {
                for (int v = 0; v < n; v++) {
                        if (v == u) continue;
                        if (g[u][v] == '1') {
                                adj[u].push_back(v);
                                tot++;
                        }
                }
        }

        vector<string> g2(n, string(n, '0'));
        for (int u = 0; u < n; u++) g2[u][u] = '1';
        vector<int> vis(n);
        function<void(int)> dfs = [&](int u) {
                if (vis[u]) return;
                vis[u] = 1;

                for (auto v : adj[u]) {
                        dfs(v);

                        for (int i = 0; i < n; i++) {
                                if (g2[v][i] == '1') g2[u][i] = '1';
                        }
                }
        };
        for (int i = 0; i < n; i++) dfs(i);

        bool isTree = true;
        vector<set<int>> adj2(n);
        for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                        if (g[i][j] == '1' or g[j][i] == '1') {
                                adj2[i].insert(j);
                                adj2[j].insert(i);
                        }
                }
        }

        vector<int> vis2(n);
        function<void(int, int)> dfs2 = [&](int u, int p) {
                vis2[u] = 1;
                for (auto v : adj2[u]) {
                        if (v == p) continue;
                        if (v == u) continue;

                        if (vis2[v]) {
                                isTree = false;
                        } else
                                dfs2(v, u);
                }
        };
        dfs2(0, -1);

        if (g2 != go or tot != n - 1 or !isTree or
            accumulate(vis2.begin(), vis2.end(), 0) < n) {
                cout << "No" << '\n';
                return;
        }

        cout << "Yes" << endl;
        for (int u = 0; u < n; u++) {
                for (auto v : adj[u]) {
                        cout << u + 1 << ' ' << v + 1 << '\n';
                }
        }
}
signed main() {
        ios_base::sync_with_stdio(!cin.tie(0));
        int t;
        cin >> t;
        while (t--) solve();
}
