#include <bits/stdc++.h>

#include <numeric>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(!cin.tie(0));
    int n, k;
    cin >> n >> k;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> depth(n), sz(n);
    function<void(int, int)> dfs = [&](int u, int p) {
        sz[u] = 1;
        for (int v : adj[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                dfs(v, u);
                sz[u] += sz[v];
            }
        }
    };
    dfs(0, -1);

    vector<int> cs(n);
    for (int i = 0; i < n; i++) {
        cs[i] = depth[i] - sz[i] + 1;
    }
    sort(cs.rbegin(), cs.rend());

    cout << accumulate(cs.begin(), cs.begin() + k, 0ll) << endl;
}
