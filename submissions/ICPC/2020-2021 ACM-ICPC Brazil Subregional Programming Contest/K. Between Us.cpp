#include <bits/stdc++.h>
using namespace std;

/*
 * XOR-SAT or Gauss XOR Elimination O(n*(m^2)/64)
 */

const int MAXXI = 2009;
using Equation = bitset<MAXXI>;
struct GaussXor {
	vector<char> B;
	vector<Equation> A;

	void add(const Equation& ai, bool bi) {
		A.push_back(ai);
		B.push_back(bi);
	}

	pair<bool, Equation> solution() {
		int cnt = 0, n = A.size();
		Equation vis; vis.set();
		Equation x;
		for(int j = MAXXI-1, i; j >= 0; j--) {
			for(i = cnt; i < n; i++) {
				if (A[i][j]) break;
			}
			if (i == n) continue;
			swap(A[i], A[cnt]), swap(B[i], B[cnt]);
			i = cnt++; vis[j] = 0;
			for(int k = 0; k < n; k++) {
				if (i == k || !A[k][j]) continue;
				A[k] ^= A[i]; B[k] ^= B[i];
			}
		}
		x = vis;
		for(int i = 0; i < n; i++) {
			int acum = 0;
			for(int j = 0; j < MAXXI; j++) {
				if (!A[i][j]) continue;
				if (!vis[j]) {
					vis[j] = 1;
					x[j] = acum^B[i];
				}
				acum ^= x[j];
			}
			if (acum != B[i]) return {false, Equation()};
		}
		return {true, x};
	}

};


int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, f;
	cin >> n >> f;

	vector<vector<int>> adj(n);
	while (f--) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	GaussXor gauss;
	for (int i = 0; i < n; i++) {
		Equation eq;

		for (auto v : adj[i]) {
			eq.set(v);
		}

		if (adj[i].size() & 1) {
			eq.set(i);
			gauss.add(eq, 0);
		}
		else {
			gauss.add(eq, 1);
		}
	}

	cout << "NY\n"[gauss.solution().first] << '\n';
}

// AC, gauss xor
