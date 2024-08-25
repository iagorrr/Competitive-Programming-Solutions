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
/*8<==========================================>8*/
/*8<
  @Title:

    Venice Set

  @Description:

    A container that you can insert $q$ copies
    of element $e$, increment every element in
    the contaiver in $x$, query which is the
    best element and it's quantity and also
    remove $k$ copies of the greatest element.


  @Time:

    \begin{compactitem}
      \item add elment $O(\log{N})$
      \item remove $O(\log{N})$
      \item update: $O(1)$
      \item query $O(1)$
    \end{compactitem}

>8*/
struct VeniceSet {
  set<pll> pq;
  ll acc;
  VeniceSet() : acc() {}

  ll add_element(ll e, ll q=1) {
    q+=erase(e);
    e-=acc;
    pq.emplace(e, q);
    return q;
  }

  void update_all(ll x) { acc += x; }

  int erase(ll x){
    x-=acc;
    auto it=pq.lb({x,LLONG_MIN});
    if(it==end(pq)||(*it).first!=x)return 0;
    int ret=(*it).second;
    pq.erase(it);
    return ret;
  }

  pll best() {
    auto ret = *pq.rbegin();
    ret.first += acc;
    return ret;
  }

  void pop() { pq.erase(prev(end((pq)))); }

  void pop_k(int k) {
    auto [e, q] = *pq.rbegin();
    pq.erase(prev(end(pq)));
    q -= k;
    if (q) pq.emplace(e, q);
  }

  int howMuch(ll x){
    x-=acc;
    auto it=pq.lb({x,LLONG_MIN});
    if(it==end(pq)||(*it).first!=x)return 0;
    return (*it).second;
  }
};

void run() {
  int N;cin>>N;
  vi XS(N);for(auto&xi:XS)cin>>xi;
  VeniceSet st;
  ll ans=0;
  trav(xi,XS){
    dbg(st.pq,st.acc);
    dbg(st.howMuch(xi),xi);  
    ans+=st.howMuch(xi);
    st.add_element(xi);
    st.update_all(1);
  }
  cout<<ans<<endl;
}

/*8<
  AC, data structures
>8*/
