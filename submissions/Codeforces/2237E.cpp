/*
42

O que faz quando já tá definido ?

O que faz quando tem ciclo ?

E se começar pelos que já estão definidos ?
    - Acho que é bom por que quando for nos livres
    não tem o risco de pegar algum valor que vai ter que ser usado
    no futuro


> Começa o grafo por B1

> Quando tem uma posição livre a gente escolhe somente a primeira
o resto é definido automagicamente

> duro é se quando a gente setar a primeira os demais que a gente é obrigado
a colocar já estiverem sendo usados daí não daria pra setar somente o menor

> Da pra isso virar um sat ?
    - Ainda que desse teria de minimizar um sat e aí é trevas 100%


> Da pra montar algo como cc e dizer rápido peguei esse valor
isso implica que eu tenho que pegar esses outros aqui, com isso pra cada posição
eu sei qual o primeiro disponível em O(N), mas daí se um valor não tá pegável,
eu tiro ele dessa lista então é amortizado tá safe.
    > Isso é relativo pra cada constraint
    > Se eu pego o 1, eu sei que o valor da esquerda vai ter que assumir
    a posição do 1 em A
    > Cada valor adiciona uma constraint
    > Que é uma aresta
    > Gera um trem aí que dá pra usar...
    > Quando eu uso um valor eu quebro o componente ? Se sim aí fudeu
    > Supondo que não, é só eu dar -- no componente do valor quando eu uso ele
    > So posso pegar um componente, se a contador dele for igual ao size (tenho
todos disponíveis)
    > Se em algum momento tiver um componente inválido eu aborto


> Quando começo por um valor que eu já tenho ele vai torar o componente inteiro
dele


Acho que é isso


Dá xabu quando:
-> Preciso setar alguém e não tenho nenhum
-> Vou setar um valor que já tá setado e entro em contradição

- Parte de baixo vai gerar alguns cilos tbm
- Tenho meio que fazer match dos ciclos, pegar um ciclo de baixo e encaixar em
um de cima
- Pra cada ciclo de cima eu pego um ciclo de baixo com o mesmo tamanho e o menor
menor valor

*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
        int n;
        cin >> n;
        vector<int> as(n);
        for (auto &ai : as) cin >> ai, ai--;

        vector<int> bs(n);
        for (auto &bi : bs) cin >> bi, bi = bi == -1 ? -1 : bi - 1;

        auto originalBs = bs;
        bs = vector<int>(n, -1);

        vector<int> posInA(n);
        for (int i = 0; i < n; i++) {
                posInA[as[i]] = i;
        }

        vector<int> deps(n, -1);
        for (int i = 0; i < n; i++) {
                int cur = i;
                while (deps[cur] == -1) {
                        deps[cur] = posInA[cur];
                        cur = posInA[cur];
                }
        }

        bool aborted = false;
        auto abort = [&]() { aborted = true; };

        vector<int> vUsed(n);
        function<void(int, int)> go = [&](int idxB, int v) -> void {
                if (bs[idxB] != -1) {
                        if (bs[idxB] != v) abort();
                        return;
                }

                if (vUsed[v]) {
                        abort();
                        return;
                }

                vUsed[v] = 1;
                bs[idxB] = v;

                idxB = posInA[idxB];
                v = posInA[v];

                go(idxB, v);
        };

        for (int i = 0; i < n; i++) {
                if (originalBs[i] != -1) {
                        go(i, originalBs[i]);
                        if (aborted) {
                                cout << "NO\n";
                                return;
                        }
                }
        }

        vector<vector<pair<int, vector<int>>>> down_cyclesBySize(n + 1);
        vector<int> down_vis(n);
        vector<int> down_cycleSize(n, -1);  // precisa deses -1 ?
        for (int i = 0; i < n; i++) {
                vector<int> curCycle;
                int u = i;
                while (!down_vis[u]) {
                        down_vis[u] = 1;
                        curCycle.push_back(u);
                        u = as[u];
                }

                if (!curCycle.empty()) {
                        pair<int, vector<int>> e{i, curCycle};
                        down_cyclesBySize[curCycle.size()].push_back(e);
                        for (auto x : curCycle)
                                down_cycleSize[x] = curCycle.size();
                }
        }
        for (auto &x : down_cyclesBySize) {
                sort(x.rbegin(), x.rend());
        }

        vector<vector<pair<int, vector<int>>>> up_cyclesBySize(n + 1);
        vector<int> up_vis(n);
        vector<int> up_cycleSize(n, -1);
        for (int i = 0; i < n; i++) {
                vector<int> curCycle;
                int u = i;
                while (!vUsed[u] and !up_vis[u]) {
                        up_vis[u] = 1;
                        curCycle.push_back(u);
                        u = posInA[u];
                }

                if (!curCycle.empty()) {
                        pair<int, vector<int>> e{i, curCycle};
                        up_cyclesBySize[curCycle.size()].push_back(e);
                        for (auto v : curCycle)
                                up_cycleSize[v] = curCycle.size();
                }
        }
        for (auto &x : up_cyclesBySize) {
                sort(x.rbegin(), x.rend());
        }

        for (int bIndex = 0; bIndex < n; bIndex++) {
                if (bs[bIndex] != -1) continue;
                int csz = down_cycleSize[bIndex];

                if (up_cyclesBySize[csz].empty()) {
                        cout << "NO\n";
                        return;
                }

                auto upCycle = up_cyclesBySize[csz].back().second;
                up_cyclesBySize[csz].pop_back();

                int curbIndex = bIndex;
                for (auto cycleValue : upCycle) {
                        bs[curbIndex] = cycleValue;
                        curbIndex = posInA[curbIndex];
                }
        }

        cout << "YES\n";
        for (int i = 0; i < n; i++) {
                cout << bs[i] + 1 << ' ';
        }
        cout << '\n';
}

signed main() {
        ios_base::sync_with_stdio(!cin.tie(0));
        int t;
        cin >> t;
        while (t--) solve();
}
