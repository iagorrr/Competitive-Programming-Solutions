#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1'000'000'000 + 7;

ll sum(ll a, ll b) {
	return (a + b) % MOD;
}

ll mul(ll a, ll b) {
	return (a * b) % MOD;
}

const int MAXN  = 1'000'000;
ll memo[MAXN+1][26+2];

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(0));

	int N;
	cin >> N;

	for (int i = 0; i <= 26; i++)
		memo[0][i] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 26; j++) {
			memo[i][j] = sum(mul(memo[i-1][j],j), memo[i-1][j+1]);
		}
	}

	cout << memo[N][0] << '\n';
}

// DP, combinatorics
