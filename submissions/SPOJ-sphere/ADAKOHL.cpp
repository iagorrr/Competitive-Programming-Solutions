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
using ll = long long;
#define rep(i, a, b) \
  for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) \
  for (ll i = (a); i > (b); i--)
#define trav(xi, xs) for (auto& xi : xs)
#define rtrav(xi, xs) \
  for (auto& xi : ranges::views::reverse(xs))
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

  cin >> T;

  rep(t, 0, T) {
    dbg(t);
    run();
  }
}
/*8<==========================================>8*/
/*8<
    @Problems:
        https://vjudge.net/problem/AtCoder-abc259_b
        https://atcoder.jp/contests/abc181/tasks/abc181_c?lang=en
        https://atcoder.jp/contests/abc248/tasks/abc248_e
        https://codeforces.com/problemset/problem/127/A
        https://cses.fi/problemset/task/2189
        https://cses.fi/problemset/task/2190
>8*/
const double EPS{1e-4};

template <class Point>
vector<Point> segInter(Point a, Point b, Point c,
                       Point d);
template <typename T>
bool equals(T a, T b) {
  if (std::is_floating_point<T>::value)
    return fabs(a - b) < EPS;
  else
    return a == b;
}

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
  pair<T,T> slope(const Point<T>&o){
    auto a=o.x-x;
    auto b=o.y-y;
    if (!is_floating_point<T>::value){
      auto g=__gcd(a,b);
      if(g)a/=g,b/=g;

    }
    return {b,a};

  }
  friend ostream& operator<<(ostream& os, P p) {
    return os << "(" << p.x << "," << p.y << ")";
  }
};

template <typename T>
struct Line {
  T a, b, c;
  Point<T> p1, p2;
  Line(T a = 0, T b = 0, T c = 0)
      : a(a), b(b), c(c) {
    if (a != 0) {
      double x = 0;
      double y = (-c) / b;
      p1 = Point<T>(x, y);
    }

    if (b != 0) {
      double y = 0;
      double x = (-c) / a;
      p2 = Point<T>(x, y);
    }
  }
  Line(const Point<T>& p, const Point<T>& q) {
    assert(p != q);
    a = p.y - q.y;
    b = q.x - p.x;
    c = p.cross(q);
    p1 = p, p2 = q;
  }
  bool operator==(const Line<T>& other) const {
    return tie(a, b, c) ==
           tie(other.a, other.b, other.c);
  }
  // Less-than operator
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
  T direction(const Point<T>& p3) {
    return p1.cross(p2, p3);
  }
  friend ostream& operator<<(ostream& os,
                             Line l) {
    return os << fixed << setprecision(6) << "("
              << l.a << "," << l.b << "," << l.c
              << ")";
  }
};

template <typename T>
struct LineSegment {
  Point<T> p1, p2;
  LineSegment(const Point<T>& p,
              const Point<T>& q) {
    // assert(p != q);
    p1 = p, p2 = q;
  }

  LineSegment(T a, T b, T c, T d)
      : LineSegment(Point<T>(a, b),
                    Point<T>(c, d)) {}
  bool operator==(
      const LineSegment<T>& other) const {
    return tie(p1, p2) == tie(other.p1, other.p2);
  }
  // Less-than operator
  bool operator<(const LineSegment& rhs) const {
    return tie(p1, p2) < tie(rhs.p1, rhs.p2);
  }
  bool operator>(const LineSegment& rhs) const {
    return rhs < *this;
  }
  T direction(const Point<T>& p3) {
    return p1.cross(p2, p3);
  }
  friend ostream& operator<<(ostream& os,
                             LineSegment l) {
    return os << "(" << l.p1 << "," << l.p2
              << ")";
  }
  vector<Point<T>> intersection(
      const LineSegment<T>& other) {
    return segInter(p1, p2, other.p1, other.p2);
  }
};

template <typename T>
ld euclidianDistance(const Point<T>& a,
                     const Point<T>& b) {
  return hypot(a.x - b.x, a.y - b.y);
}

template <class Point>
bool onSegment(Point s, Point e, Point p) {
  return p.cross(s, e) == 0 &&
         (s - p).dot(e - p) <= 0;
}

template <class Point>
vector<Point> segInter(Point a, Point b, Point c,
                       Point d) {
  auto oa = c.cross(d, a), ob = c.cross(d, b),
       oc = a.cross(b, c), od = a.cross(b, d);
  // Checks if intersection is single non-endpoint
  // point.
  if (sgn(oa) * sgn(ob) < 0 &&
      sgn(oc) * sgn(od) < 0)
    return {(a * ob - b * oa) / (ob - oa)};
  set<Point> s;
  if (onSegment(c, d, a)) s.insert(a);
  if (onSegment(c, d, b)) s.insert(b);
  if (onSegment(a, b, c)) s.insert(c);
  if (onSegment(a, b, d)) s.insert(d);
  return {all(s)};
}
/*8<==========================================>8*/

void run() {
  int N;cin>>N;
  vector<Point<ll>> XS;XS.reserve(N);
  vll QS(N);
  rep(i,0,N){
    ll x,y;cin>>x>>y;
    cin>>QS[i];
    XS.eb(x,y);
  }
  ll ans=0;
  rep(i,0,N){
    map<pair<int,int>,ll> acc;
    rep(j,0,N){
      if(i!=j){
        acc[XS[i].slope(XS[j])]+=QS[j];
      }
    }
    dbg(acc);
    for(auto&k:acc)chmax(ans,k.second+QS[i]);
    chmax(ans,QS[i]);
  }
  cout<<ans<<endl;
}

/*8<
>8*/
