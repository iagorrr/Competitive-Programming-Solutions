/*
- Por que quando não tem aresta é N
- Pra cada componente
    - Ver se é possível gerar o graph do jeito 1 e do jeito 2
    - E dos dois jeitos pega o que tem mais nós do tipo 1
    - Tem os nós que recebem e os nós que apontam
    - nenhum pode pertencer aos dois lados ao mesmo tempo
    - entao pra cada componente roda isso ai
    - e pega o componente com maior size, o lado no caso...
 */
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
/*8<
    @Title: Bipartite Graph
    @Description:
        Given a  graph, find the 'left' and
        'right' side if is a bipartite graph, if
        is not then a empty vi2d is returned
    @Time: $O(N+M)$
>8*/
vi2d bipartite_graph(const vi2d &adj, int root, vi &side) {
    vi2d ret(2);
    queue<int> q;
    q.emp(root);
    side[root] = 0;
    ret[0].eb(root);
    while (len(q)) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (side[v] == -1) {
                side[v] = side[u] ^ 1;
                ret[side[v]].eb(v);
                q.push(v);
            } else if (side[u] == side[v])
                return {};
        }
    }

    return ret;
}

void __run() {
    int n, m;
    cin >> n >> m;

    vi2d adj(n);
    repn(i, m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }

    int ans = 0;
    vi vis(n);
    function<void(int)> dfs = [&](int u) {
        vis[u] = 1;
        trav(v, adj[u]) if (!vis[v]) dfs(v);
    };

    vi side(n, -1);
    repn(u, n) {
        if (!vis[u]) {
            dfs(u);
            auto bps = bipartite_graph(adj, u, side);
            if (len(bps)) ans += max(len(bps.front()), len(bps.back()));
        }
    }

    cout << ans << endl;
}

/*8<
>8*/
