#include <bits/stdc++.h>
using namespace std;


const int MAXN = 1'000;
int memo[MAXN/2 + 1][MAXN/2 + 1][2][2];

int solve(int c01, int c00, bool mid, bool pr) {
	if (!c01 and !c00 and !mid) {
	       	return 0;
	}
	auto& ret = memo[c01][c00][mid][pr];
	if (ret != -1) {
		return ret;
	}

	ret = 1'000'000;

	int c0 = c00 * 2 + c01 + mid;

	if (c00) {
		ret = min(ret, c0 - solve(c01+1, c00-1, mid, false));
	}

	if (c01) {
		ret = min(ret, c0 - solve(c01-1, c00, mid, false));
	}

	if (!pr and c01) {
		ret = min(ret, c0 - solve(c01, c00, mid, true));
	}

	if (mid) {
		ret = min(ret, c0 - solve(c01, c00, false, false));

	}

	assert(ret != 1'000'000'000);
	return ret;
}


int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(memo, -1, sizeof memo);

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

		int a = solve(c01, c00, mid, false);
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

