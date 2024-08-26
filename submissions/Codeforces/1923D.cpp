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
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) \
  for (auto &xi : ranges::views::reverse(xs))
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

template <typename T = ll,
          auto cmp =
              [](T &src1, T &src2, T &dst) {
                dst = min(src1, src2);
              }>
class SparseTable {
 private:
  int sz;
  vi logs;
  vector<vector<T>> st;

 public:
  SparseTable(const vector<T> &v)
      : sz(len(v)), logs(sz + 1) {
    rep(i, 2, sz + 1) logs[i] = logs[i >> 1] + 1;
    st.resize(logs[sz] + 1, vector<T>(sz));
    rep(i, 0, sz) st[0][i] = v[i];
    for (int k = 1; (1 << k) <= sz; k++) {
      for (int i = 0; i + (1 << k) <= sz; i++) {
        cmp(st[k - 1][i],
            st[k - 1][i + (1 << (k - 1))],
            st[k][i]);
      }
    }
  }
  T query(int l, int r) {
    r++;
    const int k = logs[r - l];
    T ret;
    cmp(st[k][l], st[k][r - (1 << k)], ret);
    return ret;
  }
};
/*8<
  @Title: Max \& Min Check

  @Description: Returns the min/max value in range
  [l, r] that satisfies the lambda function check,
  if there is no such value the 'nullopt' is
  returned.

  @Usage: check must be a function that receives
  an integer and return a boolean.

  @Time: $O(\log{r-l+1})$
>8*/

template <typename T>
optional<T> maxCheck(T l, T r, auto check) {
  optional<T> ret;
  while (l <= r) {
    T m = midpoint(l, r);
    if (check(m))
      ret ? chmax(ret, m) : ret = m, l = m + 1;
    else
      r = m - 1;
  }
  return ret;
}

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

template <typename T = ll,
          auto op =
              [](const T &src1, const T &src2,
                 T &dst) { dst = src1 + src2; },
          auto invop =
              [](const T &src1, const T &src2,
                 T &dst) { dst = src1 - src2; }>
struct StaticRangeQueries {
  vector<T> acc;
  StaticRangeQueries(const vector<T> &XS)
      : acc(len(XS)) {
    acc[0] = XS[0];
    rep(i, 1, len(XS)) {
      op(acc[i - 1], XS[i], acc[i]);
    }
  }
  T operator()(int l, int r) {
    T lv = (l ? acc[l - 1] : T());
    T ret;
    invop(acc[r], lv, ret);
    dbg(acc[r], lv);
    dbg(l, r, ret);
    return ret;
  }
};

void run() {
  int N;
  cin >> N;
  vll XS(N);
  trav(xi, XS) cin >> xi;
  SparseTable<ll,
              [](ll &src1, ll &src2, ll &dst) {
                dst = max(src1, src2);
              }>
      mxq(XS);
  SparseTable<ll> mnq(XS);
  StaticRangeQueries ssum(XS);
  vi ans(N);
  rep(i, 0, N) {
    ans[i] =
        minCheck((int)1, N, [&](int m) -> bool {
          bool left = false;
          if (i) {
            int l = max(0ll, i - m);
            int r = max(0ll, i - 1);
            left = (mxq.query(l, r) !=
                    mnq.query(l, r)) &&
                   (ssum(l, r) > XS[i]);
            left |= XS[i - 1] > XS[i];
          }
          bool right = false;
          if (i + 1 < N) {
            int l = min(i + 1, N - 1);
            int r = min(i + m, N - 1);
            right = (mxq.query(l, r) !=
                     mnq.query(l, r)) &&
                    (ssum(l, r) > XS[i]);
            right |= XS[i + 1] > XS[i];
          }
          return left || right;
        }).value_or(-1);
  }
  trav(xi, ans) cout << xi << ' ';
  cout << endl;
}

/*8<
>8*/

