#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 998244353;

signed main() {
  ios_base::sync_with_stdio(!cin.tie(0));
  int n;
  cin >> n;

  vector<int> as(n);

  for (auto &ai : as)
    cin >> ai;

  vector<int> vis(n);
  vector<int> pos(2 * n + 1);

  function<int(int)> dfs = [&](int i) -> int {
    if (i == -1 or i >= n)
      return INT_MAX;

    if (vis[i])
      return 0;

    vis[i] = 1;

    int ai = as[i];
    int bi = i + 1;

    return max({ai, bi, dfs(ai - 1), dfs(pos[bi])});
  };

  vector<ll> p2(n + 1);
  p2[0] = 1;
  for (int i = 1; i <= n; i++) {
    p2[i] = (p2[i - 1] * 2ll) % mod;
  }

  ll ans = 0;
  for (int _ = 0; _ < n; _++) {
    fill(vis.begin(), vis.end(), 0);
    fill(pos.begin(), pos.end(), -1);

    int c = 0;

    for (int i = 0; i < n; i++)
      pos[as[i]] = i;

    for (int i = 0; i < n; i++) {
      if (vis[i])
        continue;

      int x = dfs(i);

      if (x <= n)
        c++;
    }

    ll inc = (p2[c] - 1 + mod) % mod;
    ans = (ans + inc) % mod;

    for (auto &li : as)
      li++;
  }

  cout << ans << endl;
}
