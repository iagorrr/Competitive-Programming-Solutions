#include <bits/stdc++.h>
using namespace std;


vector<set<int>> adj;
vector<int> vis;
vector<int> order;
int n;
bool dfs(int u, int next = -1) {
	order.push_back(u);
	vis[u] = 1;
	if (order.size() == n) return true;

	if (next != -1) {
		// so tenho que escolher o next do next...
		for (auto v : adj[next]) {
			if (adj[u].count(v)) {
				if (dfs(next, v)) return true;
			}
		}
	}
	else {
		for (auto v : adj[u]) {
			for (auto v2 : adj[v]) {
				if (adj[u].count(v2)) {
					if (dfs(v, v2)) return true;
				}
			}
		}
	}

	order.pop_back();
	return false;
}

auto run() {
	cin >> n;

	adj.resize(n);

	for (int i = 0, a, b; i < n; i++) {
		cin >> a  >> b;
		a--, b--;
		adj[i].insert(a);
		adj[i].insert(b);
	}

	vis.resize(n);
	dfs(0);

	for (int i =0; i < n; i++) {
		cout << order[i]  + 1<<  " \n"[i==n-1];
	}

}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}


// AC, graphs, dfs and similar
