#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll n;
	cin >> n;

	const int MOD = 1'000'000'007;
	int ans = 0;

	ll c = 1;

	while (c <= n) {
		ll k = n/c;

		ll b = n/k;

		__int128 sz = (b-c+1)%MOD;
		__int128 p = ((c*sz)%MOD + ((sz*(sz-1))/(__int128)2) % MOD) % MOD;
		__int128 cans = (p*k) % MOD;

		ans = (ans + cans) % MOD;

		c = b + 1;
	}

	cout << ans << '\n';
}

// AC, math
