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

  rep(t, 0, T) {
    dbg(t);
    run();
  }
}

vi solve(vi xs, int n, int k){
	vi2d pos(k);
	rrep(i,n-1,0-1)
		pos[xs[i]].eb(i);
	vi done(k);
	int cp=-1;
	vi ans;
	bool ok=false;
	for(int i=0;i<k;i++){
		vi app(k,INT_MAX);
		for(int j=0;j<k;j++){
			if(done[j]){
				app[j]=-1;
				continue;
			}
			while(len(pos[j])&&pos[j].back()<=cp)
				pos[j].ppb();
			if(len(pos[j]))
				app[j]=pos[j].back();
		}
		if(*max_element(all(app))==INT_MAX){
			ok=true;
			break;
		}
		int cur=max_element(all(app))-begin(app);
		ans.eb(cur),done[cur]=1,cp=app[cur];
	}
	if(ok){
		for(int j=0;j<k;j++){
			if(!done[j])ans.eb(j);
		}
		return ans;
	}
	return {};
}

bool check(vi xs, vi perm){
	if(!len(perm))return false;
	int k=len(perm);
	int j=0;
	trav(xi,xs){
		if(xi==perm[j]){
			j++;
		}
		if(j==k)return false;
	}
	return true;
}

int memo[1<<25];
int best[1<<25];
void run() {
	memset(best,-1,sizeof best);
	int n,k;cin>>n>>k;
	vi xs(n);trav(xi,xs)cin>>xi,xi--;
	if(k>=20){
		auto perm1=solve(xs,n,k);
		trav(i,perm1)cout<<i+1<<' ';
		cout<<endl;
	}
	else{
		const int oo=1e8;
		vi2d pos(k,vi(n+1,oo));
		rrep(i,n-1,0-1){
			rep(c,0,k){
				pos[c][i]=pos[c][i+1];
			}
			pos[xs[i]][i]=i;
		}
		for(int i=0;i<n;i++)pos[xs[i]].eb(i);
		for(int mask=0;mask<(1<<k);mask++){
			auto&ret=memo[mask];
			for(int x=0;x<k&&ret!=oo;x++){
				if(mask&(1<<x)){
					int mask2=mask^(1<<x);
					int p=memo[mask2];
					// int p2 =*lower_bound(all(pos[x]),p);
					int p2=p!=oo?pos[x][p]:oo;
					if(p2>ret){
						best[mask]=x;
						ret=p2;
					}
				}
			}
		}
		if(memo[(1<<k)-1]==oo){
			int curmask=(1<<k)-1;
			int cur=best[curmask];
			vi ans;
			rep(i,0,k){
				ans.eb(cur);
				curmask^=(1<<cur);
				cur=best[curmask];
			}
			reverse(all(ans));
			trav(i,ans)cout<<i+1<<' ';
			cout<<endl;
		}
		else{
			cout<<"*\n";
		}
	}
}

/*8<
  AC, greedy, dynamic programming
>8*/
