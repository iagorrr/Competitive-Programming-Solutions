#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int h, w, d;
	cin >> h >> w >> d;

	using t3 = tuple<int,int,int>;
	vector<vector<t3>> cords(d);
	for (int i = 0; i < h; i++) {
		for(int j = 0, ij; j < w; j++) {
			cin >> ij;
			cords[ij%d].push_back({ij, i, j});
		}
	}

	vector<vector<int>> psums(d);
	for (int i = 0; i < d; i++) {
		sort(cords[i].begin(), cords[i].end());
		auto &psum = psums[i];
		int px, py;
		for (auto [_, x, y] : cords[i]) {
			if (psum.empty()) {
				psum.push_back(0);

			}
			else {
				psum.push_back(psum.back() + abs(x-px) + abs(y-py));
			}
			px = x, py = y;
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;

		auto idx = l % d;
		l = (l+d-1)/d, r = (r+d-1)/d;
		l--, r--;
		cout << psums[idx][r] - (l ? psums[idx][l] : 0) << '\n';

	}
}

// AC, prefix sum
