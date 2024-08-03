#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	/*
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	*/

	/*
	int sz = 100;
	vector test(sz+1, vector(101, '.'));
	int _shots = 0;
	for (int r = 1; r <= sz; r++) {
		for (int c = r; c >= 1; c -= 5) {
			test[r][c] = '#';
			_shots++;
		}

		for (int c = r+5; c <= sz; c += 5) {
			test[r][c] = '#';
			_shots++;
		}
	}

	for (int i = 1; i <= sz; i++){
		for (int j = 1; j <= sz; j++)
			cerr << test[i][j];
		cerr << '\n';
	}
	cerr << _shots << '\n';
	return 0;
	*/

	int N, K;
	cin >> N >> K;

	vector grid(N+1, vector(N+1, -1));

	// miss = 0
	// hit = 1
	vector<pair<int,int>> hits;
	int sunks = 0;
	int shots = 0;
	auto ask = [&](int x, int y) -> int {
		if (x < 1 or y < 1 or x > N or y > N)
			return -1;

		auto &ret = grid[x][y];
		if (ret != -1)
			return ret;

		assert(shots < 2500);
		cout << x << ' ' << y << endl;
		shots++;

		string s;
		cin >> s;

		if (s == "hit" or s == "sunk") {
			sunks += (s == "sunk");
			ret = 1;
		}
		else ret = 0;

		if (sunks == K) {
			exit(0);
		}

		if (ret == 1) {
			hits.emplace_back(x, y);
		}
		return ret;
	};

	for (int r = 1; r <= N; r++) {
		for (int c = r; c <= N; c += 5) {
			ask(r, c);
		}

		for (int c = r; c >= 1; c -= 5) {
			ask(r, c);
		}
	}

	static const int dx[] = {1, -1, 0, 0};
	static const int dy[] = {0, 0, 1, -1};
	int m = hits.size();
	for (int i = 0; i < m; i++) {
		auto [x, y] = hits[i];
		for (int d = 0; d < 4; d++) {
			for (int l = 1; l <= 10; l++) {
				ask(x + dx[d]*l, y + dy[d]*l);
			}
		}
	}

	assert(sunks >= K);
}

// AC, interactive problem, brute force
