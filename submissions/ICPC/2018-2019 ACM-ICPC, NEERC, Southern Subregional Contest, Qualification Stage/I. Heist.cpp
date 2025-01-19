#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int32_t main() {
        ios_base::sync_with_stdio(!cin.tie(0));
        int N;
        cin >> N;

        vector<ll> XS(N);
        for (auto& xi : XS) cin >> xi;

        sort(begin(XS), end(XS));

        ll ans = 0;

        for (int i = 0; i + 1 < N; i++) {
                if (XS[i + 1] - XS[i] > 1) ans += (XS[i + 1] - XS[i] - 1);
        }

        cout << ans << endl;
}

// AC, ad-hoc
