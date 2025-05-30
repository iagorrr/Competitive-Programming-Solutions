#include <bits/stdc++.h>
using namespace std;

#define int long long

const int oo = 2e9;

int check(int u, vector<vector<pair<int,int>>> &tg, vector<int> &bs,
		int mx, vector<int>&memo) {

	if (memo[u] != -2)
		return memo[u];

	int ret = u ? -1 : min(mx, bs[u]);

	for (auto &[v, w] : tg[u]) {
		if (w > mx) continue;
		int w2 = check(v, tg, bs, mx, memo);
		if (w2 == -1) continue;
		if (w2 < w) continue;
		if (w2 > mx) continue;

		ret = max(ret,  min(w2+ bs[u], mx));
	}


	return memo[u] = ret;
}


void solve(void) {
        int n, m;
        cin >> n >> m;

        vector<int> bs(n);
        for (auto &bi : bs)
        cin >> bi;


        vector<vector<pair<int,int>>> adj(n);
        for (int i = 0; i < m; i++) {
                int u, v, w;
                cin >> u >> v >>w;
                u--, v--;
                adj[v].emplace_back(u, w);
        }


        int ans = oo;


        for (int l = 0, r = oo; l <= r; ) {
                int mid = midpoint(l, r);
		vector<int> memo(n, -2);
                if (check(n-1, adj, bs, mid, memo) != -1) {
                        ans = min(ans, mid);
                        r = mid -1;
                }
                else l = mid + 1;

        }

        cout << (ans == oo ? -1 : ans) << '\n';

}

int32_t main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        int t;
        cin >> t;

        while(t--)
                solve();

}

// every dag have a toposort, how to use it ?
// AC, graphs, dag, dynamic programming, binary search
