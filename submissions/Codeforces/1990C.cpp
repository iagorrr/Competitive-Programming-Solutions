/*{=============~ BEGIN TEMPLATE ~==============*/
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
           i = a;                              \
       i < b; i++)
#define rrep(i, a, b)                          \
  for (common_type_t<decltype(a), decltype(b)> \
           i = a;                              \
       i > b; i--)
#define pb push_back
#define pf push_front
#define eb emplace_back

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
using vs = vector<string>;

template <typename T, typename U>
inline bool chmax(T &a, U const &b) {
  return (a < b ? a = b, 1 : 0);
}
template <typename T, typename U>
inline bool chmin(T &a, U const &b) {
  return (a > b ? a = b, 1 : 0);
}

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

/*===============~ END TEMPLATE ~==============}*/

/*{
  AC, greddy, math
}*/

void run() {
  int N;cin >> N;
  vi AS(N);for(auto&ai:AS)cin>>ai;
  ll ans=accumulate(all(AS),0ll);
  vi bs(N);
  {
    vi have(N+1);
    int cur=0;
    rep(i,0,N){
      have[AS[i]]++;
      if(have[AS[i]]>=2)
        chmax(cur,AS[i]);
      bs[i]=cur;
    }
  }
  dbg(bs);
  ll lst=0;
  rep(i,0,N){
    ans+=bs[i];
    if((i+1<N&&bs[i]==bs[i+1])||
        (i-1>=0&&bs[i]==bs[i-1])){
          ans+=bs[i]*(N-i-1);
          lst=bs[i];
    }
    else{
          ans+=lst*(N-i-1);
    }
  }

  cout<<ans<<endl;
}
