#include <bits/stdc++.h>
using namespace std;

using ll = int;
using vll = vector<ll>;
const ll MAXN = 70;
vll list_primes(ll n = MAXN) {
  vll ps;
  bitset<MAXN + 1> sieve;
  sieve.set();
  sieve.reset(1);
  for (ll i = 2; i <= n; ++i) {
    if (sieve[i]) ps.push_back(i);
    for (ll j = i * 2; j <= n; j += i) {
      sieve.reset(j);
    }
  }
  return ps;
}

vector<ll> primes;
const ll mod = 1'000'000'000 + 7;
const int maxb = 19;
using T = bitset<maxb>;

vector<vector<ll>> ways(70 + 1, vector<ll>(2));
vector<vector<ll>> dp(70 + 1, vector<ll>(1<<maxb));

auto run() {
	int n;
	cin >> n;

	vector<int> xs(n);
	for (int i = 0; i <= 70; i++) ways[i][0] = 1;

	for (auto &xi : xs) {
		cin >> xi;

		ll tmp = ways[xi][0];
		ways[xi][0] = (ways[xi][1] + ways[xi][0]) % mod;
		ways[xi][1] = (ways[xi][1] + tmp) % mod;
	}

	vector<ll> masks(70+1);
	for (int j = 1; j <= 70; j++) {
		T mask;	
		int tj = j;
		for (int i = 0; i < maxb; i++) {
			while(tj % primes[i] == 0) {
				mask[i] = !mask[i];
				tj /= primes[i];
			}

		}
		masks[j] = mask.to_ullong();

	}

	dp[0][0] = 1;
	for (int i = 1; i <= 70; i++) {
		for (int msk = 0; msk < (1<<maxb); msk++) {
			dp[i][msk] = 	(	((1ll*dp[i-1][msk]*ways[i][0]) % mod) + 
						((1ll*dp[i-1][msk^masks[i]]*ways[i][1])%mod) ) % mod;
		}
	}

	cout << (dp[70][0] - 1 + mod) % mod << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	primes = list_primes();

	run();
}

// AC, math, combinatorics, dp
