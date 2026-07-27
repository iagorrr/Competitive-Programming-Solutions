#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> ps, sz;

    // vector<unordered_set<int>> sts;

    DSU(int N)
        : ps(N + 1),
          sz(N, 1) /*, sts(N) */
    {
        iota(ps.begin(), ps.end(), 0);
        // for (int i = 0; i < N; i++)
        // sts[i].insert(i);
    }
    int find_set(int x) { return ps[x] == x ? x : ps[x] = find_set(ps[x]); }
    int size(int u) { return sz[find_set(u)]; }
    bool same_set(int x, int y) { return find_set(x) == find_set(y); }
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

struct LCA {
    int n;
    const int maxlog;
    vector<vector<int>> up;
    vector<int> depth;

    LCA(const vector<vector<int>> &tree, int root)
        : n(tree.size()),
          maxlog(ceil(log2(n))),
          up(n, vector<int>(maxlog + 1)),
          depth(n, -1) {
        dfs(root, -1, tree);
    }

    void dfs(int u, int p, const vector<vector<int>> &tree) {
        if (p != -1) {
            depth[u] = depth[p] + 1;
            up[u][0] = p;
            for (int i = 1; i <= maxlog; i++) {
                up[u][i] = up[up[u][i - 1]][i - 1];
            }
        }
        for (int v : tree[u]) {
            if (v == p) continue;
            dfs(v, u, tree);
        }
    }

    int kth_jump(int u, int k) {
        for (int i = maxlog; i >= 0; i--) {
            if ((1 << i) & k) {
                u = up[u][i];
            }
        }
        return u;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        u = kth_jump(u, diff);
        if (u == v) return u;
        for (int i = maxlog; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

    bool on_path(int u, int v, int s) {
        int uv = lca(u, v), us = lca(u, s), vs = lca(v, s);
        return (uv == s or (us == uv and vs == s) or (vs == uv and us == s));
    }

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    DSU dsu(n);
    int backEdgeU, backEdgeV;
    backEdgeU = backEdgeV = -1;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (dsu.same_set(u, v)) {
            assert(backEdgeU == -1);
            backEdgeU = u, backEdgeV = v;
        } else {
            adj[u].push_back(v);
            adj[v].push_back(u);
            dsu.union_set(u, v);
        }
    }

    vector<int> sz(n), ps(n);
    function<void(int, int)> dfs = [&](int u, int p) {
        sz[u] = 1;
        ps[u] = p;
        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u);
                sz[u] += sz[v];
            }
        }
    };
    dfs(backEdgeU, -1);

    long long ans = 0;
    int cur = backEdgeV;
    int lastSz = 0;
    while (cur != -1) {
        long long a = sz[cur] - lastSz;
        ans += ((long long)a * (a - 1)) / 2ll;
        ans += (long long)a * (n - a);
        lastSz = sz[cur];
        cur = ps[cur];
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(!cin.tie(0));
    int t;
    cin >> t;
    while (t--) solve();
}
