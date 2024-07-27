#include <bits/stdc++.h>
using namespace  std;

void run() {
	int N;
	cin >> N;

	vector<int> XS(N);
	for (auto& xi : XS) {
		cin >> xi;
	}


	unordered_map<int,int> st(N);
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		auto xi = XS[i];
		for (int j = i+1; j < N; j++) {
			auto xj = XS[j];
			ans = ans + st[xi-(xj-xi)];
		}
		st[xi]++;
	}

	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--) {
		run();
	}
}

// AC, ad-hoc
