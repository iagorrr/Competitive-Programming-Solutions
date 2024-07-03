#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	if (m == 0) {
		for (int i = 1; i <= n; i++) {
			cout << i*2 << ' ' << i *2 + 1 << '\n';
		}
		return 0;
	}

	if (m < 0 or m == n or m + 1 == n) {
		cout << -1 << '\n';
		return 0;
	}

	using pii = pair<int,int>;
	vector<pii> ans;
	int pr = 1;
	int r = 1 + (m+1)*2 + 1;
	cout << 1 << ' ' <<  r << '\n';
	for (int i = 1; i < n; i++) {
		int a =  pr + 1;
		if (a == r) a++;
		int b = a + 1;

		cout << a << ' ' << b << '\n';

		pr = b;
	}
}

// AC, contructive algorithms, greddy
