#include <bits/stdc++.h>
using namespace std;

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

	int n, m;
	cin >> n >> m;

	vector<string> grid(n);
	for (auto& gi : grid) {
		cin >> gi;
	}
	/*
	   0..n-1 linhas
	   n...n+m-1 colunas
	   n+m source
	   n+m + 1 sink
	 */	

	Dinic st(n+m+1 + 1);
	int prev = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '1') {
				st.addEdge(i, j + n, 1);
				prev++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		st.addEdge(n+m, i, 1);
	}

	for (int i = 0; i < m; i++) {
		st.addEdge(n+i, n+m+1, 1);
	}

	int choose = st.calc(n+m, n+m+1);
	cerr << choose << '\n';
	cout << prev - choose << '\n';
}

// AC, maxflow
