/*
...
- unidirectionally
- da pra ir pra qualquer nó do feixo transitivo
- mínimo de arestas necessárias para que exista caminho entre M pares
em um grafo direcionado
- Se eu adicionar todas as arestas que ele propõem e ir removendo as
"desnecessárias"
- Se a P b e a P c, e a -> b e b -> c, não preciso das duas arestas...
- Se ligo em um nó e ele liga em algum outro que eu preciso, eu só preciso ligar
nele e posso matar essa dep minha...
- Isso se quebra em ciclos né, por que se for um dag é só ligar no pai de cada
nó...
- Se eu tiver mais de N requirements posso só fazer um ciclo
- Se detectar os ciclos nesse grafo dado é meio tiro e queda né todo
- teria de decompor nos maiores ciclos
- esses ciclos são os scc connected components
- cada connected comopnente paga size + 1
- agora entre componentes
- pra todo componente que tem uma aresta saindo dele é só ligar
no componente mais alto ele, ou qeu se liga em amis ou coisa assi
acho que dá pra salvar umas arestas nisso
- Dá pra meio que ir subindo com o DSU né
- Processar os componentes das folhas para as mais altas
- Daí pra cada nó eu só preciso ligar no pai dele né
- e o pai dele já liga em tudo eu já sei qeu não preciso ligar em outros
- dsu não funciona eu acho pq é direcionado essa bomba
- acho que funciona sim kkk
- to errando pra menos ou pra mais ???
- to errando pra mais !
- nunca vale a pena fechar o ciclo no meu componente, é melhor eu fechar
o ciclo em um ancestral meu ou em algum nó que liga nos demais que eu quero se
fechar ciclo vapo
- deve ter um casinho torado assim


...
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
  @Title:

    Strongly Connected Components (struct)

  @Description:

    Find the connected component for each edge
    (already in a topological order), some
    additional functions are also provided.

  @Time:

    Build: $O(V+E)$
>8*/
struct SCC {
    int n, num_sccs;
    vi2d adj;
    vi scc_id;

    SCC(const vi2d &_adj)
        : n(len(_adj)), num_sccs(0), adj(_adj), scc_id(n, -1) {
        build();
    }

    void build() {
        int timer = 1;
        vi tin(n), st;
        st.reserve(n);
        function<int(int)> dfs = [&](int u) -> int {
            int low = tin[u] = timer++, siz = len(st);
            st.eb(u);
            for (int v : adj[u])
                if (scc_id[v] < 0) low = min(low, tin[v] ? tin[v] : dfs(v));
            if (tin[u] == low) {
                rep(i, siz, len(st)) scc_id[st[i]] = num_sccs;
                st.resize(siz);
                num_sccs++;
            }
            return low;
        };

        for (int i = 0; i < n; i++)
            if (!tin[i]) dfs(i);
    }

    vector<set<int>> build_gscc() {
        vector<set<int>> gscc(len(adj));
        for (int i = 0; i < len(adj); ++i)
            for (auto j : adj[i])
                if (scc_id[i] != scc_id[j]) gscc[scc_id[i]].emplace(scc_id[j]);
        return gscc;
    }

    vi2d per_comp() {
        vi2d ret(num_sccs);
        rep(i, 0, n) ret[scc_id[i]].eb(i);
        reverse(all(ret));  // already in topological order ;)
        return ret;
    }
};

/*8<{=============~ BEGIN DSU ~===============>8*/
/*8<
  @Title:

    DSU / UFDS

  @Usage:

    You may discomment the commented parts to
    find online which nodes belong to each
    set, it makes the $union\_set$ method cost
    $O(log^2)$ instead $O(A)$

>8*/

struct DSU {
    vector<int> ps, sz;

    // vector<unordered_set<int>> sts;

    DSU(int N)
        : ps(N + 1),
          sz(N, 1) /*, sts(N) */
    {
        iota(ps.begin(), ps.end(), 0);
        // for (int i = 0; i < N; i++)
        // sts[i].insert(i);
    }
    int find_set(int x) { return ps[x] == x ? x : ps[x] = find_set(ps[x]); }
    int size(int u) { return sz[find_set(u)]; }
    bool same_set(int x, int y) { return find_set(x) == find_set(y); }
    void union_set(int x, int y) {
        if (same_set(x, y)) return;

        int px = find_set(x);
        int py = find_set(y);

        if (sz[px] < sz[py]) swap(px, py);

        ps[py] = px;
        sz[px] += sz[py];
        // sts[px].merge(sts[py]);
    }
};

/*8<===============~ END DSU ~===============}>8*/

void __run() {
    int n, m;
    cin >> n >> m;

    DSU dsu(n);
    vi2d adj(n);
    iter(m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        dsu.union_set(u, v);
    }
    SCC scc(adj);

    vi sccSz(n);

    vi hasCycle(n);
    repn(i, n) {
        int pi = dsu.find_set(i);
        int sccId = scc.scc_id[i];
        sccSz[sccId]++;
        hasCycle[pi] |= (sccSz[sccId] > 1);
    }
    int ans = 0;
    vi vis(n);
    repn(i, n) {
        int pi = dsu.find_set(i);
        if (vis[pi]) continue;
        vis[pi] = 1;
        ans += dsu.size(pi) - (!hasCycle[pi]);
    }
    cout << ans << endl;
}

/*8<
>8*/
