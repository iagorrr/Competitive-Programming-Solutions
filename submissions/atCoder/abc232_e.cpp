#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1'000'000;	 
const ll MOD = 998244353;

#define int ll

ll h, w, k;
ll dp[MAXN+20][2][2];
ll X1, X2, Y1, Y2;

ll solve(int ops, bool sl, bool sc) {
	if (ops == 0) return sl and sc;

	auto& ret = dp[ops][sl][sc];
	if (ret != -1) return ret;

	ll p1 = (h-1ll-!sl) % MOD;
	ll c1 = (solve(ops-1, false, sc) * p1) % MOD;
	ll c2 = sl ? 0 : solve(ops-1, true, sc);
	ll p3 = (w-1ll-!sc) % MOD;
	ll c3 = (solve(ops-1, sl, false)*p3)%MOD;
	ll c4 = sc ? 0 : solve(ops-1, sl, true);

	ret = c1;
	ret = (ret + c2)%MOD;
	ret = (ret + c3)%MOD;
	ret = (ret + c4)%MOD;

	return ret % MOD;
}


int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(dp, -1, sizeof dp);

	cin >> h >> w >> k;

	cin >> X1 >> Y1 >> X2 >> Y2;


	cout << solve(k, X1 == X2, Y1 == Y2)%MOD << '\n';
}

// AC, dynamic programming
