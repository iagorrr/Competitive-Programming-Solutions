#include <bits/stdc++.h>
using namespace std;

// dsu pra unir as colunas
// dsu pra unir as linhas
// produtorio safado
// vapo
#define int long long
struct DSU {
  vector<int> ps, sz;

  // vector<unordered_set<int>> sts;

  DSU(int N) : ps(N + 1), sz(N, 1) /*, sts(N) */ {
    iota(ps.begin(), ps.end(), 0);
    // for (int i = 0; i < N; i++) sts[i].insert(i);
  }
  int find_set(int x) {
    return ps[x] == x ? x : ps[x] = find_set(ps[x]);
  }
  int size(int u) { return sz[find_set(u)]; }
  bool same_set(int x, int y) {
    return find_set(x) == find_set(y);
  }
  void union_set(int x, int y) {
    if (same_set(x, y)) return;

    int px = find_set(x);
    int py = find_set(y);

    if (sz[px] < sz[py]) swap(px, py);

    ps[py] = px;
    sz[px] += sz[py];
    // sts[px].merge(sts[py]);
  }
};


int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int N, K;
	cin >> N >> K;

	vector<vector<int>> xs(N, vector<int>(N));
	for (auto& i : xs)
		for (auto& j : i)
			cin >> j;

	DSU lin(N), col(N);
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			bool okl = true;
			bool okc = true;
			for (int k = 0; k < N; k++) {
				okc &= (xs[k][i] + xs[k][j] <= K);
				okl &= (xs[i][k] + xs[j][k] <= K);
			}

			if (okl) {
				lin.union_set(i, j);
			}
			if (okc) {
				col.union_set(i, j);
			}
			
		}
	}
	
	const int mod = 998244353;

	vector<int> fat(N+1);
	fat[0] = 1;
	for (int i = 1; i <= N; i++) {
		fat[i] = ((long long)fat[i-1]*i) % mod;
	}
	int ans = 1;
	vector<char> donec(N), donel(N);
	for (int i = 0; i < N; i++) {
		int l = lin.find_set(i);
		int szl = lin.sz[l];

		int c = col.find_set(i);
		int szc = col.sz[c];

		if (!donel[l]) ans = ((long long)ans*fat[szl]) % mod;
		if (!donec[c]) ans = ((long long)ans*fat[szc]) % mod;

		donel[l] = donec[c] = true;
	}

	cout << ans << '\n';
}

// AC, math, combinatorics, connected components
