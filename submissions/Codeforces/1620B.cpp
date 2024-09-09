#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define x first
#define y second
ll det(pll a, pll b, pll c) {
  return (a.x*b.y+a.y*c.x+b.x*c.y)-(b.y*c.x+a.x*c.y+b.x*a.y);
}

void run() {
  ll w, h;
  cin >> w >> h;
  vector<vector<pll>> pts(4);

  int k;
  cin >> k;
  pts[0].resize(k);
  for (auto &[x, y] : pts[0]) {
    cin >> x;
    y = 0;
  }

  cin >> k;
  pts[1].resize(k);
  for (auto &[x, y] : pts[1]) {
    cin >> x;
    y = h;
  }

  cin >> k;
  pts[2].resize(k);
  for (auto &[x, y] : pts[2]) {
    cin >> y;
    x = 0;
  }

  cin >> k;
  pts[3].resize(k);
  for (auto &[x, y] : pts[3]) {
    cin >> y;
    x = w;
  }

  ll ans = 0;
  for (ll i = 0; i < 4; i++) {
    for (ll j = 0; j < 4; j++) {
      if (i != j) {
        for (auto pk : pts[j]){
          auto cur=abs(det(pts[i].back(),pts[i].front(), pk));
          ans = max(ans,cur);
        }
      }
    }
  }
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    run();
  }
}

// AC, geometry, brute force
