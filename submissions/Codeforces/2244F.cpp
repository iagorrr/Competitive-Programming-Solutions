/*
...

- se tiver numero repetido fudeo
- ah n tem
- so preciso pra cada nó guardar o menor e maior valor que tem na subárvore dele
- assumindo que todos os filhos estejam safe eu posso so reordenar eles
dai começando do que tem o menor L eu tenho que ir de cada par e eles serem
"certinhos", se for true pra todos os nós é vapo

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

void __run() {
    int n;
    cin >> n;

    vi ps(n, -1);
    rep(i, 1, n) { cin >> ps[i], ps[i]--; }

    vi as(n);
    cin >> as;
    trav(ai, as) ai--;

    vi2d childs(n);
    rep(i, 1, n) {
        if (ps[i] == -1) continue;
        childs[ps[i]].pb(i);
    }
    trav(x, childs) sort(all(x));

    dbg(childs);

    const ll oo = 1e10;
    vll mx(n, -oo), mn(n, oo);

    bool ok = true;
    function<void(int)> dfs = [&](int u) {
        dbg("Processing ", u, childs[u]);
        if (len(childs[u]) == 0) {
            mx[u] = mn[u] = as[u];
            return;
        }

        trav(v, childs[u]) {
            dfs(v);
            chmax(mx[u], mx[v]);
            chmin(mn[u], mn[v]);
        }

        vector<pair<int, int>> rngs;
        trav(v, childs[u]) { rngs.eb(mn[v], mx[v]); }
        dbg(rngs);

        int m = len(rngs);

        int s = 0;
        repn(i, m) if (rngs[i].first < rngs[s].first) s = i;

        repn(i, len(rngs) - 1) {
            auto [cl, cr] = rngs[(i + s) % m];
            auto [nl, nr] = rngs[(i + s + 1) % m];
            ok &= cr + 1 == nl;
        }
        dbg(u, s, ok);
    };
    dfs(0);

    cout << (ok ? "YES" : "NO") << endl;
}

/*8<
>8*/
