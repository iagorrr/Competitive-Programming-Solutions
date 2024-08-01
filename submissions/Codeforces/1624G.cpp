#include <bits/stdc++.h>
using namespace std;
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

auto run() {
	int N, M;
	cin >> N >> M;

	using Edge = pair<int, int>;
	vector<vector<Edge>> ADJ(N);
	for (int m = 0; m < M; m++){
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		ADJ[u].emplace_back(v, w);
		ADJ[v].emplace_back(u, w);
	}

	int ans = (long long)(1ll<<31ll)-1;
	for (int b = 30; b >= 0; b--) {
		DSU dsu(N);

		ans ^= (1<<b);
		for (int u = 0; u < N; u++) {
			for (auto [v, w] : ADJ[u]) {
				if ((w & ans) == w)
					dsu.union_set(u, v);
			}
		}
		if (dsu.size(0) != N) {
			ans ^= (1<<b);
		}
	}
	
	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		run();
	}
}

/*
	coloca todos que for 0 enquanto der, quando não achar mais
	coloca o menor custo que da pra por cada um e pega o menor
	e orda a partir dele ?

	n né 
	pode ter descoberto outros hkjk
	volta na recurção 

	AC, bitwise operations, greddy, graphs
 */

