#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod = 998244353;
const int maxm = 10;
const int maxn = 10000;


int n, m;
vector<int> xs;
vector<int> fs[maxm];

ll memo[maxn][(1<<10)];

ll solve(int p, int s) {
	if ( p == n ) return 1;

	ll &ret = memo[p][s]; 
	if (ret != -1) return ret;

	ll ans = 0;
	for (int i = 0; i <= 9; i++) {
		if (s & (1<<i)) {
			auto ns = s;

			ns ^= (1<<i);
			for (auto j : fs[i]) ns |= (1<<j);

			ans = (ans + solve(p+1, ns)) % mod;
		}
	}

	ret = ans;
	return ret;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(memo, -1, sizeof memo);

	cin >> m >> n;

	xs.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> xs[i]; xs[i]--;
		fs[xs[i]].push_back(i);
	}

	cout << solve(0, (1<<m)-1) << '\n';;
}
