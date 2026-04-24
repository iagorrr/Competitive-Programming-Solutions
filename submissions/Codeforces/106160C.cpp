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
using vpll = vector<pll>;
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
/*8<{=============~ BEGIN DSU ~===============>8*/
/*8<
  @Title:

    DSU / UFDS

  @Usage:

    You may discomment the commented parts to
    find online which nodes belong to each
    set, it makes the $union\_set$ method cost
    $O(log^2)$ instead $O(A)$

>8*/

struct DSU {
  vector<int> ps, sz;

  // vector<unordered_set<int>> sts;

  DSU(int N)
      : ps(N + 1), sz(N, 1) /*, sts(N) */
  {
    iota(ps.begin(), ps.end(), 0);
    // for (int i = 0; i < N; i++)
    // sts[i].insert(i);
  }
  int find_set(int x) { return ps[x] == x ? x : ps[x] = find_set(ps[x]); }
  int size(int u) { return sz[find_set(u)]; }
  bool same_set(int x, int y) { return find_set(x) == find_set(y); }
  void union_set(int x, int y) {
    if (x == y)
      return;
    if (same_set(x, y))
      return;

    int px = find_set(x);
    int py = find_set(y);

    if (sz[px] < sz[py])
      swap(px, py);

    ps[py] = px;
    sz[px] += sz[py];
    // sts[px].merge(sts[py]);
  }
};

/*8<===============~ END DSU ~===============}>8*/

int dx[] = {0, 0, 0, -1, 1, 1, 1, -1, -1};
int dy[] = {0, -1, 1, 0, 0, 1, -1, -1, 1};

void __run() {
  int n;
  cin >> n;

  using t3 = tuple<ll, ll, ll, ll>;
  vector<t3> pts(n);
  int idx = 0;
  for (auto &[a, b, c, d] : pts) {
    cin >> a >> b >> c;
    d = idx;
    idx++;
  }
  map<pii, vector<t3>> ptsByq;

  ll sz = 200;
  for (auto &[a, b, c, d] : pts) {
    int x = a / sz;
    int y = b / sz;
    ptsByq[{x, y}].eb(a, b, c, d);
  }

  DSU dsu(n);
  vi edges(n);

  auto connect = [&](t3 p1, t3 p2) {
    auto [x1, y1, r1, _] = p1;
    auto [x2, y2, r2, __] = p2;

    ld dist = hypot(x1 - x2, y1 - y2);
    return dist - (ld)(r1 / 2.0) - (ld)(r2 / 2.0) <= 50.8;
  };

  for (auto [q, ps] : ptsByq) {
    auto [x, y] = q;

    repn(i, 9) {

      int x2 = x + dx[i];
      int y2 = y + dy[i];

      for (auto pi : ps) {
        ll ii = get<3>(pi);
        for (auto pj : ptsByq[{x2, y2}]) {
          ll ij = get<3>(pj);
          if (ii == ij)
            continue;

          if (connect(pi, pj)) {
            dsu.union_set(ii, ij);
            edges[ii]++;
            edges[ij]++;
          }
        }
      }
    }
  }

  dbg(dsu.size(0));
  dbg(edges);
  bool ok = dsu.size(0) == n and (n < 7 or *min_element(all(edges)) / 2 >= 2);
  cout << (ok ? "yes" : "no") << endl;
}

/*8<
>8*/
