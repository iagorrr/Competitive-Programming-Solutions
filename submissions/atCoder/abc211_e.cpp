#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;


int cur = 0;

vector<string> grid;
int n;
int k;
set<ull> vis;
set<ull> st;
const int dx[]=  {0,  0,  1, -1};
const int dy[]=  {1, -1, 0,  0};

void bfs(int xs, int ys) {
	using T = bitset<64>;
	queue<T> q;
	bitset<64> viss;
	viss[xs*n + ys]=  1;
	q.push(viss);


	while (!q.empty()) {
		auto state = q.front();
		q.pop();

		if (state.count() == k) {
			st.emplace(state.to_ullong());
			continue;
		}

		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				if (state[x*n + y]) continue;
				if (grid[x][y] == '#') continue;

				for (int i = 0; i < 4; i++) {
					int x2 = x + dx[i];
					int y2 = y + dy[i];

					if (x2 < 0 or y2 < 0) continue;
					if (x2 >= n or y2 >= n) continue;
					if (grid[x2][y2] == '#') continue;
					if (!state[x2*n+y2]) continue;


					state[x*n+y] = 1;

					if (vis.count(state.to_ullong())) {
						state[x*n+y] = 0;
						continue;
					}

					vis.emplace(state.to_ullong());
					q.push(state);

					state[x*n+y] = 0;

				}
			}
		}

	}
}

auto run() {
	cin >> n;
	cin >> k;

	grid.resize(n);
	for (auto &xi : grid) cin >> xi;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == '#') continue;
			bfs(i,j);
		}
	}	

	cout << st.size() << '\n';

}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}

// AC, graphs, bfs
