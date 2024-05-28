#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int 	MAXLEN = 10;
constexpr int 	MAXSUMD = 9*MAXLEN;
const int 	MAXK = 1'0'000;
ll memo[MAXLEN][MAXSUMD+1][MAXSUMD+1];

ll pow10(int p, int d, int sz) {
	int n = sz - (p+1);
	ll ret = d;
	for (;n--;) ret *= 10ll;
	return ret;
}

ll solve(int p, bool dif, int sumd, int modk, const int K, const string &digits) {
	if (p == (int)digits.size()) {
		return ((sumd % K) == 0) and (modk == 0);
	}

	auto &ans = memo[p][sumd][modk];
	if (dif and ans != -1) return ans;

	ll ret = 0;

	int u = dif ? 9 : digits[p]-'0';
	for (int d = 0; d <= u; d++) {
		int nmodk = (modk + (pow10(p, d, digits.size()) % K)) % K;
		ret += solve(p+1, dif | (d != (digits[p]-'0')), sumd+d, nmodk, K, digits);
	}

	return dif ? ans = ret : ret;
}

ll solve(ll N, int K) {
	string digits = to_string(N);

	// reset memo
	for (int i = 0; i <  (int)digits.size(); i++) {
		for (int j = 0; j < MAXSUMD; j++) {
			for (int k = 0; k < K; k++) {
				memo[i][j][k] = -1;
			}
		}
	}

	return solve(0, 0, 0, 0, K, digits);
}


ll solve(ll A, ll B, int K) {
	if (K > MAXSUMD) return 0;

	ll tot = solve(B, K);
	ll pref = solve(A-1, K);
	return tot - pref;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		ll A, B;
		int K;
		cin >> A >> B >> K;
		cout << "Case " << i << ": " << solve(A, B, K) << '\n';
	}
}

// AC, digit dynamic programming
