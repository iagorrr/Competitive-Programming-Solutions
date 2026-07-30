/*
...
- Monta a bridge tree
- Enraiza no nó 1
- Calcula a menor distância para todos os nós co uma dfs safada
- vapo
- é nada por que ainda tem que chegar naquele nó
mas posso pegar as arestas que foram usadas para chegar nele....
- e depois rodo uma bfs multi-source pra propagar as respostas
- que merda quando o prórprio nó já é isso daí fica meio zuado pra cahr
- mas cada nó nunca vai sar do componente então é a menor distância pra sair
do componente ou 1 quando já é a quele nó ou 0000 ??
- tem que ver os de entrada po

...
 */
#pragma once
/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define all(j) j.begin(), j.end()
#define found(x, y) ((x).find((y)) != (x).end())
#define rall(j) j.rbegin(), j.rend()
#define len(j) (int)j.size()
#define rep(i, a, b) \
    for (common_type_t<decltype(a), decltype(b)> i = (a); i < (b); i++)
#define rrep(i, a, b) \
    for (common_type_t<decltype(a), decltype(b)> i = (a); i > (b); i--)
#define repn(i, b) for (auto i = 0; i < (b); i++)
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) for (auto &xi : ranges::views::reverse(xs))
#define loop while (1)
#define iter(x) repn(__, x)
using ll = long long;
#define endl '\n'
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define ef emplace_back
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
using vpll = vector<pll>;
using vc = vector<char>;
using vs = vector<str>;

#define TT template <typename T>
#define TTU template <typename T, typename U>

TTU using umap = unordered_map<T, U>;
TT using uset = unordered_set<T>;
TT using pqmn = priority_queue<T, vector<T>, greater<T>>;
TT using pqmx = priority_queue<T, vector<T>>;

TTU inline bool chmax(T &a, U const &b) { return (a < b ? a = b, 1 : 0); }
TTU inline bool chmin(T &a, U const &b) { return (a > b ? a = b, 1 : 0); }

// read vector
// TODO: abstract this to any container.
TT std::istream &operator>>(std::istream &is, std::vector<T> &vec) {
    for (auto &element : vec) {
        is >> element;
    }
    return is;
}

// print vector
// TODO: abstract this to any container.
TT ostream &operator<<(ostream &os, vector<T> &xs) {
    rep(i, os.iword(0), xs.size()) os << xs[i] << (i == xs.size() ? "" : " ");
    os.iword(0) = 0;
    return os;
}

// print pair
TTU ostream &operator<<(ostream &os, pair<T, U> &p) {
    os << p.first << " " << p.second;
    return os;
}

// read pair
TTU std::istream &operator>>(std::istream &is, pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
}

// print multiset
// TODO: abstract this to any container.
TT ostream &operator<<(ostream &os, multiset<T> &xs) {
    for (auto it = xs.begin(); it != xs.end(); it++)
        os << *it << (next(it) == end(xs) ? "" : " ");
    return os;
}

// sum a vector, using the default constructor as initial value
// TODO: abstract this to any container.
TT T sumList(vector<T> &xs) { return accumulate(all(xs), T()); }

/*
 * verify if a `predicate` is valid for
 * values in range [l, r]
 *
 * TODO: put a type in predicate ??
 * */
// bool all_of_in_range(T l, T r, auto predicate) {
//     return ranges::all_of(views::iota(l, r + 1),
//                           [&](T v) { return predicate(v); });
// }

// checks if a  value v is the interval [l, r]
TT bool inline between(T v, T l, T r) { return clamp(v, l, r) == v; }

/*8<============~ END TEMPLATE ~============}>8*/
void __init();
void __run();
void __pre_run();

int32_t main() {
#ifndef LOCAL
    fastio;
#endif
    __init();

    int T = 1;

    cin >> T;

    rep(t, 0, T) {
        dbg(t);
        __pre_run();
        __run();
    }
}

/*
 *
 *
 *
 *
 *
 * */

void __init() {}

void __pre_run() {}

struct TwoEdgeCC {
    int n, qtdComps;
    vector<vpii> g;
    vector<set<pii>> tree;
    vi tin, stck, compId;

    TwoEdgeCC(const vector<vpii> &_g)
        : n(_g.size()), qtdComps(0), g(_g), tree(n), tin(n, -1), compId(n, -1) {
        stck.reserve(n);

        for (int i = 0; i < n; i++) {
            if (tin[i] == -1) dfs(i);
        }

        for (int i = 0; i < n; i++) {
            int ci = compId[i];
            for (auto [j, id] : g[i]) {
                int cj = compId[j];
                if (ci != cj) {
                    tree[ci].emp(cj, id);
                    tree[cj].emp(ci, id);
                }
            }
        }
    }

    int dfs(int u, int p = -1) {
        int low = tin[u] = len(stck);
        stck.emplace_back(u);

        bool multEdge = false;
        for (auto [v, id] : g[u]) {
            if (v == p and !multEdge) {
                multEdge = true;
                continue;
            }
            low = min(low, tin[v] == -1 ? dfs(v, u) : tin[v]);
        }

        if (low == tin[u]) {
            for (int i = tin[u]; i < len(stck); i++) compId[stck[i]] = qtdComps;
            stck.resize(tin[u]);
            qtdComps++;
        }
        return low;
    }
};

void __run() {
    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<vpii> g(n);
    vpii edges;

    repn(i, m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].eb(v, i);
        g[v].eb(u, i);
        edges.eb(u, v);
    }

    TwoEdgeCC tecc(g);

    auto &compId = tecc.compId;
    auto &tree = tecc.tree;

    vi ps(n, -1);
    function<void(int)> dfsTree = [&](int u) {
        for (auto [v, _] : tree[u]) {
            if (v != ps[u]) {
                ps[v] = u;
                dfsTree(v);
            }
        }
    };

    dbg(compId);
    dfsTree(compId[0]);
    dbg(ps);

    dbg(tree);
    vi edgesCursedIdx;
    int cur = compId[n - 1];
    while (cur != -1) {
        for (auto [v, idx] : tree[cur]) {
            if (v == ps[cur]) {
                edgesCursedIdx.eb(idx);
                break;
            }
        }
        cur = ps[cur];
    }
    dbg(edgesCursedIdx);

    const int oo = n + 1;
    vi dst(n, oo);
    vi ans(n, oo);

    queue<int> quiui;
    sort(all(edgesCursedIdx));
    trav(i, edgesCursedIdx) {
        auto [u, v] = edges[i];
        if (ans[u] == oo) {
            ans[u] = i;
            dst[u] = 0;
            quiui.emp(u);
        }

        if (ans[v] == oo) {
            ans[v] = i;
            dst[v] = 0;
            quiui.emp(v);
        }
    }
    dbg(ans);

    while (len(quiui)) {
        auto u = quiui.front();
        quiui.pop();

        for (auto [v, _] : g[u]) {
            if (dst[v] == oo) {
                dst[v] = dst[u] + 1;
                ans[v] = ans[u];
                quiui.emp(v);
            }
        }
    }

    int q;
    cin >> q;
    iter(q) {
        int ci;
        cin >> ci;
        ci--;
        cout << (dst[ci] == oo ? -1 : ans[ci] + 1) << ' ';
    }
    cout << endl;
}
