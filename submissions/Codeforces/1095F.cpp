#include <bits/stdc++.h>
using namespace std;


using ll = long long;

const int maxn = 2'00'000;

vector<pair<ll,int>> G[maxn];
const int MAXN(2'00'000);
int N;
using vi = vector<int>;
ll prim(vi s = vi(1, 0)) {
  priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                 greater<pair<ll, int>>>
    pq;
  vector<char> ingraph(MAXN);
  int ingraphcnt(0);
  for (auto si : s) {
    ingraphcnt++;
    ingraph[si] = true;
    for (auto &[w, v] : G[si]) pq.emplace(w, v);
  }

  ll mstcost = 0;
  while (ingraphcnt < N and !pq.empty()) {
    ll w;
    int v;

    do {
      tie(w, v) = pq.top();
      pq.pop();
    } while (not pq.empty() and ingraph[v]);

    mstcost += w, ingraph[v] = true, ingraphcnt++;

    for (auto &[w2, v2] : G[v]) {
      pq.emplace(w2, v2);
    }
  }

  return mstcost;
}

auto run() {
	int n, m;
	cin >> n >> m;

	N = n;

	vector<ll> cs(n);
	for (auto &ci : cs)
		cin >> ci;


	for (int i = 0; i < m; i++) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		u--, v--;
		G[u].emplace_back(w, v);
		G[v].emplace_back(w, u);
	}

	int idx_min = min_element(cs.begin(), cs.end())- cs.begin();

	for (int i = 0; i < n; i++) {
		if (i == idx_min) continue;
		G[i].emplace_back(cs[i] + cs[idx_min], idx_min);
		G[idx_min].emplace_back(cs[i] + cs[idx_min], i);
	}

	cout << prim() << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}

// AC, graphs, mst
