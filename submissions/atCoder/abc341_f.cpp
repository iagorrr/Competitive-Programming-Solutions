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
        rep(i, os.iword(0), xs.size()) os << xs[i]
                                          << (i == xs.size() ? "" : " ");
        os.iword(0) = 0;
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

    Knapsack

  @Description:

    Finds the maximum score you can achieve,
    given that you have $N$ items, each item has
    a $cost$, a $point$ and a $quantity$, you can
    spent at most $maxcost$ and buy each item the
    maximum quantity it has.

  @Time:

    $O(n \cdot maxcost \cdot \log{maxqtd})$

  @Memory:

    $O(maxcost)$.

>8*/

ll knapsack(const vi &weight, const vll &value, const vi &qtd, int maxCost) {
        vi costs;
        vll values;
        for (int i = 0; i < len(weight); i++) {
                ll q = qtd[i];
                for (ll x = 1; x <= q; q -= x, x <<= 1) {
                        costs.eb(x * weight[i]);
                        values.eb(x * value[i]);
                }
                if (q) {
                        costs.eb(q * weight[i]);
                        values.eb(q * value[i]);
                }
        }

        vll dp(maxCost + 1);
        for (int i = 0; i < len(values); i++) {
                for (int j = maxCost; j > 0; j--) {
                        if (j >= costs[i])
                                dp[j] = max(dp[j],
                                            values[i] + dp[j - costs[i]]);
                }
        }
        return dp[maxCost];
}

void __run() {
        int n, m;
        cin >> n >> m;

        vi2d adj(n);
        rep(i, 0, m) {
                int u, v;
                cin >> u >> v;
                u--, v--;
                adj[u].eb(v);
                adj[v].eb(u);
        }

        vll ws(n);
        cin >> ws;

        vll as(n);
        cin >> as;

        vll memo(n, -1);
        auto f = [&](auto &&f_, int u) -> ll {
                auto &ret = memo[u];
                if (~ret) return ret;

                vll pts;
                vi weights;

                trav(v, adj[u]) {
                        if (ws[u] > ws[v]) weights.eb(ws[v]), pts.eb(f_(f_, v));
                }
                dbg(u, pts, weights);

                vi cs(len(as), 1);
                return ret = knapsack(weights, pts, cs, ws[u] - 1) + 1;
        };

        ll ans = 0;
        rep(i, 0, n) {
                ans += as[i] * f(f, i);
                dbg(i, f(f, i));
        }

        cout << ans << endl;
}

/*8<
 * the graph is actually a dag.
 * So when we want to perform some operation the problem is which nodes to
actually choose.
 * Feels like dp.
 *
 * we can make something n by w
 *
 * the total of edges is quite small also.
>8*/
