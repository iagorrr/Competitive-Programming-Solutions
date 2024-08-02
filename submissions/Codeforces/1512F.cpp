#include <bits/stdc++.h>
using namespace std;

using ll = long long;

auto run() {
	int N;
	ll C;
	cin >> N >> C;

	vector<ll> AS(N);
	for (auto& ai : AS)
		cin >> ai;

	vector<ll> BS(N-1);
	for (auto& bi : BS)
		cin >> bi;

	ll ans = LLONG_MAX;
	ll curd = 0;
	ll curc = 0;
	for (int i = 0; i < N; i++) {
		auto ai = AS[i];
		auto bi = BS[i];

		// parar aqui
		ans = min(ans, curd + max(C-curc+ai-1, 0ll) / ai);

		if (i + 1 <  N) {
			// pegar o suficiente pra upar e upar ne
			ll ds = max(BS[i]-curc+ai-1,0ll)/ai;
			curc = curc+ds*ai-BS[i];
			curd += ds+1;
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

// AC, greddy
