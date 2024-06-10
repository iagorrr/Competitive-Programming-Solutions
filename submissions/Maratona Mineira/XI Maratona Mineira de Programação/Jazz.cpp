#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.cpp"
#else
#define dbg(...)
#endif

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> hist(2e5 + 1), a(n);
  int mx = 0;
  for (auto &x : a) {
    cin >> x;
    hist[x]++;
    mx = max(mx, x);
  }
  vector<int> memo(mx + 1, -1);
  auto dp = [&](auto &&self, int i) {
    if (i > mx) return 0;
    auto &res = memo[i];
    if (~res) return res;
    res = hist[i];
    for (int j = i + i; j <= mx; j+=i) {
      res = max(res, self(self, j) + hist[i]);
    }
    return res;
  };
  cout << dp(dp, 1) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  // cin >> t; cin.ignore();
  for (auto i = 1; i <= t; i++) {
    solve();
  }

  return 0;
}

// AC, math, dynamic programming
