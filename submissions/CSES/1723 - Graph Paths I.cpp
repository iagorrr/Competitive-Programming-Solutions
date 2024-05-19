#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const ll MOD = 1'000'000'007;
 
#define len(x) (int)x.size()
 
template <typename T>
vector<vector<T>> prod(vector<vector<T>> &a,
                       vector<vector<T>> &b) {
  int n = len(a);
  vector<vector<T>> c(n, vector<T>(n));
 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        c[i][j] =
          (c[i][j] + ((a[i][k] * b[k][j]) % MOD)) % MOD;
      }
    }
  }
 
  return c;
}
 
template <typename T>
vector<vector<T>> fpow(vector<vector<T>> &xs, ll p) {
  vector<vector<T>> ans(len(xs), vector<T>(len(xs)));
  for (int i = 0; i < len(xs); i++) ans[i][i] = 1;
 
  auto b = xs;
  while (p) {
    if (p & 1) ans = prod(ans, b);
    p >>= 1;
    b = prod(b, b);
  }
  return ans;
}
 
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	int n ,m, k;
	cin >> n >> m >> k;
 
	vector<vector<ll>> ways(n, vector<ll>(n));
 
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		a--, b--;
 
		ways[a][b]++;
	}
 
	ways = fpow(ways, k);
 
	cout << ways[0][n-1] << '\n';
}
