#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 500;
const int oo = 1'000'000'000;
int dp[MAXN][MAXN][MAXN+1];

int solve(int l, int r, int k, const string &S) {
	if (k == 0) return 0;

	if (l == r) {
		return k > 1? oo : 0;
	}

	if (l > r) return oo;

	auto& ret = dp[l][r][k];
	if (~ret) return ret;

	ret = oo;
	ret = min(ret, (S[l] != S[r]) + solve(l+1, r-1, k-2, S));
	ret = min(ret, solve(l+1, r, k, S));
	ret = min(ret, solve(l, r-1, k, S));

	return ret;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(dp, -1, sizeof dp);

	int N, K;
	cin >> N >> K;

	string S;
	cin >> S;

	cout << solve(0, N-1, K, S) << '\n';
}

// AC, strings, dynamic programming
