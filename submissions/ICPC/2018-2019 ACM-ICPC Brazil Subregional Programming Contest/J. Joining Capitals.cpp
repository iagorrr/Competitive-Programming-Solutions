/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define endl '\n'
#define fastio                        \
        ios_base::sync_with_stdio(0); \
        cin.tie(0);
#define int long long
#define all(j) j.begin(), j.end()
#define rall(j) j.rbegin(), j.rend()
#define len(j) (int)j.size()
#define rep(i, a, b)                                     \
        for (common_type_t<decltype(a), decltype(b)> i = \
                 (a);                                    \
             i < (b); i++)
#define rrep(i, a, b)                                    \
        for (common_type_t<decltype(a), decltype(b)> i = \
                 (a);                                    \
             i > (b); i--)
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) \
        for (auto &xi : ranges::views::reverse(xs))
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
using ll = long long;
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

template <typename T>
T steinerCost(const vector<vector<T>> &adj, const vi ks,
               T inf = numeric_limits<T>::max()) {
  int k=len(ks),n=len(adj);
  vector<vector<T>> dp(n,vector<T>(1<<k,inf));
  vi inks(n);
  trav(ki,ks)inks[ki]=1;

  trav(ki,ks){
    rep(j,0,n){
      if(count(all(ks),j)==0){
        dp[j][1<<ki]=adj[ki][j];
      }
    }
  }
  rep(mask,2,(1<<k)){
    rep(i,0,n){
      if(inks[i])continue;
      for(int mask2=(mask-1)&mask;mask2>=1;mask2=(mask2-1)&mask){
        int mask3 = mask ^ mask2;
        chmin(dp[i][mask], dp[i][mask2] + dp[i][mask3]);
      }
      rep(j,0,n){
        if(inks[j])continue;
        chmin(dp[j][mask],  dp[i][mask] + adj[i][j]);
      }
    }
  }
  T ans = inf;
  rep(i,0,n)
    chmin(ans,dp[i][(1 << k) - 1]);
  return ans;
}

void run() {
  int N,K;cin>>N>>K;
  dbg(N,K);
  vector<pii>pts(N);
  for(auto&[x,y]:pts)cin>>x>>y;
  const ld inf=1e9;
  vector<vector<ld>> ds(N,vector<ld>(N,inf));
  rep(i,0,N){
    rep(j,0,N){
      if(i!=j){
      ds[i][j]=hypot(pts[i].fi-pts[j].fi,pts[i].se-pts[j].se);
      }
    }
  }
  vi ks(K);
  iota(all(ks),0);
  cout<<fixed<<setprecision(5)<<steinerCost(ds,ks)<<endl;
}

/*8<
  AC, dynamic programming, trees, steiner tree
>8*/
