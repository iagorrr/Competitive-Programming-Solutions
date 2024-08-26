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
#define trav(xi, xs) for (auto&xi:xs)
#define rtrav(xi,xs) \
  for(auto&xi:ranges::views::reverse(xs))


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


const int MAXN(5'000);
const ll MOD = 1000027957;
const ll MOD2 = 1000015187;
const ll P = 31;

ll p[MAXN + 1], p2[MAXN + 1];
void precompute() {
  p[0] = p2[0] = 1;
  for (int i = 1; i <= MAXN; i++)
    p[i] = (P * p[i - 1]) % MOD,
    p2[i] = (P * p2[i - 1]) % MOD2;
}

struct Hash {
  int n;
  vll h, h2, hi, hi2;
  Hash() {}
  Hash(const string &s)
      : n(s.size()), h(n), h2(n), hi(n), hi2(n) {
    h[0] = h2[0] = s[0];
    for (int i = 1; i < n; i++)
      h[i] = (s[i] + h[i - 1] * P) % MOD,
      h2[i] = (s[i] + h2[i - 1] * P) % MOD2;

    hi[n - 1] = hi2[n - 1] = s[n - 1];
    for (int i = n - 2; i >= 0; i--)
      hi[i] = (s[i] + hi[i + 1] * P) % MOD,
      hi2[i] = (s[i] + hi2[i + 1] * P) % MOD2;
  }
  pll query(int l, int r) {
    ll hash =
        (h[r] -
         (l ? h[l - 1] * p[r - l + 1] % MOD : 0));
    ll hash2 =
        (h2[r] -
         (l ? h2[l - 1] * p2[r - l + 1] % MOD2
            : 0));

    return {(hash < 0 ? hash + MOD : hash),
            (hash2 < 0 ? hash2 + MOD2 : hash2)};
  }
  pll query_inv(int l, int r) {
    ll hash = (hi[l] -
               (r + 1 < n ? hi[r + 1] *
                                p[r - l + 1] % MOD
                          : 0));
    ll hash2 =
        (hi2[l] -
         (r + 1 < n
              ? hi2[r + 1] * p2[r - l + 1] % MOD2
              : 0));
    return {(hash < 0 ? hash + MOD : hash),
            (hash2 < 0 ? hash2 + MOD2 : hash2)};
  }
};
int32_t main() {
#ifndef LOCAL
  fastio;
#endif
  precompute();

  int T = 1;

  cin >> T;

  rep(t, 0, T) {
    dbg(t);
    run();
  }
}
void run() {
  str S;cin>>S;
  int N=len(S);
  vi markpos;
  rep(i,0,N){
    if(S[i]=='?')markpos.eb(i);
  }
  int ans=0;
  rep(sz,1,N+1){
    int mx=0;
    int cur=0;
    rep(l,0,N-sz){
      bool eq=(S[l]==S[l+sz])||
              (S[l]=='?')||
              (S[l+sz]=='?');
      cur=(eq?cur+1:0);
      chmax(mx,cur);
    }
    if(mx>=sz)ans=sz*2;
  }
  cout<<ans<<endl;
}

/*8<
  AC, strings, brute force
>8*/
