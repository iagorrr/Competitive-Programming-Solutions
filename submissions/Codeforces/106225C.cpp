#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> xs(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> xs[i][j];
    }
  }

  if (!(n & 1)) {
    set<vector<int>> st;
    for (auto xi : xs)
      st.insert(xi);

    for (auto si : st) {
      for (auto sij : si) {
        cout << sij << ' ';
      }
    }
    cout << '\n';

  } else {
    map<vector<int>, vector<int>> prefixToSuffix;
    map<vector<int>, vector<int>> suffixToPrefix;
    vector<int> cur;
    for (int i = 0; i < n; i++) {
      vector<int> prefix = vector<int>(xs[i].begin(), xs[i].begin() + m / 2);
      if (i == 0)
        cur = prefix;
      vector<int> suffix = vector<int>(xs[i].begin() + m / 2, xs[i].end());
      prefixToSuffix[prefix] = suffix;
      suffixToPrefix[suffix] = prefix;
    }
    vector<int> ans;
    auto f = cur;
    do {
      for (auto ci : cur)
        ans.emplace_back(ci);
      auto s = prefixToSuffix[cur];
      cur = s;

    } while (cur != f);

    for (auto ai : ans)
      cout << ai << ' ';
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(!cin.tie(0));
  int t;
  cin >> t;
  while (t--)
    solve();
}
