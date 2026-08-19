#include <bits/stdc++.h>
using namespace std;

struct SackRec {
  int n, root, timer;
  vector<vector<int>> g;
  vector<int> par, sz, heavy, tin, tout, ord;

  SackRec(const vector<vector<int>> &g_, int root_)
      : n(g_.size()), root(root_), g(g_), par(n, -1), sz(n, 0), heavy(n, -1),
        tin(n), tout(n), ord(n)

  {
    timer = 0;
    dfs(root);
  }

  void dfs(int u) {
    sz[u] = 1;
    tin[u] = timer;
    ord[timer++] = u;
    for (int v : g[u])
      if (v != par[u]) {
        par[v] = u;
        dfs(v);
        sz[u] += sz[v];
        if (heavy[u] == -1 || sz[v] > sz[heavy[u]])
          heavy[u] = v;
      }
    tout[u] = timer;
  }

  template <class FA, class FS, class FD, class FE>
  void go(int u, bool keep, FA &ADD, FS &SNAP, FD &DEL, FE &EMPTY) {
    for (int v : g[u])
      if (v != par[u] && v != heavy[u])
        go(v, false, ADD, SNAP, DEL, EMPTY);
    if (heavy[u] != -1)
      go(heavy[u], true, ADD, SNAP, DEL, EMPTY);
    for (int v : g[u])
      if (v != par[u] && v != heavy[u])
        for (int i = tin[v]; i < tout[v]; i++)
          ADD(ord[i]);
    ADD(u);
    SNAP(u);
    if (!keep) {
      for (int i = tin[u]; i < tout[u]; i++)
        DEL(ord[i]);
      EMPTY();
    }
  }
  template <class FA, class FS, class FD, class FE>
  void run(FA ADD, FS ANS, FD DEL, FE EMPTY) {
    go(root, true, ADD, ANS, DEL, EMPTY);
  }

  template <class FA, class FS, class FD> void run(FA ADD, FS SNAP, FD DEL) {
    auto E = [] {};
    go(root, true, ADD, SNAP, DEL, E);
  }
};

signed main() {
  ios_base::sync_with_stdio(!cin.tie(0));
  int n;
  cin >> n;

  vector<int> cs(n);
  for (auto &ci : cs)
    cin >> ci;

  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  SackRec sack(g, 0);

  unordered_map<int, int> cnt;
  int totUnique = 0;
  auto add = [&](int u) {
    cnt[cs[u]]++;
    totUnique += cnt[cs[u]] == 1;
  };
  vector<int> ans(n);
  auto answer = [&](int u) { ans[u] = totUnique; };
  auto del = [&](int u) {
    cnt[cs[u]]--;
    totUnique -= cnt[cs[u]] == 0;
  };

  sack.run(add, answer, del);

  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i + 1 == n];
  }
}
