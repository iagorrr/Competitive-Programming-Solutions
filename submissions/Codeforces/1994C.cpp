#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define endl '\n'

#define fastio                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);

#define int long long

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define rep(i, a, b) for (common_type_t<decltype(a), decltype(b)> i = a; i != b; (a < b) ? ++i : --i)
#define sz(x) (int)x.size()
#define pb push_back
#define eb emplace_back 

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;

int T = 1;

auto run() {
	int N, X;
	cin >> N >> X;

	vector<int> XS(N);
	for (auto& xi : XS)
		cin >> xi;

	vector<ll> psum(N);
	psum[0] = XS[0];
	rep(i, 1, N)
		psum[i] = psum[i-1] + XS[i];

	vector<ll> dp(N+1);
	rep(i, N-1, 0-1) {
		int j = N*2; 

		ll dec = (i ? psum[i-1] : 0);
		for (int l = i, r = N-1; l <= r; ) {
			int mid = midpoint(l, r);
			if (psum[mid]-dec > X) {
				j = min(j, mid);
				r =  mid - 1;
			}
			else l = mid + 1;
		}

		dbg(i, j);
		dp[i] = (j == N*2 ? N-i : j-i + dp[j+1]);
	}
	dbg(dp);

	ll ans = accumulate(all(dp), 0ll);
	cout << ans << endl;
}

int32_t main() {
#ifndef LOCAL
	fastio;
#endif

	cin >> T;

	rep(t, 0, T) {
                dbg(t);
		run();
  	}
}


/*
	
   AC, dynamicp programming, binary search
 */

