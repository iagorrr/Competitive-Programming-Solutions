/*
aaaaa

*/
/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>

#include <numeric>
#include <vector>
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
#define spc ' '
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

void __run() {
    int n;
    cin >> n;

    vs grid(n);
    cin >> grid;

    vi gridCnt(n);
    repn(u, n) {
        repn(v, n) { gridCnt[u] += grid[u][v] == '1'; }
    }

    auto adj = grid;
    auto adjCnt = gridCnt;

    vi2d ans(n);
    int totEdges = 0;
    repn(u, n) {  // O(N)
        // em teoria roda n-1 vezes
        while (adjCnt[u] > 1) {
            int v = -1;
            repn(mayV, n) {  // O(N)
                if (mayV != u and adj[u][mayV] == '1')
                    if (v == -1 or gridCnt[mayV] > gridCnt[v]) v = mayV;
            }

            ans[u].pb(v);
            totEdges++;
            if (totEdges > n - 1) {
                cout << "NO" << endl;
                return;
            }
            repn(x, n) {  // O(N)
                if (grid[v][x] == '1' and adj[u][x])
                    adj[u][x] = '0', adjCnt[u]--;
            }
        }
    }

    if (totEdges != n - 1) {
        cout << "NO" << endl;
        return;
    }

    vs newGrid(n, str(n, '0'));
    function<void(int)> dfs = [&](int u) {
        if (newGrid[u][u] == '1') return;

        newGrid[u][u] = '1';

        trav(v, ans[u]) {
            dfs(v);

            repn(i, n) {
                if (newGrid[v][i] == '1') newGrid[u][i] = '1';
            }
        }
    };
    repn(i, n) dfs(i);

    if (newGrid != grid) return cout << "NO" << endl, (void)0;

    auto ans2 = ans;
    repn(u, n) {
        trav(v, ans[u]) { ans2[v].pb(u); }
    }
    bool haveCycle = false;
    vi vis(n);
    function<void(int, int)> dfs2 = [&](int u, int p) {
        dbg("dfs2", u, p);
        vis[u] = 1;
        trav(i, ans2[u]) if (i != p and i != u) {
            if (vis[i]) {
                haveCycle = true;
                dbg(u, i);
            } else
                dfs2(i, u);
        }
    };

    dfs2(0, -1);

    dbg(haveCycle);
    if (haveCycle or accumulate(all(vis), 0) != n) {
        cout << "NO" << endl;
        return;
    } else {
        cout << "YES" << endl;
        repn(u, n) trav(v, ans[u]) cout << u + 1 << spc << v + 1 << endl;
    }
}

/*8<
>8*/
