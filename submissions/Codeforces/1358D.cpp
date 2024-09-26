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
using Graph = vector<vector<pair<ll, int>>>;
/*8<============~ END TEMPLATE ~============}>8*/

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


int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,x;cin>>n>>x;
	vector<ll>ds(n);for(auto&di:ds)cin>>di;
	for(int i=0;i<n;i++){
		ds.emplace_back(ds[i]);
	}
	auto psum=ds;partial_sum(psum.begin(),psum.end(),begin(psum));
	dbg(psum);
	auto psum2=ds;
	for(auto&di:psum2){
		di=((di)*(di+1))/2ll;
	}
	partial_sum(begin(psum2),end(psum2),begin(psum2));
	dbg(psum2);
	ll ans=0;
	for(ll i=n;i<n*2;i++){ // ends at i
		auto di=ds[i];
		if(di>=x){
			ans=max(ans,x*di-((x*(x-1))/2ll));
			continue;
		}
		ll curX=x;
		ll curAns=0ll;
		ll j=*minCheck(0ll,i,[&](ll m){
			return psum[i]-(m?psum[m-1]:0ll)<=curX;
		});
		curAns+=psum2[i]-(j?psum2[j-1]:0ll);
		curX-=(psum[i]-(j?psum[j-1]:0ll));
		dbg(i,j,curX);
		if(j&&curX){
			j--;
			auto dj=ds[j];
			ll inc=(curX*dj-((curX*(curX-1))/2ll));
			dbg(inc);
			curAns+=inc;
		}
		dbg(i,curAns);
		ans=max(ans,curAns);
	}
	cout<<ans<<'\n';
}

// AC, greddy, binary search
