#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--) {
		int n;
		cin >> n;

		int x;
		cin >> x;

		int xorsum = 0;
		for (int i = 1; i < n; i++) {
			cin >> x;
			if ((i & 1) and x)
				xorsum ^= x;
		}

		if (xorsum) cout << "first\n";
		else cout << "second\n";
	}
}

// AC, math, game theory
