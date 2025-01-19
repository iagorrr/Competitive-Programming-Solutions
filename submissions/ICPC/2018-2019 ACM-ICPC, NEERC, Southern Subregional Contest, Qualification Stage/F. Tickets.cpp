#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int32_t main() {
        ios_base::sync_with_stdio(!cin.tie(0));
        vector<int> res(1'000'000, 0), cnt(28, 0);
        for (int i = 0; i <= 9; ++i) {
                for (int j = 0; j <= 9; ++j)
                        for (int k = 0; k <= 9; ++k)
                                for (int a = 0; a <= 9; ++a)
                                        for (int b = 0; b <= 9; ++b)
                                                for (int c = 0; c <= 9; ++c) {
                                                        int x = abs(a + b + c -
                                                                    i - j - k);
                                                        ++cnt[x];
                                                        int r = 0;
                                                        for (int z = 0; z < x;
                                                             ++z)
                                                                r += cnt[z];
                                                        res[i * 100000 +
                                                            j * 10000 +
                                                            k * 1000 + a * 100 +
                                                            b * 10 + c] = r;
                                                }
        }
        int t;
        cin >> t;
        while (t--) {
                string x;
                cin >> x;
                int now = stoi(x);
                cout << res[now] << "\n";
        }
}
