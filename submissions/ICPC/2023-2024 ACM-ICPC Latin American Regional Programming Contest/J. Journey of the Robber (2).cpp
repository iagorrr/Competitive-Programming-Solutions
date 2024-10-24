#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1'00'000;
const int OO = 1'000'000;

int N;
vector<int> ADJ[MAXN];
vector<pair<int,int>> ans(MAXN,{OO, OO});


int removed[MAXN];
int sz[MAXN];

int dfsSize(int u, int p = -1) {
	sz[u] = 1;
	for (int v : ADJ[u]) {
		if (v != p and !removed[v]) {
			sz[u] += dfsSize(v, u);
		}
	}
	return sz[u];
}

int findCentroid(int u, int p, int mxSz) {
	for (int v : ADJ[u]) {
		if (v != p and !removed[v] and sz[v] * 2 >= mxSz)
			return findCentroid(v, u, mxSz);
	}
	return u;
}

int depth[MAXN];
vector<int> vs;
void dfs(int u, int p) {
	vs.emplace_back(u);
	for (int v : ADJ[u]) {
		if (v != p and !removed[v]) {
			depth[v] = depth[u] + 1;
			dfs(v, u);
		}
	}
}

void solve(int u) {
	u= findCentroid(u, -1, dfsSize(u));
		
	depth[u] = 0;
	dfs(u, -1);

	sort(vs.rbegin(), vs.rend());
	int highest = -1;
	for (int v : vs) {
		if (~highest) {
			ans[v] = min(ans[v], {depth[v] + depth[highest], highest});
		}


		if (highest == -1 or depth[v] <= depth[highest])
			highest = v;
	}

	vs.clear();

	removed[u] = true;

	for (int v : ADJ[u]) {
		if (!removed[v])
			solve(v);
	}
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(0));
	cin >> N;
	for (int i = 0, u, v; i < N - 1; i++) {
		cin >> u >> v;
		u--, v--;
		ADJ[u].emplace_back(v);
		ADJ[v].emplace_back(u);
	}

	vs.reserve(N);

	
	solve(0);
	ans[N-1].second = N-1;

	for (int i = 0; i < N; i++) {
		cout << ans[i].second + 1 << " \n"[i == N -1];

	}

}

// AC, centroid de composition
