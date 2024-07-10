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

	int n, m, e;
	cin >> n >> m >> e;


	vector<pair<int,int>> edges(e);
	for (auto& [u, v] : edges)
		cin >> u >> v, u--, v--;

	vector<char> removed(e);
	int q;
	cin >> q;
	vector<int> qs(q);
	for (auto& qi : qs) {
		cin >> qi, qi--;
		removed[qi] = true;
	}

	DSU dsu(n+m);
	int cur = 0;
	vector<char> ele(n+m);
	fill(ele.begin()+n, ele.end(), true);
	auto join = [&](int u, int v) -> void {
		int su = dsu.find_set(u);
		int sv = dsu.find_set(v);
		if (!ele[su] and ele[sv]) {
			cur +=  dsu.size(su);
			ele[su] = true;
		}
		else if (ele[su] and !ele[sv]) {
			cur +=  dsu.size(sv);
			ele[sv] = true;
		}

		dsu.union_set(u, v);
	};

	for (int i = 0; i < e; i++) {
		if (not removed[i]) {
			const auto& [u, v] = edges[i];
			join(u, v);
		}
	}

	vector<int> ans;
	for (auto it = qs.rbegin(); it != qs.rend(); it++) {
		ans.push_back(cur);
		const auto& [u, v] = edges[*it];
		join(u, v);

	}

	for (auto it = ans.rbegin(); it != ans.rend(); it++) {
		cout << *it << '\n';
	}

}

// AC, graphs, dsu/ufds
