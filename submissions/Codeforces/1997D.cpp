#include <bits/stdc++.h>
using namespace std;

#define int long long

const int OO = INT_MAX;

int solve(int u, const vector<vector<int>>& adj, const vector<int>& as) {
	int au = as[u];
	int mx_leaf = -1;

	for (auto v : adj[u]) {
		mx_leaf = mx_leaf == -1 ? solve(v, adj,as) : min(mx_leaf, solve(v, adj, as));
	}

	int ans =  -1;
	if (adj[u].size() == 0) {
		ans = au;
	}
	else {
		if (u == 0)
			ans = au + mx_leaf;
		else {
			if (mx_leaf >= au) {
				ans = (mx_leaf + au) / 2;
			}
			else  ans = mx_leaf;
		}
	}

	//cerr << "u: " <<  u << '\n';
	//cerr << "	mx_leaf: " << mx_leaf << '\n';
	return ans;
}

auto run() {
	int N;
	cin >> N;

	vector<int> AS(N);
	for (auto& ai : AS)
		cin >> ai;

	vector<vector<int>> ADJ(N);
	for (int i = 1; i < N; i++) {
		int pi;
		cin >> pi;
		pi--;
		ADJ[pi].emplace_back(i);
	}

	cout << solve(0, ADJ, AS) << '\n';
	// cerr << "\n\n\n";
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		run();
	}

}

// AC, trees, dp, dfs
