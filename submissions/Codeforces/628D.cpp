#include <bits/stdc++.h>

#define int long long

const int MOD = 1'000'000'000 + 7;

int M, D;
const int MAXLEN = 2000 + 20;
int memo[MAXLEN][2][MAXLEN];
std::string digits;

int solve(int p, bool low, int m) {
	if (p == (int)digits.size()) {
		return m == 0;
	}

	auto &ans = memo[p][low][m];
	if (ans != -1) return ans;

	ans = 0;
	for (int d = 0; d < 10; d++) {
		if ((p&1) and  d != D) continue;
		if (!(p&1) and d == D) continue;
		if (!low and d > digits[p]-'0') continue;
		ans = (ans + solve(p+1, low | (d < digits[p]-'0'), (m*10+d) % M)) % MOD;
	}

	return ans;
}

int valid(const std::string &s) {
	int r = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		if (i&1 and s[i]-'0' != D) return false;
		if (!(i&1) and s[i]-'0' == D) return false;
		r = (r*10+(s[i]-'0')) % M;
	}
	return !r;
}

int32_t main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	std::cin >> M >> D;

	std::string A, B;
	std::cin >> A >> B;

	assert(A.size() == B.size());

	memset(memo, -1, sizeof memo);
	digits = B;
	auto b = solve(0, 0, 0);

	memset(memo, -1, sizeof memo);
	digits = A;
	auto a = solve(0, 0, 0);

	std::cerr << b << ' ' << a << '\n';
	auto ans = (b-a+MOD)%MOD;
	ans = (ans + valid(A)) % MOD;

	std::cout << ans << '\n';
}

// AC, dynamic programming on digits
