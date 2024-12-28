#include <bits/stdc++.h>
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(0));
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> xs(n);
        for (auto &xi : xs)
            cin >> xi;

        int l = max(0, n - 2 * k - 1);
        long long ans = LLONG_MIN;
        for (int i = l; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                auto cur = (long long)(i+1)*(j+1) - k * (xs[i]|xs[j]);
                ans = max(cur, ans);
            }
        }

        cout << ans << '\n';
    }
}

// Math, greedy, bruteforce
