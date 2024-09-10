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

long long area(
    const vector<Point<long long>>& pts) {
  long long a = 0.0;
  int n = size(pts);
  for (int i = 0; i < n; i++) {
    a += pts[i].x * pts[(i + 1) % n].y;
    a -= pts[i].y * pts[(i + 1) % n].x;
  }
  return llabs(a);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<Point<long long>> pts(n);
  for (auto& [x, y] : pts) cin >> x >> y;
  cout << area(pts) << '\n';
}

// AC, geometry
