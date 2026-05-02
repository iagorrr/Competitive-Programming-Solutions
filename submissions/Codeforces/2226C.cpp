/*
BB ?
    - É monotônico
    - Como que checa se consigo fazer de 0 ... M números ?

    - Se quero fazer E a partir de Ai

        M > E, M <= N

        Ai equiv E (mod m)
        Ai - E equiv 0 (mod m)


        Ai - E = m * k

    - Supondo que eu conisga saber quais elementos de A que geram E,
    como que escolho de modo que consiga gerar E+1, E+2 ...
    - Com BB Dava pra fazer o contrário, gerando a partir do maior e chegando no
    menor, mas acho que o problema é o memso.

    - BB mais guloso ?
        Se tem vários valores disponíves para fazer E, eu escolho aquele
        que gera menos valores novos sozinho, por que lee ...


    - Pra fazer E preciso de um Ai - E, tal que possua um divisor D tal que D >
        E
        - O maior divisor possível é ele mesmo
        - Se Ai - E > E é vapo
            Ai > 2 * E

    - Falta o caso em que x mod m onde m muito maior que x da sempre x
        - Tratar a parte, se Ai == E, é só pegar

*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool check(vector<ll>& xs, int E) {
        E--;
        multiset<ll> st(xs.begin(), xs.end());
        while (E >= 0 and !st.empty()) {
                if (st.find(E) != st.end()) {
                        st.extract(E);
                        E--;
                        continue;
                }

                if (*st.rbegin() > 2 * E) {
                        st.extract(*st.rbegin());
                        E--;
                        continue;
                }

                return false;
        }
        return E < 0;
}

void solve() {
        int n;
        cin >> n;

        vector<ll> xs(n);
        for (auto& xi : xs) cin >> xi;
        sort(xs.rbegin(), xs.rend());

        int ans = -1;

        for (int L = 0, R = n; L <= R;) {
                int M = midpoint(L, R);

                if (check(xs, M)) {
                        ans = max(ans, M);
                        L = M + 1;
                } else
                        R = M - 1;
        }

        cout << ans << '\n';
}

signed main() {
        ios_base::sync_with_stdio(!cin.tie(0));
        int t;
        cin >> t;
        while (t--) solve();
}
