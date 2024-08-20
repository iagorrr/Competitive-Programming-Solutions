/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>

#include <iomanip>
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

  cin >> T;

  rep(t, 0, T) {
    dbg(t);
    run();
  }
}

using SegT = ll;

struct QueryT {
  SegT v, v2;
  QueryT()
      : v(numeric_limits<SegT>::min()),
        v2(numeric_limits<SegT>::max()) {}
  QueryT(SegT _v) : v(_v), v2(_v) {}
};

inline QueryT combine(QueryT ln, QueryT rn,
                      pii lr1, pii lr2) {
  chmax(ln.v, rn.v);
  chmin(ln.v2, rn.v2);
  return ln;
}

using LazyT = SegT;

inline QueryT applyLazyInQuery(QueryT q, LazyT l,
                               pii lr) {
  if (q.v == QueryT().v) q.v = 0;
  if (q.v2 == QueryT().v2) q.v2 = 0;
  q.v += l;
  q.v2 += l;
  return q;
}

inline LazyT applyLazyInLazy(LazyT a, LazyT b) {
  return a + b;
}

using UpdateT = SegT;

inline QueryT applyUpdateInQuery(QueryT q,
                                 UpdateT u,
                                 pii lr) {
  if (q.v == QueryT().v) q.v = 0;
  q.v += u;

  if (q.v2 == QueryT().v2) q.v2 = 0;
  q.v2 += u;
  return q;
}

inline LazyT applyUpdateInLazy(LazyT l, UpdateT u,
                               pii lr) {
  return l + u;
}

template <typename Qt = QueryT,
          typename Lt = LazyT,
          typename Ut = UpdateT, auto C = combine,
          auto ALQ = applyLazyInQuery,
          auto ALL = applyLazyInLazy,
          auto AUQ = applyUpdateInQuery,
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
    rrep(i, n - 1, 0) {
      lrs[i] = {lrs[i << 1].first,
                lrs[i << 1 | 1].second};
    }
  }

  LazySegmentTree(const vector<Qt> &xs)
      : LazySegmentTree(len(xs)) {
    copy(all(xs), ts.begin() + n);
    rep(i, 0, n) lrs[i + n] = {i, i};
    rrep(i, n - 1, 0) {
      ts[i] = C(ts[i << 1], ts[i << 1 | 1],
                lrs[i << 1], lrs[i << 1 | 1]);
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
      if (l & 1)
        resl = C(resl, ts[l], lr1, lrs[l]), l++;
      if (r & 1)
        r--, resr = C(ts[r], resr, lrs[r], lr2);
    }
    return C(resl, resr, lr1, lr2);
  }

  void build(int p) {
    while (p > 1) {
      p >>= 1;
      ts[p] = ALQ(C(ts[p << 1], ts[p << 1 | 1],
                    lrs[p << 1], lrs[p << 1 | 1]),
                  ds[p], lrs[p]);
    }
  }

  void push(int p) {
    rrep(s, h, 0) {
      int i = p >> s;
      if (ds[i] != Lt()) {
        apply(i << 1, ds[i]),
            apply(i << 1 | 1, ds[i]);
        ds[i] = Lt();
      }
    }
  }

  inline void apply(int p, Ut v) {
    ts[p] = AUQ(ts[p], v, lrs[p]);
    if (p < n) ds[p] = AUL(ds[p], v, lrs[p]);
  }
};
//}
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
  int N;
  cin >> N;
  vll XS(N);
  trav(xi, XS) cin >> xi;

  if (N == 1) {
    cout << 1 << endl;
    cout << XS.front() << endl;
    cout << endl;
    return;
  }

  vi2d perpos(N + 1);
  rep(i, 0, N) perpos[XS[i]].eb(i);

  vi have(N + 1);
  int distinct = 0;
  vector<QueryT> aux;
  rrep(i, N - 1, 0 - 1) {
    distinct += !have[XS[i]];
    have[XS[i]]++;
    aux.eb(QueryT(distinct));
  }
  reverse(all(aux));
  LazySegmentTree seg(aux);

  vector<QueryT> aux2;
  trav(xi, XS) aux2.pb(QueryT(xi));
  LazySegmentTree segmn(aux2);
  LazySegmentTree segmx(aux2);

  int need = distinct;
  vi ans;
  int p = 0;
  for (; len(ans) < distinct;) {
    function<bool(int)> check = [&](int m) {
      auto q = seg.qry(m, m).v;
      return q >= need;
    };
    int p2 = maxCheck((int)p, (int)N - 1, check);
    dbg(p2);
    /*
    cout << "seg:";
    rep(i, p, p2 + 1) {
      cout << setw(4) << seg.qry(i, i).v;
    }
    cout << endl;
    */
    int bestp = -1;
    int curv;
    if (len(ans) & 1) {
      ll mn = segmn.qry(p, p2).v2;
      function<bool(int)> c = [&](int m) -> bool {
        ll v = segmn.qry(p, m).v2;
        return v <= mn;
      };
      bestp = minCheck(p, p2, c);
      curv = segmn.qry(bestp, bestp).v2;
    } else {
      ll mx = segmx.qry(p, p2).v;
      /*
      cout << "segmx:";
      rep(i, p, p2 + 1) {
        cout << setw(4) << segmx.qry(i, i).v;
      }
      cout << endl;
      */
      function<bool(int)> c = [&](int m) -> bool {
        ll v = segmx.qry(p, m).v;
        dbg(p, m, v);
        return v >= mx;
      };
      bestp = minCheck(p, p2, c);
      dbg(bestp);
      curv = segmx.qry(bestp, bestp).v;
    }

    dbg(curv, perpos[curv]);
    for (auto pv : perpos[curv]) {
      segmn.set(pv, QueryT(N * 4));
      segmx.set(pv, QueryT(-1));
    }
    seg.upd(0, perpos[curv].back(), -1);
    ans.eb(curv);
    p = bestp + 1;
    need--;
  }

  cout << len(ans) << endl;
  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << endl;
}
// AC, greedy, range queries
