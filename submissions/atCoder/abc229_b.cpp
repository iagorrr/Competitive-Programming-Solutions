#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	using ll = long long;
	string a, b;
	cin >> a >> b;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	bool ok = true;
	for (int i = 0; i < (int)min(b.size(), a.size()); i ++) {

		ok &= (a[i] + b[i] - 2*'0' < 10);
	}

	if (ok) {
		cout << "Easy\n";
	}
	else cout << "Hard\n";


}


// AC, ad-hoc
