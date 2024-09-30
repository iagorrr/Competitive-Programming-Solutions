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

int solve(vector<int>&box_pos,vector<int>&esp_pos){
	sort(rall(box_pos)),sort(all(esp_pos));
	dbg(box_pos);
	dbg(esp_pos);
	set<int>boxSet(all(box_pos));
	vi match(len(esp_pos)+1);
	rrep(i,len(esp_pos)-1,0-1){
		auto ei=esp_pos[i];
		match[i]=match[i+1];
		if(boxSet.count(ei)){
			match[i]++;
		}
	}
	dbg(match);
	int ans=match[0];
	int totBox=0;
	for(int i=0;i<len(esp_pos);i++){
		auto ei=esp_pos[i];
		while(len(box_pos)&&box_pos.back()<=ei+totBox-1){
			totBox++;
			box_pos.ppb();
		}
		if(!totBox)continue;
		int r=*maxCheck(i,len(esp_pos)-1,[&](int m){
				return ei + totBox - 1 >=  esp_pos[m];
				});
		int cur=r-i+1+match[r+1];
		chmax(ans,cur);
	}

	dbg(ans);
	return ans;
}

void run() {
	int n,m;cin>>n>>m;
	vector<int>xs(n);trav(xi,xs)cin>>xi;
	vector<int>ys(m);trav(yi,ys)cin>>yi;
	int ans=0;
	{
		vector<int>a,b;
		trav(xi,xs)if(xi<0)a.eb(-xi);
		trav(yi,ys)if(yi<0)b.eb(-yi);
		ans+=solve(a,b);
	}	
	{
		vector<int>a,b;
		trav(xi,xs)if(xi>0)a.eb(xi);
		trav(yi,ys)if(yi>0)b.eb(yi);
		ans+=solve(a,b);
	}	
	cout<<ans<<endl;
}

/*8<
  AC, implementation
>8*/
