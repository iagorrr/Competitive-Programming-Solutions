#include <bits/stdc++.h>
using namespace std;



const int mod = 998244353;

int n, k;
string S;

const int MAXN = 1000, MAXK = 10;
vector<map<string,int>> dp(MAXN);

bool ispal(const string& s) {
	int n = s.size();
	for (int l = 0, r = n-1; l < r; l++, r--) {
		if (s[l] != s[r]) return false;
	}
	return true;
}

int solve(int p, string &s) {
	if (p == n) return 1;

	if (dp[p].count(s))
		return dp[p][s];

	dp[p][s] = 0;
	if (S[p] == '?') {
		string ns = s;
		ns.push_back('A');

		if ((int)ns.size() > k) ns = ns.substr(1);
		if ((int)ns.size() != k or !ispal(ns))
			dp[p][s] = solve(p+1, ns);

		ns.pop_back();
		ns.push_back('B');

		if ((int)ns.size() != k or !ispal(ns))
		dp[p][s] = (dp[p][s] + solve(p+1, ns)) % mod;
	}
	else {
		string ns = s;
		ns.push_back(S[p]);
		if ((int)ns.size() > k) ns = ns.substr(1);
		if ((int)ns.size() != k or !ispal(ns))
			dp[p][s] = solve(p+1, ns);
	}

	return dp[p][s];
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	cin >> S;

	string i;
	cout << solve(0, i) << '\n';;



}


// AC, dynamic programming, strings
