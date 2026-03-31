#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define eb emplace_back
#define all(xs) xs.begin(), xs.end()

void solve() {
  ll n, l, r;
  cin >> n >> l >> r;
  vll xs(n);
  for (ll &x : xs)
    cin >> x;
  sort(all(xs));

  ll left = 0, right = 0;
  ll ans = 0;

  for (ll x : xs) {
    left += x - l;
    right += x - r;
  }

  ans = max(ans, min(left, right));

  for (ll x : xs) {
    left -= x - l;
    right -= x - r;

    ans = max(ans, min(left, right));

    left += l - x;
    right += r - x;
    ans = max(ans, min(left, right));
  }

  cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  ll t;
  cin >> t;
  while (t--)
    solve();
}
