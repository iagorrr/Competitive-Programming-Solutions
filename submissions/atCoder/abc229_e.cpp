#include <bits/stdc++.h>
using namespace std;
struct DSU {
  vector<int> ps, sz;

  // vector<unordered_set<int>> sts;

  DSU(int N) : ps(N + 1), sz(N, 1) /*, sts(N) */ {
    iota(ps.begin(), ps.end(), 0);
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

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> g(n);
	for (int i= 0, a, b; i < m; i++) {
		cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	vector<int> ans(n);
	int cur = 0;
	DSU dsu(n);
	for (int i = n - 1; i >= 0; i--) {
		ans[i] = cur;

		set<int> dis;
		for (auto v : g[i]) {
			if (v > i)
				dis.emplace(dsu.find_set(v));
		}

		for (auto v : g[i]) {
			if (v > i)
				dsu.union_set(i, v);
		}

		if (dis.empty()) {
			cur++;
		}
		else {
			cur = cur - dis.size() + 1;
		}

	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << " \n"[i+1==n];
}


// AC, graphs, data structures, DSU/UFDS
