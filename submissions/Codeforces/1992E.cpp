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
  pra cada N a gente itera pelo A

  vamos terum A * N

  vamos transfomrar A*N no número
  que é um prefixo do A*N', so precisamos
  testar enquanto esse prefixo
  for menor que A*N, tem log10 tentativas
  pra cada A
  acho que tá safo

  AC, math, brute force
}*/

void run() {
  int N;cin>>N;
  vll ds;
  string sn=to_string(N);
  while(len(ds)<=20){
    for(auto c:sn){
      ds.eb(c-'0');
    }
  }
  vpii ans;
  rep(a,1,10000+1){
    ll pref=0;
    for(auto&d:ds){
      pref=pref*10ll+d;
      if(pref>a*N)break;
      ll b=a*N-pref;
      if(b&&len(sn)*a-len(to_string(pref))==b){
        ans.eb(a,b);
      }
    }
  }
  cout<<len(ans)<<endl;
  for(auto&[a,b]:ans)cout<<a<<' '<<b<<endl;
}
