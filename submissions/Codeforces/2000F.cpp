/*{=======================~ BEGIN MACRO ~================================*/

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
#define rep(i, a, b) \
        for (common_type_t<decltype(a), decltype(b)> i = a; i < b; i++)
#define rrep(i, a, b) \
        for (common_type_t<decltype(a), decltype(b)> i = a; i > b; i--)
#define pb push_back
#define pf push_front
#define eb emplace_back
#define INV(xs) for(auto&xi:xs)cin>>xi;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;
using vs = vector<string>;

template<typename T, typename U> inline bool chmax(T &a, U const& b) {
       	return (a < b ? a = b, 1 : 0);
}
template<typename T, typename U> inline bool chmin(T &a, U const& b) {
       	return (a > b ? a = b, 1 : 0);
}

/*=========================~ END MACRO ~================================}*/

/*
  dp[i][k] -> lowest cost to achieve k points considering only the first
  i elements
 */

const ll OO=1'000'000'000;

auto run() {
  int N,K;
  cin>>N>>K;
  vector<pii>XS(N);
  for(auto&[ai,bi]:XS)cin>>ai>>bi;
  vll2d dp(2,vll(K+1,OO));
  dp[1][0]=0;
  rep(i,0,N){
    auto&cur=dp[i&1];
    auto&prev=dp[!(i&1)];
    rep(k,0,K+1){
      auto[ai,bi]=XS[i];
      int cost=0;
      rep(d,0,k+1){
        chmin(cur[k],prev[k-d]+cost);
        if(!ai&&!bi)break;
        if(ai>bi)swap(ai,bi);
        cost+=ai;
        bi--;
      }
    }
  }
  dbg(dp);
  auto ans=dp[(N-1)&1][K];
  ans=ans>=OO?-1:ans;
  cout<<ans<<endl;
}

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

/*{
  AC, dynamic programming, knap sack
  }*/

