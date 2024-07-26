#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
vector<vll> dist;
vector<vll> memo;
/* O ( N^2 * 2^N )*/
int tsp(int i, int mask, int N) {
  if (mask == (1 << N) - 1) return dist[i][0];
  if (memo[i][mask] != -1) return memo[i][mask];
  ll ans = 1e9;
  for (int j = 0; j < N; ++j) {
    if (mask & (1 << j)) continue;
    auto t = tsp(j, mask | (1 << j), N) + dist[i][j];
    ans = min(ans, t);
  }
  return memo[i][mask] = ans;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	using T =  array<int, 3>;
	vector<T> XS(N);
	for (auto& [a, b, c] : XS)
		cin >> a >> b >> c;

	auto ds = [&](int i, int j) -> ll {
		auto [a, b, c] = XS[i];
		auto [p, q, r] = XS[j];

		return abs(a-p) + abs(q-b) + max(0,r-c);
	};

	dist = vector<vector<ll>>(N, vector<ll>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {
				dist[i][j] = ds(i, j);
			}
		}
	}


	const ll oo = 1e14;
	memo = vector<vector<ll>>(N, vector<ll>(1<<N, -1));
	cout << tsp(0, 1, N) << '\n';
}

// AC, graphs, dymic programming, tsp
