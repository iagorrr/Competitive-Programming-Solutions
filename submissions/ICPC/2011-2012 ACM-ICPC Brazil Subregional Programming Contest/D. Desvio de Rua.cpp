#include<bits/stdc++.h>

using namespace std;

struct SCC {
	int size;
	vector<int> comp_id;
	vector<vector<int>> comps, g;
	SCC(const vector<vector<int>> &g_) : size(0), comp_id(g_.size(), -1), g(0) {
		int timer = 1;
		vector<int> tin(g_.size()), st;
		st.reserve(g_.size());
		auto dfs = [&](auto &&self, int u) -> int {
			int low = tin[u] = timer++, now = (int)st.size();
			st.push_back(u);
			for (auto v : g_[u]) {
				if (comp_id[v] < 0)
					low = min(low, tin[v] ? tin[v] : self(self, v));
			}
			if (tin[u] == low) {
				for (int i = now; i < (int)st.size(); i++)
					comp_id[st[i]] = size;
				st.resize(now);
				size++;
			}
			return low;
		};
		for (int i = 0; i < g_.size(); i++) {
			if (!tin[i]) dfs(dfs, i);
		}
		comps.resize(size);
		for (int i = 0; i < (int)comp_id.size(); i++) {
			comps[comp_id[i]].push_back(i);
		}

		g = [&]() {
			set<pair<int, int>> edges;
			for (int i = 0; i < (int)g_.size(); i++) {
				for (auto x : g_[i]) {
					edges.emplace(comp_id[i], comp_id[x]);
				}
			}
			vector<vector<int>> tree(size);
			for (auto [u, v] : edges)
				tree[u].push_back(v);
			return tree;
		}();
	}
};

void solve() {
for (int n, m; cin >> n >> m;) {
	vector<vector<int>> g(n), gd(n);
	set<pair<int, int>> edges;
	bool fst = 1;
	for (int i = 0; i < m; i++) {
		int u, v, t;
		cin >> u >> v >> t;
		--u, --v;
		if (!fst) {
			gd[u].push_back(v);
			gd[v].push_back(u);
			g[u].push_back(v);
		}
		if (t == 2) {
			if (!fst) g[v].push_back(u);
			edges.emplace(minmax(u, v));
		}
		fst = 0;
	}

	if (SCC(g).size == 1) {
		cout << "-\n";
		continue;
	}

	vector<int> tin(n, -1);
	int timer = 0;
	vector<vector<int>> ng(n);
	auto dfs = [&](auto &&self, int u, int p) -> void {
		tin[u] = timer++;
		for (auto v : gd[u]) if (v != p) {
			if (tin[v] < tin[u]) {
				ng[u].push_back(v);
				if (edges.count(minmax(u, v)))
					ng[v].push_back(u);
			}
			if (tin[v] == -1)
				self(self, v, u);
		}
	};
	dfs(dfs, 0, -1);
	if (timer != n) {
		cout << "*\n";
		continue;
	}

	cout << (SCC(ng).size == 1 ? "1" : "2") << '\n';
}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
}


// AC, graphs, dfs and similar, connected components
