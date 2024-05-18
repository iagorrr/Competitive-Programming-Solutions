#include <bits/stdc++.h>
using namespace std;

using ll = long long;
auto run() {
	int n;
	cin >> n;

	ll s = 0;
	vector<string> xs(n);
	for (int i= 0 ; i < n; i++) {
		cin >> xs[i];
		ll r;
		cin >> r;
		s += r;
	}

	sort(xs.begin(), xs.end());
	cout << xs[s % n] << '\n';

}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}

// AC, ad-hoc
