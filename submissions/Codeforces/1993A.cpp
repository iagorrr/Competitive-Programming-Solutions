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
	int N;
	cin >> N;

	string S;
	cin >> S;

	int a, b, c, d;
	a = b = c = d = N;

	int ans = 0;
	for (auto& si : S)  {
		si = tolower(si);

		if (si == 'a' and a) {
			a--;
			ans++;
		}

		if (si == 'b' and b) {
			b--;
			ans++;
		}

		if (si == 'c' and c) {
			c--;
			ans++;
		}

		if (si == 'd' and d) {
			d--;
			ans++;
		}
	}

	cout << ans << '\n';

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
   AC, implementation
 */
