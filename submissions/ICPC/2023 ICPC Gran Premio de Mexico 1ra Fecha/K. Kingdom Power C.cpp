/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define fastio                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
#define all(j) j.begin(), j.end()
#define rall(j) j.rbegin(), j.rend()
#define len(j) (int)j.size()
#define rep(i, a, b) \
  for (common_type_t<decltype(a), decltype(b)> i = (a); i < (b); i++)
#define rrep(i, a, b) \
  for (common_type_t<decltype(a), decltype(b)> i = (a); i > (b); i--)
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) for (auto &xi : ranges::views::reverse(xs))
using ll = long long;
#define inte ll
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define emp emplace
#define ins insert
#define divc(a, b) ((a) + (b)-1ll) / (b)
using str = string;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vc = vector<char>;
using vs = vector<str>;
template <typename T, typename T2>
using umap = unordered_map<T, T2>;
template <typename T>
using pqmn = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using pqmx = priority_queue<T, vector<T>>;
template <typename T, typename U>
inline bool chmax(T &a, U const &b) {
  return (a < b ? a = b, 1 : 0);
}
template <typename T, typename U>
inline bool chmin(T &a, U const &b) {
  return (a > b ? a = b, 1 : 0);
}
/*8<============~ END TEMPLATE ~============}>8*/
void run();

int32_t main() {
#ifndef LOCAL
  fastio;
#endif

  int T = 1;

  rep(t, 0, T) {
    dbg(t);
    run();
  }
}

/*8<
  @Title: Maximum flow (Dinic)

  @Description:

    Finds the \textbf{maximum flow} in a graph
    network, given the \textbf{source $s$} and
    the \textbf{sink $t$}. Add edge from $a$ to
    $b$ with capcity $c$.

  @Time:

    In general $O(E \cdot V^2)$, if every capacity
    is 1, and every vertice has in degree equal 1
    or out degree equal 1 then $O(E \cdot
    \sqrt{V})$,

  @Warning:

    Suffle the edges list for every vertice may
    take you out of the worst case
>8*/
struct Dinic {
  struct Edge {
    int to, rev;
    ll c, oc;
    ll flow() { return max(oc - c, 0LL); }  // if you need flows
  };

  vi lvl, ptr, q;
  vector<vector<Edge>> adj;

  Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}

  void addEdge(int a, int b, ll c = 1, ll rcap = 0) {
    adj[a].pb({b, len(adj[b]), c, c});
    adj[b].pb({a, len(adj[a]) - 1, rcap, rcap});
  }

  ll dfs(int v, int t, ll f) {
    if (v == t || !f) return f;
    for (int &i = ptr[v]; i < len(adj[v]); i++) {
      Edge &e = adj[v][i];
      if (lvl[e.to] == lvl[v] + 1)
        if (ll p = dfs(e.to, t, min(f, e.c))) {
          e.c -= p, adj[e.to][e.rev].c += p;
          return p;
        }
    }
    return 0;
  }

  ll maxFlow(int s, int t) {
    ll flow = 0;
    q[0] = s;
    rep(L, 0, 31) {
      do {  // 'int L=30' maybe faster for random
            // data
        lvl = ptr = vi(len(q));
        int qi = 0, qe = lvl[s] = 1;
        while (qi < qe && !lvl[t]) {
          int v = q[qi++];
          for (Edge e : adj[v])
            if (!lvl[e.to] && e.c >> (30 - L))
              q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
        }

        while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
      } while (lvl[t]);
    }
    return flow;
  }

  bool leftOfMinCut(int a) { return lvl[a] != 0; }

  void debug() {
	  for (int i = 0; i < adj.size(); i++) {
		  for (auto e : adj[i]) {
			  if (e.flow() == 1) {
				  cout << i << ' ' << e.to << endl;
			  }
		  }
	  }
  }
};



void run() {
	int N, S, E;
	cin >> N >> S >> E;

	Dinic dinic(2*N + 2);
	rep(i, 0, N) {
		dinic.addEdge(i * 2, i * 2 +1);
	}

	int source = 2*N;
	int sink = source + 1;

	rep(i, 0, S) {
		int xi; cin >> xi, xi--;
		dinic.addEdge(source, xi*2);

	}

	rep(i, 0, E) {
		int xi;
		cin >> xi, xi--;
		dinic.addEdge(xi*2+1, sink);
	}

	int M; cin >> M;
	rep(i, 0, M) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		dinic.addEdge(u*2+1, v*2);
	}


	cout << dinic.maxFlow(source, sink) << endl;
}

/*8<
  AC, maximum flow
>8*/
