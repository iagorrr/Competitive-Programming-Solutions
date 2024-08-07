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
#define len(x) (int)x.size()
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
	int N;
	cin >> N;

	vi XS(N);
	for(auto& xi : XS)
		cin >> xi;

	const int MAXXI = 1'00'000'000;
	constexpr int MAXB = log2(MAXXI);

	ll ans = 0;
	rep(b, 0, MAXB + 1) {
		int cnt = 0;
		vi odds(N), evens(N), cs(N);

		rep(i, 0, N) {
			auto xi = XS[i];
			cnt += ((xi & (1<<b)) != 0);
			cs[i] = cnt;
			odds[i] = (i ? odds[i-1] : 0) + (cnt&1);
			evens[i] = (i ? evens[i-1] : 1) + !(cnt&1);
		}
		dbg(b, odds);
		dbg(b,evens);

		rep(i, 0, N) {
			auto ci = cs[i];
			ll inc = (ci&1) ? evens[i] : odds[i];
			dbg(b, i, inc);
			ans = ans + (inc*(1ll<<b));
		}
	}

	cout << ans - accumulate(all(XS), 0ll) << endl;

}

int32_t main() {
#ifndef LOCAL
	fastio;
#endif

	// cin >> T;

	rep(t, 0, T) {
                dbg(t);
		run();
  	}
}


/*
   	1 3 2
	1 2 2
	1 2 1
	7
	2 5 6 5 2 1 7
	0 1 0 1 0 1 1	
	0 1 1 2
	1 0 1 0 1 0 1
	0 1 1 1 0 0 1

	AC, prefix sums, math, bitwise
 */
