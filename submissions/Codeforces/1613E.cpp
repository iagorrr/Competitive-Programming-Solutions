#include <bits/stdc++.h>
using namespace std;

auto run() {
	int N, M;
	cin >> N >> M;

	vector<string> XS(N);
	for (auto& xi : XS)
		cin >> xi;

	int si, sj=-1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (XS[i][j] == 'L') {
				si = i, sj = j;
				break;
			}
		}
		if (sj != -1) break;
	}

	queue<pair<int,int>> q;
	q.emplace(si, sj);

	static const int dx[] = {-1, 1, 0, 0};
	static const int dy[] = {0, 0, 1, -1};

	while(!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		for (int d = 0; d < 4; d++) {
			int x2 = x + dx[d];
			int y2 = y + dy[d];

			if (x2 >= 0 and y2 >= 0 and x2 < N and y2 < M and XS[x2][y2] == '.') {
				int free_cells = 0;
				int lab_cell = 0;

				for (int d2 = 0; d2 < 4; d2++) {
					int x3 = x2 + dx[d2];
					int y3 = y2 + dy[d2];
					if (x3 >= 0 and y3 >= 0 and x3 < N and y3 < M) {
						free_cells += (XS[x3][y3] != '#');
						lab_cell += (XS[x3][y3] == '+' or XS[x3][y3] == 'L');
					}
				}

				if (free_cells - 1 <= lab_cell) {
					XS[x2][y2] = '+';
					q.emplace(x2, y2);
				}

			}
		}
	}

	for (auto& i : XS) {
		cout << i << '\n';
	}

}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		run();
	}
}


/*
	#++++
	..##L
	...#+
	...++

	AC, graphs, bfs
 */

