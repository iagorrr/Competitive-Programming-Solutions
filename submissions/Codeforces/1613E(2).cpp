#include <bits/stdc++.h>
using namespace std;

auto run() {
	int N, M;
	cin >> N >> M;

	vector<string> GRID(N);
	for (auto& xi : GRID) {
		cin >> xi;
	}

	vector cnt(N, vector(M, 0));	

	static const int dx[] = {1, -1, 0, 0};
	static const int dy[] = {0, 0, 1, -1};

	int si, sj;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (GRID[i][j] == 'L') {
				si = i, sj = j;
			}


			for (int d = 0; d < 4; d++) {
				int i2 = i + dx[d];
				int j2 = j  + dy[d];
				if (i2 >= 0 and j2 >= 0 and i2 < N and j2 < M) {
					cnt[i][j] += (GRID[i2][j2] != '#');
				}
			}
		}
	}

	auto dfs = [&](auto&& self, int x, int y) -> void {
		for (int d = 0; d < 4; d++) {
			int x2 = x + dx[d];
			int y2 = y + dy[d];

			if (x2 >= 0 and y2 >= 0 and x2 < N and y2 < M) {
				if (GRID[x2][y2] == '.') {
					cnt[x2][y2]--;

					if (cnt[x2][y2] <= 1) {
						GRID[x2][y2] = '+';
						self(self, x2, y2);
					}
				}

			}
		}
	};

	dfs(dfs, si, sj);



	for (auto& i : GRID) {
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

	AC, graphs, dfs
 */

