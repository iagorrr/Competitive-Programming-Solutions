#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using Matrix = vector<vector<ll>>;

const ll mod = 998244353;

ll mul(ll a, ll b) {
	return (a * b) % mod;
}

ll add(ll a, ll b) {
	return (a + b) % mod;
}

ll sub(ll a, ll b) {
	return (a - b + mod + mod) % mod;
}


ll fpow(ll a, ll b) {
	ll ret = 1;
	while (b) {
		if (b&1) ret = mul(ret, a);
		a = mul(a, a);
		b >>= 1;

	}
	return ret;
}

ll _div(ll a, ll b) {
	return mul(a, fpow(b, mod-2));
}

Matrix mul(Matrix a, Matrix b) {
	Matrix ret = { {0, 0}, {0, 0} };

	for (int i = 0; i < 2; i++) 
		for (int j = 0; j < 2; j++) 
			for (int k = 0; k < 2; k++)  {
				ret[i][j] = add(mul(a[i][k], b[k][j]), ret[i][j]);
			}


	return ret;
}

Matrix exp(Matrix a, ll b) {
	Matrix ret = { {1, 0}, {0, 1} };

	while (b) {
		if (b&1) ret = mul(ret, a);
		a = mul(a, a);
		b >>= 1;
	}

	return ret;
}


void solve() {
	ll a, b, n, m, vn, vm;
	cin >> a >> b >> n >> m >> vn >> vm;

	vector<vector<ll>> r0 = { {0, b}, {1, a} };
	auto rm = exp(r0, m);
	auto rn = exp(r0, n);

	ll A = rm[0][0];
	ll B = rm[1][0];

	ll C = rn[0][0];
	ll D = rn[1][0];

	ll f1 = _div ( sub( mul(  vn , A  ) , mul(  C, vm  ) ) , 
			   sub(mul(   A,   D ) , mul(  B, C)) );

	ll f0 = _div(sub(vm, mul(B, f1)), A);


	cout << f0 << ' ' << f1 << endl;



}

signed main() {
	ios_base::sync_with_stdio(!cin.tie(0));
	int t; cin >> t; while(t--) solve();
}
