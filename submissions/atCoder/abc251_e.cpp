
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 3'00'000;
const int OO = 1e16;
int dp[MAXN][2];
int xs[MAXN];

bool done0 = false;
int solve(int i, bool need) {
	if (i == 0) {
		if (need) {
			return xs[0];
		}
		else {
			return done0 ? 0 : xs[i];
		}
	}

	auto& ret = dp[i][need];
	if (ret != -1) return ret;

	if (need) {
		ret = solve(i-1, false) + xs[i];
	}
	else {
		ret = min( 
			solve(i-1, true),
			solve(i-1, false) + xs[i]
		 );
	}
	
	return ret;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(dp, -1, sizeof dp);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> xs[i];

	int ans = OO;
	ans = solve(n-1,0);
	done0 = 1;
	memset(dp, -1, sizeof dp);
	ans = min(ans, solve(n-1, 1));

	cout << ans << '\n';
}


// AC, dynamic programming, dp
