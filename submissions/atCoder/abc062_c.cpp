#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int h, w;
	cin >> h >> w;

	// case 1
	ll c1 = h % 3 ? w : 0;

	// case 2
	ll c2 = w % 3 ? h : 0;

	// case 3
	ll c3 = numeric_limits<ll>::max();
	for (ll i = 1; i < h; i++) {
		ll a = w * i;
		ll b = (w+1ll)/2ll * (h-i);
		ll c = (w)/2ll * (h-i);
		auto [mn, mx] = minmax({a,b,c});
		c3 = min(c3, mx-mn);
	}

	// case 4
	ll c4 = numeric_limits<ll>::max();
	for (ll i = 1; i < w; i++) {
		ll a = h * i;
		ll b = (h+1ll)/2ll * (w-i);
		ll c = (h)/2ll * (w-i);
		auto [mn, mx] = minmax({a,b,c});
		c4 = min(c4, mx-mn);
	}

	cout << min({c1, c2, c3, c4}) << '\n';
}

// AC, math, geometry, brute force
