#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i < 5; i++) {
		if (c[i] != a[i] and c[i] != b[i]) {
			cout << "Orra meu...\n";
			return 0;
		}
	}
	cout << "Herdou!\n";
}

// AC, ad-hoc
