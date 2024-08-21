#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
#define rep(i,s,t) for(ll i=s; i<t;i++)
#define rrep(i,s,t) for(ll i=s; i>t;i--)

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<tuple<int, int, bool, int>> v(n);
  for (int i = 0; i < n; i++) {
    auto &[a,b,c,d]= v[i];
    cin >> a >> b >> c;
    d=i;
  }
  sort(begin(v), end(v));
  queue<pair<int, int>> q;
  vector<int> res;
  int ti = 0;
  for (auto [t, m, c, d] : v) {
    while (size(q) and ti + q.front().first <= t) ti += q.front().first, q.pop();
    if (empty(q)) ti = t;
    if (!c) {
      q.emplace(m, d);
      continue;
    }
    if (size(q)) {
      res.push_back(q.front().second);
      q.front() = {m, d};
    } else {
      q.emplace(m, d);
    }
    ti = t;
  }
  cout << size(res) << '\n';
  for (int i = 0; i < (int)size(res); i++) {
    cout << res[i]+1 << " \n"[i+1 == (int)size(res)];
  }
}
// AC, implementation
