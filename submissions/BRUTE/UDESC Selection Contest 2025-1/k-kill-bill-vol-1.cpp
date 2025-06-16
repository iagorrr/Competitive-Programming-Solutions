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

int solve(int i, bool m, const vi &as, vi2d &mem, umap<int, vi> &ps) {
        if (i >= len(as)) return 0;

        auto &ret = mem[i][m];
        if (~ret) return ret;

        int ans = 1e9;

        chmin(ans, !m + solve(i + 1, 0, as, mem, ps));

        int ai = as[i];
        auto it = upper_bound(all(ps[ai]), i);
        if (it != end(ps[ai])) {
                dbg(i, *it);
                chmin(ans, !m + solve(*it, 1, as, mem, ps));
        }

        return ret = ans;
}

void __run() {
        int n;
        cin >> n;

        vi as(n);
        cin >> as;

        vi2d mem(n, vi(2, -1));
        umap<int, vi> ps;
        rep(i, 0, n) ps[as[i]].eb(i);

        cout << solve(0, 0, as, mem, ps) << endl;
}

/*8<
 * only distinct values the answer is N
 * first and last equal, the answer is 1
 *
 * if think there may be a DP approach
 *
 * considering i'm at position i, i can either
 * jump to another positino j jusch that a[j] == a[i]
 * and keep solving from that point.
 *
 * or just move and don't merge any segment.
 *
 * we could list every position of some number.
 * and simply choose a position greater than his.
 *
 * but it would be square, as transiciton is linear
 *
 * tomake transition O(1), only merge i with the next occcurence
 * of a[i], and the next such occurence may merge with the
 * "next of the next", and so on, making it equivalent to a big merge
 * at once.
 *
 * just need to keep track that we arrived at i with a merge
 * so we don't increment the answer again...
>8*/
