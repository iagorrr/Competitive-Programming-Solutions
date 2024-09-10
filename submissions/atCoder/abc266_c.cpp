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

template <typename T>
T determinant(const Point<T>& p,
              const Point<T>& q,
              const Point<T>& r) {
  return (p.x * q.y + p.y * r.x + q.x * r.y) -
         (r.x * q.y + r.y * p.x + q.x * p.y);
}

template <typename T>
bool checkIfPolygonIsConvex(
    vector<Point<T>>& pts) {
  int n = size(pts);
  if (n < 3) return false;
  int l, g, e;
  l = g = e = 0;
  for (int i = 0; i < n; i++) {
    auto d = determinant(pts[i], pts[(i + 1) % n],
                         pts[(i + 2) % n]);
    d ? (d > 0 ? g++ : l++) : e++;
  }
  return l == n or g == n;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<Point<ld>> pts(4);
  for (auto& [x, y] : pts) cin >> x >> y;
  if (checkIfPolygonIsConvex(pts))
    cout << "Yes" << '\n';
  else
    cout << "No" << '\n';
}

// AC,geometry
