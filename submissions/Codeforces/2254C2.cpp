/*
...
01001
10010
...
 */
#pragma once
/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif

// Fastio
#define vapo                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

// Iteration
#define rep1(a) for (int _ = 0; _ < int(a); ++_)
#define rep2(i, a) for (int i = 0; i < int(a); ++i)
#define rep3(i, a, b) for (int i = int(a); i < int(b); ++i)
#define rep4(i, a, b, c) for (int i = int(a); i < int(b); i += int(c))
#define rep1_R(a) for (int i = int(a) - 1; i >= 0; --i)
#define rep2_R(i, a) for (int i = int(a) - 1; i >= 0; --i)
#define rep3_R(i, a, b) for (int i = int(b) - 1; i >= int(a); --i)
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rep_R(...) overload3(__VA_ARGS__, rep3_R, rep2_R, rep1_R)(__VA_ARGS__)
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) for (auto &xi : ranges::views::reverse(xs))

// Template macro
#define TT template <typename T>
#define TTU template <typename T, typename U>

// Types
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
using ll = long long;
using str = string;
using ull = unsigned long long;
using ld = long double;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vs = vector<str>;
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using i128 = __int128;
using u128 = unsigned __int128;
TTU using umap = unordered_map<T, U>;
TT using uset = unordered_set<T>;
TT using pqmn = priority_queue<T, vector<T>, greater<T>>;
TT using pqmx = priority_queue<T, vector<T>>;

// random alias
#define all(j) j.begin(), j.end()
#define found(x, y) ((x).find((y)) != (x).end())
#define rall(j) j.rbegin(), j.rend()
#define len(j) (int)j.size()
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
template <typename T>
T POP(queue<T> &que) {
    T a = que.front();
    que.pop();
    return a;
}
template <typename T>
T POP(deque<T> &que) {
    T a = que.front();
    que.pop_front();
    return a;
}
template <class T, class Container, class Compare>
T POP(priority_queue<T, Container, Compare> &que) {
    T a = que.top();
    que.pop();
    return a;
}
template <typename T>
T POP(vc<T> &que) {
    T a = que.back();
    que.pop_back();
    return a;
}

TTU inline bool chmax(T &a, U const &b) { return (a < b ? a = b, 1 : 0); }
TTU inline bool chmin(T &a, U const &b) { return (a > b ? a = b, 1 : 0); }

// bit operations, i may remove this soon
using f128 = __float128;
int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(u32 x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int popcnt(u64 x) { return __builtin_popcountll(x); }
int popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 : 1); }
int popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }
int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }
int popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
int lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

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

// BEGIN: other/io.hpp
#line 1 "other/io.hpp"
#define FASTIO

// https:judge.yosupo.jp/submission/21623
namespace fastio {
static constexpr uint32_t SZ = 1 << 17;
char ibuf[SZ];
char obuf[SZ];
char out[100];
// pointer of ibuf, obuf
uint32_t pil = 0, pir = 0, por = 0;

struct Pre {
    char num[10000][4];
    constexpr Pre() : num() {
        for (int i = 0; i < 10000; i++) {
            int n = i;
            for (int j = 3; j >= 0; j--) {
                num[i][j] = n % 10 | '0';
                n /= 10;
            }
        }
    }
} constexpr pre;

inline void load() {
    memmove(ibuf, ibuf + pil, pir - pil);
    pir = pir - pil + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);
    pil = 0;
    if (pir < SZ) ibuf[pir++] = '\n';
}

inline void flush() {
    fwrite(obuf, 1, por, stdout);
    por = 0;
}

void rd(char &c) {
#if defined(LOCAL) || defined(INTERACTIVE)
    cin >> c;
#else
    do {
        if (pil + 1 > pir) load();
        c = ibuf[pil++];
    } while (isspace(c));
#endif
}

void rd(string &x) {
#if defined(LOCAL) || defined(INTERACTIVE)
    cin >> x;
#else
    x.clear();
    char c;
    do {
        if (pil + 1 > pir) load();
        c = ibuf[pil++];
    } while (isspace(c));
    do {
        x += c;
        if (pil == pir) load();
        c = ibuf[pil++];
    } while (!isspace(c));
#endif
}

template <typename T>
void rd_real(T &x) {
    string s;
    rd(s);
    x = stod(s);
}

template <typename T>
void rd_integer(T &x) {
#if defined(LOCAL) || defined(INTERACTIVE)
    cin >> x;
#else
    if (pil + 100 > pir) load();
    char c;
    do c = ibuf[pil++];
    while (c < '-');
    bool minus = 0;
    if constexpr (is_signed<T>::value || is_same_v<T, i128>) {
        if (c == '-') {
            minus = 1, c = ibuf[pil++];
        }
    }
    x = 0;
    while ('0' <= c) {
        x = x * 10 + (c & 15), c = ibuf[pil++];
    }
    if constexpr (is_signed<T>::value || is_same_v<T, i128>) {
        if (minus) x = -x;
    }
#endif
}

template <class T>
enable_if_t<is_integral_v<T> || is_same_v<T, i128> || is_same_v<T, u128>> rd(
    T &x) {
    rd_integer(x);
}

template <class T>
enable_if_t<is_floating_point_v<T> || is_same_v<T, f128>> rd(T &x) {
    rd_real(x);
}

template <class T, class U>
void rd(pair<T, U> &p) {
    rd(p.first), rd(p.second);
}
template <size_t N = 0, typename T>
void rd_tuple(T &t) {
    if constexpr (N < tuple_size<T>::value) {
        auto &x = get<N>(t);
        rd(x);
        rd_tuple<N + 1>(t);
    }
}
template <class... T>
void rd(tuple<T...> &tpl) {
    rd_tuple(tpl);
}

template <size_t N = 0, typename T>
void rd(array<T, N> &x) {
    for (auto &d : x) rd(d);
}
template <class T>
void rd(vc<T> &x) {
    for (auto &d : x) rd(d);
}

void read() {}
template <class H, class... T>
void read(H &h, T &...t) {
    rd(h), read(t...);
}

inline void wt_range(const char *s, size_t n) {
    size_t i = 0;
    while (i < n) {
        if (por == SZ) flush();
        size_t chunk = min(n - i, (size_t)(SZ - por));
        memcpy(obuf + por, s + i, chunk);
        por += chunk;
        i += chunk;
    }
}

void wt(const char c) {
    if (por == SZ) flush();
    obuf[por++] = c;
}
void wt(const char *s) { wt_range(s, strlen(s)); }
void wt(const string &s) { wt_range(s.data(), s.size()); }

template <typename T>
void wt_integer(T x) {
    if (por > SZ - 100) flush();
    if (x < 0) {
        obuf[por++] = '-', x = -x;
    }
    int outi;
    for (outi = 96; x >= 10000; outi -= 4) {
        memcpy(out + outi, pre.num[x % 10000], 4);
        x /= 10000;
    }
    if (x >= 1000) {
        memcpy(obuf + por, pre.num[x], 4);
        por += 4;
    } else if (x >= 100) {
        memcpy(obuf + por, pre.num[x] + 1, 3);
        por += 3;
    } else if (x >= 10) {
        int q = (x * 103) >> 10;
        obuf[por] = q | '0';
        obuf[por + 1] = (x - q * 10) | '0';
        por += 2;
    } else
        obuf[por++] = x | '0';
    memcpy(obuf + por, out + outi + 4, 96 - outi);
    por += 96 - outi;
}

template <typename T>
inline void wt_real(T x) {
    static char buf[1000];
    int n = std::snprintf(buf, sizeof(buf), "%.15f", (double)x);
    wt_range(buf, (size_t)n);
}

template <class T>
enable_if_t<is_integral_v<T> || is_same_v<T, i128> || is_same_v<T, u128>> wt(
    T x) {
    wt_integer(x);
}

template <class T>
enable_if_t<is_floating_point_v<T> || is_same_v<T, f128>> wt(T x) {
    wt_real(x);
}

inline void wt(bool b) { wt(static_cast<char>('0' + (b ? 1 : 0))); }

template <class T, class U>
void wt(const pair<T, U> &val) {
    wt(val.first);
    wt(' ');
    wt(val.second);
}
template <size_t N = 0, typename T>
void wt_tuple(const T &t) {
    if constexpr (N < tuple_size<T>::value) {
        if constexpr (N > 0) wt(' ');
        wt(get<N>(t));
        wt_tuple<N + 1>(t);
    }
}
template <class... T>
void wt(const tuple<T...> &tpl) {
    wt_tuple(tpl);
}
template <class T, size_t S>
void wt(const array<T, S> &val) {
    auto n = val.size();
    for (size_t i = 0; i < n; i++) {
        if (i) wt(' ');
        wt(val[i]);
    }
}
template <class T>
void wt(const vector<T> &val) {
    auto n = val.size();
    for (size_t i = 0; i < n; i++) {
        if (i) wt(' ');
        wt(val[i]);
    }
}

void print() {
    wt('\n');
#if defined(INTERACTIVE)
    flush();
#endif
}
template <class Head, class... Tail>
void print(Head &&head, Tail &&...tail) {
    wt(head);
    if (sizeof...(Tail)) wt(' ');
    print(forward<Tail>(tail)...);
}

void printS() { wt(' '); }
template <class Head, class... Tail>
void printS(Head &&head, Tail &&...tail) {
    wt(head);
    if (sizeof...(Tail)) wt(' ');
    printS(forward<Tail>(tail)...);
}

// gcc expansion. called automatically after main.
void __attribute__((destructor)) _d() { flush(); }
}  // namespace fastio
using fastio::flush;
using fastio::print;
using fastio::read;

#define INT(...)     \
    int __VA_ARGS__; \
    read(__VA_ARGS__)
#define LL(...)     \
    ll __VA_ARGS__; \
    read(__VA_ARGS__)
#define U32(...)     \
    u32 __VA_ARGS__; \
    read(__VA_ARGS__)
#define U64(...)     \
    u64 __VA_ARGS__; \
    read(__VA_ARGS__)
#define STR(...)        \
    string __VA_ARGS__; \
    read(__VA_ARGS__)
#define CHAR(...)     \
    char __VA_ARGS__; \
    read(__VA_ARGS__)
#define DBL(...)        \
    double __VA_ARGS__; \
    read(__VA_ARGS__)

#define VEC(type, name, size) \
    vector<type> name(size);  \
    read(name)
#define VV(type, name, h, w)                       \
    vector<vector<type>> name(h, vector<type>(w)); \
    read(name)

void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }
// END: other/io.hpp
/*8<============~ END TEMPLATE ~============}>8*/
void __init();
void __run();
void __pre_run();

int32_t main() {
#ifndef LOCAL
    vapo;
#endif
    __init();

    int T = 1;

    read(T);

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
    INT(n);
    STR(a, b);
    dbg(n, a, b);

    vvvc<int> pos(2, vvc<int>(2));
    rep_R(i, 0, n) { pos[a[i] - '0'][i & 1].eb(i); }

    dbg(pos);

    ll ans = 0;
    rep(i, 0, n) {
        dbg(i);
        int bi = b[i] - '0';
        auto &ps = pos[bi][i & 1];

        if (!len(ps)) {
            cout << -1 << endl;
            return;
        }

        if (ps.back() > i) ans += (ps.back() - i) / 2;

        ps.pop_back();
    }

    cout << ans << endl;
}

/*8<
>8*/
