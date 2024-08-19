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
           i = a;                              \
       i < b; i++)
#define rrep(i, a, b)                          \
  for (common_type_t<decltype(a), decltype(b)> \
           i = a;                              \
       i > b; i--)
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
using min_heap =
    priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T, vector<T>>;

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
  pega o max entre zero, então tá de boa se fizer 
  a operação e 'ficar negativo'

  não daria pra simular naive pq o K eh 1e9

  mas da pra saber quantas operaçẽos vou fazer
  no maior elemento até que ele se torne o menor ?

  eh uma PAzinha né
  Ai + Ai-bi + Ai-2*bi....

  ta eh sermpre bom ir no maior valor direto mesmo

  o problema é só o maior valor ficar trocando de
  lugar com o segudno maior a cda operação

  se eu tenho dois valores e quero saber até
  onde vale a pena fazer operação no maior dele
  é 

  e se a gente sair 'distribuindo' ?

  dá faz todas no maior valor menos quando ele já
  se tornou 0, dai passa pro segundo maior valor
  e assim por diante

  dps passa do maior valor pro menor conforme for valendo
  a pena...

  na parece muito quebrado
>8*/
/*8<
  @Title:

    Max \& Min Check

  @Description:

    Returns the min/max value in range [l, r] that
    satisfies the lambda function check, if there
    is no such value the max/min possible value
    for that type will be returned.

  @Time:

    $O(\log{l-r+1})$
>8*/

template <typename T>
T maxCheck(T l, T r, function<bool(T)> check) {
  T best = numeric_limits<T>::min();
  while (l <= r) {
    T m = midpoint(l, r);
    if (check(m))
      chmax(best, m), l = m + 1;
    else
      r = m - 1;
  }
  return best;
}

template <typename T>
T minCheck(T l, T r, function<bool(T)> check) {
  T best = numeric_limits<T>::max();
  while (l <= r) {
    T m = midpoint(l, r);
    if (check(m))
      chmin(best, m), r = m - 1;
    else
      l = m + 1;
  }
  return best;
}

void run() {
  ll N,K;cin>>N>>K;
  vector<pll> XS(N);
  for(auto&[ai,bi]:XS)cin>>ai;
  for(auto&[ai,bi]:XS)cin>>bi;
  sort(rall(XS));
  function<bool(int)> check=[&](ll x){
    ll tot=0;
    for(auto&[ai,bi]:XS){
      if(ai<x)break;
      ll d=ai-x;
      tot+=(d/bi)+1;
    }
    return tot>=K; 
  };
  ll mx=maxCheck(1ll,(ll)1e10,check);
  if(mx==numeric_limits<ll>::min()){
    mx=0;
  }
  ll onmx=0,notmx=0;
  ll ans=0;
  for(auto&[ai,bi]:XS){
    if(ai<mx)break;
    ll d=ai-mx;
    ll o=d/bi;
    ans=ans+ai*(o+1)-bi*(o*(o+1))/2ll;
    notmx+=o;
    if(ai-o*bi==mx)onmx++;
    else notmx++;
  }
  ll dec=(onmx-(K-notmx))*mx;
  ans-=dec;
  cout<<ans<<endl;
}

// AC, greddy, binary search
