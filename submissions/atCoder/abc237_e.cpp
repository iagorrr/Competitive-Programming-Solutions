/*~=========================BEGIN MACRO=================================~*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define endl '\n'

#define fastio                        \
        ios_base::sync_with_stdio(0); \
        cin.tie(0);

#define int long long

#define all(j) j.begin(), j.end()
#define rall(j) j.rbegin(), j.rend()
#define len(j) (int)j.size()
#define rep(i, a, b) \
        for (common_type_t<decltype(a), decltype(b)> i = a; i < b; i++)
#define rrep(i, a, b) \
        for (common_type_t<decltype(a), decltype(b)> i = a; i > b; i--)
#define pb push_back
#define eb emplace_back

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;
using vs = vector<string>;

template<typename T, typename U> inline bool chmax(T &a, U const& b) { return (a < b ? a = b, 1 : 0); }
template<typename T, typename U> inline bool chmin(T &a, U const& b) { return (a > b ? a = b, 1 : 0); }
/*~==========================END MACRO==================================~*/
using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
const int MAXN = 2'00'000;
const ll MAXW = 1'00'000'000ll;
constexpr ll OO = MAXW * MAXN + 1;
using Edge = pair<ll, int>; // { weigth, node}
using Adj = vector<vector<Edge>>;

pair<vll, vi> dijkstra(const Adj &g, int s) {
	int n = g.size();
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	vll ds(n, OO);
	vi ps(n, -1);
	pq.emplace(0, s);
	ds[s] = 0;
	while (!pq.empty()) {
		auto [du, u] = pq.top(); pq.pop();
		if (ds[u] < du)
			continue;

		dbg(u, du);

		for (auto [w, v] : g[u]) {
			ll ndv = du + w;
			if (ds[v] > ndv) {
				ds[v] = ndv;
				ps[v] = u;
				pq.emplace(ndv, v);
			}
		}
	}

	return {ds, ps};
}

// optional !
vi recover_path(int source, int ending, const vi &ps) {
	if (ps[ending] == -1) return {};
	int cur = ending;
	vi ans;
	while (cur != -1) {
		ans.emplace_back(cur);
		cur = ps[cur];
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

auto run() {
	int N, M;
	cin >> N >> M;

	vi HS(N);
	for (auto& hi : HS)
		cin >> hi;


	Adj adj(N);
	int mn = INT_MAX;
	rep(i, 0, M) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		auto hu = HS[u];
		auto hv = HS[v];
		auto d = abs(hu - hv);
		if (hu <= hv) {
			chmin(mn, -d);
			chmin(mn, 2*d);
			adj[v].eb(-d + hv-hu, u);
			adj[u].eb(2*d + hu-hv, v);
		}
		else {
			chmin(mn, -d);
			chmin(mn, 2*d);
			adj[u].eb(-d + hu - hv, v);
			adj[v].eb(2*d + hv - hu, u);
		}
	}

	
	dbg(adj);
	auto [dists, _] = dijkstra(adj, 0);
	ll ans = 1'000'000'000;
	rep(i, 0, N){
		chmin(ans, dists[i] - (HS[0]-HS[i]));
	}

	cout << -ans << '\n';

}

int32_t main() {
#ifndef LOCAL
        fastio;
#endif

        int T = 1;

        // cin >> T;

        rep(t, 0, T) {
                dbg(t);
                run();
        }
}

/*
	Hs vai até 10^8 não da pra fazer na baseado nisso ?
	dp de melhor que consigo chegar no Hi


	nunca visita o mesmo nó duas vezes ?

	flipo todas as arestas 

	e rodo um dijkstra com shortest path

	e pego a distância flipada o sinal

	não tem ciclo positivo né
	pq se nao vira ciclo negativo

	n tem pq se ganhou X descendo, pra ganhar esses X denovo precisaria 
	pagar 2X

	AC, shortest paths, dijkstra with potentials
 */
