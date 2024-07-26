#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, X;
	cin>> N >> X; X--;

	vector<int> SS(N);
	for (auto& si : SS) {
		cin >> si;
		si = si % N;
	}

	vector<int> ans(N, -1);
	using pii = pair<int,int>;
	queue<pii> q;
	q.emplace(X, 0);
	vector<set<int>> vis(N+1);

	ans[X] = 0;
	
	vis[gcd(SS[X], N)].emplace(X%(gcd(SS[X],N)));
	
	while (!q.empty()) {
		auto [u, du] = q.front();
		auto su = SS[u];
		q.pop();

		int nu = (u + su) % N;

		while (nu != u) {
			if (ans[nu] == -1) {
				ans[nu] = du + 1;
				int m = gcd(SS[nu], N);
				if (!vis[m].count(nu%m)) {
					q.emplace(nu, du+1);
					vis[m].emplace(nu%m);
				}
			}
			nu = (nu + su) % N;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << " \n"[i==N-1];
	}
}

// AC, bfs, number theory
