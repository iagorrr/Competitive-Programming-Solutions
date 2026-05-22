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

const ll mod = 1'000'000'000 + 7;

struct mint {
    ll v;
    constexpr mint(ll x) : v(x % mod) {}
    constexpr mint() : v(0) {}
    mint operator+(const mint o) const { return mint((o.v + v)); }
    mint operator*(const mint o) const { return mint((o.v * v)); }
};

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
        : n(int(v.size())),
          seg(2 * n, S::id),
          lz(n),
          ig(n, 1),
          lx(2 * n),
          rx(2 * n) {
        h = 1 + __builtin_clz(1) - __builtin_clz(n);
        for (int i = 0; i < n; i++)
            seg[i + n] = v[i], lx[i + n] = rx[i + n] = i;
        for (int i = n - 1; i >= 0; i--)
            calc(i), lx[i] = lx[2 * i], rx[i] = rx[2 * i + 1];
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

struct S {
    using T = pair<mint, ll>;
    using L = mint;
    static constexpr T id = T{mint(0ll), 0ll};
    static T op(T a, T b) { return {a.first + b.first, a.second + b.second}; }
    static T ch(T past, L upd, int lx, int rx) {
        auto [v, sz] = past;
        v = (v + mint(mint(sz) * upd));
        return T{v, sz};
    }
    static L cmp(L cur, L upd) { return cur + upd; }
};

void __run() {
    ll N, Q;
    cin >> N >> Q;

    vector<ll> ls{1};
    unordered_map<ll, pair<ll, ll>> rngs;
    while (ls.back() <= N) {
        auto l = ls.back();
        ll k = N / l;
        ll r = N / k;
        rngs[k] = {l, r};
        ls.push_back(r + 1);
    }
    ls.push_back(N + 1);

    vector<array<ll, 5>> qs;
    for (ll i = 0; i < Q; i++) {
        ll o;
        cin >> o;

        ll l, r;
        cin >> l >> r;

        ll k = -1, x = -1;
        if (o == 2) {
            cin >> k >> x;
            if (!rngs.count(k)) continue;
            auto [lk, rk] = rngs[k];
            l = max(lk, l);
            r = min(rk, r);

            if (l > r) continue;
        }
        ls.push_back(l), ls.push_back(r + 1);
        qs.push_back({o, l, r, k, x});
    }
    // int ilen = len(ls);
    // for (int i = 0; i < ilen; i++) {
    //     ls.push_back(ls[i] + 1);
    //     ls.push_back(ls[i] - 1);
    // }

    sort(all(ls)), ls.erase(unique(all(ls)), end(ls));

    vector<pair<mint, ll>> aux;
    for (int i = 0; i < (int)ls.size(); i++) {
        ll sz = i + 1 == ls.size() ? 1 : ls[i + 1] - ls[i];
        aux.push_back({mint(0), sz});
    }

    LazySeg<S> seg(aux);
    for (auto [o, l, r, k, x] : qs) {
        auto li = lower_bound(all(ls), l) - ls.begin();
        auto itr = lower_bound(all(ls), r);
        if (*itr > r) itr--;
        auto ri = itr - ls.begin();

        if (o == 1) {
            cout << seg.query(li, ri).first.v << '\n';
        } else {
            seg.update(x, li, ri);
        }
    }
}
/*8<
>8*/
