#include<bits/stdc++.h>
using namespace std;
using ll = long long;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int N = 200200;
map<pii, int> edgeToCost;
int n, m;
int totCost;

int p[N];
int sz[N];

int getPar(int v) {
	return p[v] == -1 ? v : p[v] = getPar(p[v]);
}
bool unite(int v, int u) {
	v = getPar(v);
	u = getPar(u);
	if (v == u) return false;
	if (sz[v] < sz[u]) swap(v, u);
	p[u] = v;
	sz[v] += sz[u];
	return true;
}

template<
	typename T=ll,
	auto E=0,
	auto F=[](ll a,ll b){return max(a,b);}>
struct TEQ {
	const int LOG=20;
	using Graph=vector<vector<pair<ll,int>>>;
	int n;
	vector<int> h;
	vector<vector<int>>par;
	vector<vector<T>>ed;
	TEQ (const Graph& g, int root=0) : n(size(g)), h(n,-1),
		par(n,vector<int>(LOG+1,root)),
		ed(n,vector<T>(LOG+1,E))
	{
		h[root]=0,dfs(root,g);
	}

	void dfs(int u,const Graph&g){
		for(auto&[w,v]:g[u]){
			if(h[v]==-1){
				h[v]=h[u]+1, par[v][0]=u, ed[v][0]=w;
				for(int k=0,p;k<LOG;k++){
					p=par[v][k];
					par[v][k+1]=par[p][k];
					ed[v][k+1]=F(ed[v][k],ed[p][k]);
				}
				dfs(v,g);
			}
		}
	}

	pair<int,T> up(int u, int dis){
		T res=E;
		for(int k=0;k<=LOG;k++){
			if(dis&(1<<k)){
				res=F(res,ed[u][k]);
				u=par[u][k];
			}
		}
		return{u,res};
	}
	
	pair<int,T> lca(int u, int v){
		if(h[u]>h[v])swap(u,v);
		T res=E;
		tie(v,res)=up(v,h[v]-h[u]);
		if(v==u) return{v,res};
		for(int k=LOG;~k;k--){
			if(par[u][k]!=par[v][k]){
				res=F(res,ed[v][k]);
				res=F(res,ed[u][k]);
				u=par[u][k],v=par[v][k];
			}
		}
		res=F(res,ed[v][0]);
		res=F(res,ed[u][0]);
		return {par[v][0],res};
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	vector<pair<int,pair<int,int>>> ed(m);
	for (int i = 0; i < m; i++) {
		int v, u, w;
		cin>>v>>u>>w;
		v--,u--;
		edgeToCost[mp(v, u)] = w;
		edgeToCost[mp(u, v)] = w;
		ed[i] = mp(w, mp(v, u));
	}
	for (int i = 0; i < n; i++) {
		p[i] = -1;
		sz[i] = 1;
	}
	sort(begin(ed),end(ed));
	vector<vector<pair<ll,int>>> g(n);
	for (int i = 0; i < m; i++) {
		int v = ed[i].second.first, u = ed[i].second.second;
		if (unite(v, u)) {
			totCost += ed[i].first;
			g[v].push_back(mp(ed[i].first,u));
			g[u].push_back(mp(ed[i].first,v));
		}
	}
	TEQ teq(g);
	int q;
	cin>>q;
	while(q--) {
		int v, u;
		cin>>v>>u;
		v--,u--;
		auto[l,w]=teq.lca(v,u);
		cout<<totCost-w+edgeToCost[mp(v,u)]<<'\n';
	}

	return 0;
}

