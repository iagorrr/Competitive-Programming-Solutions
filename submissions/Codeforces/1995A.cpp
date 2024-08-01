#include <bits/stdc++.h>
using namespace std;

auto run() {
	int N; int K;
	cin >> N;
	cin >> K;

	map<int,int> ds;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ds[i+j]++;
		}
	}

	vector<int> xs;
	for (auto [a, b] : ds) {
		xs.push_back(b);
	}

	sort(xs.rbegin(), xs.rend());

	int ans = 0;
	for (int i = 0; i < xs.size() and K > 0; i++) {
		K -=  xs[i];
		ans++;
	}

	cout << ans << '\n';

}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		run();
	}

}

// AC, ad-hoc
