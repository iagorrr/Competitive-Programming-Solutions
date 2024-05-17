#include <bits/stdc++.h>
using namespace std;

using ll = long long;
auto run() {

	int n;
	cin >> n;

	vector<ll> xs(n);
	for(auto &xi :xs){
		cin >> xi;
	}

	//ll h = 1e9 + 100;
	ll h = *max_element(xs.begin(), xs.end());
	ll black = ((n+1)/2)*((h+1)/2) + (n/2)*(h/2);
	ll white = ((n+1)/2)*(h/2) + (n/2)*((h+1)/2);

	//cerr << "black: " << black << " white: " << white << '\n';

	for (int i = 0; i < n; i++) {
		auto xi = xs[i];
		if (i & 1) { // white
			white -= (xi+1)/2;
			black -= (xi)/2;
		}
		else { // black
			black -= (xi+1)/2;
			white -= (xi)/2;
		}
	}
	
	//cerr << "black: " << black << " white: " << white << '\n';
	if (black == white) {
		cout << "YES\n";
		return;
	}

	if (h&1) {
		white += (n+1)/2;
		black += n/2;
	}

	if (black == white) {
		cout << "YES\n";
		return;
	}

	for (ll i = 0; i <= 1e4; i++) {
		if (i&1) {
			white += (n+1)/2;
			black += n/2;
		}
		else {
			black += (n+1)/2;
			white += n/2;
		}

		if (black == white) {
			cout << "YES\n";
			return;
		}
	}
	
	cout << "NO\n";
}


int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	// cin >> tt;

	while (tt--) {
		run();
	}
}

// AC, combinatorics, math
