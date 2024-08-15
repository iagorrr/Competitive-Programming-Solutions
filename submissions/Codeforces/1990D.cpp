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
  pior caso é N
  AC, greddy
}*/
void run() {
  int N;cin>>N;
  vector<pll> AS(N);for(auto&[_,ai]:AS)cin>>ai;
  int ans=0;
  rep(i,0,N){
    auto&[si,hi]=AS[i];
    if(si){
      if(!hi)continue;
      if(hi<=2){
        ans++;
        if(i+1<N){
          auto&[sj,hj]=AS[i+1];
          if(2<hj&&hj<=4){
            hj-=(hj>3);
            hj--;
          }
        }
      }
      else{
        ans++;
      }
    }
    else{
      if(!hi)continue;
      if(hi<=2){
        ans++;
        if(i+1<N){
          auto&[sj,hj]=AS[i+1];
          if(hj>2)
            sj=2,
            hj-=2;
          else hj=0;
        }
      }
      else{
        ans++;
      }
    }
  }
  cout<<ans<<endl;
}
