/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define fastio                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
#define all(j) j.begin(), j.end()
#define rall(j) j.rbegin(), j.rend()
#define len(j) (int)j.size()
#define rep(i, a, b) \
  for (common_type_t<decltype(a), decltype(b)> i = (a); i < (b); i++)
#define rrep(i, a, b) \
  for (common_type_t<decltype(a), decltype(b)> i = (a); i > (b); i--)
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) for (auto &xi : ranges::views::reverse(xs))
using ll = long long;
#define inte ll
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define emp emplace
#define ins insert
#define divc(a, b) ((a) + (b)-1ll) / (b)
using str = string;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vc = vector<char>;
using vs = vector<str>;
template <typename T, typename T2>
using umap = unordered_map<T, T2>;
template <typename T>
using pqmn = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using pqmx = priority_queue<T, vector<T>>;
template <typename T, typename U>
inline bool chmax(T &a, U const &b) {
  return (a < b ? a = b, 1 : 0);
}
template <typename T, typename U>
inline bool chmin(T &a, U const &b) {
  return (a > b ? a = b, 1 : 0);
}
/*8<============~ END TEMPLATE ~============}>8*/
void run();

int32_t main() {
#ifndef LOCAL
  fastio;
#endif

  int T = 1;

  // cin >> T;

  rep(t, 0, T) {
    dbg(t);
    run();
  }
}

void run() {
	int N, K;
	cin >> N >> K;
	vi2d ADJ(N);
	rep(i, 0, N-1) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		ADJ[u].eb(v);
		ADJ[v].eb(u);
	}

	vector dp(N, vll(K+1));
	ll ans = 0;

	function<void(int ,int)> dfs = [&](int u, int p = -1) -> void{
		dp[u][0] = 1;

		for (int v : ADJ[u]) {
			if (v != p) {
				dfs(v, u);
				rep(i, 0, K) {
					dp[u][i+1] += dp[v][i];
				}
			}
		}

		auto tmp = dp[u];

		ll cur = 0;
		for (int v : ADJ[u]) {
			if (v != p) {
				rep(i, 0, K) {
					tmp[i+1] -= dp[v][i];
				}

				rep(i, 0, K) {
					cur += (tmp[i] * dp[v][K-i-1]);
				}
			}
		}

		dbg(u, cur);

		ans += cur;
	};


	dfs(0, -1);

	dbg(dp);

	cout << ans << endl;
}

/*8<
  AC, trees, dfs and similar, dynamic programming
>8*/
