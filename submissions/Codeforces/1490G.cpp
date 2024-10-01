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
using Graph = vector<vector<pair<ll, int>>>;
/*8<============~ END TEMPLATE ~============}>8*/
using ll = long long;
/*8<
  @Title: Max \& Min Check

  @Description: Returns the min/max value in range
  [l, r] that satisfies the lambda function check,
  if there is no such value the 'nullopt' is
  returned.

  @Usage: check must be a function that receives
  an integer and return a boolean.

  @Time: $O(\log{r-l+1})$
>8*/
template <typename T>
optional<T> maxCheck(T l, T r, auto check) {
  optional<T> ret;
  while (l <= r) {
    T m = midpoint(l, r);
    if (check(m))
      ret ? chmax(ret, m) : ret = m, l = m + 1;
    else
      r = m - 1;
  }
  return ret;
}

template <typename T>
optional<T> minCheck(T l, T r, auto check) {
  optional<T> ret;
  while (l <= r) {
    T m = midpoint(l, r);
    if (check(m))
      ret ? chmin(ret, m) : ret = m, r = m - 1;
    else
      l = m + 1;
  }
  return ret;
}
template <typename T1, typename T2>
constexpr typename std::common_type<T1, T2>::type floor_div(T1 x, T2 y) {
  assert(y != 0);
  if (y < 0) x = -x, y = -y;
  return x < 0 ? (x - y + 1) / y : x / y;
}

void run(){
	int n,q;cin>>n>>q;
	vector<ll>xs(n);for(auto&xi:xs)cin>>xi;
	vector<ll>ps(xs.begin(),xs.end());
	partial_sum(ps.begin(),ps.end(),ps.begin());
	vector<ll>psmx(n);
	psmx[0]=ps[0];
	for(int i=1;i<n;i++){
		psmx[i]=max(ps[i],psmx[i-1]);
	}
	ll ts=accumulate(xs.begin(),xs.end(),0ll);
	ll mx=*max_element(ps.begin(),ps.end());
	for(int i=0;i<q;i++){
		int x;cin>>x;
		if(x>mx&&ts<=0){
			cout<<-1<<' ';
			continue;
		}
		if(x<=mx){
			auto ans=minCheck(0,n-1,[&](int m){
					return psmx[m]>=x;
					});
			cout<<ans.value_or(-1)<<' ';
			continue;
		}
		ll r=(x-mx+ts-1)/ts;
		x-=(ts*r);
		ll ans=*minCheck(0,n-1,[&](int m){
				return psmx[m]>=x;
				});
		ans+=((r*n)-1)+1;
		cout<<ans<<' ';
	}
	cout<<'\n';
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;cin>>t;
	while(t--){
		run();
	}
}

// AC, greedy, binary search
