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
#define lb lower_bound
#define ub upper_bound

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
  AC, greddy, binary search
}*/
const int oo=1'000'000'000;
void run() {
  int N,Q;cin>>N>>Q;
  map<string,vector<int>> pos;
  vs PS(N);
  rep(i,0,N){
    string s;cin>>s;
    if(s[0]>s[1])swap(s[0],s[1]);
    pos[s].eb(i);
    PS[i]=s;
  }
  rep(q,0,Q){
    int l,r;cin>>l>>r;l--,r--;
    if(l>r)swap(l,r);
    auto sl=PS[l],sr=PS[r];
    int ans=oo;
    rep(i,0,2){
      rep(j,0,2){
        string s;s.pb(sl[i]),s.pb(sr[j]);
        if(s[0]>s[1])swap(s[0],s[1]);
        auto it=ub(all(pos[s]),r);
        if(it!=pos[s].end()){
          chmin(ans,abs(l-*it)+abs(r-*it));
        }
        if(it!=pos[s].begin()){
          it--;
          chmin(ans,abs(l-*it)+abs(r-*it));
        }
      }
    }
    cout<<(ans==oo?-1:ans)<<endl;
  }
}
