#include <bits/stdc++.h>
using namespace std;

using ll = long long;
auto run() {
	ll h;
	cin >> h;

	int ans =  0;
	for (int i = 0; h >=  0; i++) {
		ans = i+1;
		h -= (1ll<<i);
	}
	cout << ans << '\n';

}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}

// AC, ad-hoc
