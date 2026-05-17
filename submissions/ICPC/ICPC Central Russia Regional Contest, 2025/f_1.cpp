/*

-> l é crescente (olha pra frente), for é descres
-> r é decrescente (olha pra trás), for é cres
*/
#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(!cin.tie(0));

    int n;
    cin >> n;

    vector<int> as(n);
    for (auto &xi : as) cin >> xi;

    vector mem(n, vector<int>(n, -1));

    auto solve = [&](int l, int r) {
        if (l == r) return 1;
        if (l > r) return 0;

        return mem[l][r];
    };

    int oo = n * n;
    for (int l = n - 1; l >= 0; l--) {
        for (int r = l; r <= n - 1; r++) {
            auto &res = mem[l][r];

            res = oo;

            // tirar l e e r e resolver a meiuca
            if (l != r) {
                int al = as[l], ar = as[r];
                if (al % ar == 0 or ar % al == 0) {
                    res = min(res, solve(l + 1, r - 1));
                }
            } else
                res = 1;  // acho que da pra matar esse caso

            // tirar l
            res = min(res, solve(l + 1, r) + 1);

            // tirar r
            res = min(res, solve(l, r - 1) + 1);

            // divir em dois seguementos
            for (int l2 = l; l2 < r; l2++) {
                res = min(res, solve(l, l2) + solve(l2 + 1, r));
            }
        }
    }

    vector<int> ans;

    function<void(int, int)> rebuild = [&](int l, int r) {
        if (l > r) return;
        if (l == r) ans.push_back(l);

        int goal = solve(l, r);

        int al = as[l], ar = as[r];
        if (((al % ar == 0) or (ar % al == 0)) and
            solve(l + 1, r - 1) == goal) {
            return rebuild(l + 1, r - 1), (void)0;
        }

        if (solve(l + 1, r) == goal) {
            return solve(l + 1, r), (void)0;
        }
        if (solve(l, r - 1) == goal) {
            return solve(l, r - 1), (void)0;
        }

        for (int l2 = l; l2 < r; l2++) {
            if (goal == solve(l, l2) + solve(l2 + 1, r)) {
                return rebuild(l, l2), rebuild(l2 + 1, r), (void)0;
            }
        }
    };
    rebuild(0, n - 1);

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto ai : ans) cout << ai + 1 << ' ';
    cout << '\n';
}
