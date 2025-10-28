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

vector<pair<int, int>> tree_flatten(const vector<vector<int>> &g,
                                    int root = 0) {
    vector<int> pre;
    pre.reserve(g.size());
    vector<pair<int, int>> flat(g.size());
    int timer = -1;
    auto dfs = [&](auto &&self, int u, int p) -> void {
        ++timer;
        pre.push_back(u);
        for (auto v : g[u])
            if (v != p) {
                self(self, v, u);
            }
        flat[u].second = timer;
    };
    dfs(dfs, root, -1);
    for (int i = 0; i < (int)g.size(); i++) flat[pre[i]].first = i;
    return flat;
}

#define sz(x) (int)x.size()
// #define rep(i, a, b) for (int i = (a); i < (b); i++)
#define repinv(i, a, b) for (int i = (a); i >= (b); i--)
#define for_each(x, c) for (auto x : c)
/**
        * Title: Lazy Update Segment Tree
        * Description: range query and range update
        * Complexity:
                - Query: O(log(n) * (op + ch + cmp))
                - Update: O(log(n) * (op + ch + cmp))
                - Build: O(n * op)
                - Memory: O(n * (T + bool + signed))
        * Restrictions:
                - S must be a monoid (T, id, op)
                - S must also have lazy info (L, ch, cmp)
                - Lazy updates must distribute over operation:
                        ch(op(a, b), x) = op(ch(a, x), ch(b, x))
                - Lazy composition must follow:
                        ch(a, cmp(x, y)) = ch(ch(a, x), y)
        * Observations:
                - 1-indexed and half-open only in internal implementation
                - Runtime can be increased removing lx and rx when possible
        * Tested at:
                - Range Updates and Sums (CSES)
                - Polynomial Queries (CSES)
        * Based on: https://codeforces.com/blog/entry/18051
*/

#define V vector
#define UT(s, x) using x = typename s::x
template <class S>
struct LazySeg {
    UT(S, T);
    UT(S, L);
    signed n, h;
    V<T> seg;
    V<L> lz;
    V<bool> ig;
    V<signed> lx, rx;
    LazySeg(V<T> v)
        : n(sz(v)), seg(2 * n, S::id), lz(n), ig(n, 1), lx(2 * n), rx(2 * n) {
        h = 1 + __builtin_clz(1) - __builtin_clz(n);
        rep(i, 0, n) seg[i + n] = v[i], lx[i + n] = rx[i + n] = i;
        repinv(i, n - 1, 1) calc(i), lx[i] = lx[2 * i], rx[i] = rx[2 * i + 1];
    }
    void calc(int i) { seg[i] = S::op(seg[2 * i], seg[2 * i + 1]); }
    void ch(L v, int i) { seg[i] = S::ch(seg[i], v, lx[i], rx[i]); }
    void fix(int p) { ig[p] ? calc(p) : ch(lz[p], p); }
    void apply(L v, int p) {
        ch(v, p);
        if (p < n) lz[p] = ig[p] ? v : S::cmp(lz[p], v), ig[p] = 0;
    }
    void push(int p) {
        for (int k = h; k; k--) {
            int i = (p + n) >> k;
            if (ig[i]) continue;
            apply(lz[i], 2 * i);
            apply(lz[i], 2 * i + 1);
            ig[i] = 1;
        }
    }
    void update(L v, int l, int r) {
        push(l);
        push(r);
        int cl = 0, cr = 0;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (cl) fix(l - 1);
            if (cr) fix(r);
            if (l & 1) apply(v, l++), cl = 1;
            if (r & 1) apply(v, --r), cr = 1;
        }
        for (l--; r; l /= 2, r /= 2) {
            if (cl) fix(l);
            if (cr and ((not cl) or (l != r))) fix(r);
        }
    }
    T query(int l, int r) {
        push(l);
        push(r);
        T vl = S::id, vr = S::id;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) vl = S::op(vl, seg[l++]);
            if (r & 1) vr = S::op(seg[--r], vr);
        }
        return S::op(vl, vr);
    }
};

struct S {          // E = sum of
    using T = pll;  //{E cof0, E cof1}
    using L = ll;   //{cof0, cof1}
    static constexpr T id = {0, 0};
    static T op(T a, T b) { return max(a, b); }
    static T ch(T past, L upd, int lx, int rx) {
        auto ret = past;
        past.first += upd;
        return past;
    }

    static L cmp(L cur, L upd) { return cur + upd; }
};

void __run() {
    int n;
    cin >> n;

    vi2d tree(n);
    repn(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].eb(b);
        tree[b].eb(a);
    }

    // [l, r]
    auto tf = tree_flatten(tree);
    dbg(tf);

    vi ds(n);
    vector<pll> aux;
    function<void(int, int)> dfs = [&](int u, int p) {
        aux.eb(ds[u], u + 1);
        for (auto v : tree[u]) {
            if (v != p) {
                ds[v] = ds[u] + 1;
                dfs(v, u);
            }
        }
    };

    dfs(0, -1);

    LazySeg<S> seg(aux);

    vi ans(n);

    function<void(int, int)> dfs2 = [&](int u, int p = -1) {
        // achar a resposta de u
        ans[u] = seg.query(0, n - 1).second;
        dbg(u, ans[u]);

        trav(v, tree[u]) {
            if (v != p) {
                auto [l, r] = tf[v];

                seg.update(-1, l, r);
                if (l) seg.update(1, 0, l - 1);
                if (r + 1 < n) seg.update(1, r + 1, n - 1);

                // compute others
                dfs2(v, u);

                seg.update(1, l, r);
                if (l) seg.update(-1, 0, l - 1);
                if (r + 1 < n) seg.update(-1, r + 1, n - 1);
            }
        }
    };

    dfs2(0, -1);

    trav(i, ans) cout << i << endl;
}

/*8<
>8*/
