/*
...
As operações se impactam ?


Essencialmente vai pegar um vetor zerado
e daí tu escolhe um outro vetor qualquer
e original[u] = novo[u%len(novo)]
tudo zero indexado


- importante ! todos os valores de novo são distintos

e daí quer saber se dá pra chegar no vetor final B
2 3 5 3 4

todos os valores de novo são menores iguais a n
e todoso s valores que ele quer no vetor final tbm são...

se todos os valores são distintos é izi
só fazer novo = b


se tiver dois valores iguais tipo b[i] = b[j]

significa que i = j (mod size)
onde size é o tamanho da última operação que eu fiz...
nesse caso isso tem que ser verdade para todos os valores que teem tanan
igual...


não existe restrição de tamanho


a = b = c = d = e = f (% lastSize)
se todos esses valores forem iguais....
a ultima operação nem sempre vai setar os valores né


vai né

se eu colocar um m menor que n todos os valores de m vão ser atiingidos então
sim a ultima operação vai setar tudo


se eu fizer um m > n somente os primeiros valores vão ser atingidos


dá pra fazer em uma operação só ?


caso que é yes : 2 3 5 3 4

0 1 2 3 4
2 3 5 3 4

0 zero nos diz o que

l[0 % m] = 2
l[0] = 2


l[1%m] = 3
l[1] = 3


se eu quiser terminar o tamanho eu volto pro l[0]


acho que não dá pra fazer 1 indexado...


funcional graph ??



primeira coisa transforma em 1...s

idx = 1 2 3 4 5
val = 1 2 4 2 3

tem 4 valores distintos e tem repetidos logo nosso vetor tem que ter tamnho 4 ?




1 -> 1
2 -> 2





- entendi tudo errado po
- tem que trocar somente os valores que estão nos lis



tu escolhe uns indices ai e dai cada valor desses indices vai ter
que virar o next !


2 3 5 4 3


l = [1, 2, 3]
pega os indices 1 2 e 3 e eles vao virar o valor
disso dai cicclado
2 3 1

e o tamanho de l é fixo !


ook

entao se b[i] = x, significa que tem que rolar uma operação ai
tal que em l tenha l = [ .... l, x, ...]

ai o rolê é se da pra decompor isso certinho


1 2 3 4 5
2 3 5 3 4


só os ciclos que tem que ser resolvidos os galhos é foda-se


é um grafo com rabo mesmo

k tem que dividir todos os ciclos ?

os de tamanho 1 ignora









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

@Warning: Not fully tested yet !
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

void __run() {
    int n;
    cin >> n;
    int k;
    cin >> k;

    vi nxt(n);
    cin >> nxt;
    trav(ni, nxt) ni--;

    FunctionalGraph fg(nxt);

    dbg(fg.cycleSizes);

    bool ok = true;
    for (auto cs : fg.cycleSizes) {
        ok &= (cs == k);
    }

    if (k == 1) {
        vi aux(n);
        iota(all(aux), 0);
        ok &= aux == nxt;
    }
    cout << (ok ? "YES" : "NO") << endl;
}

/*8<
>8*/
