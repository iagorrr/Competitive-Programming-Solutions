#include <bits/stdc++.h>
using namespace std;

int j(int n, int k) {
	if (n == 1) return 1;

	if (k <= (n+1)/2) {
		return 2*k <= n ? 2*k : 1;
	}

	int x = j(n/2, k - (n+1)/2);
	if (n & 1) {
		return 1 + 2*x;
	}
	else {
		return 2 * x - 1;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;

	while (q--) {
		int n, k;
		cin >> n >> k;

		cout << j(n, k) << '\n';
	}
}

// AC, math
