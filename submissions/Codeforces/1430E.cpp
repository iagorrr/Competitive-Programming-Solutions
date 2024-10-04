/*8<{==========~ BEGIN TEMPLATE ~============>8*/
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

  //cin >> T;

  rep(t, 0, T) {
    dbg(t);
    run();
  }
}
/*8<
	@Title:
		Count inversions

	@Description: 
		Count the number of inversions when transforming the vector $l$ in the
		vector $r$, which is also equivalent to the mininum number of swaps
		required.

	@Usage:
		If no $r$ vector is provided it considers r as the sorted vector, if
		there is no such way to turn $l$ into $r$ using swaps then $-1$ is
		returned

	@Time:
		$O(N\log{N})$

	@Problems:
		https://codeforces.com/problemset/problem/1430/E
>8*/
template<typename T>
ll countInversions(vector<T> l, vector<T> r = {}) {
	if (!len(r)) r = l,sort(all(r));
	int n = len(l);
	vi v(n), bit(n);
	vector<pair<T, int>> w;
	rep(i,0,n)
		w.eb(r[i], i+1);
	sort(all(w));
	rep(i,0,n){
		auto it = lower_bound(all(w), make_pair(l[i], 0));
		if (it == w.end() or it->first != l[i])
		   	return -1; // nao da
		v[i] = it->second;
		it->second = -1;
	}
	ll ans = 0;
	rrep(i,n-1,0-1){
		for (int j = v[i]-1; j; j -= j&-j)
		   	ans += bit[j];
		for (int j = v[i]; j < n; j += j&-j)
		   	bit[j]++;
	}
	return ans;
}

void run() {
	int n;cin>>n;
	string s;cin>>s;
	string rs=s;reverse(all(s));
	vi vs,vrs;
	rep(i,0,n)vs.eb(s[i]),vrs.eb(rs[i]);
	cout<<countInversions(vs,vrs)<<endl;
}

/*8<
  AC, strings, greedy
>8*/
