#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<set<int>> adj1(n), adj2(n);
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		a--, b--;
		adj1[a].emplace(b);
		adj1[b].emplace(a);
	}

	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		a--, b--;
		adj2[a].emplace(b);
		adj2[b].emplace(a);
	}

	vector<int> perm(n);
	iota(perm.begin(), perm.end(), 0);
	
	bool found = false;

	do {
		bool ok = true;
		for (int i = 0; i < n; i++) {
			for (auto j : adj1[i])
				ok &= adj2[perm[i]].count(perm[j]);
		}
		found |= ok;
	}while(next_permutation(perm.begin(), perm.end()));
	if (found) {
		cout << "Yes\n";
	}
	else cout << "No\n";

}

