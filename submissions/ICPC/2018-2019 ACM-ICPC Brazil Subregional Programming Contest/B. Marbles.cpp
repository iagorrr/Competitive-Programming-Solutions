#include <bits/stdc++.h>
using namespace std;

const int maxx = 100;
int sg[maxx+1][maxx+1];
const int maxmex = 100*4;
int flag[maxmex+1];

void init() {
	for (int i = 1; i <= maxx; i++) {
		sg[i][0] = sg[0][i] = sg[i][i] = 0;
	}

	for (int i = 1; i <= maxx; i++) {
		for (int j = 1; j <= maxx; j++) {
			if (i == j) continue;
			memset(flag, 0, sizeof flag);

			for (int k = 1; k < i; k++)
				if (k != j)
					flag[sg[k][j]] = 1;

			for (int k = 1; k < j; k++)
				if (k != i)
					flag[sg[i][k]] = 1;

			for (int k = 1; k < min(i,j); k++)
				if (i-k != j-k)
					flag[sg[i-k][j-k]] = 1;

			for (int k = 0; k <= maxmex; k++) {
				if (!flag[k]) {
					sg[i][j] = k;
					break;
				}
			}
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	init();

	int n;
	cin >> n;

	int g = 0;
	int f = 0;
	while (n--) {
		int x, y;
		cin >> x >> y;
		g ^= sg[x][y];
		f |= (x==y);
	}
	cout << "NY"[g or f] << '\n';
}

// AC, game theory, sprague grundy
