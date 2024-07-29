#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll l1, w1, h1;
	cin >> l1 >> w1 >> h1;

	vector<ll> ds(3);
	for (auto& di : ds) cin >> di;

	ll ans = 0;

	sort(ds.begin(), ds.end());

	do {
		ll l = l1 / ds[0];
		ll w = w1 / ds[1];
		ll h = h1 / ds[2];
		ans = max(ans, l * w * h);
	}while(next_permutation(ds.begin(), ds.end()));

	cout << ans << '\n';

}

// AC, brute force, math
