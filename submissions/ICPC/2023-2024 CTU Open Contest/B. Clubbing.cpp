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

  // cin >> T;

  rep(t, 0, T) {
    dbg(t);
    run();
  }
}

const int LOG=20;
vc build(const vi& masks){
  vc ret(1<<LOG);
  trav(mi,masks)ret[mi]=1;
  rep(b,0,LOG){
    rep(mask,0,(1<<LOG)){
      if(mask&(1<<b))
        ret[mask]|=ret[mask^(1<<b)];
    }
  }
  return ret;
}
void run() {
  int N;cin>>N;
  vi masks;
  rep(i,0,N){
    str s;cin>>s;
    int mk=0;
    trav(c,s){
      mk|=(1<<(c-'a'));
    }
    dbg(s,mk);
    masks.eb(mk);
  }
  auto dp=build(masks);
  string S;cin>>S;
  vi hist(LOG);
  int l=0,r=0;
  int mask=0;
  ll ans=0;
  N=len(S);
  while(l<=r&&r<=N){
    if(dp[mask]){
      ans+=(N-r+1);
      int c=(S[l]-'a');
      hist[c]--;
      if(!hist[c])
        mask^=(1<<c);
      l++;
    }
    else{
      if(r<N){
        int c=(S[r]-'a');
        hist[c]++;
        mask|=(1<<c);
      }
      r++;
    }
  }
  cout<<ans<<endl;
}

/*8<
  AC, two pointers, bitmasks
>8*/
