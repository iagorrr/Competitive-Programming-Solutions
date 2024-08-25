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

/*8<
>8*/
ll count(string &s){
  int ret=0;
  int N=len(s);
  rep(i,0,N){
    rep(j,i+1,N){
      bool ok=false;
      ok|=(s[i]==s[j]);
      rep(k,i,j){
        ok|=
          (s[k]!=s[k+1])&&(s[k]!=s[i]||(s[k+1]!=s[j]));
      }
      ret+=ok;
    }
  }
  return ret;
}
void run() {
  int N;cin>>N;
  string S;cin>>S;
  map<char,int>hist;
  for(auto c:S){
    hist[c]++;
  }
  pqmn <pair<int,char>>st;
  for(auto&[c,q]:hist)
    st.emp(q,c);
  string ans;
  while(len(st)){
    pqmn<pair<int,char>>aux;
    while(len(st)){
      auto[q,c]=st.top();
      st.pop();
      ans.pb(c);
      if(q-1>=1)
        aux.emp(q-1,c);
    }
    st=aux;
  }
  //dbg(count(ans));
  cout<<ans<<endl;
}
// AC, strings, greedy

