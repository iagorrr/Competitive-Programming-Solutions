#include <bits/stdc++.h>
using namespace std;

using ll = long long;

auto run()  {
	int N;
	cin >> N;

	vector<ll> XS(N);
	for (auto &xi : XS)
		cin >> xi;

	bool non_one = false;
	for (int i =0; i < N; i++) {
		non_one |= (XS[i] != 1);
		if (non_one and XS[i] == 1) {
			cout << -1 << '\n';
			return;
		}
	}

	vector<ll> ops(N);
	for (int i = 1; i < N; i++) {
		ll a = XS[i-1], b = XS[i];
		if (a > b)
			for (; a > b; b*=b, ops[i]++);
		else if (a  != 1)
			for (; a <= b; a*=a, ops[i]-- );
	}


	ll ans = 0;
	for (int i = 1; i < N; i++) {
		if (ops[i] < 0) { 
			if (ops[i-1] >= abs(ops[i]))
				ops[i] = ops[i-1] - abs(ops[i]) + 1;
			else ops[i] = 0;
		}
		else {
			ops[i] = ops[i] + ops[i-1];
		}
		ans += ops[i];
	}

	cout << ans << '\n';

}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	
	for (int t = 1; t <= T; t++) {
		run();
	}
}

// AC, contructive algorithms
