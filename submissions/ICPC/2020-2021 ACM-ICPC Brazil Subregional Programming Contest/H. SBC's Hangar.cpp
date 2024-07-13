#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> xs;
int n, k;

using ll = long long;
const int MAXN_BINOM = 50;
static ll binom[MAXN_BINOM+1][MAXN_BINOM+1];
void precomp() {
	binom[0][0] = 1;
	for (int i = 1; i <= MAXN_BINOM; i++) {
		binom[i][0] = 1;
		for (int j = 1; j <= MAXN_BINOM; j++) {
			binom[i][j] = binom[i-1][j-1] + binom[i-1][j];
		}
	}
}

ll solve(int i, int j, ll c, const ll w) {
	if (j == 0) return 1;
	if (i == n) return 0;

	ll ret = 0;

	if (c + xs[i] <= w) {
		ret += solve(i+1, j-1, c + xs[i], w);
		ret += binom[n-i-1][j];
	}
	else ret += solve(i+1, j, c, w);

	return ret;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	precomp();

	cin >> n >> k;

	xs.resize(n);
	for (auto& xi : xs)
		cin >> xi;

	ll l, r;
	cin >> l >> r;

	sort(xs.rbegin(), xs.rend());


	ll b = solve(0, k, 0, l-1);
	ll a = solve(0, k, 0, r);

	cout << a - b << '\n';
}
