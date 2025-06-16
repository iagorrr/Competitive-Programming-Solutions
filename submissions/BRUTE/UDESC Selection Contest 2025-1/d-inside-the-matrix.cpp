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

// read vector
// TODO: abstract this to any container.
template <typename T>
std::istream &operator>>(std::istream &is, std::vector<T> &vec) {
        for (auto &element : vec) {
                is >> element;
        }
        return is;
}

// print vector
// TODO: abstract this to any container.
template <typename T>
ostream &operator<<(ostream &os, vector<T> &xs) {
        rep(i, os.iword(0), xs.size()) os << xs[i]
                                          << (i == xs.size() ? "" : " ");
        os.iword(0) = 0;
        return os;
}

// sum a vector, using the default constructor as initial value
// TODO: abstract this to any container.
template <typename T>
T sumList(vector<T> &xs) {
        return accumulate(all(xs), T());
}

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

        // cin >> T;

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

bool reach(int xs, int ys, vi2d &vss, int f) {
        if (vss[xs][ys] & f) return false;

        vi2d vis(len(vss), vi(len(vss.back())));

        static int dx[] = {1, -1, 0, 0};
        static int dy[] = {0, 0, 1, -1};

        vector<pii> s;
        vis[xs][ys] = 1;
        s.eb(xs, ys);
        while (len(s)) {
                auto [x, y] = s.back();
                s.ppb();

                rep(d, 0, 4) {
                        int x2 = x + dx[d];
                        int y2 = y + dy[d];

                        if (clamp(x2, 0, len(vss) - 1) == x2 and
                            clamp(y2, 0, len(vss.back()) - 1) == y2) {
                                if (vis[x2][y2]) continue;

                                if (f & vss[x2][y2]) {
                                        dbg(f, x2, y2, vss[x2][y2]);
                                        continue;
                                } else {
                                        vis[x2][y2] = 1;
                                        s.eb(x2, y2);
                                }
                        }
                }
        }
        dbg(vis);

        return vis.back().back();
}

int solve(int x, int y, vi2d &vss) {
        int c = 0;
        int a = vss[x][y];

        ll mask = 1ll << 30ll;
        for (; mask; mask /= 2ll) {
                bool ok = reach(x, y, vss, c | mask);
                dbg(x, y, mask, c | mask, ok);
                if (ok)
                        c |= mask;
                else
                        a |= mask;
        }

        return a;
}

void __run() {
        int n, m;
        cin >> n >> m;

        int x, y;
        cin >> x >> y;
        x--, y--;

        vi2d vss(n, vi(m));
        rep(i, 0, n) { rep(j, 0, m) cin >> vss[i][j]; }

        auto ans1 = solve(0, 0, vss);
        auto ans2 = solve(x, y, vss);

        cout << ans1 << ' ' << ans2 << endl;
}

/*8<
>8*/
