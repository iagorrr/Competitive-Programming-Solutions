#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<string> xs(8);
	for (auto &xi : xs) cin >> xi;

	vector<int> pos(8);
	iota(pos.begin(), pos.end(), 0);

	int ans = 0;
	do {
		bool ok = true;

		vector<int> d1(8*2-1), d2(8*2-1);

		for (int x = 0; x < 8; x++) {
			auto y = pos[x];
			
			ok &= (xs[x][y] != '*');
			int d = (x > y)*7 + max(x, y)-min(x,y);
			ok &= (++d1[d] <= 1);

			d = x + y;
			ok &= (++d2[d] <= 1);
		}

		ans += ok;
	} while(next_permutation(pos.begin(), pos.end()));

	cout << ans << '\n';
}

// AC, combinatorics, brute force
