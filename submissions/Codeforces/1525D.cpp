/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define fastio                        \
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
#define endl '\n'
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
#define divc(a, b) ((a) + (b) - 1ll) / (b)
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

  @Title: Minimum Cost Flow

  @Description:

    Given a network find the minimum cost to
    achieve a flow of at most $f$. Works with
    \textbf{directed} and \textbf{undirected}
    graphs

  @Usage:

    \begin{compactitem}
      \item \textbf{add(u, v, c, w):} adds an
      edge from $u$ to $v$ with capacity $c$
      and cost $w$.

      \item \textbf{flow(f):} return a pair
      $(flow, cost)$ with the maximum flow
      until $f$ with source at $s$ and sink at
      $t$, with the minimum cost possible.
    \end{compactitem}

  @Time:

    $O(N \cdot M + f \cdot m \log{n})$
>8*/

template <typename T = int>
struct MinCostFlow {
        struct Edge {
                int to;
                ll c, rc;        // capcity, residual capacity
                T w;             // cost
        };
        int n, s, t;
        vector<Edge> edges;
        vi2d g;
        vector<T> dist;
        vi pre;

        MinCostFlow() {}
        MinCostFlow(int n_, int _s, int _t) : n(n_), s(_s), t(_t), g(n) {}

        void addEdge(int u, int v, ll c, T w) {
                g[u].pb(len(edges));
                edges.eb(v, c, 0, w);
                g[v].pb(len(edges));
                edges.eb(u, 0, 0, -w);
        }

        // {flow, cost}
        pair<ll, T> flow(ll flow_limit = LLONG_MAX) {
                ll flow = 0;
                T cost = 0;
                while (flow < flow_limit and dijkstra(s, t)) {
                        ll aug = LLONG_MAX;
                        for (int i = t; i != s; i = edges[pre[i] ^ 1].to) {
                                aug = min({flow_limit - flow, aug,
                                           edges[pre[i]].c});
                        }
                        for (int i = t; i != s; i = edges[pre[i] ^ 1].to) {
                                edges[pre[i]].c -= aug;
                                edges[pre[i] ^ 1].c += aug;

                                edges[pre[i]].rc += aug;
                                edges[pre[i] ^ 1].rc -= aug;
                        }
                        flow += aug;
                        cost += (T)aug * dist[t];
                }
                return {flow, cost};
        }

        // Needs to be called after flow method
        vi2d paths() {
                vi2d p;
                for (;;) {
                        int cur = s;
                        auto &res = p.eb();
                        res.pb(cur);
                        while (cur != t) {
                                bool found = false;
                                for (auto i : g[cur]) {
                                        auto &[v, _, c, cost] = edges[i];
                                        if (c > 0) {
                                                --c;
                                                res.pb(cur = v);
                                                found = true;
                                                break;
                                        }
                                }

                                if (!found) break;
                        }

                        if (cur != t) {
                                p.ppb();
                                break;
                        }
                }

                return p;
        }

       private:
        bool bellman_ford(int s, int t) {
                dist.assign(n, numeric_limits<T>::max());
                pre.assign(n, -1);

                vc inq(n, false);
                queue<int> q;

                dist[s] = 0;
                q.push(s);

                while (len(q)) {
                        int u = q.front();
                        q.pop();
                        inq[u] = false;

                        for (int i : g[u]) {
                                auto [v, c, w, _] = edges[i];
                                auto new_dist = dist[u] + w;
                                if (c > 0 and dist[v] > new_dist) {
                                        dist[v] = new_dist;
                                        pre[v] = i;
                                        if (not inq[v]) {
                                                inq[v] = true;
                                                q.push(v);
                                        }
                                }
                        }
                }

                return dist[t] != numeric_limits<T>::max();
        }

        bool dijkstra(int s, int t) {
                dist.assign(n, numeric_limits<T>::max());
                pre.assign(n, -1);
                dist[s] = 0;

                using PQ = pair<T, int>;
                pqmn<PQ> pq;
                pq.emp(0, s);
                while (len(pq)) {
                        auto [cost, u] = pq.top();
                        pq.pop();
                        if (cost != dist[u]) continue;

                        for (int i : g[u]) {
                                auto [v, c, _, w] = edges[i];
                                auto new_dist = dist[u] + w;
                                if (c > 0 and dist[v] > new_dist) {
                                        dist[v] = new_dist;
                                        pre[v] = i;
                                        pq.emp(new_dist, v);
                                }
                        }
                }

                return dist[t] != numeric_limits<T>::max();
        }
};

void run() {
        int N;
        cin >> N;

        vi ps, cs;
        rep(i, 0, N) {
                int x;
                cin >> x;

                if (x) {
                        ps.eb(i);
                } else
                        cs.eb(i);
        }

        int source = N, sink = N + 1;
        MinCostFlow<int> mcf(sink + 1, source, sink);

        trav(pi, ps) { mcf.addEdge(source, pi, 1, 0); }
        trav(ci, cs) { mcf.addEdge(ci, sink, 1, 0); }

        rep(i, 0, N) {
                if (i) mcf.addEdge(i, i - 1, 2 * N, 1);
                if (i + 1 < N) mcf.addEdge(i, i + 1, 2 * N, 1);
        }

        cout << mcf.flow().second << endl;
}

/*8<
 * AC, flows, minimum cost flow, graph matchings
>8*/
