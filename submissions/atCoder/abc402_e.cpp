#include <bits/stdc++.h>
using namespace std;

using ld = long double;

const int maxn = 8;
const int maxx = 5000;

int n, x;
array<int, 3> ps[maxn];
long double mem[1 << maxn][maxx];
bool done[1 << maxn][maxx];

long double solve(int ss, int xl) {
        if (xl < 0) return 0;

        if (done[ss][xl]) return mem[ss][xl];

        ld ans = 0;

        for (int i = 0; i < n; i++) {
                if (ss & (1 << i)) continue;

                auto [si, ci, pi] = ps[i];

                if (ci > xl) continue;

                ld p1 = (ld)pi / 100.0;
                ld p2 = (ld)(100 - pi) / 100.0;

                ld c1 = p1 * (solve(ss | (1 << i), xl - ci) + si);
                ld c2 = p2 * solve(ss, xl - ci);
                ans = max(c1 + c2, ans);
        }

        return done[ss][xl] = 1, mem[ss][xl] = ans;
}

int32_t main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        cin >> n >> x;

        for (int i = 0; i < n; i++) {
                auto &[si, ci, pi] = ps[i];
                cin >> si >> ci >> pi;
        }

        cout << fixed << setprecision(20);
        cout << solve(0, x) << '\n';
}
