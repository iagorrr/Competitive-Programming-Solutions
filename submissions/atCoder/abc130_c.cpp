#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long h, w, x, y;
  cin >> w >> h >> x >> y;
  bool ans = (!(w & 1) && (x == w / 2)) &&
             (!(h & 1) && (y == h / 2));
  string ans2 = to_string((h * w) / 2ll);
  if ((h * w) & 1ll)
    ans2 += ".5000000000000000000000";
  else
    ans2 += ".0000000000000000000000";
  cout << ans2 << ' ' << ans << '\n';
}
// AC, geometry
