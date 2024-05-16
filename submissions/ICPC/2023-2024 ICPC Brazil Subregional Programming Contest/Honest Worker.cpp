#include <bits/stdc++.h>

#include <climits>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...) 42
#endif
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int)__x.size()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second

int lg2(ll x) {
  return __builtin_clzll(1) - __builtin_clzll(x);
}

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D",
// "LD", "L"}); int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}; int
// dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int T(1);
const int MAXN(1'000'000);

const ll oo = (LLONG_MAX >> 1);
using Lnode = ll;
struct Qnode {
  ll v;
  Qnode() : v(-oo) {}
  Qnode(ll _v) : v(_v) {}
};

using Unode = ll;
struct LSegTree {
  int n, ql, qr;
  vector<Qnode> st;
  vector<Lnode> lz;

  /*---------------------------------------------------------------------*/
  Qnode merge(Qnode lv, Qnode rv, int nl, int nr) {
    return Qnode(max(lv.v, rv.v));
  }

  void prop(int i, int l, int r) {
    st[i].v += lz[i];
    if (l != r) lz[tol(i)] += lz[i], lz[tor(i)] += lz[i];
    lz[i] = 0;
  }

  void applyV(int i, Unode v) { lz[i] += v; }

  /*---------------------------------------------------------------------*/

  LSegTree() {}
  LSegTree(int _n) : n(_n), st(_n << 2), lz(_n << 2) {}
  bool disjoint(int l, int r) { return qr < l or r < ql; }
  bool contains(int l, int r) {
    return ql <= l and r <= qr;
  }
  int tol(int i) { return i << 1; }
  int tor(int i) { return i << 1 | 1; }
  void build(vector<Qnode> &v) { build(v, 1, 0, n - 1); }
  void build(vector<Qnode> &v, int i, int l, int r) {
    if (l == r) {
      st[i] = v[l];
      return;
    }
    int m = midpoint(l, r);
    build(v, tol(i), l, m);
    build(v, tor(i), m + 1, r);
    st[i] = merge(st[tol(i)], st[tor(i)], l, r);
  }
  void upd(int l, int r, Unode v) {
    ql = l, qr = r;
    upd(1, 0, n - 1, v);
  }
  void upd(int i, int l, int r, Unode v) {
    prop(i, l, r);
    if (disjoint(l, r)) return;
    if (contains(l, r)) {
      applyV(i, v);
      prop(i, l, r);
      return;
    }
    int m = midpoint(l, r);
    upd(tol(i), l, m, v);
    upd(tor(i), m + 1, r, v);
    st[i] = merge(st[tol(i)], st[tor(i)], l, r);
  }
  Qnode qry(int l, int r) {
    ql = l, qr = r;
    return qry(1, 0, n - 1);
  }
  Qnode qry(int i, int l, int r) {
    prop(i, l, r);
    if (disjoint(l, r)) return Qnode();
    if (contains(l, r)) return st[i];
    int m = midpoint(l, r);
    return merge(qry(tol(i), l, m), qry(tor(i), m + 1, r),
                 l, r);
  }

  // optional
  void print(int l, int r) {
    for (int i = l; i <= r; i++) {
      cout << i << " : " << qry(i, i).v << "\n";
    }
  }
};

auto run() {
  ll N, perday;
  cin >> N >> perday;

  LSegTree segtree(N + 1);
  vector<array<ll, 3>> jobs(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> jobs[i][0] >> jobs[i][1] >> jobs[i][2];
    jobs[i][1]++;
  }

  map<ll, vector<ll>> events;
  for (int i = 1; i <= N; i++) {
    auto [l, r, c] = jobs[i];
    events[l].eb(i), events[r].eb(-i);
  }

  ll ans = 0, topdotop = 0, pt = 1;
  for (auto &[t, evi] : events) {
    // update
    int dt = t - pt;
    segtree.upd(1, N, dt * perday);
    ans = max(ans, segtree.qry(1, N).v);

    // open guys
    for (auto ei : evi) {
      if (ei > 0) {
        ll best = -jobs[ei][2];
        best += ans;
        segtree.upd(ei, ei, -segtree.qry(ei, ei).v);
        segtree.upd(ei, ei, best);
      }
    }

    // close guys
    for (auto &ei : evi) {
      if (ei < 0) {
        ei = -ei;
        segtree.upd(ei, ei, -segtree.qry(ei, ei).v);
        segtree.upd(ei, ei, -oo);
      }
    }

    pt = t;
  }

  cout << ans << '\n';
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> T;

  for (int i = 1; i <= T; i++) {
    run();
  }
}

/*
 * AC
 * Data strcutres
 * Seg tree
 * https://codeforces.com/gym/104555/problem/H
 * */
