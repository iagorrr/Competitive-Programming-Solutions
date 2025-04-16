#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXB = 31;
bool is_odd(ll n, ll i) {
	return !(i & (n-i));
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;

	while(t--) {
		ll n , k;
		cin >> n >> k;

		n--;
		for (int i = 0; i <= n; i++) {
			cout << (is_odd(n,i)) * k << " \n"[i==n];
		}
	}
}

/*
 * se reduz a saber se o elemento é par ou ímpar no triangulo de pascal
 * posso fazer combinatória mod 2 ?
 * */

