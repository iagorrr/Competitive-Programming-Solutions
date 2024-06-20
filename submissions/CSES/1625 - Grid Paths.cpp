#include <bits/stdc++.h>
using namespace std;
 
vector<int> path(48);
int ans;
bool vis[9][9];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int m = 0) {
	if (!vis[x-1][y] and !vis[x+1][y] and vis[x][y+1] and vis[x][y-1]) return;
	if (!vis[x][y+1] and !vis[x][y-1] and vis[x-1][y] and vis[x+1][y]) return;

	if (x == 7 and y == 1) { ans += (m == 48u); return; }

	if (m == 48u) return;

	vis[x][y] = 1;
	if (path[m] <= 3) { 
		int x2 = x + dx[path[m]];
		int y2 = y + dy[path[m]];
 
		if (!vis[x2][y2]) {
			dfs(x2, y2, m+1);
		}

	}
	else {
		for (int j = 0; j < 4; j++) {
			int x2 = x + dx[j];
			int y2 = y + dy[j];
	 
			if (!vis[x2][y2]) {
				dfs(x2, y2, m+1);
			}
		}
	}

	vis[x][y] = 0;
}
 
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	string ps;
	cin >> ps;

	for (int i = 0; i < 48; i++) {
		if (ps[i] == 'U') path[i] = 0;
		else if (ps[i] == 'R') path[i] = 1;
		else if (ps[i] == 'D') path[i] = 2;
		else if (ps[i] == 'L') path[i] = 3;
		else path[i] = 4;
	}
 
	for (int i = 0; i <= 8; i++) {
		vis[0][i] = vis[8][i] = vis[i][0] = vis[i][8] = 1;
	}

	dfs(1, 1);
 
	cout << ans << '\n';
}

// AC, brute force, dfs/bfs
