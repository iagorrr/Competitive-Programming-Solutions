#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> xs(n, vector<int>(m));
  vector<int> ys(m);
  int s = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> xs[i][j];
      s += xs[i][j];
      ys[j] += xs[i][j];
    }
  }

  if (s <= 1) {
    cout << 0 << '\n';
    cout << string(n, 'D') + string(m, 'R') << '\n';
    return;
  }

  int l = s / 2;

  string ans;
  for (int i = 0; i < m; i++) {
    if (ys[i] <= l) {
      ans.push_back('R');
      l -= ys[i];
    } else {
      int j = 0;
      while (ys[i] > l) {
        ys[i] -= xs[j][i];
        ans.push_back('D');
        j++;
      }
      ans.push_back('R');
      while (j < n) {
        ans.push_back('D');
        j++;
      }
      break;
    }
  }

  int r = n + m - ans.size();
  cout << (long long)(s / 2) * (long long)((s + 1) / 2) << '\n';
  cout << (ans + string(r, 'R')) << '\n';
}

signed main() {
  ios_base::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;

  while (t--)
    solve();
}

// AC, constructive, greedy
