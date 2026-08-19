/*
...

...
 */
#pragma once
/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
#include <mutex>
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
#define found(x, y) ((x).find((y)) != (x).end())
#define rall(j) j.rbegin(), j.rend()
#define len(j) (int)j.size()
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) for (auto &xi : ranges::views::reverse(xs))
// Stolen from https://codeforces.com/profile/Geothermal
// https:trap.jp/post/1224/
#define rep1(a) for (int _ = 0; _ < int(a); ++_)
#define rep2(i, a) for (int i = 0; i < int(a); ++i)
#define rep3(i, a, b) for (int i = int(a); i < int(b); ++i)
#define rep4(i, a, b, c) for (int i = int(a); i < int(b); i += int(c))
#define rep1_R(a) for (int i = int(a) - 1; i >= 0; --i)
#define rep2_R(i, a) for (int i = int(a) - 1; i >= 0; --i)
#define rep3_R(i, a, b) for (int i = int(b) - 1; i >= int(a); --i)
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rep_R(...) overload3(__VA_ARGS__, rep3_R, rep2_R, rep1_R)(__VA_ARGS__)

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
using vpll = vector<pll>;
using vc = vector<char>;
using vs = vector<str>;

#define TT template <typename T>
#define TTU template <typename T, typename U>

TTU using umap = unordered_map<T, U>;
TT using uset = unordered_set<T>;
TT using pqmn = priority_queue<T, vector<T>, greater<T>>;
TT using pqmx = priority_queue<T, vector<T>>;

TTU inline bool chmax(T &a, U const &b) { return (a < b ? a = b, 1 : 0); }
TTU inline bool chmin(T &a, U const &b) { return (a > b ? a = b, 1 : 0); }

// bit operations, i may remove this soon
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using i128 = __int128;
using u128 = unsigned __int128;
// using f128 = __float128;
int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(u32 x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int popcnt(u64 x) { return __builtin_popcountll(x); }
int popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 : 1); }
int popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }
int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }
int popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
int lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

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

// print pair
TTU ostream &operator<<(ostream &os, pair<T, U> &p) {
  os << p.first << " " << p.second;
  return os;
}

// read pair
TTU std::istream &operator>>(std::istream &is, pair<T, U> &p) {
  is >> p.first >> p.second;
  return is;
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

  // cin >> T;

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

void __init() {}

void __pre_run() {}
/*8<
  @Title:
    DSU on Tree (Sack)

  @Description:
    Answers offline subtree queries in $O(N\log N)$ using the
    small-to-large trick. For every vertex it processes the light
    children first (adding then discarding their subtrees), keeps
    the heavy child's contribution, re-adds the light subtrees and
    the vertex itself, then takes a snapshot for that vertex. Each
    element is added $O(\log N)$ times.

    The traversal is driven by four callbacks:
    \textbf{ADD(u)} inserts vertex $u$ into the current structure,
    \textbf{ANS(u)} records the answer for $u$ (whole subtree of
    $u$ is present), \textbf{DEL(u)} removes $u$, and the optional
    \textbf{EMPTY()} is called after a light subtree is fully erased
    (handy to reset aggregates in $O(1)$ instead of per-element
    deletions).

  @Usage:
    Sack sack(g, root);
    unordered\_map<int,int> cnt; int distinct = 0;
    auto add = [\&](int u){ distinct += !cnt[c[u]]++; };
    auto ans = [\&](int u){ res[u] = distinct; };
    auto del = [\&](int u){ distinct -= !--cnt[c[u]]; };
    sack.run(add, ans, del); // 3-arg form: no EMPTY callback

  @Time:
    $O(N\log N)$ times the cost of one callback.

>8*/

struct Sack {
  int n, root, timer;
  vector<vector<int>> g;
  vector<int> par, sz, heavy, tin, tout, ord;

  Sack(const vector<vector<int>> &g_, int root_)
      : n(g_.size()), root(root_), g(g_), par(n, -1), sz(n, 0), heavy(n, -1),
        tin(n), tout(n), ord(n) {
    timer = 0;
    dfs(root);
  }

  void dfs(int u) {
    sz[u] = 1;
    tin[u] = timer;
    ord[timer++] = u;
    for (int v : g[u])
      if (v != par[u]) {
        par[v] = u;
        dfs(v);
        sz[u] += sz[v];
        if (heavy[u] == -1 || sz[v] > sz[heavy[u]])
          heavy[u] = v;
      }
    tout[u] = timer;
  }

  template <class FA, class FS, class FD, class FE>
  void go(int u, bool keep, FA &ADD, FS &SNAP, FD &DEL, FE &EMPTY) {
    for (int v : g[u])
      if (v != par[u] && v != heavy[u])
        go(v, false, ADD, SNAP, DEL, EMPTY);
    if (heavy[u] != -1)
      go(heavy[u], true, ADD, SNAP, DEL, EMPTY);
    for (int v : g[u])
      if (v != par[u] && v != heavy[u])
        for (int i = tin[v]; i < tout[v]; i++)
          ADD(ord[i]);
    ADD(u);
    SNAP(u);
    if (!keep) {
      for (int i = tin[u]; i < tout[u]; i++)
        DEL(ord[i]);
      EMPTY();
    }
  }

  template <class FA, class FS, class FD, class FE>
  void run(FA ADD, FS ANS, FD DEL, FE EMPTY) {
    go(root, true, ADD, ANS, DEL, EMPTY);
  }

  template <class FA, class FS, class FD> void run(FA ADD, FS ANS, FD DEL) {
    auto E = [] {};
    go(root, true, ADD, ANS, DEL, E);
  }
};

void __run() {
  int n;
  cin >> n;

  vi as(n);
  cin >> as;

  vi2d g(n);
  rep(n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].eb(v);
    g[v].eb(u);
  }

  Sack sack(g, 0);
  dbg("build");

  unordered_map<int, int> hist;
  map<int, ll> bySize;
  ll sum = 0;
  auto add = [&](int u) {
    int au = as[u];
    if (hist[au])
      bySize[hist[au]] -= au;
    if (!bySize[hist[au]])
      bySize.erase(hist[au]);
    hist[au]++;
    if (hist[au])
      bySize[hist[au]] += au;
    if (!bySize[hist[au]])
      bySize.erase(hist[au]);
  };
  auto del = [&](int u) {
    int au = as[u];
    if (hist[au])
      bySize[hist[au]] -= au;
    if (!bySize[hist[au]])
      bySize.erase(hist[au]);
    hist[au]--;
    if (hist[au])
      bySize[hist[au]] += au;
    if (!bySize[hist[au]])
      bySize.erase(hist[au]);
  };

  vll x(n);
  auto ans = [&](int u) {
    dbg(bySize);
    x[u] = len(bySize) ? bySize.rbegin()->second : 0;
  };

  sack.run(add, ans, del);

  cout << x << endl;
}

/*8<
>8*/
