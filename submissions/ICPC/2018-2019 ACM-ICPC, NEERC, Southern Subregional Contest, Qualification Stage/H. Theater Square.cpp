#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll f(ll h, ll w) {
        // cerr << h << ' ' << w << '\n';
        return (w & 1ll) * h;
}

int32_t main() {
        ios_base::sync_with_stdio(!cin.tie(0));
        ll N, M;
        cin >> N >> M;

        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        ll ans = 0;

        ans += f(x1 - 1, M);                  // q1
        ans += f(x2 - x1 + 1, y1 - 1);        // q2
        ans += f(x2 - x1 + 1, M - y2);        // q3
        ans += f(N - x2, M);                  // q4

        cout << (ans + 1) / 2 << '\n';
}
