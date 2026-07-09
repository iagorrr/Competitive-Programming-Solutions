/*
- Torar todas as folhas em 3 * x operações
- Tem cara de DP

- DP(i, j), se consigo torar todas as folhas do i, com 3 * x + j operações,
j é o mod 3 da quantidade de operações
- Pra garantir que sempre é resolvido se estiver olhando para uma folha
a gente sempre faz a operação
- Então pra uma folha f só é true DP(F, 1)
- Pra todo nó esse é true né, se eu fizer nele para ali mesmo
- Pro caso que quero DP(u, 1) não tem por que testar para os filhos...
- Pro caso que quero DP(u, 2), não posso fazer no u em si, e daí a soma dos
filhos tem que dar certo
- Só tem 3 somas possíveis, como que eu checo esse role
- Ans é DP(root, 0)
- Essas DP de árvore que considera os filhos como q faz mesmo ???
- DP(i, f, j), o f é que eu posso considerar a partir do f-ésimo filho somente
- Só da pra fazer a transição de pegar o próprio nó se o f for zero
- Sempre posso torar todos os valores de j para o filho, e dai eu vou pra f+1
mudando somente o valor de j
xapa ?


da pra imaginar que cada nó cobre um intervalo [l, r] das folhas
o que quero é no fim cobrir todo esse intervalo com mod 3
dpzinha safe de duas dimensões e da pra ignorar a árvore
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

void dfs(int u, int p, const vi2d &adj, vi &totChild) {
    trav(v, adj[u]) {
        if (v != p) {
            totChild[u]++;
            dfs(v, u, adj, totChild);
        }
    }
}

void __run() {
    int n;
    cin >> n;

    vi2d adj(n);
    repn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }

    if (n == 2) {
        cout << "NO" << endl;
        return;
    }

    vi ls(n, INT_MAX);
    vi rs(n, -1);
    int m = 0;

    dbg(adj);
    function<void(int, int)> dfs = [&](int u, int p) {
        dbg(u, p);
        if (len(adj[u]) == 1 and u != 0) {
            ls[u] = rs[u] = m;
            m++;
            return;
        }

        trav(v, adj[u]) {
            if (v != p) {
                dfs(v, u);
                chmin(ls[u], ls[v]);
                chmax(rs[u], rs[v]);
            }
        }
    };

    dfs(0, -1);
    dbg(ls);
    dbg(rs);

    vi2d jmp(m);
    repn(i, n) { jmp[ls[i]].pb(rs[i]); }

    dbg(jmp);

    vi2d mem(m + 2, vi(3, false));
    mem[0][0] = 1;
    repn(i, m) {
        repn(j, 3) {
            trav(k, jmp[i]) {
                dbg(i, j, k);
                mem[k + 1][(j + 1) % 3] |= mem[i][j];
            }
        }
    }

    cout << (mem[m][0] ? "YES" : "NO") << endl;
}

/*8<
>8*/
