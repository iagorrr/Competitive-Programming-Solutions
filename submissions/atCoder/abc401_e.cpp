#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(0));
	int N, M;
	cin >> N >> M;

	vector<vector<int>> ADJ(N);
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >>v;

		u--, v--;

		ADJ[u].emplace_back(v);
		ADJ[v].emplace_back(u);
	}

	vector<int> inGraph(N), waiting(N);
	vector<int> reachable(N);

	int border = 0, inGraphCnt = 0;

	function<void(int)> add = [&](int u) {
		if (inGraph[u]) return;

		if (!reachable[u]) {
			waiting[u] = true;
			return;
		}

		inGraphCnt += !inGraph[u];

		inGraph[u] = true;

		border -= reachable[u];

		for (auto v : ADJ[u]) {
			border += !reachable[v];
			reachable[v] = 1;

			if (waiting[v]) add(v);
		}
	};




	reachable[0] = 1;
	border = 1;
	add(0);
	cout << border << '\n';

	for (int i = 1; i < N; i++) {
		add(i);
		if (inGraphCnt == i+1) cout << border << '\n';
		else cout << -1 << '\n';
		
	}



}

/*
 * AC, graphs
*/

