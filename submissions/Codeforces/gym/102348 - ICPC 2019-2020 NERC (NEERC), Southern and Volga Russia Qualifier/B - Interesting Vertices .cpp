#include<bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(0));
    int N, K;
    cin >> N >> K;

    vector<int> marked(N);

    for (int i = 0; i < K; i++) {
        int u;
        cin >> u;
        u--;
        marked[u]++;
    }

    vector<vector<int>> ADJ(N);
    for (int i = 0, u, v; i < N -1; i++) {
        cin >> u >> v;
        u--, v--;
        ADJ[u].emplace_back(v);
        ADJ[v].emplace_back(u);
    }

    vector<int> tot(N);

    function<int(int,int)> dfs_calc =
        [&](int u, int p) {
            tot[u] = marked[u];
            for (int v : ADJ[u]) {
                if (v != p) {
                    tot[u] += dfs_calc(v, u);
                }
            }
            return tot[u];
        };

    int root = N - 1;

    dfs_calc(root, -1);

    vector<int> ans;
    function<void(int,int)> dfs = 
        [&](int u, int p) {
            bool ok = !marked[u];
            bool at_least = false;
            for (auto v : ADJ[u]) {
                at_least |= (tot[v]>=1);
                ok &= (tot[v] >= 1);
            }

            ok &= (at_least);
            if (ok) ans.push_back(u);

            int ori = tot[u];
            for (auto v : ADJ[u]) {
                if (v != p) {
                    int ori2 = tot[v];
                    tot[u] = ori - tot[v];
                    tot[v] = ori;
                    dfs(v, u);
                    tot[v] = ori2;
                    tot[u] = ori;
                }
            }
        };

    dfs(root, -1);

    sort(begin(ans), end(ans));

    cout << ans.size() << '\n';
    for (auto ai : ans){ 
        cout << ai + 1 << ' ';
    }
    cout << '\n';
}

// AC, reroot
