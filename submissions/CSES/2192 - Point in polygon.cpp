#include <bits/stdc++.h>
using namespace std;

using ld = long double;
template <typename T>
using Point = pair<T, T>;
#define x first
#define y second

const double EPS{1e-9};
const ld PI = acos(-1);

template <typename T>
bool equals(T a, T b) {
  if (std::is_floating_point<T>::value)
    return fabs(a - b) < EPS;
  else
    return a == b;
}

template <typename T>
bool equals(Point<T> a, Point<T> b) {
  if (std::is_floating_point<T>::value)
    return fabs(a.x - b.x) < EPS &&
           fabs(a.y - b.y) < EPS;
  else
    return a == b;
}
/*8<
  @Description: checks if the point $p$ is inside
the polygon with vertices in $pts$, works for both
convex and concave polygons. >8*/
/*8<
  @Description: Computes the angle apb in radians
  @Warning: $a$ is equal to $b$ then the angle
isn't defined. >8*/
template <typename T>
ld angle(const Point<T>& p, const Point<T>& a,
         const Point<T>& b) {
  auto ux = p.x - a.x;
  auto uy = p.y - a.y;

  auto vx = p.x - b.x;
  auto vy = p.y - b.y;

  auto num = ux * vx + uy * vy;
  auto den = hypot(ux, uy) * hypot(vx, vy);

  return acos(num / den);
}
template <typename T>
T determinant(const Point<T>& p,
              const Point<T>& q,
              const Point<T>& r) {
  return (p.x * q.y + p.y * r.x + q.x * r.y) -
         (r.x * q.y + r.y * p.x + q.x * p.y);
}

template <typename T>
bool contains(const vector<Point<T>>& pts,
              const Point<T>& p) {
  int n = size(pts);
  if (n < 3) return false;  // may treat it appart
  T sum = 0.0;
  for (int i = 0; i < n; i++) {
    auto d =
        determinant(p, pts[i], pts[(i + 1) % n]);
    auto a = angle(p, pts[i], pts[(i + 1) % n]);
    sum += d > 0 ? a : (d < 0 ? -a : 0);
  }
  return equals((ld)fabs(sum), (2 * PI));
}

template <typename T>
T cross(const Point<T>& p, const Point<T>& q) {
  return p.x * q.y - p.y * q.x;
}

template <typename T>
inline tuple<T, T, T> defineLine(
    const Point<T>& p, const Point<T>& q) {
  return {p.y - q.y, q.x - p.x, cross(p, q)};
}

template <typename T>
bool lineContainsPoint(const Point<T>& r,
              const Point<T>& p,
              const Point<T>& q) {
  auto [a, b, c] = defineLine(p, q);
  return equals((T)0, a * r.x + b * r.y + c);
}
template <class P>
bool segmentContainsPoint(const P& p, const P& a, const P& b) {
  auto xmin = min(a.x,b.x);
  auto xmax = max(a.x,b.x);

  auto ymin = min(a.y,b.y);
  auto ymax = max(a.y,b.y);

  if (p.x < xmin or p.x > xmax or p.y < ymin or p.y > ymax)
    return false;
  return equals((p.y-a.y)*(b.x-a.x), (p.x-a.x)*(b.y-a.y));
}

template <typename T>
int pointInPolygon(const vector<Point<T>>& pts,
                   const Point<T> p) {
  if (contains(pts, p)) return 1;
  int n = size(pts);
  for (int i = 0; i < n; i++) {
    if (segmentContainsPoint(p, pts[i], pts[(i + 1) % n])) {
      return 2;
    }
  }
  return 0;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  const string output[]{"OUTSIDE", "INSIDE",
                        "BOUNDARY"};
  int n, m;
  cin >> n >> m;
  vector<Point<ld>> pts(n);
  for (auto& [x, y] : pts) cin >> x >> y;
  while (m--) {
    Point<ld> q;
    cin >> q.x >> q.y;
    cout << output[pointInPolygon(pts, q)]
         << '\n';
  }
}

