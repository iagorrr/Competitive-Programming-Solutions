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
#define rep(i, a, b)                           \
  for (common_type_t<decltype(a), decltype(b)> \
           i = (a);                            \
       i < (b); i++)
#define rrep(i, a, b)                          \
  for (common_type_t<decltype(a), decltype(b)> \
           i = (a);                            \
       i > (b); i--)
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) \
  for (auto &xi : ranges::views::reverse(xs))
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
using pqmn =
    priority_queue<T, vector<T>, greater<T>>;
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

struct RollbackUF {
	vi e; vector<pii> st;
	RollbackUF(int n) : e(n, -1) {}
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : find(e[x]); }
	int time() { return len(st); }
	void rollback(int t) {
		for (int i = time(); i --> t;)
			e[st[i].first] = st[i].second;
		st.resize(t);
	}
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		st.push_back({a, e[a]});
		st.push_back({b, e[b]});
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

int id(int i, int j,int n,int m){
  return i*m+j;
}

int di[4]={0,0,1,-1};
int dj[4]={1,-1,0,0};

int solve(vs &grid){
  int n=len(grid),m=len(grid.back());

  RollbackUF dsu(n*m);
  int ans=0;
  rep(i,0,n){
    rep(j,0,m){
      if(grid[i][j]!='#')
        continue;
      rep(d,0,4){
        int i2=i+di[d];
        int j2=j+dj[d];
        if(i2>=0&&i2<n&&j2>=0&&j2<m&&grid[i2][j2]=='#'){
          dsu.join(id(i,j,n,m),id(i2,j2,n,m));
        }
      }
    }
  }

  int initial=dsu.time();
  chmax(ans,n);
  chmax(ans,m);
  rep(i,0,n){
    dsu.rollback(initial);
    auto before=grid[i];
    grid[i]=string(m,'#');
    rep(j,0,m-1){
      dsu.join(id(i,j,n,m),id(i,j+1,n,m));
      chmax(ans,dsu.size(id(i,j,n,m)));
    }
    rep(j,0,m){
      chmax(ans,dsu.size(id(i,j,n,m)));
      rep(d,0,4){
        int i2=i+di[d];
        int j2=j+dj[d];
        if(i2>=0&&i2<n&&j2>=0&&j2<m&&grid[i][j]=='#'&&
            grid[i2][j2]=='#'){
          dsu.join(id(i,j,n,m),id(i2,j2,n,m));
          chmax(ans,dsu.size(id(i,j,n,m)));
        }
      }
    }
    grid[i]=before;
  }
  return ans;
}

void rotate(vs&grid){
  int n=len(grid),m=len(grid.back());
  vs aux;
  rep(j,0,m){
    aux.eb("");
    rrep(i,n-1,0-1){
      aux.back().pb(grid[i][j]);
    }
  }
  /*
  cerr<<"grid:"<<endl;
  rep(i,0,n){
    rep(j,0,m)
      cout<<grid[i][j];
    cout<<endl;
  }
  cout<<endl;
  cerr<<"aux:"<<endl;
  rep(i,0,m){
    rep(j,0,n)
      cout<<aux[i][j];
    cout<<endl;
  }
  */
  grid=aux;
}

void run() {
  int N,M;cin>>N>>M;
  vs grid(N);trav(gi,grid)cin>>gi;
  auto ans=solve(grid);
  rotate(grid);
  chmax(ans,solve(grid));
  cout<<ans<<endl;
}

/*8<
  resovle so pra linha e dps
  rotaciona

  da pra fazer com union find com roll back n ?

  AC, data structures, brute force
>8*/
