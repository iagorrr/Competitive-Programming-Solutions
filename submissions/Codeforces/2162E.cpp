/*8<{==========~ BEGIN TEMPLATE ~============>8*/
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

const ll P = 31;
const ll MOD = 1e9 + 9;
const int MAXN(1e6);

ll ppow[MAXN + 1];
void pre_calc() {
  ppow[0] = 1;
  for (int i = 1; i <= MAXN; i++)
    ppow[i] = (ppow[i - 1] * P) % MOD;
}

struct Hash {
  int n;
  vll h, hi;
  Hash(const vll &s) : n(s.size()), h(n), hi(n) {
    h[0] = s[0];
    hi[n - 1] = s[n - 1];
    for (int i = 1; i < n; i++) {
      h[i] = (s[i] + h[i - 1] * P) % MOD;
      hi[n - i - 1] = (s[n - i - 1] + hi[n - i] * P) % MOD;
    }
  }

  ll qry(int l, int r) {
    ll hash = (

        h[r] -

        (l ? h[l - 1]

                 * ppow[r - l + 1] % MOD
           : 0));
    return hash < 0 ? hash + MOD : hash;
  }

  ll qry_inv(int l, int r) {
    ll hash = (hi[l] - (r + 1 < n ? hi[r + 1] * ppow[r - l + 1] % MOD : 0));
    return hash < 0 ? hash + MOD : hash;
  }
};

void __init() { pre_calc(); }

void __pre_run() {}

ll compose(ll h, ll v, ll sz) { return (h * P + v) % MOD; }

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

ll compose_inv(ll h, ll v, ll sz) {
  return (h * fpow(P, MOD - 2, MOD) + ((v * ppow[sz]) % MOD)) % MOD;
}

void __run() {
  ll n, k;
  cin >> n >> k;

  vll as(n);
  cin >> as;

  vi2d posByValue(n + 1);
  rep(i, 0, n) { posByValue[as[i]].eb(i); }

  Hash hashAs(as);

  vll xs;

  auto f = [&]() {
    rep(i, 1, n + 1) {
      if (len(xs) >= 3 or len(xs) >= k)
        break;

      if (as.back() == i)
        continue;

      bool ok = true;
      trav(p, posByValue[i]) {
        ll h = hashAs.qry(p + 1, len(as) - 1);
        ll hi = hashAs.qry_inv(p + 1, len(as) - 1);

        ok &= h != hi;
      }

      if (ok) {
        xs.eb(i);
        as.eb(i);
        hashAs = Hash(as);
        posByValue[i].eb(len(as) - 1);
      }
    }
  };
  f();
  f();
  f();

  repn(i, k) cout << xs[i % len(xs)] << ' ';
  cout << endl;
}

/*8<
>8*/
