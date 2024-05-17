#include <bits/stdc++.h>
using namespace std;

auto run() {
	int n ,k;

	cin >> n >> k;

	int c = 0;
	for (int i = 0; i < n; i++) {
		cout << (char)('a'+c);
		c = (c+1) % k;
	}
	cout << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;

	while (tt--) {
		run();
	}
}

// AC, ad-hoc
