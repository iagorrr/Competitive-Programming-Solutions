#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 5000;
constexpr int ASZ = 'z'-'a';
int hs[ASZ+1];

const int MAX = 5000+1;
using ll = long long;
vector<ll> fac,finv,inv;
void binom_init() {
    fac.resize(MAX);
    finv.resize(MAX);
    inv.resize(MAX);
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    for(int i=2; i<MAX; i++){
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = MOD-MOD/i*inv[MOD%i]%MOD;
        finv[i] = finv[i-1]*inv[i]%MOD;
    }
}

ll binom(ll n, ll r){
    if(n<r || n<0 || r<0) return 0;
    return fac[n]*finv[r]%MOD*finv[n-r]%MOD;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	binom_init();
	string s; cin >> s; for (auto c : s) hs[c-'a']++;

	vector<vector<int>> dp(s.size()+1, vector<int>(ASZ+1));
	for (int j = 0; j <= ASZ; j++)
		dp[0][j] = 1;

	for (int i = 1; i <= s.size(); i++) {
		dp[i][0] = hs[0] >= i;
	}

	int ans = 0;
	for (int i = 1;  i <= (int)s.size(); i++) {
		for (int j = 1; j <= ASZ; j++) {
			auto& cur = dp[i][j];
			for (int k = 0; k <= min(i, hs[j]); k++) {
				int p = ((long long)dp[i-k][j-1] * binom(i,k)) % MOD;
				cur = (cur + p);
				if (cur >= MOD) cur -= MOD;

			}
		}
		ans = (ans+dp[i]['z'-'a']);
		if (ans >= MOD) ans -= MOD;
	}

	cout << ans << '\n';
}


// AC, dynamic programming, strings, combinatorics
