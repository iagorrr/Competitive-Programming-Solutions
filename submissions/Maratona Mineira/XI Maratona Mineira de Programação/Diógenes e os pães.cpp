#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, d;
	cin >> n >> d;

	vector<pair<int, int>> paes(n);
	for (auto &pi : paes) {
		cin >> pi.first;
		pi.second  = 1;
	}

	int ans = 0;

	for (int i = 0; i < 200 + 6; i++) {
		int is, id;
		is = id = -1;
		for (int j = 0; j < n; j++) {
			auto [dj, sj] = paes[j];
			if (dj != d) continue;
			if (sj == 1) id =  j;
			if (sj == 2) is =  j;
		}

		if (is != -1) {
			ans++;
			paes[is].second = 0;
		}
		else if (id != -1) {
			ans++;
			paes[id].second = 0;
		}

		for (auto &[dj, sj] : paes) {
			if (sj == 0) continue;
			if (sj == 1) {
				dj--;
				if (dj < 0) dj =1, sj = 2;
			}
			else dj++;
		}
	}

	cout << ans << '\n';
}

// AC, simulation, greddy
