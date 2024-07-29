#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> min_vertex_cover(vector<vector<int>> &g, int n, int m) {
	vector<int> match(m, -1), vis;

	auto  find = [&](auto&& self, int j) -> bool {
		if (match[j] == -1)
		       	return 1;

		       	// pretend isn't
		vis[j] = 1;
	       	int di = match[j];
		for (int e : g[di])
			if (!vis[e] and self(self, e)) {
				match[e] = di;
				return 1;
			}
		return 0;
	};

	for (int i = 0; i < (int)g.size(); i++) {
		vis.assign(match.size(), 0);
		for (int j : g[i]) {
			if (find(find, j)) {
				match[j] = i;
				break;
			}
		}
	}

	int res = (int)match.size() - (int)count(match.begin(), match.end(), -1);


	vector<char> lfound(n, true), seen(m);
	for (int it : match)
	       	if (it != -1)
		       	lfound[it] = false;

	vector<int> q, cover;
	for (int i = 0; i < n; i++)
		if (lfound[i])
			q.push_back(i);

	while (!q.empty()) {
		int i = q.back(); q.pop_back();
		lfound[i] = 1;
		for (int e : g[i])
		       	if (!seen[e] and match[e] != -1) {
				seen[e] = true;
				q.push_back(match[e]);
			}
	}

	for (int i = 0; i < n; i++)
	       	if (!lfound[i])
			cover.push_back(i);

	for (int i = 0; i < m; i++)
	       	if (seen[i])
			cover.push_back(n+i);

	assert((int)size(cover) == res);

	return cover;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> mat(n, vector<int>(n, -1));
	int w = 0, b = 0;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		if ((u+v)&1) mat[u][v] = w++;
		else mat[u][v] = b++;
	}
	vector<pair<int, int>> dir = {
		{-2, -1}, {-2, 1}, {-1, 2}, {-1, -2},
		{1, 2}, {1, -2}, {2, -1}, {2, 1}
	};
	vector<vector<int>> g(w);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == -1  or !((i+j)&1)) continue;
			for (auto [dx, dy] : dir) {
				auto x = dx +i;
				auto y = dy + j;
				if (0 <= x and x < n and 0 <= y and y < n and mat[x][y] != -1) {
					g[mat[i][j]].push_back(mat[x][y]);
				}
			}
		}
	}

	auto res = min_vertex_cover(g, w, b);
	cout << res.size() << '\n';
}

// AC, graphs, min vertex cover
