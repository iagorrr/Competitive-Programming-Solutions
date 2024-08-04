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

        vector<pii> AS;
	rep(i, 1, N+1) {
		int vi;
		cin >> vi;
		AS.eb(i, vi);
	}


	vector<pii> ans(N-1);

	rep(i, N-1, 1-1) {
		vi occ(i, -1);
		rep(j, 0, sz(AS)) {
			auto [u, au] = AS[j];
			if (occ[au%i] != -1) {
				auto [v, _] = AS[occ[au%i]];
				ans[i-1] = {u, v};
				swap(AS[occ[au%i]], AS.back());
				AS.pop_back();
				break;
			}
			occ[au%i] = j;
		}
	}

	cout << "YES\n";
	for (auto &[a, b] : ans)
		cout << a << ' ' << b << '\n';
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

// AC, number theory

