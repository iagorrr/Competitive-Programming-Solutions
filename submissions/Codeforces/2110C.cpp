#include <bits/stdc++.h>
using namespace std;

void solve() {
        int n;
        cin >> n;

        vector<int> ds(n);
        for (auto &di : ds) cin >> di;

        vector<pair<int, int>> rngs(n);
        for (auto &[li, ri] : rngs) cin >> li >> ri;

        bool ok = true;

        auto intersec = [&](pair<int, int> a, pair<int, int> b,
                            int m) -> pair<int, int> {
                if (m == 1) b.first -= 1, b.second -= 1;
                if (m == -1) b.first -= 1;

                if (a.first > b.second or a.second < b.first) {
                        ok = false;
                        return {-1, -1};
                }
                return {max(a.first, b.first), min(a.second, b.second)};
        };

        for (int i = n - 1; i >= 1 and ok; i--) {
                rngs[i - 1] = intersec(rngs[i - 1], rngs[i], ds[i]);
        }

        if (!ok) {
                cout << -1 << '\n';
                return;
        }

        int y = 0;
        for (int i = 0; i < n; i++) {
                auto [li, ri] = rngs[i];

                if (ds[i] == -1) {
                        bool keep = li <= y and y <= ri;
                        bool inc = li <= y + 1 and y + 1 <= ri;
                        if (inc) {
                                ds[i] = 1;
                                y++;
                        } else if (keep) {
                                ds[i] = 0;
                        } else {
                                cout << -1 << '\n';
                                return;
                        }
                } else
                        y += ds[i];

                if (clamp(y, li, ri) != y) {
                        cout << -1 << '\n';
                        return;
                }
        }

        for (int i = 0; i < n; i++) {
                cout << ds[i] << " \n"[i + 1 == n];
        }
}

int32_t main() {
        ios_base::sync_with_stdio(!cin.tie(0));
        int T;
        cin >> T;

        while (T--) {
                solve();
        }
}

/*
 * greedy
 * */
