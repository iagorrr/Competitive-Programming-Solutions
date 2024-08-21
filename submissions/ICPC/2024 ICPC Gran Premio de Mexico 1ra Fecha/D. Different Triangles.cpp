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

  // cin >> T;

  rep(t, 0, T) {
    dbg(t);
    run();
  }
}
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
optional<T> maxCheck(T l, T r, auto check) {
  optional<T> best;
  while (l <= r) {
    T m = midpoint(l, r);
    if (check(m))
      best ? chmax(best, m) : best = m, l = m + 1;
    else
      r = m - 1;
  }
  return best;
}

template <typename T>
optional<T> minCheck(T l, T r, auto check) {
  optional<T> best;
  while (l <= r) {
    T m = midpoint(l, r);
    if (check(m))
      best ? chmin(best, m) : best = m, r = m - 1;
    else
      l = m + 1;
  }
  return best;
}

/*8<
  @Title: Arithmetic Progression Sum
  @Usage:
    \begin{compactitem}
      \item $s$ : first term
      \item $d$ : common difference
      \item $n$ : number of terms
    \end{compactitem}
>8*/
inline ll f(ll s, ll d, ll n) {
  return (s + (s + d * (n - 1))) * n / 2ll;
}
/*8< itera pelo maior lado
  e acho e fecha uma formula pros outros dois
  se o maior lado for l:
    - então o segundo maior lado precisa ser
    pelo menos ceil(l/2)

    3 3 [ 1..3 ] 1->min(max(N-3*2
    3 2 [ 2..2 ]
    3 1 [ 2..2 ] X

[l] = [1]
[l,l2,l3mn,l3mx,inc] = [1, 1, 1, 1, 1]
[l] = [2]
[l,l2,l3mn,l3mx,inc] = [2, 2, 1, 2, 2]
[l] = [3]
[l,l2,l3mn,l3mx,inc] = [3, 2, 2, 2, 1]
[l,l2,l3mn,l3mx,inc] = [3, 3, 1, 3, 3]
[l] = [4]
[l,l2,l3mn,l3mx,inc] = [4, 3, 2, 3, 2]
[l,l2,l3mn,l3mx,inc] = [4, 4, 1, 4, 4]
[l] = [5]
[l,l2,l3mn,l3mx,inc] = [5, 3, 3, 3, 1]
[l,l2,l3mn,l3mx,inc] = [5, 4, 2, 4, 3]
[l,l2,l3mn,l3mx,inc] = [5, 5, 1, 5, 5]
[l] = [6]
[l,l2,l3mn,l3mx,inc] = [6, 4, 3, 4, 2]
[l,l2,l3mn,l3mx,inc] = [6, 5, 2, 5, 4]
[l,l2,l3mn,l3mx,inc] = [6, 6, 1, 6, 6]
[l] = [7]
[l,l2,l3mn,l3mx,inc] = [7, 4, 4, 4, 1]
[l,l2,l3mn,l3mx,inc] = [7, 5, 3, 5, 3]
[l,l2,l3mn,l3mx,inc] = [7, 6, 2, 6, 5]
[l,l2,l3mn,l3mx,inc] = [7, 7, 1, 6, 6]
[l] = [8]
[l,l2,l3mn,l3mx,inc] = [8, 5, 4, 5, 2]
[l,l2,l3mn,l3mx,inc] = [8, 6, 3, 6, 4]
[l,l2,l3mn,l3mx,inc] = [8, 7, 2, 5, 4]
[l,l2,l3mn,l3mx,inc] = [8, 8, 1, 4, 4]
[l] = [9]
[l,l2,l3mn,l3mx,inc] = [9, 5, 5, 5, 1]
[l,l2,l3mn,l3mx,inc] = [9, 6, 4, 5, 2]
[l,l2,l3mn,l3mx,inc] = [9, 7, 3, 4, 2]
[l,l2,l3mn,l3mx,inc] = [9, 8, 2, 3, 2]
[l,l2,l3mn,l3mx,inc] = [9, 9, 1, 2, 2]
>8*/
const int MOD = 1'000'000'000 + 7;
void run() {
  int N;
  cin >> N;
  int ans = 0;
  rep(l, 1, N + 1) {
    if (l + l + 1 > N) break;
    dbg(l);
    int s = l / 2 + 1;
    // l+2*s <= N which is the highest s?
    auto hs = maxCheck(s, l, [&](int m) -> bool {
      return l + m * 2 <= N;
    });
    if (hs) {
      int inis = 2 - (l & 1);
      ll inc = f(inis, 2, *hs - s + 1) % MOD;
      ans = (ans + inc) % MOD;
    }
    hs = minCheck((int)1, l, [&](int m) -> bool {
      return l + m * 2 > N;
    });
    if (hs) {
      int l3mn = (l + 1) - *hs;
      int l3mx = N - l - *hs;
      int sz = l3mx - l3mn + 1;
      int hs2 = min(N - 1 - l, l);
      int inc = (hs2 - *hs + 1) * sz;
      dbg(*hs, hs2, sz, inc);
      ans = (ans + inc) % MOD;
    }
  }
  cout << ans << endl;
}

// AC, binary search, math, geometry
