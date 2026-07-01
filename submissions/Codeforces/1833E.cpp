/*

 Se todos os valores  são distintos o mínimo é 1
 E o máxmo é N/2, pra baixo ou pra cima ? acho que é pra baixo


 - cada número aparecen o máximo 2 vezes
 - quando eu tenho algum que aparece 2 vezes, iusso já impoe todos
 os demais numeros ?
- mais ou menos os valores que estão faltando não da pra dizer nada

- acho que é meio que um dsu, e dai é alguma combinatória na quantidade
de comps
- cada comp pode ser ele de trás pra frente tbm..
- O máximo é a qtd de componentes
- O mínimo depende se tem algum componente "fechado"


- É falso o role dos distintos
- É em cima dos ciclos tbm, se um
- Fica ambíguo quando a liga em b e b em a, não da pra saber se fechou ciclo ou
n
- Ciclos fechados aumentam o mínimo
- Ciclos abertos podem ser concatenados pra minimizar
 */

#include <bits/stdc++.h>
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<int> as(n);
        for (auto &ai : as) cin >> ai, ai--;

        vector<int> root(n, -1);
        function<void(int)> dfs = [&](int u) -> void {
                if (root[u] != -1) return;
                int v = as[u];

                root[u] = u;
                if (root[v] == -1) {
                        dfs(v);
                }

                root[u] = root[v];
        };

        for (int i = 0; i < n; i++) dfs(i);

        vector<int> visroot(n);
        int o, c;
        o = c = 0;

        for (int i = 0; i < n; i++) {
                if (visroot[root[i]]) continue;

                bool open = as[as[root[i]]] == root[i];
                o += open;
                c += !open;

                visroot[root[i]] = 1;
        }

        cout << min(c + (o ? 1 : 0), n) << ' ' << o + c << endl;
}

signed main() {
        ios_base::sync_with_stdio(!cin.tie(0));
        int t;
        cin >> t;
        while (t--) solve();
}
