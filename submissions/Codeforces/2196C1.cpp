/*
- n <= 15
- não tem restrição em cima do M
- Mas o pior seria um grafo bamboo onde todo nó liga em todos os vértices abaixo
ou a cima dele
- Mas ele limitou em 2^30
- os caminhos que mais me dizem algo são os maiores ?
- É uma busca binária claro...


Os caminhos em ordem são sempre algo do tipo


A
A -> B
A -> B -> C
A -> C

coisas assim
Como é um dag os nós não se repetem
Cada nó pode ter até 15 arestas  sendo bem exagerado....
Da pra fazer busca binária pra achar a priemira posicao tal que o primeiro é U e
o outro V, e deopis diferente de V .... e xalala

pra cada um acahr todas as arestas...

quao caro é isso ?

N, N-1, N-2, N-3 , ... 1
N^2 / 2  arestas

32 * (n+m) é certamente maior que N ^2
E 32 pq eu pago no máximo 32 pra cada aresta que eu quero achar
no caos 32 * m né

tá com folga

pra cada 1 eu vejo a ultima posica em que U->V, e a próxima se começar em U,
U->X tal que X é diferente de V

sempre olho só para os 2 primeiros nós da query...

*/
/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
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
// #define endl '\n'
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
@Title: Max \& Min Check

@Description: Returns the min/max value in range
[l, r] that satisfies the lambda function check,
if there is no such value the 'nullopt' is
returned.

@Usage: check must be a function that receives
an integer and return a boolean.

@Time: $O(\log{r-l+1})$
>8*/

template <typename T>
optional<T> maxCheck(T l, T r, auto check) {
    optional<T> ret;
    while (l <= r) {
        T m = midpoint(l, r);
        if (check(m))
            ret ? chmax(ret, m) : ret = m, l = m + 1;
        else
            r = m - 1;
    }
    return ret;
}

template <typename T>
optional<T> minCheck(T l, T r, auto check) {
    optional<T> ret;
    while (l <= r) {
        T m = midpoint(l, r);
        if (check(m))
            ret ? chmin(ret, m) : ret = m, r = m - 1;
        else
            l = m + 1;
    }
    return ret;
}

umap<ll, vi> cache;
vi query(ll k) {
    if (cache.count(k)) return cache[k];

    cout << "? " << k << endl;
    int q;
    cin >> q;
    vi xs(q);
    cin >> xs;
    cache[k] = xs;
    return xs;
}

void __run() {
    cache.clear();

    ll n;
    cin >> n;

    if (n == 1) {
        cout << "! " << 0 << endl;
        return;
    }

    // arrumar isso aqui depois
    const ll maxK = (1 << 30);

    ll curK = 1;
    vi2d ans(n);
    while (len(query(curK))) {
        if (len(query(curK)) == 1) {
            curK++;
            continue;
        }

        int v1 = query(curK)[0];
        int v2 = query(curK)[1];

        ans[v1 - 1].pb(v2 - 1);

        auto nxtK = maxCheck(curK, maxK, [&](ll guess) {
            auto ps = query(guess);
            if (len(ps) < 2) return false;
            int p0 = ps[0];
            int p2 = ps[1];
            return p0 == v1 and p2 == v2;
        });

        assert(nxtK);
        curK = *nxtK + 1;
    }

    int totEdges = 0;
    trav(ai, ans) totEdges += len(ai);

    cout << "! " << totEdges << endl;
    repn(u, n) trav(v, ans[u]) { cout << u + 1 << ' ' << v + 1 << endl; }
}

/*8<
>8*/
