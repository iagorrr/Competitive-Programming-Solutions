#include <bits/stdc++.h> 
using namespace std;

#define int long long

using ll = int64_t;
 
const int mod = 1'000'000'007;

int fpow(int a, int b, int m) {
	int ret = 1;
	while (b) {
		if (b&1) ret = (ret * (ll)a) % m;
		a = (a*(ll)a) % m;
		b >>= 1;
	}
	return ret;
}

ll powersumlessone(ll x, ll n, ll m) {
	ll num = (fpow(x, n+1, m) - 1 + m) % m;
	ll denom = fpow(x-1, m-2, m);
	ll ret = (num * denom) % m;	
 
	ret--;
	if (ret < 0) ret += m;
 
	return ret;
}
 
 
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	int m;
	cin >> m;
 
	vector<int> ps(m), ks(m);
	for (int i = 0; i < m; i++) {
		cin >> ps[i] >> ks[i];
	}
 
	int nod = 1;
	ll nod2 = 1;
	int nod3 = 1;
	bool done = false;
	for (auto ki : ks) {
		nod = (nod*(ll)(ki+1)) % mod;
		nod3 = (nod3*(ki+1ll)) % (mod-1);

		if (!done and ki&1) ki = (ki+1)/2 - 1, done = 1;
		
		nod2 = (nod2*(ki+1ll)) % (mod-1);
	}
 
	int s = 1;
	for (int i = 0; i < m; i++) {
		auto pi = ps[i];
		auto ki = ks[i];


 
		int prox = s;
		int psum = (powersumlessone(pi, ki, mod)) % mod;
		prox = (prox * psum) % mod;
		s = (s+prox) % mod;
	}

	bool is_sqrt = true;
	int n = 1;
	int sqrtn = 1;
	for (int i = 0; i < m; i++) {
		auto pi = ps[i];
		auto ki = ks[i];
		n = (n * fpow(pi, ki, mod)) % mod;
		sqrtn = (sqrtn * fpow(pi, ki/2, mod)) % mod;
		is_sqrt &= !(ki&1);
	}

	int prod = -1;
	if (!is_sqrt) {
		prod = fpow(n, nod2, mod);
	}
	else {
		prod = fpow(sqrtn, nod3, mod);

	}

	cout << nod << ' ' << s << ' ' << prod << '\n';
}

// AC, math
