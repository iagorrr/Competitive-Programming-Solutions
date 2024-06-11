#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 200;
const ll MOD = 998244353ll;

ll FACT[MAXN*2 + 1];
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


bool GOOD[2*MAXN][2*MAXN];

int N;
ll memo[2*MAXN][2*MAXN];

ll solve(int l, int r) {
	//cerr << "l: " << l << " r: " << r << " gd: " << GOOD[l][r] << '\n';
	if (l > r) return 1;

	if (l + 1 == r) return GOOD[l][r];

	auto &ret = memo[l][r];
	if (ret != -1) return ret;

	
	ll ans = 0;

	if (GOOD[l][r]) {
		ans = solve(l+1, r-1);
	}

	if (GOOD[l][l+1]) {
		ll t = solve(l+2, r);
		t =  (t * (r-l+1ll)/2ll) % MOD;
		ans = (ans + t) % MOD;
	}

	for (int m = l + 3; m + 1 < r; m += 2) {
		if (!GOOD[l][m]) continue;
		ll t1 = solve(l+1, m-1);

		ll t2 = solve(m+1, r);

		ll c =  binommod((r-l+1)/2, (m-l+1)/2);

		ll t = (t2*t1) % MOD;
		t = (t * c) % MOD;

		ans = (ans + t) % MOD;
	}

	return ret = ans;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(memo, -1, sizeof memo);
	precompute();

	cin >> N;

	int m;
	cin >> m;

	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		a--, b--;
		GOOD[a][b] = 1;
	}
	
	ll ans = solve(0, 2*N-1);

	cout << ans << '\n';
}


// AC, dynamic programming, combinatorics
