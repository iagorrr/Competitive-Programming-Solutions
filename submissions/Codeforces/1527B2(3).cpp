#include <bits/stdc++.h>
using namespace std;


const int MAXN = 1'000;
constexpr int MAXC = MAXN/2;
constexpr int OO = MAXN + 1;
int memo[MAXC + 1][MAXC + 1][2][2];

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i <= MAXC; i++) {
		for (int j = 0; j <= MAXC; j++) {
			for (int k = 0; k < 2; k++) {
				for (int l = 0; l < 2; l++) {
					memo[i][j][k][l] = OO;
				}
			}
		}
	}

	for (int c00 = 0; c00 <= MAXC; c00++) {
		for (int c01 = 0; c01 <= MAXC; c01++) {
			for (int mid = 0; mid < 2; mid++) {
				for (int pr = 1; pr >= 0; pr--) {
					auto& cur = memo[c00][c01][mid][pr];
					cur = OO;
					if (!c00 and !c01 and !mid) {
						cur = 0;
						continue;
					}

					int c0 = c00 * 2 + c01 + mid;
					if (!pr and c01)
						cur = min(cur, c0 - memo[c00][c01][mid][1]);
					if (c00) 
						cur = min(cur, c0 - memo[c00-1][c01+1][mid][0]);
					if (c01)
						cur = min(cur, c0 - memo[c00][c01-1][mid][0]);
					if (mid)
						cur = min(cur, c0 - memo[c00][c01][0][0]);
				}

			}
		}
	}

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;

		int c01, c00, mid;
		c01 = c00 = mid = 0;
		mid = (n&1) and s[n/2] == '0';
		for (int l = 0, r = n - 1; l < r; l++, r--) {
			c01 += (s[l] != s[r]);
			c00 += ((s[l] == s[r]) and (s[l] == '0'));
		}

		auto &st = memo[c00][c01][mid];
		int a = min(st[false], st[true]);
		int b = (c01 + c00*2 + mid) - a;
		if ( a < b) {
			cout << "ALICE";
		}
		else if (a == b) {
			cout << "DRAW";
		}
		else cout << "BOB";

		cout << "\n";
	}
}

/*
	AC, strings, games, dynamic programming
 */

