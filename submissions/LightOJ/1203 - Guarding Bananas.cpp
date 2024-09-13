#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()

template <typename T>
using Point = pair<T, T>;
#define x first
#define y second

template <typename T>
T det2(const Point<T>& a, const Point<T>& b,
       const Point<T>& c) {
  return a.x * b.y + a.y * +c.x + b.x * c.y -
         c.x * b.y - c.y * a.x - b.x * a.y;
}

template <typename T>
vector<Point<T>> convexHull(
    vector<Point<T>> pts) {
  if (len(pts) <= 1) return pts;
  sort(all(pts));
  vector<Point<T>> h(len(pts) + 1);
  int s = 0, t = 0;
  for (int it = 2; it--;
       s = --t, reverse(all(pts)))
    for (Point<T> p : pts) {
      while (t >= s + 2 &&
             det2(h[t - 2], h[t - 1], p) <= 0)
        t--;
      h[t++] = p;
    }
  return {
      h.begin(),
      h.begin() + t - (t == 2 && h[0] == h[1])};
}

template <typename T>
double angle(const Point<T>& p, const Point<T>& a,
             const Point<T>& b) {
  auto ux = p.x - a.x;
  auto uy = p.y - a.y;

  auto vx = p.x - b.x;
  auto vy = p.y - b.y;

  auto num = ux * vx + uy * vy;
  auto den = hypot(ux, uy) * hypot(vx, vy);

  return acos(num / den);
}

void run() {
  int n;
  cin >> n;
  vector<Point<ll>> pts(n);
  for (auto& pi : pts) cin >> pi.x >> pi.y;
  auto ch = convexHull(pts);
  int m = len(ch);
  if (m < 3) {
    cout << 0.0 << '\n';
    return;
  }
  double ans = 10000;
  for (int i = 0; i < m; i++) {
    vector<Point<double>> tmp;
    tmp.push_back(Point<double>{(double)ch[i].x,
                                (double)ch[i].y});
    tmp.push_back(
        Point<double>{(double)ch[(i + 1) % m].x,
                      (double)ch[(i + 1) % m].y});
    tmp.push_back(
        Point<double>{(double)ch[(i + 2) % m].x,
                      (double)ch[(i + 2) % m].y});
    auto a = angle(tmp[1], tmp[0], tmp[2]);
    ans = min(ans, a / (M_PI / 180));
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(10);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case " << i << ": ";
    run();
  }
}


// AC, geometry
