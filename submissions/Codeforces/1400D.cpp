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

	vi AS(N);
	for(auto& ai : AS) {
		cin >> ai;
		ai--;
	}

	ll ans = 0;
	for (int i = 0; i + 3 < N; i++) {
		auto ai = AS[i];

		vi hist_left(N), hist_right(N);
		for (int k = i + 1; k < N; k++) {
			auto ak = AS[k];
			hist_right[ak]++;
		}

		ll cur = 0;
		for (int k = i + 1; k + 1< N; k++) {
			auto ak = AS[k];

			cur = cur - hist_left[ak] * hist_right[ak];

			hist_right[ak]--;
			cur = cur + hist_left[ak] * hist_right[ak];

			if (ak == ai) ans += cur;

			cur = cur - hist_left[ak] * hist_right[ak];

			hist_left[ak]++;
			cur = cur + hist_left[ak] * hist_right[ak];
		}
	}

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
	AC, brute force, two pointers
 */
