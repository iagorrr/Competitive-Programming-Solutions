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
	int k,n;cin>>n>>k;
	vi marked(n);
	rep(i,0,k){
		int xi;cin>>xi;xi--;
		marked[xi]=1;
	}
	vi2d adj(n);
	rep(i,0,n-1){
		int u,v;cin>>u>>v;u--,v--;
		adj[u].eb(v);
		adj[v].eb(u);
	}
	vi dleaf(n,2*n),ds(n);
	function<void(int,int)> dfs1=[&](int u,int p){
		for(auto v:adj[u])if(v!=p){
			ds[v]=ds[u]+1;
			dfs1(v,u);
			dleaf[u]=min(dleaf[v]+1,dleaf[u]);
		}
		if(marked[u])dleaf[u]=0;
	};
	dfs1(0,-1);
	bool rl=0;
	int rm=0;
	function<void(int,int)> dfs=[&](int u,int p){
		if(dleaf[u]<=ds[u]){
			rm++;
			return;
		}
		if(len(adj[u])==1&&u)rl|=1;
		for(auto v:adj[u])if(v!=p){
			dfs(v,u);
		}
	};
	dfs(0,-1);
	cout<<(rl?-1:rm)<<endl;
}

/*8<
  AC, trees, greedy
>8*/
