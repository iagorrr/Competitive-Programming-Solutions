/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
using namespace std;

/*8<{=========~ BEGIN ORDERED SET ~===========>8*/
/*8<
     @Title:

          Orderd Set (GNU PBDS)

     @Usage:

          If you need an ordered \textbf{multi}
          set you may add an id to each value.
          Using greater\_equal, or less\_equal
          is considered undefined behavior.


          \begin{compactitem}
            \item  \textbf{order\_of\_key (k)}:
            Number of items strictly
            smaller/greater than k .
            \item  \textbf{find\_by\_order(k)}:
K-th element in a set (counting from zero).
          \end{compactitem}


     @Time:

          Both $O(\log{N})$

     @Warning:

          Is 2 or 3 times slower then a regular
set/map. >8*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;

/*8<===========~ END ORDERED SET
 * ~============}>8*/

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

void run() {
        int N, K;
        cin >> N >> K;

        vector<pll> XS(N);
        rep(i, 0, N) cin >> XS[i].second;
        rep(i, 0, N) cin >> XS[i].first;

        sort(rall(XS));

        int idx = 0;
        ordered_set<pii> ost;
        for (auto &[b, a] : XS) {
                ost.insert({a, idx++});
        }

        ll ans = 0;

        dbg(ost);
        ll l = 0;
        do {
                dbg(XS);
                ll r = XS.back().first;
                auto best = maxCheck(l, r, [&](ll x) {
                        return ost.order_of_key({x, -1}) <= K;
                });
                if (best) {
                        ll cur = *best * len(XS);
                        dbg(cur);
                        ans = max(ans, cur);
                }

                while (len(XS) and XS.back().first == r) {
                        ost.erase({XS.back().second, len(XS) - 1});
                        XS.pop_back();
                }
                l = r + 1;
        } while (len(XS));

        cout << ans << endl;
}
/*8<
 * AC, brute force, binary search, data strucutures
>8*/
