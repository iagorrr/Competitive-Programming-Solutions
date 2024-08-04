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

	vector<int> AS(N);
	for (auto& ai : AS)
		cin >> ai;
	

	multiset<int> odds, evens;
	for (auto ai : AS) {
		if (ai&1) {
			odds.emplace(ai);
		}
		else {
			evens.emplace(ai);
		}
	}

	int ans = 0;

	while (!evens.empty() and !odds.empty()) {
		auto mn_even = *evens.begin();
		auto mx_even = *evens.rbegin();

		auto mx_odd = *odds.rbegin();

		int a = mx_odd+mn_even;

		if (mx_odd > mn_even) {
			evens.erase(evens.begin());
			odds.emplace(a);
		}
		else {
			odds.extract(mx_odd);
			odds.emplace(mx_odd+mx_even);
		}

		ans++;
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

// AC, constructive algorithms, greddy
