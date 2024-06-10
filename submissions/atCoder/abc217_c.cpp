#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> xs(n+1);
	for (int i = 1; i <= n; i++) cin >> xs[i];

	vector<int> ans(n+1);
	for (int i = 1; i <= n; i++) {
		ans[xs[i]] = i;
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " \n"[i==n];
	}
}

// AC, ad-hoc

