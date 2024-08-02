#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

auto run()  {
	int N;
	cin >> N;

	vector<ll> XS(N);
	for (auto &xi : XS)
		cin >> xi;

	bool non_one = false;
	int fnotone = -1;
	for (int i = 0; i < N; i++) {
		non_one |= (XS[i] != 1);
		if (non_one and fnotone == -1)
			fnotone =  i;
		if (non_one and XS[i] == 1) {
			cout << -1 << '\n';
			return;
		}
	}

	if (fnotone == -1)  {
		cout << 0 << '\n';
		return;
	}


	vector<ld> ys(N);
	for (int i = 0; i < N; i++)  {
		ys[i] = log(log(XS[i]));
	}

	const ld eps = 1e-9;

	ll ans = 0;
	for (int i = fnotone+1; i < N; i++) {
		ld need = ys[i-1] - ys[i];
		if (need > eps) {
			ll cnt = 1 + ((need-eps)/log(2));
			ans += cnt;
			ys[i] += cnt * log(2);
		}
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

// AC, contructive algorithms, math
