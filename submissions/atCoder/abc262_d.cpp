#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

inline int sum(int a, int b) {
	return (a + b) % mod;
}

const int maxn = 100;
int memo[maxn+1][maxn][maxn];

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> xs(n);
	for (auto &xi : xs) cin >> xi;

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		memset(memo, 0, sizeof memo);

		for (int j = 0; j <= n-1; j++)
			memo[0][0][j] = 1;

		for (int j = 1; j <= i; j++) {
			for (int k = 0; k <= n-1; k++) {
				for (int m = 0; m < i; m++) {
					auto& cur =	memo[j][m][k];
					auto p1 =	k ? memo[j][m][k-1] : 0;
					int nm = ((m-(xs[k]%i))+i)%i;
					auto p2 = 	k ? memo[j-1][nm][k-1] : j == 1 and nm == 0;
					cur = sum(p1, p2);
				}
			}
		}

		ans = sum(ans, memo[i][0][n-1]);
	}

	cout << ans << '\n';	
}

// AC, dynamic programming, math
