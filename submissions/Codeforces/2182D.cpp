/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define fastio                                                                 \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#define all(j) j.begin(), j.end()
#define rall(j) j.rbegin(), j.rend()
#define len(j) (int)j.size()
#define rep(i, a, b)                                                           \
  for (common_type_t<decltype(a), decltype(b)> i = (a); i < (b); i++)
#define rrep(i, a, b)                                                          \
  for (common_type_t<decltype(a), decltype(b)> i = (a); i > (b); i--)
#define repn(i, b) for (auto i = 0; i < (b); i++)
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) for (auto &xi : ranges::views::reverse(xs))
#define loop while (1)
using ll = long long;
#define endl '\n'
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define ef emplace_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define emp emplace
#define ins insert
#define divc(a, b) ((a) + (b) - 1ll) / (b)
using str = string;
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

#define TT template <typename T>
#define TTU template <typename T, typename U>

TTU using umap = unordered_map<T, U>;
TT using pqmn = priority_queue<T, vector<T>, greater<T>>;
TT using pqmx = priority_queue<T, vector<T>>;

TTU inline bool chmax(T &a, U const &b) { return (a < b ? a = b, 1 : 0); }
TTU inline bool chmin(T &a, U const &b) { return (a > b ? a = b, 1 : 0); }

// read vector
// TODO: abstract this to any container.
TT std::istream &operator>>(std::istream &is, std::vector<T> &vec) {
  for (auto &element : vec) {
    is >> element;
  }
  return is;
}

// print vector
// TODO: abstract this to any container.
TT ostream &operator<<(ostream &os, vector<T> &xs) {
  rep(i, os.iword(0), xs.size()) os << xs[i] << (i == xs.size() ? "" : " ");
  os.iword(0) = 0;
  return os;
}

// print multiset
// TODO: abstract this to any container.
TT ostream &operator<<(ostream &os, multiset<T> &xs) {
  for (auto it = xs.begin(); it != xs.end(); it++)
    os << *it << (next(it) == end(xs) ? "" : " ");
  return os;
}

// sum a vector, using the default constructor as initial value
// TODO: abstract this to any container.
TT T sumList(vector<T> &xs) { return accumulate(all(xs), T()); }

/*
 * verify if a `predicate` is valid for
 * values in range [l, r]
 *
 * TODO: put a type in predicate ??
 * */
// bool all_of_in_range(T l, T r, auto predicate) {
//     return ranges::all_of(views::iota(l, r + 1),
//                           [&](T v) { return predicate(v); });
// }

// checks if a  value v is the interval [l, r]
TT bool inline between(T v, T l, T r) { return clamp(v, l, r) == v; }

/*8<============~ END TEMPLATE ~============}>8*/
void __init();
void __run();
void __pre_run();

int32_t main() {
#ifndef LOCAL
  fastio;
#endif
  __init();

  int T = 1;

  cin >> T;

  rep(t, 0, T) {
    dbg(t);
    __pre_run();
    __run();
  }
}

/*
 *
 *
 *
 *
 *
 * */

const int maxn = 1e6 + 1;

const ll mod = 998244353;

vll _f(maxn);
ll fac(ll x) { return _f[x]; }

const ll MOD = 998244353;
inline ll _binom(ll n, ll k) {
  static const int BINMAX = maxn;
  static vll FAC(BINMAX + 1), FINV(BINMAX + 1);
  static bool done = false;
  if (!done) {
    vll INV(BINMAX + 1);
    FAC[0] = FAC[1] = INV[1] = FINV[0] = FINV[1] = 1;
    for (int i = 2; i <= BINMAX; i++) {
      FAC[i] = FAC[i - 1] * i % MOD;
      INV[i] = MOD - MOD / i * INV[MOD % i] % MOD;
      FINV[i] = FINV[i - 1] * INV[i] % MOD;
    }
    done = true;
  }

  if (n < k || n < 0 || k < 0)
    return 0;
  return FAC[n] * FINV[k] % MOD * FINV[n - k] % MOD;
}

ll binom(ll n, ll x) { return _binom(n, x); }

void precompute() {

  _f[0] = 1;
  rep(i, 1, maxn) { _f[i] = (_f[i - 1] * i) % mod; }
}

ll mul(ll a, ll b) { return (a * b) % mod; }

void __init() { precompute(); }
void __pre_run() {}

/*8<
  @Title: Fast Pow
  @Description: Computes $a^b \pmod{m}$
  @Time: $O(\log{B})$.
>8*/
ll fpow(ll a, ll b, ll m) {
  ll ret = 1;
  while (b) {
    if (b & 1)
      ret = (ret * a) % m;
    b >>= 1;
    a = (a * a) % m;
  }
  return ret;
}

void __run() {
  int n;
  cin >> n;

  ll a0;
  cin >> a0;

  vll as(n);
  cin >> as;

  ll s = a0 + accumulate(all(as), 0ll);

  ll base = s / n;

  ll tot_base = 0, tot_base_plus = 0;

  for (auto ai : as) {
    if (ai > base + 1) {
      cout << 0 << endl;
      return;
    }

    if (ai == base + 1) {
      tot_base_plus++;
      continue;
    }

    tot_base++;

    a0 -= (base - ai);
    if (a0 < 0) {
      cout << 0 << endl;
      return;
    }
  }

  ll r = s % n;
  ll to_choose = r - tot_base_plus;
  ll ans = mul(mul(fac(r), fac(n - r)), binom(tot_base, to_choose));

  cout << ans << endl;
}

/*8<
>8*/
