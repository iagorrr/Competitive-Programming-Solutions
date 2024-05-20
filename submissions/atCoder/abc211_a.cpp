#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

auto run() {
	ld a, b;	
	cin >> a >> b;

	cout <<fixed << setprecision(10)<< (a-b)/(ld)3 + b << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}

// AC, ad-hoc
