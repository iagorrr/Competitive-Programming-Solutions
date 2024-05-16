
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
#define all(x) x.begin(), x.end()

struct DSU {
  vi ps, sz;

  // vector<unordered_set<int>> sts;

  DSU(int N) : ps(N + 1), sz(N, 1) /*, sts(N) */ {
    iota(all(ps), 0);
    // for (int i = 0; i < N; i++) sts[i].insert(i);
  }
  int find_set(int x) {
    return ps[x] == x ? x : ps[x] = find_set(ps[x]);
  }
  int size(int u) { return sz[find_set(u)]; }
  bool same_set(int x, int y) {
    return find_set(x) == find_set(y);
  }
  void union_set(int x, int y) {
    if (same_set(x, y)) return;

    int px = find_set(x);
    int py = find_set(y);

    if (sz[px] < sz[py]) swap(px, py);

    ps[py] = px;
    sz[px] += sz[py];
    // sts[px].merge(sts[py]);
  }
};
auto run() {
        int n, m;
        cin >> n >> m;

        DSU dsu(n);
        vector<int> adj_cnt(n);
        for (int i = 0; i < m; i++) {
                int a, b;
                cin >> a >> b;
                a--, b--;
                adj_cnt[a]++;
                adj_cnt[b]++;
                dsu.union_set(a, b);
        }

        using ll = long long;
        ll ans = 0;

        for (int i = 0; i < n; i++) {
                int sza = dsu.size(i);
                ans += (sza - 1 - adj_cnt[i]);
        }

        ans >>= 1;

        cout << ans << '\n';
}

int32_t main() {
        run();        
}

// AC, permutations
