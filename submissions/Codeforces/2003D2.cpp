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
#define int long long
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
#define trav(a, x) for (auto &a : x)
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
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

void run() {
  int N,M;cin>>N>>M;
  vi2d ASS(N);
  int mxmex=0;
  trav(AS,ASS){
    int n;cin>>n;
    chmax(mxmex,n+1);
    AS.resize(n);
    trav(ai,AS)cin>>ai;
  }
  vi2d adj(mxmex+1);
  vi mex,mex2;
  vi histmex(mxmex+1);
  trav(AS,ASS){
    vi have(len(AS)+2);
    int cur=0;
    trav(ai,AS){
      if(ai>len(AS))continue;
      have[ai]++;
      while(have[cur])cur++;
    }
    mex.eb(cur);
    histmex[cur]++;
    have[cur]++;
    while(have[cur])cur++;
    mex2.eb(cur);
    adj[mex.back()].eb(mex2.back());
  }
  vi dpmx(mxmex+1,-1);
  function<int(int)> fbest=
    [&](int u)->int{
    auto&ret=dpmx[u];
    if(~ret)return ret;
    ret=u;
    for(auto&v:adj[u]){
      chmax(ret,fbest(v));
    }
    return ret;
  };
  dbg(mex,mex2);
  int posbest=0;
  rep(i,0,mxmex+1){
    if(histmex[i]>1){
      chmax(posbest,fbest(i));
    }
    if(histmex[i])
      chmax(posbest,i);
  }
  dbg(posbest);
  ll ans=0;
  rep(i,0,min(M,mxmex)+1){
    ans+=(max(posbest,fbest(i)));
  }
  if(M>mxmex){
    ll tot=(M*(M+1))/2ll;
    ll dec=((mxmex)*(mxmex+1))/2ll;
    ll inc=tot-dec;
    ans+=inc;
  }
  cout<<ans<<endl;
}
/*8<
3 4
0 2 0 4 11  mex: 1 mex2: 3
1           mex: 0 mex2: 2
1 3 0 3 3   mex: 2 mex2: 4

0 -> 2 -> 4
1 -> 3
2 -> 4
3
4
  sempre vou pro meu mex ou pra alguém que 
  de pra trancisionar e ir pro mex dele

  AC, graphs, dynamic programming, 
  data structures,  greedy
>8*/

