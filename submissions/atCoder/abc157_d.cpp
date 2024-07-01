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

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> dg(n);
	DSU dsu(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;

		dsu.union_set(a, b);

		dg[a]++;
		dg[b]++;
	}

	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		ans[i] = dsu.sz[dsu.find_set(i)] - dg[i] - 1;
	}

	while (k--) {
		int a, b;
		cin >> a >> b;
		a--, b--;

		if (dsu.same_set(a, b)) {
			ans[a]--;
			ans[b]--;
		}
	}

	for (auto i : ans) cout << i << ' ';
	cout << '\n';
}

// AC, graphs, connected components
