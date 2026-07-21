/*
...

- não tem auto loop !
- grafo com rabo !
- contagemzinha safe né
- todas as arestas que não são do ciclo não vão conseguir gerar novos ciclos
- então os únicos flips que
- posso ter algo que não é um ciclo mas de algum modo quando flipo vira um ciclo
?
- pode né...
- então o que não é um ciclo pode virar
- tem que considerar como se fosse um grafo não direcionado
- pegar os tamanhos dos ciclos
- e vapo ?


- supondo que seja isso, todas as arestas
- sempre já morren os ciclos mesmo eu acho, pq não tem auto loop
- vejo o tamanho de cada ciclo
- todo o resto é 2^n  tanto faz, mas aí pra cada ciclo tem dois casos
que não dá pra fazer (2^cycleSize - 2) ciclo pra um lado e ciclo pro outro

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
@Title: Functional Graph (Cycle-Tree Decomposition + Optional Binary Lifting)

@Description: Decomposes a functional graph into cycle-tree components in $O(N)$
time and space, calculating cycle sizes, node positions, and distances.
Optionally builds a binary lifting table to support $k$-th successor
and distance queries.

@Usage: Instantiate passing a 0-indexed vector $next$ where $next[u]$
is the outgoing edge.
IMPORTANT: Must call `buildBinaryLifting()` before using `kth()` or `dist()`.
- $kth(u, k)$: handles arbitrarily large $k$ efficiently using modulo on cycles.
- $dist(u, v)$: returns shortest distance or -1 if unreachable.
Warning: Cases where a node has no outgoing edge (e.g., $next[u] = -1$) are
undefined behavior. Handle terminal nodes outside the decomposition.

@Time: Construction $O(N)$, buildBinaryLifting $O(N \log N)$, kth $O(\log N)$,
dist $O(\log N)$

@Memory: $O(N)$ base, $O(N \log N)$ with binary lifting
>8*/

struct FunctionalGraph {
    int n;
    vector<int> next;
    vector<int> cycleIds;
    vector<int> cycleSizes;
    vector<int> distanceToCycle;
    vector<int> cyclePos;
    vector<vector<int>> succ;

    FunctionalGraph(const vector<int> &next) : n(next.size()), next(next) {
        cycleIds.assign(n, 0);
        distanceToCycle.assign(n, 0);
        cyclePos.assign(n, -1);

        vector<int> inDegree(n, 0);
        for (int i = 0; i < n; i++) {
            inDegree[next[i]]++;
        }

        queue<int> q;
        for (int u = 0; u < n; u++) {
            if (inDegree[u] == 0) q.push(u);
        }

        vector<int> topologicOrder;
        topologicOrder.reserve(n);

        while (not q.empty()) {
            int curNode = q.front();
            q.pop();

            topologicOrder.push_back(curNode);

            int nextNode = next[curNode];
            inDegree[nextNode]--;

            if (inDegree[nextNode] == 0) q.push(nextNode);
        }

        for (int u = 0; u < n; u++) {
            if (inDegree[u] == 0) continue;

            int curNode = u;
            int cycleSize = 0;

            while (inDegree[curNode] != 0) {
                inDegree[curNode] = 0;

                distanceToCycle[curNode] = 0;
                cycleIds[curNode] = (int)cycleSizes.size();
                cyclePos[curNode] = cycleSize;
                cycleSize++;

                curNode = next[curNode];
            }

            cycleSizes.push_back(cycleSize);
        }

        for (auto v : ranges::views::reverse(topologicOrder)) {
            int nv = next[v];
            cycleIds[v] = cycleIds[nv];
            distanceToCycle[v] = distanceToCycle[nv] + 1;
        }
    }

    void buildBinaryLifting() {
        if (!succ.empty()) return;

        int maxLog = __lg(n) + 1;
        succ.assign(maxLog, vector<int>(n));
        succ[0] = next;

        for (int k = 1; k < maxLog; k++) {
            for (int i = 0; i < n; i++) {
                succ[k][i] = succ[k - 1][succ[k - 1][i]];
            }
        }
    }

    int kth(int u, ll k) const {
        if (k <= 0) return u;

        // Fast-forward huge K by reaching the cycle and applying modulo
        if (k > distanceToCycle[u]) {
            ll distToC = distanceToCycle[u];
            k -= distToC;

            int maxLog = succ.size();
            for (int i = 0; i < maxLog; i++) {
                if ((1ll << i) & distToC) u = succ[i][u];
            }

            k %= cycleSizes[cycleIds[u]];
        }

        // Advance the remaining K <= N steps
        int maxLog = succ.size();
        for (int i = 0; i < maxLog; i++) {
            if ((1ll << i) & k) u = succ[i][u];
        }

        return u;
    }

    int dist(int u, int v) const {
        if (cycleIds[u] != cycleIds[v]) return -1;

        // Check if v is an ancestor of u in the tree paths
        if (distanceToCycle[u] >= distanceToCycle[v]) {
            int diff = distanceToCycle[u] - distanceToCycle[v];
            if (kth(u, diff) == v) return diff;
        }

        // If v is in the cycle, u can definitely reach it
        if (distanceToCycle[v] == 0) {
            int u_entry = kth(u, distanceToCycle[u]);
            int cSize = cycleSizes[cycleIds[u]];

            // O(1) distance inside the cycle using positions
            int distInCycle = (cyclePos[v] - cyclePos[u_entry] + cSize) % cSize;
            return distanceToCycle[u] + distInCycle;
        }

        return -1;
    }
};

template <ll m>
struct mod_int {
    ll x;

    mod_int(ll v = 0) {
        x = v % m;
        if (x < 0) x += m;
    }

    mod_int &operator+=(mod_int const &b) {
        x += b.x;
        if (x >= m) x -= m;
        return *this;
    }

    mod_int &operator-=(mod_int const &b) {
        x -= b.x;
        if (x < 0) x += m;
        return *this;
    }
    mod_int &operator*=(mod_int const &b) {
        x = (ll)x * b.x % m;
        return *this;
    }

    void exp(ll e) {
        mod_int res = 1;
        while (e) {
            if (e & 1) res *= this->x;
            this->x *= this->x;
            e >>= 1;
        }
    }

    friend mod_int mpow(mod_int a, ll e) {
        mod_int res = 1;
        while (e) {
            if (e & 1) res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }
    friend mod_int inverse(mod_int a) { return mpow(a, m - 2); }

    mod_int &operator/=(mod_int const &b) { return *this *= inverse(b); }
    friend mod_int operator+(mod_int a, mod_int const b) { return a += b; }
    mod_int operator++(int) { return this->x = (this->x + 1) % m; }
    mod_int operator++() { return this->x = (this->x + 1) % m; }
    friend mod_int operator-(mod_int a, mod_int const b) { return a -= b; }
    friend mod_int operator-(mod_int const a) { return 0 - a; }
    mod_int operator--(int) { return this->x = (this->x - 1 + m) % m; }

    mod_int operator--() { return this->x = (this->x - 1 + m) % m; }
    friend mod_int operator*(mod_int a, mod_int const b) { return a *= b; }
    friend mod_int operator/(mod_int a, mod_int const b) { return a /= b; }
    friend ostream &operator<<(ostream &os, mod_int const &a) {
        return os << a.x;
    }
    friend bool operator==(mod_int const &a, mod_int const &b) {
        return a.x == b.x;
    }
    friend bool operator!=(mod_int const &a, mod_int const &b) {
        return a.x != b.x;
    }
};

const ll mod = 1'000'000'000 + 7;

using mint = mod_int<mod>;
mint fpow(ll a, ll b) {
    mint ret(1);

    mint ma(a);
    while (b) {
        if (b & 1) ret *= ma;
        ma *= ma;
        b >>= 1;
    }

    return ret;
}

void __run() {
    int n;
    cin >> n;

    vi next(n);
    cin >> next;
    trav(x, next) x--;

    FunctionalGraph fg(next);

    mint ans = 1;
    int m = n;
    trav(ci, fg.cycleSizes) {
        ans *= (fpow(2, ci) - 2);
        m -= ci;
    }
    ans *= fpow(2, m);

    cout << ans << endl;
}

/*8<
>8*/
