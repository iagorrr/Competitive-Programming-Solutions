#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<ll> cs(n), as(n), bs(n);
  for (int i = 0; i < n; i++) cin >> cs[i];
  for (int i = 0; i < n; i++) cin >> as[i];
  for (int i = 0; i < n; i++) cin >> bs[i];

  ll ans = 0;
  vector<ll> best(n);
  best.back() = cs.back() - 1;
  for (int i = n - 2; i >= 0; i--) {
    ll o = 2 + abs(as[i + 1] - bs[i + 1]) + best[i + 1];
    ans = max(ans, o);

    if (as[i + 1] != bs[i + 1]) {
      best[i] = 2 + best[i + 1] + cs[i] - abs(as[i + 1] - bs[i + 1]) - 1;
    }
    best[i] = max(cs[i] - 1, best[i]);
  }

  cout << ans << '\n';
}

signed main() {
  ios_base::sync_with_stdio(!cin.tie(0));
  int t;
  cin >> t;
  while (t--) solve();
}
