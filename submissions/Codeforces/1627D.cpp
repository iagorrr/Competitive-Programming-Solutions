#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1'000'000;
bool have[MAXN + 1];
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int xi;
		cin >> xi;

		have[xi] = 1;
	}

	for (int i = 1; i <= MAXN; i++) {
		int g = -1;
		for (int j = i; j <= MAXN; j += i) {
			if (have[j]) {
				g = g == -1 ? j : gcd(g, j);
			}
			have[g] = 1;
		}
	}

	int ans = -N;
	for (int i = 1; i <= MAXN; i++) {
		ans += have[i];
	}

	cout << ans << '\n';

}

// AC, number theory
