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
           i = (a);                              \
       i < (b); i++)
#define rrep(i, a, b)                          \
  for (common_type_t<decltype(a), decltype(b)> \
           i = (a);                              \
       i > (b); i--)
#define trav(a,x) for (auto& a : x)
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define emp emplace
#define ins insert
#define divc(a,b) ((a)+(b)-1ll)/(b)
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

/*8<
  posso matar todas as folhas ou matar
  o pai

  acho que tem sempre no máximo 3 rounds

  dp(i,j) quantas vezes o cara i
  fica vivo sabendo que :
    j=0: não posso matar ele agora
    j=1: posso matar ele agora

  faz diferença onde enriaoz ?ßæ®đæßdfjas 

  vai ter no máximo umas 30 operações vai
  montar dp(i,j) dizendo que o monstro i
  só pode morrer a partir da j-ésima operação
>8*/
void run() {
  int N;cin>>N;
  vll AS(N);trav(ai,AS)cin>>ai;
  vi2d ADJ(N);
  rep(i,0,N-1){
    int u,v;cin>>u>>v;u--,v--;
    ADJ[u].eb(v);ADJ[v].eb(u);
  }
  int mxop=log2(N)+1;
  vll2d dp(N, vll(30,-1));
  auto solve=[&](auto&&self,int u,int t,int p){
    auto&ret=dp[u][t];
    if(~ret)return ret;
    ret=(t+1)*AS[u];
    trav(v,ADJ[u])if(v!=p){
      ll cur=LLONG_MAX;
      rep(t2,0,30)if(t2!=t){
        chmin(cur, self(self,v,t2,u));
      }
      ret+=cur;
    }
    return ret;
  };
  ll ans=LLONG_MAX;
  rep(i,0,30)chmin(ans,solve(solve,0,i,-1));
  cout<<ans<<endl;
}
// AC,dynamic programming,trees
