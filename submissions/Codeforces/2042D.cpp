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

void run() {
        int N;
        cin >> N;

        vector<pll> intervals(N);
        for (auto &[l, r] : intervals) {
                cin >> l >> r;
        }

        map<ll, vll> os, cs;
        set<ll> ts;
        rep(i, 0, N) {
                auto &[l, r] = intervals[i];
                os[l].eb(i), cs[r].eb(i);
                ts.emp(l), ts.emp(r);
        }

        multiset<ll> ls, rs;
        vector<pll> ans{all(intervals)};
        trav(ti, ts) {
                dbg(ls, rs);
                // primeiro os abrindo
                for (auto idx : os[ti]) {
                        auto &[l, r] = intervals[idx];
                        ls.emp(l), rs.emp(r);
                }

                for (auto idx : os[ti]) {
                        auto &[l, r] = intervals[idx];
                        // menor r maior que o meu,
                        // não tem garantia de que esse suposto
                        // r abriu depois de mim, ve isso na hora que abre ent
                        auto itr = next(rs.lower_bound(r));
                        if (itr != end(rs)) {
                                ans[idx].second = *itr;
                        }
                }

                // depois os fechando
                for (auto idx : cs[ti]) {
                        auto &[l, r] = intervals[idx];

                        // maior l menor que o meu, se tiver vários tem que ser
                        // ele msm... pega a última ocorrência do L
                        auto it = prev(ls.upper_bound(l));
                        if (it != begin(ls)) {
                                it--;
                                ans[idx].first = *it;
                        }
                }
                for (auto idx : cs[ti]) {        // so remover...
                        auto &[l, r] = intervals[idx];
                        ls.extract(l), rs.extract(r);
                }
        }

        dbg(intervals, ans);
        rep(i, 0, N) {
                ll sz1 = intervals[i].second - intervals[i].first + 1;
                ll sz2 = ans[i].second - ans[i].first + 1;
                cout << sz2 - sz1 << endl;
        }
}

/*8<
4
3
3 8
2 5
4 5
2
42 42
1 1000000000
3
42 42
1 1000000000
42 42
6
1 10
3 10
3 7
5 7
4 4
1 2

AC, sortings, implementation, two pointers, sliding window
>8*/
