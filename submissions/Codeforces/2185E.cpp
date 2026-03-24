#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void run() {
  ll n, m, k;
  cin >> n >> m >> k;

  vector<ll> as(n);
  for (auto &ai : as)
    cin >> ai;
  vector<ll> bs(m);
  for (auto &bi : bs)
    cin >> bi;

  string is;
  cin >> is;

  sort(bs.begin(), bs.end());
  const ll oo = 4e9;
  vector<ll> ls(n, -oo), rs(n, oo);
  multiset<pair<ll, ll>> lss, rss;
  for (int i = 0; i < n; i++) {
    auto ai = as[i];
    auto ptr = lower_bound(bs.begin(), bs.end(), ai);

    if (ptr != end(bs)) {
      rs[i] = *ptr - ai;
    }

    if (ptr != begin(bs)) {
      ls[i] = -(ai - *prev(ptr));
    }

    lss.emplace(ls[i], i);
    rss.emplace(rs[i], i);
  }

  // for (int i = 0; i < n; i++) {
  //   cout << ls[i] << ' ';
  // }
  // cout << '\n';
  // for (int i = 0; i < n; i++) {
  //   cout << rs[i] << ' ';
  // }
  // cout << '\n';

  ll d = 0;
  for (auto c : is) {
    d += (c == 'L' ? -1 : 1);

    while (lss.size() and (*(lss.rbegin())).first == d) {
      int i = lss.rbegin()->second;
      lss.erase({ls[i], i});
      rss.erase({rs[i], i});
    }

    while (rss.size() and (*(rss.begin())).first == d) {
      int i = rss.begin()->second;
      lss.erase({ls[i], i});
      rss.erase({rs[i], i});
    }

    cout << lss.size() << ' ';
  }

  cout << '\n';
}

signed main() {
  ios_base::sync_with_stdio(!cin.tie(0));
  ll t;
  cin >> t;
  while (t--)
    run();
}
