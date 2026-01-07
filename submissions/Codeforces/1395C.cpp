
#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios_base::sync_with_stdio(!cin.tie(0));

  int n, m;
  cin >> n >> m;

  vector<int> as(n);
  for (int i = 0; i < n; i++) cin >> as[i];

  vector<int> bs(m);
  for (int i = 0; i < m; i++) cin >> bs[i];

  int c = 0;
  for (int b = 10; b >= 0; b--) {
    c |= (1 << b);
    bool ok = 1;
    for (int i = 0; i < n; i++) {
      bool ok2 = 0;
      for (int j = 0; j < m; j++) {
        ok2 |= ((as[i] & bs[j]) & c) == 0;
      }
      ok &= ok2;
    }

    if (!ok) {
      c ^= (1 << b);
    }
  }

  int ans = ((1 << 11) - 1) ^ c;

  cout << ans << '\n';
}

// AC, greedy, bitmasks
