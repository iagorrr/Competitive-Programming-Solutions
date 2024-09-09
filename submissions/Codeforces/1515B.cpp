#include <bits/stdc++.h>
using namespace std;
void run() {
  int n;
  cin >> n;
  bool ans = false;
  if (n % 2 == 0)
    for (int i = 1; i * i <= n / 2; i++) {
      if ((((n / 2) % i) == 0) &&
          ((n / 2) / i) == i)
        ans |= true;
    }
  if (n % 4 == 0)
    for (int i = 1; i * i <= n / 4; i++) {
      if ((((n / 4) % i) == 0) &&
          ((n / 4) / i) == i)
        ans |= true;
    }

  cout << (ans ? "YES" : "NO") << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    run();
  }
}

// AC, geometry
