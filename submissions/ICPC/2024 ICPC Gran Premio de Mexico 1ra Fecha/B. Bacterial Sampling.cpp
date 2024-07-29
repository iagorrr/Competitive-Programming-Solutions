#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<typename T>
vector<vector<T>> prod(vector<vector<T>> &a,
			vector<vector<T>> &b, const ll mod) {
	int n = a.size();
	vector<vector<T>> c(n, vector<T>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				c[i][j] =
					(
					 c[i][j] +
					 (a[i][k] * b[k][j]) % mod
					 )%mod;
			}
		}
	}
	return c;
}

template<typename T>
vector<vector<T>> fpow(vector<vector<T>> &xs, ll p, ll mod) {
	vector<vector<T>> ans(xs.size(), vector<T>(xs.size()));
	for (int i = 0; i < (int)xs.size(); i++)
		ans[i][i] =  1;

	for (auto b = xs; p; p>>=1, b = prod(b,b,mod))
		if (p & 1)
			ans = prod(ans, b, mod);

	return ans;
}
template<typename T>
ll linear_req(vector<vector<T>> rec, vector<ll> first_k, ll n, ll mod) {
	int k = first_k.size();
	if (n < k) {
		return first_k[n];
	}

	ll n2 = n- k + 1;
	rec = fpow(rec, n2, mod);
	ll ret = 0;
	for (int i = 0; i < k; i++) {
		ret = (ret + (rec.back()[i]*first_k[i]%mod)) % mod;
	}
	return ret;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	const int MAXD = 20;
	vector<vector<ll>> rec(MAXD, vector<ll>(MAXD));
	for (int i = 1+4; i < MAXD; i+=4) {
		rec[0][i] = 3;
	}
	for (int i = 1; i < MAXD; i++) {
		rec[i][i-1] = 1;
	}

	vector<ll> initial(MAXD);
	initial[0] = 1;

	int t;
	cin >> t;


	const ll MOD = 1'000'000'000 + 7;
	while(t--) {
		ll n;
		cin >> n;
		auto rec2 = fpow(rec, n, MOD);

		/*
		for (int i = 0; i < MAXD; i++) {
			for (int j = 0; j < MAXD; j++) {
				cerr << setw(3) << rec2[i][j];
			}
			cerr << '\n';
		}
		cerr << "\n\n\n";
		*/

		ll ans = 0;
		for (int i = 0; i < MAXD; i++) {
			ans = (ans + rec2[i][0]) % MOD;
		}

		cout << ans << '\n';
	}
}

// AC, linear recurrence, math

