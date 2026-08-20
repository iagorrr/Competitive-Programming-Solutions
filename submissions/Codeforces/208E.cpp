/*
...

...
 */
#pragma once
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

#pragma once

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
struct LCA {
  int n;
  const int maxlog;
  vector<vector<int>> up;
  vector<int> depth, par;

  LCA(const vector<int> &par_)
      : n(par_.size()), maxlog(ceil(log2(max(n, 2)))),
        up(n, vector<int>(maxlog + 1)), depth(n, -1), par(par_) {
    // Level 0: parent (a root is its own ancestor).
    for (int i = 0; i < n; i++)
      up[i][0] = (par[i] == -1 ? i : par[i]);
    // Build level by level, so it does not depend on node order.
    for (int j = 1; j <= maxlog; j++)
      for (int i = 0; i < n; i++)
        up[i][j] = up[up[i][j - 1]][j - 1];
    for (int i = 0; i < n; i++)
      get_depth(i);
  }

  int get_depth(int u) {
    if (depth[u] != -1)
      return depth[u];
    if (par[u] == -1)
      return depth[u] = 0;
    return depth[u] = get_depth(par[u]) + 1;
  }

  int kth_jump(int u, int k) {
    for (int i = maxlog; i >= 0; i--) {
      if ((1 << i) & k) {
        u = up[u][i];
      }
    }
    return u;
  }

  int lca(int u, int v) {
    if (depth[u] < depth[v])
      swap(u, v);
    int diff = depth[u] - depth[v];
    u = kth_jump(u, diff);
    if (u == v)
      return u;
    for (int i = maxlog; i >= 0; i--) {
      if (up[u][i] != up[v][i]) {
        u = up[u][i];
        v = up[v][i];
      }
    }
    return up[u][0];
  }

  bool on_path(int u, int v, int s) {
    int uv = lca(u, v), us = lca(u, s), vs = lca(v, s);
    return (uv == s or (us == uv and vs == s) or (vs == uv and us == s));
  }

  int dist(int u, int v) { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }
};

void __run() {
  int n;
  cin >> n;
  vi2d tree(n + 1);
  vi par(n + 1, -1);
  rep(i, 0, n) {
    int p;
    cin >> p;
    p--;
    if (p >= 0)
      tree[p].emplace_back(i), par[i] = p;
    else
      tree[n].eb(i), par[i] = n;
  }

  LCA lca(par);
  dbg("built");

  int m;
  cin >> m;
  vector<vector<pair<int, int>>> qs(n + 1);
  rep(i, m) {
    int u, p;
    cin >> u >> p;
    u--;
    if (lca.depth[u] <= p)
      continue;
    int z = lca.kth_jump(u, p);

    qs[z].eb(i, p);
  }

  vector<int> ans(m);
  Sack sack(tree, n);
  map<int, int> hist;
  sack.run([&](int u) { hist[lca.depth[u]]++; },
           [&](int u) {
             for (auto &[i, p] : qs[u]) {
               ans[i] = hist[p + lca.depth[u]] - 1;
             }
           },
           [&](int u) {}, [&]() { hist.clear(); });

  cout << ans << endl;
}

/*8<
>8*/
