#include <bits/stdc++.h>
using namespace std;

void run() {
  int n;
  cin >> n;
  vector<int> xs(n);
  for (auto& xi : xs) cin >> xi;
  for (auto& xi : xs) xi *= 2;
  set<int> areas;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      areas.emplace(xs[j] - xs[i]);
    }
  }
  cout << areas.size() << '\n';
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

// AC, math, brute force, geometry
