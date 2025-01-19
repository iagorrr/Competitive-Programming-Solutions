#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int32_t main() {
        ios_base::sync_with_stdio(!cin.tie(0));
        ll a, b, x, y;
        cin >> a >> b >> x >> y;
        ll g = gcd(x, y);
        while (g != 1) {
                y /= g, x /= g;
                g = gcd(x, y);
        }
        cout << min(a / x, b / y) << endl;
}
