#include <bits/stdc++.h>
using namespace std;

const long double EPS = 1e-9;
void run() {
  long double a, b, c, d;
  cin >> a >> b >> c >> d;
  long double w1 = (d * d - b * b + a * a -
                    2 * a * c + c * c) /
                   (2 * a - 2 * c);
  long double h = sqrt(d * d - (w1 * w1));
  cout << fixed << setprecision(10)
       << ((a + c) * h) / 2.0 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case " << i << ": ";
    run();
  }
}

// AC, geometry
