/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>

#include <algorithm>
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
using ll = long long;
#define endl '\n'
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
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
template <typename T, typename T2>
using umap = unordered_map<T, T2>;
template <typename T>
using pqmn = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using pqmx = priority_queue<T, vector<T>>;
template <typename T, typename U>
inline bool chmax(T &a, U const &b) {
        return (a < b ? a = b, 1 : 0);
}
template <typename T, typename U>
inline bool chmin(T &a, U const &b) {
        return (a > b ? a = b, 1 : 0);
}

template <typename T>
std::istream &operator>>(std::istream &is, std::vector<T> &vec) {
        for (auto &element : vec) {
                is >> element;
        }
        return is;
}

/*8<============~ END TEMPLATE ~============}>8*/
void run();

int32_t main() {
#ifndef LOCAL
        fastio;
#endif

        int T = 1;

        cin >> T;

        rep(t, 0, T) {
                dbg(t);
                run();
        }
}

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

/*8<

  @Problems:
    https://codeforces.com/contest/1547/problem/F

>8*/

using ll = long long;

struct Node {
        ll value;
        bool undef;
        Node() : value(1), undef(1) {};        // Neutral element
        Node(ll v) : value(v), undef(0) {};
};

inline Node combine(const Node &nl, const Node &nr) {
        if (nl.undef) return nr;
        if (nr.undef) return nl;
        Node m;
        m.value = gcd(nl.value, nr.value);
        m.undef = false;
        return m;
}

template <typename T = Node, auto F = combine>
struct SegTree {
        int n;
        vector<T> st;
        SegTree(int _n) : n(_n), st(n << 1) {}

        void assign(int p, const T &k) {
                for (st[p += n] = k; p >>= 1;)
                        st[p] = F(st[p << 1], st[p << 1 | 1]);
        }

        T query(int l, int r) {
                T ansl, ansr;
                for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
                        if (l & 1) ansl = F(ansl, st[l++]);
                        if (r & 1) ansr = F(st[--r], ansr);
                }
                return F(ansl, ansr);
        }
};

void run() {
        int N;
        cin >> N;

        vll AS(N);
        cin >> AS;

        vll ds;
        rep(i, 0, N - 1) ds.eb(abs(AS[i] - AS[i + 1]));

        SegTree seg(N - 1);
        rep(i, 0, N - 1) seg.assign(i, ds[i]);

        auto ans = maxCheck(1, N, [&](int sz) {
                if (sz == 1) return true;
                sz--;
                for (int l = 0, r = sz - 1; r < N - 1; r++, l++) {
                        if (seg.query(l, r).value != 1) return true;
                }
                return false;
        });

        cout << ans.value() << endl;
}

/*8<
 *      7 14 21 28
 *      +1
 *      8 15 22 29 dá errado nisso aqui !
 *      +1
 *      9 16 23 30
 *
 *      aqui9 todo mudno tem uma diferença
 *      múltipla de 7
 *      então todo mundo se altera em razões de 7
 *
 *      então se existe essa razão comum é vapo
 *      nenhum deles tem a mesma congurencia nem 2 e nem 3
 *      mas tem 7
 *
 *
 *      8 15 22 29
 *      %6
 *      2  3 2 5
 *
 *      pq o 7 é válido ali ?
 *
 *      não da pra testar todos os restos possíveis
 *
 *      todos os números são distintos !
 *
 *      oque eu faço com isso ?
 *
 *      AC, math, number theory, data structures, binary search
>8*/
