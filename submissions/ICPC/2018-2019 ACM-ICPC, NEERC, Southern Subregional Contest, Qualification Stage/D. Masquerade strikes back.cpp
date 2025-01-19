#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXA = 10'000'000;

int hist[MAXA + 1];
vector<pair<int, int>> ans[MAXA + 1];

int32_t main() {
        ios_base::sync_with_stdio(!cin.tie(0));
        cout.tie(0);
        int N;
        cin >> N;
        vector<ll> XS(N);

        for (auto &xi : XS) {
                cin >> xi;
                hist[xi]++;
        }

        for (auto &i : XS) {
                if (ans[i].size()) continue;
                if (hist[i] == 1) {
                        ans[i] = {{1, i}};
                        continue;
                }

                for (int d = 1; d * d <= i; d++) {
                        if (ans[i].size() == hist[i]) break;
                        if (i % d == 0) {
                                ans[i].emplace_back(d, i / d);
                                if (i / d != d) ans[i].emplace_back(i / d, d);
                        }
                }

                if (ans[i].size() < hist[i]) {
                        cout << "NO\n";
                        return 0;
                }
        }

        cout << "YES\n";
        for (auto &xi : XS) {
                cout << ans[xi].back().first << ' ' << ans[xi].back().second
                     << '\n';
                ans[xi].pop_back();
        }
}
