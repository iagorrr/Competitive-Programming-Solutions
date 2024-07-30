#include <bits/stdc++.h>
using namespace std;

auto run() {
	int N;
	cin >> N;

	string GRID[2];
	cin >> GRID[0] >> GRID[1];

	int freepos = 0;
	for (int i = 0; i < 2; i++)
		freepos += count(GRID[i].begin(), GRID[i].end(), '.');

	// cerr << "free: " <<  freepos << '\n';

	int ans = 0;
	for (int j = 0; j < 2; j++) {
		int free_r = freepos;
		int free_l = 0;

		free_r -= (GRID[j][0] == '.');
		free_r -= (GRID[!j][0] == '.');
		free_l += (GRID[j][0]== '.');
		free_l += (GRID[!j][0] == '.');

		for (int i = 1; i + 1< N; i++) {
			free_r -= (GRID[j][i] == '.');
			free_r -= (GRID[!j][i] == '.');

			if (GRID[j][i] == '.') {
				if ( 		GRID[!j][i-1] == 'x' and
					       	GRID[!j][i+1] == 'x' and
						GRID[!j][i] == '.' and
						free_l > 0 and
						free_r > 0
				)
					ans++;

			}

			free_l += (GRID[j][i]== '.');
			free_l += (GRID[!j][i] == '.');



		}
	}


	cout << ans << '\n';

}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		run();
	}

}

// AC, greddy
