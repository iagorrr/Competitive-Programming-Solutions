#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1'000'000'000 + 7;

ll sum(ll a, ll b) {
	return (a + b) % MOD;
}

ll mul(ll a, ll b) {
	return (a * b) % MOD;
}

const int MAXN  = 1'000'000;
ll memo[MAXN+1][26+1];
int N;

ll solve(int n, int k) {
	if (k > 26) return 0;
	if (n == 0) return 1;

	auto &ret = memo[n][k];
	if (~ret) return ret;


	return ret = sum(mul(k,solve(n-1, k)), solve(n-1, k+1));
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(0));
	memset(memo, -1, sizeof memo);

	cin >> N;

	cout << solve(N, 0) << '\n';
}
