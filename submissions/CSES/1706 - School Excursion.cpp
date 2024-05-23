#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
#define all(x) x.begin(), x.end()

struct DSU {
  vi ps, sz;

  // vector<unordered_set<int>> sts;

  DSU(int N) : ps(N + 1), sz(N, 1) /*, sts(N) */ {
    iota(all(ps), 0);
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

const int maxn = 1'00'000;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	DSU dsu(n);
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		a--, b--;

		dsu.union_set(a, b);
	}

	bitset<maxn> used;
	vector<int> szs;
	for (int i = 0; i < n; i++) {
		int si = dsu.find_set(i);
		if (used[si]) continue;
		used[si] = 1;
		szs.emplace_back(dsu.size(si));
	}

	bitset<2*maxn+1> ans;
	ans[0] = 1;
	for (auto sz : szs) {
		ans |= (ans<<sz);
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i];
	}
	cout << '\n';
}

// AC, connected components, bitset
