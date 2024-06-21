#include <bits/stdc++.h>
using namespace std;

const int MAXP = 10;
using pii = pair<int, int>;
// This implementation considers the rotations as distinct
//               0, 10, 10+9, 10+9+8...
int pos[11] = {0, 10, 19, 27, 34, 40, 45, 49, 52, 54, 55};
struct Polyominoes {
  pii v[MAXP];
  int64_t id;
  int n;
  Polyominoes() {
    n = 1;
    v[0] = {0, 0};
    normalize();
  }
  pii &operator[](int i) { return v[i]; }
  bool add(int a, int b) {
    for (int i = 0; i < n; i++)
      if (v[i].first == a and v[i].second == b)
        return false;
    v[n++] = pii(a, b);
    normalize();
    return true;
  }
  void normalize() {
    int mnx = 100, mny = 100;
    for (int i = 0; i < n; i++)
      mnx = min(mnx, v[i].first), mny = min(mny, v[i].second);
    id = 0;
    for (int i = 0; i < n; i++) {
      v[i].first -= mnx, v[i].second -= mny;
      id |= (1LL << (pos[v[i].first] + v[i].second));
    }
  }
};
vector<Polyominoes> polyominoes[MAXP + 1];
void buildPolyominoes(int mxN = 10) {

  vector<pair<int, int>> dt({{1, 0}, {-1, 0}, {0, -1}, {0, 1}});
  for (int i = 0; i <= mxN; i++)
    polyominoes[i].clear();
  Polyominoes init;
  queue<Polyominoes> q;
  unordered_set<int64_t> used;
  q.push(init);
  used.insert(init.id);
  while (!q.empty()) {
    Polyominoes u = q.front();
    q.pop();
    polyominoes[u.n].push_back(u);
    if (u.n == mxN)
      continue;
    for (int i = 0; i < u.n; i++) {
      for (auto [dx, dy] : dt) {
        Polyominoes to = u;
        bool ok = to.add(to[i].first + dx, to[i].second + dy);
        if (ok and !used.count(to.id)) {
          q.push(to);
          used.insert(to.id);
        }
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> xs(n, vector<int>(n));
  for (auto &i : xs) {
    for (auto &j : i) {
      cin >> j;
    }
  }

  buildPolyominoes(m);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (auto &p : polyominoes[m]) {
        bool ok = true;
        int cursum = 0;
        for (int k = 0; k < m; k++) {
          auto [x, y] = p.v[k];
          ok &= ((x + i < n) and (y + j < n));
          if (ok)
            cursum += xs[x + i][y + j];
        }
        ans = max(cursum, ans);
      }
    }
  }

  cout << ans << '\n';
}


// AC, polyminoes
