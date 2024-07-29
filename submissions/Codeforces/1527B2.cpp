#include <bits/stdc++.h>
using namespace std;


int pal(const string &s) {
	int cs = 0;
	for (int l = 0, r = s.size()-1; l < r; l++, r--) {
		cs += (s[l] != s[r]);
	}
	return cs;
}

string solve(int n, const string& s) {
	int c1 = count(s.begin(), s.end(), '1');
	int c0 = n - c1;

	int cspal = pal(s);

	if (cspal) {
		if (n&1 and c0 == 2 and s[n/2] == '0')
			return "DRAW";
		else return "ALICE";
	}

	if (c0 & 1) {
		return c0 == 1 ? "BOB" : "ALICE";
	}
	else {
		return "BOB";
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;

		// cout << s << '\n';
		cout << solve(n, s) << '\n';
	}
}

/*
	AC, strings, games, greddy
 */
