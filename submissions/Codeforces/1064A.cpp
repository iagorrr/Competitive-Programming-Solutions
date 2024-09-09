#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  array<int, 3> xs;
  for (int i = 0; i < 3; i++) cin >> xs[i];
  sort(begin(xs), end(xs));
  cout << max(0, 1 + xs[2] - xs[1] - xs[0])
       << endl;
}
// AC, geometry
