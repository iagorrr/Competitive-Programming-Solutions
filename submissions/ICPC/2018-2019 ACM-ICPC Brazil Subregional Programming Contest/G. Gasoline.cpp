#include <bits/stdc++.h>
using namespace std;

#define int long long
struct Dinic {
  struct Edge {
    int to, rev;
    long long c, oc;
    long long flow() {
      return max(oc - c, 0LL);
    }  // if you need flows
  };
  vector<int> lvl, ptr, q;
  vector<vector<Edge>> adj;
  Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
  void addEdge(int a, int b, long long c,
               long long rcap = 0) {
    adj[a].push_back({b, (int)adj[b].size(), c, c});
    adj[b].push_back(
      {a, (int)adj[a].size() - 1, rcap, rcap});
  }
  long long dfs(int v, int t, long long f) {
    if (v == t || !f) return f;
    for (int& i = ptr[v]; i < (int)adj[v].size(); i++) {
      Edge& e = adj[v][i];
      if (lvl[e.to] == lvl[v] + 1)
        if (long long p = dfs(e.to, t, min(f, e.c))) {
          e.c -= p, adj[e.to][e.rev].c += p;
          return p;
        }
    }
    return 0;
  }
  long long calc(int s, int t) {
    long long flow = 0;
    q[0] = s;
    for (int L = 0; L < 31; L++)
      do {  // 'int L=30' maybe faster for random data
        lvl = ptr = vector<int>(q.size());
        int qi = 0, qe = lvl[s] = 1;
        while (qi < qe && !lvl[t]) {
          int v = q[qi++];
          for (Edge e : adj[v])
            if (!lvl[e.to] && e.c >> (30 - L))
              q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
        }
        while (long long p = dfs(s, t, LLONG_MAX))
          flow += p;
      } while (lvl[t]);
    return flow;
  }
  bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int P, R, C;
	cin >> P >> R >> C;

	vector<int> DS(P);
	for (auto& di : DS)
		cin >> di;

	vector<int> ES(R);
	for (auto& ei : ES)
		cin >> ei;

	using tipin = tuple<int,int,int>;
	vector<tipin> CS(C);
	for (auto& [ti, ii, ji] : CS) {
		cin >> ii >> ji >> ti;
		ii--, ji--;
	}
	sort(CS.begin(), CS.end());
	
	int ans = 1'000'000 +  1;
	const int oo = 1'000'000;
	for (int l = 0, r = 1'000'000+1; l <= r; ) {
		int k = midpoint(l ,r);


		Dinic dinic(R+P+1 + 1);
		int source = R+P, sink = R+P+1;
		
		for (auto [ti, pi, ri] : CS) {
			if (ti > k) break;
			dinic.addEdge(ri, pi + R, oo);
		}

		for (int i = 0; i < R; i++)
			dinic.addEdge(source, i, ES[i]);
		int tot = 0;
		for (int i = 0; i < P; i++) {
			dinic.addEdge(R+i, sink, DS[i]);
			tot += DS[i];
		}

		if (dinic.calc(source, sink) == tot) {
			ans = min(ans, k);
			r = k - 1;
		}
		else l = k + 1;
	}

	if (ans == 1'000'000 + 1)
		ans = -1;

	cout << ans << '\n';
}

/*
	Acho que da pra fazer busca binária na maior aresta
	Dai tenta abastecer geral dando prioridade pras maiores arestas
	Se der vapo

	Deu errado

	Acho que se tiver um caso que a maior aresta X vai consumir tudo de uma refinaria
	que era a unica que abastecia um mano lá com essa única conexão, era melhor
	ter feito pro mano lá com essa única conexão

	E se o guloso for nos postos com menos conexões, resovler eles primeiro

	E se eu rodar um fluxo e ver se deu fluxo máximo ???
	Num da TLE n ?

	E V^2
	2*10^4 * (1000)^2
	2*10^4 * 10^6

	Acho que da ruim né po

	Vish passou

	Dinic faz mágica mesmo

	AC, flow, dinic, binary search
 */
 
