#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int H, W, M;
	cin >> H >> W >> M;

	map<int,int> atRow, atCol;
	map<int, vector<int>> atRowCord;

	for (int i = 0; i < M; i++) {
		int hi, wi;
		cin >> hi >> wi;
		atRow[hi]++;
		atCol[wi]++;
		atRowCord[hi].emplace_back(wi);
	}

	set<pair<int,int>> colSt;
	for (auto& [c, q] : atCol) {
		colSt.emplace(q, c);
	}

	int ans = 0;
	for (auto& [hi , ws] : atRowCord) {
		int bestInHi = 0;
		for (auto wi : ws) {
			colSt.erase({atCol[wi], wi});
			bestInHi = max(bestInHi, atCol[wi]);
		}

		int bestCol = 0;
		if (!colSt.empty())
			bestCol = (*colSt.rbegin()).first;
		bestCol = max(bestCol, bestInHi-1);

		ans = max(ans, atRow[hi] + bestCol);

		for (auto wi : ws) {
			colSt.emplace(pair<int,int>{atCol[wi], wi});
		}
	}

	cout << ans << '\n';
}

// AC, greddy, brute force, data structures
