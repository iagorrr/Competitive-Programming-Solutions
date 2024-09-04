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
#define trav(xi, xs) for (auto& xi : xs)
#define rtrav(xi, xs) \
  for (auto& xi : ranges::views::reverse(xs))
using ll = long long;
#define inte ll
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
inline bool chmax(T& a, U const& b) {
  return (a < b ? a = b, 1 : 0);
}
template <typename T, typename U>
inline bool chmin(T& a, U const& b) {
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

const double EPS{1e-4};

template <typename T>
bool equals(T a, T b) {
  if (std::is_floating_point<T>::value)
    return fabs(a - b) < EPS;
  else
    return a == b;
}

/*8<
    @Problems:
        https://vjudge.net/problem/AtCoder-abc259_b
        https://atcoder.jp/contests/abc181/tasks/abc181_c?lang=en
>8*/
template <class T>
int sgn(T x) {
  return (x > 0) - (x < 0);
}
template <class T>
struct Point {
  typedef Point P;
  T x, y;
  explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
  bool operator<(P p) const {
    return tie(x, y) < tie(p.x, p.y);
  }
  bool operator==(P p) const {
    return tie(x, y) == tie(p.x, p.y);
  }
  P operator+(P p) const {
    return P(x + p.x, y + p.y);
  }
  P operator-(P p) const {
    return P(x - p.x, y - p.y);
  }
  P operator*(T d) const {
    return P(x * d, y * d);
  }
  P operator/(T d) const {
    return P(x / d, y / d);
  }
  T dot(P p) const { return x * p.x + y * p.y; }
  T cross(P p) const { return x * p.y - y * p.x; }
  T cross(P a, P b) const {
    return (a - *this).cross(b - *this);
  }
  T dist2() const { return x * x + y * y; }
  double dist() const {
    return sqrt((double)dist2());
  }
  // angle to x-axis in interval [-pi, pi]
  double angle() const { return atan2(y, x); }
  P unit() const {
    return *this / dist();
  }  // makes dist()=1
  P perp() const {
    return P(-y, x);
  }  // rotates +90 degrees
  P normal() const { return perp().unit(); }
  // returns point rotated 'a' radians ccw around
  // the origin
  P rotate(double a) const {
    return P(x * cos(a) - y * sin(a),
             x * sin(a) + y * cos(a));
  }
  friend ostream& operator<<(ostream& os, P p) {
    return os << "(" << p.x << "," << p.y << ")";
  }
};

template <typename T>
struct Line {
  T a, b, c;
  Line(T a = 0, T b = 0, T c = 0)
      : a(a), b(b), c(c) {}
  Line(const Point<T>& p, const Point<T>& q) {
    assert(p != q);
    a = p.y - q.y;
    b = q.x - p.x;
    c = p.cross(q);
  }
  bool operator==(const Line<T>& other) const {
    return tie(a, b, c) ==
           tie(other.a, other.b, other.c);
  }
  // less/greater operator so you can make a
  // set/map of Line :D
  bool operator<(const Line& rhs) const {
    return tie(a, b, c) <
           tie(rhs.a, rhs.b, rhs.c);
  }
  bool operator>(const Line& rhs) const {
    return rhs < *this;
  }
  Line<T> norm() {
    T d = a == 0 ? b : a;
    return Line(a / d, b / d, c / d);
  }
  bool contains(const Point<T>& p) {
    return equals(a * p.x + b * p.y + c, (T)0);
  }

  friend ostream& operator<<(ostream& os,
                             Line l) {
    return os << fixed << setprecision(6) << "("
              << l.a << "," << l.b << "," << l.c
              << ")";
  }
};

void run() {
  int N, K;
  cin >> N >> K;
  if (K == 1) {
    cout << "Infinity" << endl;
    return;
  }
  vector<Point<ld>> PS;
  map<int, int> histx;
  rep(i, 0, N) {
    int x, y;
    cin >> x >> y;
    histx[x]++;
    PS.eb(x, y);
  }
  set<Line<ld>> st;
  rep(i, 0, N) {
    rep(j, 0, N) {
      if (i == j) continue;
      auto l = Line(PS[i], PS[j]);
      auto l2 = l.norm();
      int tot = 0;
      trav(pk, PS) { tot += l2.contains(pk); }
      dbg(i, j, l2, tot);
      if (tot >= K) st.insert(l2);
    }
  }
  dbg(st);
  auto ans = len(st);
  cout << ans << endl;
}

/*8<
 AC, geometry
>8*/