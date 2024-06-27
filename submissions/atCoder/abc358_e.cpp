#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 998244353;
const ll MAXN = 1'000;
ll FACT[MAXN + 1];
void precompute() {
#warning Remember to call precompute before use binommod !
  FACT[0] = 1;
  for (ll i = 1; i <= MAXN; i++) {
    FACT[i] = (FACT[i - 1] * i) % MOD;
  }
}

ll fpow(ll a, ll k) {
  ll ret = 1;
  while (k) {
    if (k & 1) ret = (ret * a) % MOD;
    a = (a * a) % MOD;
    k >>= 1;
  }
  return ret;
}

ll binommod(ll n, ll k) {
  ll upper = FACT[n];
  ll lower = (FACT[k] * FACT[n - k]) % MOD;
  return (upper * fpow(lower, MOD - 2ll)) % MOD;
}

ll sum(ll a, ll b) {
	return (a+b)%MOD;
}
ll mul(ll a, ll b) {
	return (a*b)%MOD;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	precompute();

	int k;
	cin >> k;

	vector<int> cs(26);
	for (auto& ci : cs)
		cin >> ci;

	vector<vector<ll>> memo(k+1, vector<ll>(26, -1));
	auto solve = [&](auto &&self, int sz, int mxc) -> int {
		if (sz == 0) return 1;
		if (sz < 0 or mxc < 0) return 0;

		auto& ans = memo[sz][mxc];
		if (ans != -1) return ans;

		ans = 0;
		for (int i = 0; i <= min(cs[mxc], sz); i++) {
			ans = sum(ans, mul(binommod(sz, i), self(self, sz-i, mxc-1)));
		}

		return ans;
	};

	ll ans = 0;

	for (int i = 1; i <= k; i++)
		ans = sum(ans, solve(solve, i, 25));

	cout << ans << '\n';
}

// AC, dynamic programming, combinatorics
