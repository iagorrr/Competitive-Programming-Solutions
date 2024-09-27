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
using Edge=pair<ll,int>;
using Graph=vector<vector<Edge>>;
template <typename T>
struct SparseTable {
  vector<T> v;
  int n;
  static const int b = 30;
  vi mask, t;

  int op(int x, int y) { return v[x] < v[y] ? x : y; }
  int msb(int x) { return __builtin_clz(1) - __builtin_clz(x); }
  SparseTable() {}
  SparseTable(const vector<T> &v_) : v(v_), n(v.size()), mask(n), t(n) {
    for (int i = 0, at = 0; i < n; mask[i++] = at |= 1) {
      at = (at << 1) & ((1 << b) - 1);
      while (at and op(i, i - msb(at & -at)) == i) at ^= at & -at;
    }
    for (int i = 0; i < n / b; i++)
      t[i] = b * i + b - 1 - msb(mask[b * i + b - 1]);
    for (int j = 1; (1 << j) <= n / b; j++)
      for (int i = 0; i + (1 << j) <= n / b; i++)
        t[n / b * j + i] =
            op(t[n / b * (j - 1) + i], t[n / b * (j - 1) + i + (1 << (j - 1))]);
  }
  int small(int r, int sz = b) { return r - msb(mask[r] & ((1 << sz) - 1)); }
  T query(int l, int r) {
    if (r - l + 1 <= b) return small(r, r - l + 1);
    int ans = op(small(l + b - 1), small(r));
    int x = l / b + 1, y = r / b - 1;
    if (x <= y) {
      int j = msb(y - x + 1);
      ans = op(ans, op(t[n / b * j + x], t[n / b * j + y - (1 << j) + 1]));
    }
    return ans;
  }
};

struct LCA {
  SparseTable<int> st;
  int n;
  vector<int> v, pos, dep;

  LCA(const Graph &g, int root) : n(len(g)), pos(n) {
    dfs(root, 0, -1, g);
    st = SparseTable<int>(vector<int>(all(dep)));
  }

  void dfs(int i, ll d, int p, const Graph &g) {
    v.eb(len(dep)) = i, pos[i] = len(dep), dep.eb(d);
    for (auto [w,j] : g[i])
      if (j != p) {
        dfs(j, d + w, i, g);
        v.eb(len(dep)) = i, dep.eb(d);
      }
  }

  int lca(int a, int b) {
    int l = min(pos[a], pos[b]);
    int r = max(pos[a], pos[b]);
    return v[st.query(l, r)];
  }
  int dist(int a, int b) {
    return dep[pos[a]] + dep[pos[b]] - 2 * dep[pos[lca(a, b)]];
  }
};

struct VTree  {
	int n;
	LCA lca;
	VTree(const Graph&g,int root=0):
		n(len(g)),
		lca(g,root){}
	pair<vector<tuple<ll,int,int>>,int> vtree(vector<int> vs){
		sort(vs.begin(),vs.end(),[&](int u,int v){
				return lca.pos[u]<lca.pos[v];
				});
		for(int i=0,n=size(vs);i+1<n;i++){
			vs.eb(lca.lca(vs[i],vs[i+1]));
		}
		sort(vs.begin(),vs.end(),[&](int u,int v){
				return lca.pos[u]<lca.pos[v];
				});
		vs.erase(unique(all(vs)),vs.end());
		vi st{vs.front()};
		vector<tuple<ll,int,int>>ret;
		for(int i=1;i<len(vs);i++){
			int v=vs[i];
			while(len(st)>=2&&lca.lca(v,st.back())!=st.back()){
				int a=end(st)[-2];
				int b=st.back();
				ll c=lca.dist(a,b);
				ret.eb(c,a,b);
				st.pop_back();
			}
			st.pb(v);
		}
		while(len(st)>=2){
				int a=end(st)[-2];
				int b=st.back();
				ll c=lca.dist(a,b);
				ret.eb(c,a,b);
				st.pop_back();
		}
		return {ret,st.back()};
	}
};

const int MAXN=5'00'000+100;
vector<Edge>tree_adj[MAXN];
void run() {
	int n;cin>>n;
	Graph adj(n);
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;u--,v--;
		adj[u].eb(1,v);
		adj[v].eb(1,u);
	}
	vector<vector<int>>perdist(n);
	function<void(int,int,int)> dfs=
	[&](int u, int p, int h){
		perdist[h].eb(u);
		for(auto &[w,v]:adj[u])if(v!=p){
			dfs(v,u,h+1);
		}
	};
	dfs(0,-1,0);
	ll ans=n-1;
	VTree vt(adj);
	for(int d=1;d<n;d++){
		dbg(d);
		perdist[d].eb(0);
		auto tree=vt.vtree(perdist[d]).first;
		for(auto&[w,u,v]:tree){
			tree_adj[u].eb(w,v);
			tree_adj[v].eb(w,u);
		}

		ll curans=0;
		dbg(tree);
		function<void(int,int)> dfs2=
		[&](int u, int p){
			dbg(u,p);
			curans++;
			for(auto &[w,v]:tree_adj[u])if(v!=p){
				curans+=(w-1);
				dfs2(v,u);
			}
		};
		dfs2(0,-1);
		ans=min(ans,n-curans);
		dbg(curans);

		for(auto&[w,u,v]:tree){
			tree_adj[u].clear();
			tree_adj[v].clear();
		}
	}
	cout<<ans<<endl;
}

/*8<
  testar o custo de deixar todas as folhas a uma dist
  ancia di:
  	so pode ficar os nós que :
		estão a di de distância
		ou são antecessores de nós com di de distância
		olha a virtual tree como vem 

	AC, trees, data structures
>8*/
