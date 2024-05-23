#include <bits/stdc++.h>
using namespace std;

const int maxx = 5 * 1'00'000;
list<int> ls[maxx+1];

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;

	int p = 0;
	for (int i = 0; i < q; i++) {
		int o;
		cin >> o;

		if (o == 1) {
			int x;
			cin >> x;
			ls[x].push_back(p++);
		}
		else {
			int x, y;
			cin >> x >> y;
			ls[y].splice(ls[y].end(), ls[x]);
		}
	}

	vector<int> ans(p);
	for (int i = 0; i <= maxx; i++) {
		for (auto v : ls[i]) ans[v] = i;
	}

	for (auto i : ans) cout << i << ' ';
	cout << '\n';
}

// AC, data structures, implementations
