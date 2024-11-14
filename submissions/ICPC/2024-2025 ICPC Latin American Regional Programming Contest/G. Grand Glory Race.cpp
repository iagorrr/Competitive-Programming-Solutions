#include <bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second


const int OO = 1'000'000'000;
const int MAXN = 1'00'000;
using t3int = tuple<int,int,int>;
using pii = pair<int,int>;

int N, Q;
vector<pii> ADJ[MAXN];
int ans[MAXN], totPoints[MAXN], vis[MAXN];
pii ps[MAXN];
vector<pii> queryInNode[MAXN];
vector<pii> conquer(MAXN, {OO, OO});

int root;

void getParents(int u = root, int p = -1) {
	for (auto [v, w] : ADJ[u]) {
		if (v != p) {
			ps[v] = {u, w};
			getParents(v, u);
		}
	}
}

pii calc(int u = root, int p = -1) {
	if (conquer[u].x != OO) return conquer[u];

	if (ADJ[u].size() == 1) {
		totPoints[u]++;
		return conquer[u] = {0, u};
	}

	for (auto [v, w] : ADJ[u]) {
		if (v != p) {
			auto [d, c] = calc(v, u);
			d += w;
			conquer[u] = min(conquer[u], {d,c});
		}
	}

	totPoints[conquer[u].y]++;
	return conquer[u];
}

void solve(int u = root, int p = -1) {
	for (auto [v, i] : queryInNode[u]) {
		ans[i] = totPoints[v];
	}

	pii secondBest {OO, OO};
	for (auto [v, w] : ADJ[u]) {
		if (conquer[u].y != conquer[v].y)
			secondBest = min(secondBest, {conquer[v].x + w, conquer[v].y});
	}


	auto prevU = conquer[u];
	for (auto [v, w] : ADJ[u]) if (v != p) {
		auto prevV = conquer[v];

		auto fromU = conquer[u].y != conquer[v].y ? conquer[u] : secondBest;

		{
			if (conquer[u].y == conquer[v].y) {
				totPoints[conquer[u].y]--;
				conquer[u] = secondBest;
				totPoints[conquer[u].y]++;
			}
		}

		{
			auto [d, c] = fromU;
			d += w;
			totPoints[conquer[v].y]--;
			conquer[v] = min(conquer[v], {d, c});
			totPoints[conquer[v].y]++;
		}

		solve(v, u);

		totPoints[conquer[v].y]--;
		conquer[v] = prevV;
		totPoints[conquer[v].y]++;

		totPoints[conquer[u].y]--;
		conquer[u] = prevU;
		totPoints[conquer[u].y]++;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0, u, v, l; i < N - 1; i++) {
		cin >> u >> v >> l;
		u--, v--;
		ADJ[u].emplace_back(v, l);
		ADJ[v].emplace_back(u, l);
	}

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		queryInNode[v].emplace_back(u, i);
	}

	for (int i = 0; i < N; i++) {
		if (ADJ[i].size() > 1u)
			root = i;
	}
	
	calc(root, -1);
	
	solve();

	for (int i = 0; i < Q; i++) {
		cout << ans[i] << '\n';
	}

}

/*
   Trees
 */
