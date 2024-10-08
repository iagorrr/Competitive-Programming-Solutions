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

  // cin >> T;

  rep(t, 0, T) {
    dbg(t);
    run();
  }
}
/*
vector<int> g[MAXN];int n;
bool tk[MAXN];
int fat[MAXN]; // father in centroid decomposition
int szt[MAXN]; // size of subtree
int calcsz(int x, int f){
	szt[x]=1;
	for(auto y:g[x])if(y!=f&&!tk[y])szt[x]+=calcsz(y,x);
	return szt[x];
}
void cdfs(int x=0, int f=-1, int sz=-1){ // O(nlogn)
	if(sz<0)sz=calcsz(x,-1);
	for(auto y:g[x])if(!tk[y]&&szt[y]*2>=sz){
		szt[x]=0;cdfs(y,f,sz);return;
	}
	tk[x]=true;fat[x]=f;
	for(auto y:g[x])if(!tk[y])cdfs(y,x);
}
void centroid(){memset(tk,false,sizeof(tk));cdfs();}
*/
struct CentroidDecomposition {
	int n;
	vi fat,szt,tk;
	CentroidDecomposition (vi2d&g) :
		n(len(g)),
		fat(n,-1),
		szt(n),
		tk(n)
	{

		cdfs(0,-1,-1,g);
	}
	int calcsz(int x, int f,vi2d&g){
		szt[x]=1;
		for(auto y:g[x])if(y!=f&&!tk[y])szt[x]+=calcsz(y,x,g);
		return szt[x];
	}
	void cdfs(int x, int f, int sz,vi2d&g){ // O(nlogn)
		if(sz<0)sz=calcsz(x,-1,g);
		for(auto y:g[x])if(!tk[y]&&szt[y]*2>=sz){
			szt[x]=0;cdfs(y,f,sz,g);return;
		}
		tk[x]=true;fat[x]=f;
		for(auto y:g[x])if(!tk[y])cdfs(y,x,-1,g);
	}
};

vi centroidDecomposition(const vi2d &g) {
	int n=len(g);
	vi fat(n,-1),szt(n),tk(n);
	function<int(int,int)>calcsz=[&](int x, int f){
		szt[x]=1;
		for(auto y:g[x])if(y!=f&&!tk[y])szt[x]+=calcsz(y,x);
		return szt[x];
	};
	function<void(int,int,int)> cdfs=[&](int x,int f,int sz){
		if(sz<0)sz=calcsz(x,-1);
		for(auto y:g[x])if(!tk[y]&&szt[y]*2>=sz){
			szt[x]=0;cdfs(y,f,sz);return;
		}
		tk[x]=true;fat[x]=f;
		for(auto y:g[x])if(!tk[y])cdfs(y,x,-1);
	};
	cdfs(0,-1,-1);
	return fat;
}

/*8<
  @Title:
    Lowest Common Ancestor

  @Description:

    Given two nodes of a tree find their lowest
    common ancestor, or their distance

  @Title:

    Build : $O(V)$, Queries: $O(1)$
>8*/

using Graph=vector<vector<pair<ll,int>>>;
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
  vi v, pos, dep;
  vll wdep;

  LCA(const Graph &g, int root) : n(len(g)), pos(n), wdep(n) {
    dfs(root, 0, -1, g);
    st = SparseTable<int>(vector<int>(all(dep)));
  }

  void dfs(int i, int d, int p, const Graph &g) {
    v.eb(len(dep)) = i, pos[i] = len(dep), dep.eb(d);
    for (auto [w, j] : g[i])
      if (j != p) {
        wdep[j] = wdep[i] + w;
        dfs(j, d + 1, i, g);
        v.eb(len(dep)) = i, dep.eb(d);
      }
  }

  int lca(int a, int b) {
    int l = min(pos[a], pos[b]);
    int r = max(pos[a], pos[b]);
    return v[st.query(l, r)];
  }
  ll dist(int a, int b) {
    return wdep[a] + wdep[b] - 2ll * wdep[lca(a, b)];
  }
};

void run() {
	int n,m;cin>>n>>m;
	vi2d g(n);
	Graph g2(n);

	rep(i,0,n-1){
		int u,v;
		cin>>u>>v;
		u--,v--;
		g[u].eb(v);
		g[v].eb(u);

		g2[u].eb(1,v);
		g2[v].eb(1,u);
	}
	auto fat =centroidDecomposition(g);
	LCA lca(g2,0);
	vll ans(n,INT_MAX);
	auto add=[&](int u){
		ans[u]=0;
		for(int cur=u;cur!=-1;cur=fat[cur]){
			ans[cur]=min(ans[cur],lca.dist(cur,u));
		}
	};
	add(0);
	auto answer=[&](int u){
		ll ret=INT_MAX;
		for(int cur=u;cur!=-1;cur=fat[cur]){
			dbg(cur);
			ret=min(ret,ans[cur]+lca.dist(cur,u));
		}
		return ret;
	};


	while(m--){
		int o,x;cin>>o>>x;
		x--;
		dbg(o,x);
		if(o==1){
			add(x);
		}
		else cout<<answer(x)<<endl;
	}
		
}

/*8<
  AC, trees, centroid decomposition
>8*/