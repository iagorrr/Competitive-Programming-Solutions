#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	if (a == b) {
		cout << a << '\n';
	}
	else {
		cout << max(a, b) << '\n';
	}
}

// AC, ad-hoc
