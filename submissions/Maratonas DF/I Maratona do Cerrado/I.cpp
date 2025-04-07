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

template <typename T>
std::istream &operator>>(std::istream &is, std::vector<T> &vec) {
        for (auto &element : vec) {
                is >> element;
        }
        return is;
}

template <typename T>        // print vector
ostream &operator<<(ostream &os, vector<T> &xs) {
        rep(i, os.iword(0), xs.size()) os << xs[i]
                                          << (i == xs.size() ? "" : " ");
        os.iword(0) = 0;
        return os;
}

/*8<============~ END TEMPLATE ~============}>8*/
void run();

struct BlockCutTree {
        int n;
        vi idOnTree, tin, low, stk, isGraphCutpoint, isTreeCutpoint;
        vi2d comps, tree;
        BlockCutTree(vi2d &g)
                : n(len(g)), idOnTree(n), tin(n), low(n), isGraphCutpoint(n) {
                rep(i, 0, n) {
                        if (!tin[i]) {
                                int timer = 0;
                                dfs(i, -1, timer, g);
                        }
                }

                int node_id = 0;
                rep(u, 0, n) {
                        if (isGraphCutpoint[u]) {
                                idOnTree[u] = node_id++;
                                isTreeCutpoint.eb(true);

                                tree.pb({});
                        }
                }

                for (auto &comp : comps) {
                        int node = node_id++;
                        tree.pb({});
                        isTreeCutpoint.eb(false);
                        for (int u : comp) {
                                if (!isGraphCutpoint[u]) {
                                        idOnTree[u] = node;
                                } else {
                                        tree[node].eb(idOnTree[u]),
                                                tree[idOnTree[u]].eb(node);
                                }
                        }
                }
        }

        void dfs(int u, int p, int &timer, vi2d &g) {
                tin[u] = low[u] = ++timer;
                stk.eb(u);

                for (auto v : g[u]) {
                        if (v == p) continue;
                        if (!tin[v]) {
                                dfs(v, u, timer, g);
                                low[u] = min(low[u], low[v]);
                                if (low[v] >= tin[u]) {
                                        isGraphCutpoint[u] =
                                                (tin[u] > 1 or tin[v] > 2);
                                        comps.pb({u});
                                        while (comps.back().back() != v) {
                                                comps.back().eb(stk.back());
                                                stk.pop_back();
                                        }
                                }
                        } else
                                low[u] = min(low[u], tin[v]);
                }
        }

        void debug() {
                dbg(n);
                dbg(id);
                dbg(isGraphCutpoint);
                dbg(isTreeCutpoint);
                dbg(tin);
                dbg(low);
                dbg(stk);
                dbg(comps);
                dbg(tree);
        }

        int countMandatoryNodesOnPath(int startNode, int endNode) {
                startNode = idOnTree[startNode], endNode = idOnTree[endNode];

                int ans = !isTreeCutpoint[startNode] + !isTreeCutpoint[endNode];

                int artPoints = 0;
                function<void(int, int)> dfsCount = [&](int u, int p) {
                        artPoints += isTreeCutpoint[u];

                        if (u == endNode) ans += artPoints;

                        for (auto v : tree[u]) {
                                if (v != p) {
                                        dfsCount(v, u);
                                }
                        }

                        artPoints -= isTreeCutpoint[u];
                };

                dfsCount(startNode, -1);

                return ans;
        }
};

int32_t main() {
#ifndef LOCAL
        fastio;
#endif

        int T = 1;

        //    cin >> T;

        rep(t, 0, T) {
                dbg(t);
                run();
        }
}

void run() {
        int N, M;
        cin >> N >> M;

        vi2d ADJ(N);
        rep(i, 0, M) {
                int u, v;
                cin >> u >> v;
                u--, v--;
                ADJ[u].eb(v);
                ADJ[v].eb(u);
        }

        int source, sink;
        cin >> source >> sink, source--, sink--;

        BlockCutTree bct(ADJ);

        bct.debug();

        cout << bct.countMandatoryNodesOnPath(source, sink) << endl;
}

/*8<
>8*/
