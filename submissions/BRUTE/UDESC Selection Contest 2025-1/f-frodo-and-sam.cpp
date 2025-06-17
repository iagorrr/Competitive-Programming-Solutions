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

void __run() {
        int n, s, f;
        cin >> n >> f >> s;

        vi ps(n);
        cin >> ps;

        vi qs(n);
        cin >> qs;

        vi pos_of_i_in_q(n + 1);
        rep(i, 0, n) pos_of_i_in_q[qs[i]] = i;

        vi plms(n), qlms(n);
        for (int pl = 0; pl < n;) {
                int ql = pos_of_i_in_q[ps[pl]];
                vector<pii> stk;
                while (ql < n and pl < n and ps[pl] == qs[ql]) {
                        stk.eb(pl, ql);
                        pl++, ql++;
                }

                int sz = 0;
                while (len(stk)) {
                        auto [pi, qi] = stk.back();
                        stk.ppb();
                        plms[pi] = qlms[qi] = sz;
                        sz++;
                }
        }

        dbg(plms);
        dbg(qlms);

        ll ans = LLONG_MAX;
        rep(i, 0, n) {
                ll lp = i, lq = pos_of_i_in_q[ps[i]];
                ll rp = i + plms[i], rq = lq + plms[i];

                ll szf = (lp + lq);
                ll ft = szf * f;

                ll szs = (n - 1 - rp + n - 1 - rq);
                ll st = szs * s;

                dbg(lp, rp, szs, st);
                dbg(lq, rq, szf, ft);
                cerr << "\n\n\n";

                chmin(ans, max(st, ft));
        }

        cout << ans << endl;
}

/*8<
 * AC, greedy
>8*/
