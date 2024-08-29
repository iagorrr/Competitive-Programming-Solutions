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

void run() {
  int N,K;cin>>N>>K;
  vll AS(N);trav(ai,AS)cin>>ai;
  sort(all(AS));
  map<ll,vll>permod;
  trav(ai,AS)permod[ai%K].eb(ai);
  dbg(permod);
  int odd=0;
  for(auto&[m,xs]:permod)
    odd+=(len(xs)&1);
  if(odd>1||(!(N&1)&&odd)){
    cout<<-1<<endl;
    return;
  }
  ll ans=0;
  for(auto&[m,xs]:permod){
    if(len(xs)&1){
      if(len(xs)==1){
        continue;
      }
      vll psum(len(xs));
      psum[1]=(xs[1]-xs[0])/K;
      rep(i,2,len(xs)){
        psum[i]=psum[i-2]+(xs[i]-xs[i-1])/K;
      }
      ll best=LLONG_MAX;
      rep(i,0,len(xs)){
        ll cur=0;
        if(i&1){
          cur+=(i-2>=0)?psum[i-2]:0;
          cur+=((xs[i+1]-xs[i-1])/K);
          cur+=(psum[len(xs)-1]);
          cur-=(psum[i+1]);
        }
        else{
          cur=i?psum[i-1]:0ll;
          cur+=psum[len(xs)-1];
          cur-=psum[i];
        }
        dbg(cur);
        chmin(best,cur);
      }
      ans+=best;
    }
    else{
      rep(i,0,len(xs)){
        ans+=(xs[i+1]-xs[i])/K;
        i++;
      }
    }
  }
  cout<<ans<<endl;
}

/*8<
  AC, math, brute force
>8*/
