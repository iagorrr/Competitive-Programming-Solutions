#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int anyodd=0;
		while(n--) {
			int x;
			cin >> x;
			anyodd |= (x&1);
		}

		if (anyodd) cout << "first\n";
		else cout << "second\n";
	}
}

// AC, game theory
