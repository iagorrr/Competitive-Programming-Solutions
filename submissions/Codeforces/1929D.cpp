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

  cin >> T;

  rep(t, 0, T) {
    dbg(t);
    run();
  }
}

void run() {
	int n;cin>>n;
	vector<vector<int>> adj(n);
	for(int i=0;i<n-1;i++){
		int u,v;cin>>u>>v,u--,v--;
		adj[u].eb(v);
		adj[v].eb(u);
	}
	const ll mod=998244353;
	vector memo(n,pair<ll,ll>({-1,-1}));
	function<pair<ll,ll>(int,int)> solve=[&](int u,int p){
		auto&[r1,r2]=memo[u];
		if(~r1)return pair<ll,ll>{r1,r2};
		r1=0,r2=0;
		for(int v:adj[u])if(v!=p){
			auto [a1,a2]=solve(v,u);
			r1=(r1+r1*a1)%mod;
			r1=(r1+a1)%mod;
			r2=(r2+a1)%mod;
			r2=(r2+a2)%mod;
		};
		r1=(r1+1)%mod;
		return pair<ll,ll>{r1,r2};
	};
	auto[r1,r2]=solve(0,-1);
	dbg(r1,r2);
	ll ans=(1+r1+r2)%mod;
	cout<<ans<<'\n';
}

/*8<
  we can choose at least (n*(n+1))/2 distinct pairs
  just choose what ever two intersections

  for a set be valid the path between any
  two nodes in the set can't be in the set

  dp(i,j) how many ways can i choose nodes in the subtree
  of i such that i exactly at most j in a 'row'

  AC, trees, combinatorics

>8*/
