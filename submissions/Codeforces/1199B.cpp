#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  double h, l;
  cin >> h >> l;
  double a = (l * l - h * h) / (2.0 * h);
  cout << fixed << setprecision(10) << a << endl;
}
// AC, geometry
