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

  cin >> T;

  rep(t, 0, T) {
    dbg(t);
    run();
  }
}

void run() {
	int N;
	cin >> N;
	
	vi XS(N);
	for (auto &xi : XS)
		cin >> xi;

	if (N == 1) {
		cout << 0 << endl;
		return;
	}

	if (N == 2) {
		cout << (XS.back() == XS.front()) << endl;
		return;
	}




	vi2d memo(N, vi(2, -1));
	function<int(int,int)> solve = 
		[&](int i, bool j) {
			if (i == 0) return 0;

			auto &ret = memo[i][j];
			if (~ret) return ret;

			int vl = XS[i];
			int vr = XS[N-i-1];
			if (j) swap(vl, vr);

			bool plus = (i + 1 == N - i - 1 and vl == vr);

			i--;
			int pvl = XS[i];
			int pvr = XS[N-i-1];



			ret = solve(i, 0) + (vl == pvl) + (vr == pvr) + plus;
			swap(pvl, pvr);
			ret = min(ret, solve(i, 1) + (vl == pvl) + (vr == pvr)) + plus;

			return ret;
		};

	auto ans = min(solve((N-1)/2, 0), solve((N-1)/2, 1));
	cout << ans << endl;
}


/*8<
>8*/
