#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;
using vll = vector<ll>;

void solve() {
  int n;
  cin >> n;

  vector<ll> as(n);
  for (auto &ai : as)
    cin >> ai;

  { // compression
    vector<ll> sas(all(as));
    sort(all(sas));
    unordered_map<ll, ll> idx;
    for (auto ai : sas) {
      if (idx.count(ai))
        continue;
      int i = idx.size();
      idx[ai] = i;
    }

    for (auto &ai : as)
      ai = idx[ai];
  }

  vll ms(n + 1, n); // even cases with no median are cursed
                    // n is cursed
  {
    vll cur;
    for (int i = n - 1, sz = 1; i >= 0; i--, sz++) {
      cur.push_back(as[i]);
      sort(all(cur));
      if (sz & 1)
        ms[i] = cur[sz / 2];
      else if (cur[sz / 2] == cur[sz / 2 - 1]) {
        ms[i] = cur[sz / 2];
      }
    }
  }

  vector<vector<ll>> mem(n + 1, vector<ll>(n + 1, -1e4));
  for (int r = n - 1; r >= 0; r--) {
    ll m = ms[r + 1]; // problem when r = n -1 (or not)

    ll totLess = 0, totEq = 0;
    for (int l = r, sz = 1; l >= 0; l -= 2, sz += 2) {
      totLess += as[l] < m, totEq += as[l] == m;

      if (r + 1 == n) {
        mem[l][ms[l]] = 1;
      } else {
        bool isM = totLess <= sz / 2 and totLess + totEq > sz / 2;
        if (isM)
          mem[l][m] = max(mem[l][m], mem[r + 1][m] + 1);
      }

      if (l)
        totLess += as[l - 1] < m, totEq += as[l - 1] == m;
    }
  }

  ll ans = 1;
  for (int i = 0; i < n; i++)
    ans = max(ans, mem[0][i]);
  cout << ans << endl;
}

signed main() {
  ios_base::sync_with_stdio(!cin.tie(0));
  int t;
  cin >> t;
  while (t--)
    solve();
}
