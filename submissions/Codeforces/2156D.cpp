#include <bits/stdc++.h>
using namespace std;

int query(int i, int mask) {
  cout << "? " << i << ' ' << mask << endl;
  int res;
  cin >> res;
  return res;
}

void solve() {
  int n;
  cin >> n;

  vector<int> scope(n);
  iota(scope.begin(), scope.end(), 1);
  vector<int> idxs(n - 1);
  iota(idxs.begin(), idxs.end(), 1);
  for (int b = 0; (1 << b) <= n and scope.size() > 1; b++) {
    vector<int> query_result;
    int got = 0;
    for (auto i : idxs) {
      int v = query(i, (1 << b));
      got += v;
      query_result.push_back(v);
    }

    int expected = 0;
    for (auto i : scope) {
      expected += ((i & (1 << b)) != 0);
    }

    vector<int> new_idx, new_scope;
    if (got != expected) {
      for (int i = 0; i < idxs.size(); i++) {
        if (query_result[i] == 1) {
          new_idx.push_back(idxs[i]);
        }
      }

      for (auto i : scope) {
        if (i & (1 << b)) {
          new_scope.push_back(i);
        }
      }

    } else {
      for (int i = 0; i < idxs.size(); i++) {
        if (query_result[i] == 0) {
          new_idx.push_back(idxs[i]);
        }
      }

      for (auto i : scope) {
        if (!(i & (1 << b))) {
          new_scope.push_back(i);
        }
      }
    }

    scope = new_scope;
    idxs = new_idx;
  }

  cout << "! " << scope.front() << endl;
}

signed main() {
  ios_base::sync_with_stdio(!cin.tie(0));
  int t;
  cin >> t;

  while (t--)
    solve();
}

// AC, interactive, bitmasks, constructive algorithms
