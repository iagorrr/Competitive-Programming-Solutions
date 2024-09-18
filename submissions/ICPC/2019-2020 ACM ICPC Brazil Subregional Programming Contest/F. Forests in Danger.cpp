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
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) \
  for (auto &xi : ranges::views::reverse(xs))
using ll = long long;
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

template <typename T>
using Point = pair<T, T>;
#define x first
#define y second

template <typename T>
optional<T> minCheck(T l, T r, auto check) {
  optional<T> ret;
  while (l <= r) {
    T m = midpoint(l, r);
    if (check(m))
      ret ? chmin(ret, m) : ret = m, r = m - 1;
    else
      l = m + 1;
  }
  return ret;
}

using SegT = ll;
const SegT eSeg=1e9;

struct QueryT {
  SegT q, v;
  QueryT() : q(0), v(eSeg) {}
  QueryT(SegT _v) : q(1), v(_v) {}
};

inline QueryT combine(QueryT ln, QueryT rn, pii lr1, pii lr2) {
	QueryT ret;
	if(ln.v<rn.v)
		ret = ln;
	if(rn.v<ln.v)
		ret = rn;
	if(rn.v==ln.v){
		ret.v=ln.v;
		ret.q=ln.q+rn.q;
	}
	return ret;
}

using LazyT = SegT;

inline QueryT applyLazyInQuery(QueryT q, LazyT l, pii lr) {
	if(l==LazyT())return q;
	if(q.v==eSeg)q.v=0,q.q=1;
	q.v+=l;
  return q;
}

inline LazyT applyLazyInLazy(LazyT a, LazyT b) { return a + b; }

using UpdateT = SegT;

inline QueryT applyUpdateInQuery(QueryT q, UpdateT u, pii lr) {
	return applyLazyInQuery(q,u,lr);
}

inline LazyT applyUpdateInLazy(LazyT l, UpdateT u, pii lr) { return l + u; }

template <typename Qt = QueryT, typename Lt = LazyT, typename Ut = UpdateT,
          auto C = combine, auto ALQ = applyLazyInQuery,
          auto ALL = applyLazyInLazy, auto AUQ = applyUpdateInQuery,
          auto AUL = applyUpdateInLazy>
struct LazySegmentTree {
  int n, h;
  vector<Qt> ts;
  vector<Lt> ds;
  vector<pii> lrs;

  LazySegmentTree(int _n)
      : n(_n),
        h(sizeof(int) * 8 - __builtin_clz(n)),
        ts(n << 1),
        ds(n),
        lrs(n << 1) {
    rep(i, 0, n) lrs[i + n] = {i, i};
    rrep(i, n - 1, 0) { lrs[i] = {lrs[i << 1].first, lrs[i << 1 | 1].second}; }
  }

  LazySegmentTree(const vector<Qt> &xs) : LazySegmentTree(len(xs)) {
    copy(all(xs), ts.begin() + n);
    rep(i, 0, n) lrs[i + n] = {i, i};
    rrep(i, n - 1, 0) {
      ts[i] = C(ts[i << 1], ts[i << 1 | 1], lrs[i << 1], lrs[i << 1 | 1]);
    }
  }

  void set(int p, Qt v) {
    ts[p + n] = v;
    build(p + n);
  }

  void upd(int l, int r, Ut v) {
    l += n, r += n + 1;
    int l0 = l, r0 = r;
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) apply(l++, v);
      if (r & 1) apply(--r, v);
    }
    build(l0), build(r0 - 1);
  }

  Qt qry(int l, int r) {
    l += n, r += n + 1;
    push(l), push(r - 1);
    Qt resl = Qt(), resr = Qt();
    pii lr1 = {l, l}, lr2 = {r, r};
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = C(resl, ts[l], lr1, lrs[l]), l++;
      if (r & 1) r--, resr = C(ts[r], resr, lrs[r], lr2);
    }
    return C(resl, resr, lr1, lr2);
  }

  void build(int p) {
    while (p > 1) {
      p >>= 1;
      ts[p] = ALQ(C(ts[p << 1], ts[p << 1 | 1], lrs[p << 1], lrs[p << 1 | 1]),
                  ds[p], lrs[p]);
    }
  }

  void push(int p) {
    rrep(s, h, 0) {
      int i = p >> s;
      if (ds[i] != Lt()) {
        apply(i << 1, ds[i]), apply(i << 1 | 1, ds[i]);
        ds[i] = Lt();
      }
    }
  }

  inline void apply(int p, Ut v) {
    ts[p] = AUQ(ts[p], v, lrs[p]);
    if (p < n) ds[p] = AUL(ds[p], v, lrs[p]);
  }
};

ll areaOfRectanglesUnion(
    const vector<pair<Point<int>, Point<int>>>
        &rectangles) {
  if (!size(rectangles)) return 0;
  int maxy = INT_MIN;
  for (auto &[p1, p2] : rectangles) {
    assert(p1.x < p2.x && p1.y < p2.y);
    maxy = max({maxy, p1.y, p2.y});
  }
  vector<array<int, 4>> sl;
  sl.reserve(size(rectangles) * 2);
  for (auto &[p1, p2] : rectangles) {
    sl.push_back({p1.x, p1.y, p2.y - 1, 1});
    sl.push_back({p2.x, p1.y, p2.y - 1, -1});
  }
  sort(sl.begin(), sl.end());

	vector<QueryT> aux(maxy, QueryT(0));
	LazySegmentTree seg(aux);
  //memset(seg_vec, 0, sizeof(ll) * maxy);
  //seg::build(maxy, seg_vec);

  int prevx = get<0>(sl.front());
  ll ans = 0;
  for (auto &[curx, ys, yf, inc] : sl) {
    auto [q, v] = seg.qry(0,maxy-1);
    //auto [q, v] = seg::query(0, maxy - 1);
    ans += (ll)(curx - prevx) *
           (v ? maxy : maxy - q);
    seg.upd(ys, yf, inc);
    prevx = curx;
  }
  return ans;
}


/*
         Assumes that the points P, Q that define
   a rectangle are the bottom-left and top-right
   corner
 */
template <typename T>
optional<pair<Point<T>, Point<T>>>
rectangleIntersection(
    const pair<Point<T>, Point<T>> &r1,
    const pair<Point<T>, Point<T>> &r2) {
  assert(r1.first.x < r1.second.x &&
         r1.first.y < r1.second.y);
  assert(r2.first.x < r2.second.x &&
         r2.first.y < r2.second.y);
  T x1 = max(r1.first.x, r2.first.x);
  T x2 = min(r1.second.x, r2.second.x);

  T y1 = max(r1.first.y, r2.first.y);
  T y2 = min(r1.second.y, r2.second.y);
  if (x1 >= x2 or y1 >= y2) return nullopt;
  return pair<Point<T>, Point<T>>{{x1, y1},
                                  {x2, y2}};
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<Point<ll>, Point<ll>>> segs(n);
  for (auto &[p1, p2] : segs) {
    auto &[x1, y1] = p1;
    auto &[x2, y2] = p2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (p1 > p2) swap(p1, p2);
  }
  int P;
  cin >> P;
  Point<ll> A, B;
  cin >> A.x >> A.y >> B.x >> B.y;
  if (A > B) swap(A, B);
  ll totArea = abs((A.x - B.x) * (A.y - B.y));
  auto ans =
      minCheck((int)1, (int)1e5, [&](int r) {
        // cerr<<"r:"<<r<<'\n';
        vector<pair<Point<int>, Point<int>>>
            rectangles;
        for (auto [p1, p2] : segs) {
          auto &[x1, y1] = p1;
          auto &[x2, y2] = p2;
          x1 -= r, y1 -= r;
          x2 += r, y2 += r;
          auto inter = rectangleIntersection(
              pair<Point<ll>, Point<ll>>{p1, p2},
              pair<Point<ll>, Point<ll>>{A, B});
          if (inter) {
            rectangles.push_back(*inter);
          }
        }
        auto area =
            areaOfRectanglesUnion(rectangles);
        return totArea * P <= area * 100ll;
      });
  assert(ans);
  cout << *ans << '\n';
}

// AC, data structures, geometry
