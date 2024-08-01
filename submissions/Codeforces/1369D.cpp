#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1'000'000'007;
const int MAXN = 2'000'000;
ll DP[MAXN+1];

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int n = 3; n <= MAXN; n++) {
		DP[n] = (DP[n-2]*2 + DP[n-1] + (n%3==0)*4) % MOD;
	}

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin>> N;

		cout << DP[N] << '\n';
	}
}


// AC, math, trees
