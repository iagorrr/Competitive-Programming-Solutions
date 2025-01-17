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

void run() {
        int N;
        cin >> N;

        vll AS(N);
        trav(ai, AS) cin >> ai;

        ll ans = 0;

        ordered_set<pair<ll, int>> ost;
        unordered_map<ll, ll> hist;
        rep(i, 0, N) {
                ll tot = len(ost);
                ll less = ost.order_of_key({AS[i], -1});
                ll greater = tot - less - hist[AS[i]];
                dbg(less, greater);

                ans += min(less, greater);
                ost.insert({AS[i], i});
                hist[AS[i]]++;
        }

        cout << ans << endl;
}

/*8<
 * 6
4

CASO 1:
3 7 5 5

5 (3 7 5) + 1
ou
(3 7 5) 5 + 1


(3 7) 5 + 1
ou
5 (3 7)+ 1


(3) 7 + 0
out
7 (3) + 1

R = 1 + 1 + 0 = 2

CASO 2
3
3 2 1

(3 2) 1  + 2
ou
1 (3 2) + 0


2 (3) + 0

(3) + 1

R = 0 + 0 = 0



CASO 3:
3
3 1 2

(3 1) 2 + 1
ou
2 (3 1) + 1

(3) 1 + 1
ou
1 (3) + 0

R = 1 + 0 = 1

CASO 4:
4
-1 2 2 -1

(-1 2 2) -1 + 2
ou
-1 (-1 2 2) + 0

(-1 2) 2 + 0
ou
2 (-1 2)  + 1

(-1) 2 + 0
ou
2 (-1) + 1
R = 0 + 0 + 0 = 0

CASO 5:
4
4 5 1 3

(4 5 1) 3 + 2
ou
3 (4 5 1) + 1

(4 5) 1 + 1
ou
1 (4 5) + 0

(4) 5 + 0
ou
5 (4) + 1

R = 0 + 0 + 1 = 1


CASO 6:
5
1 3 1 3 2

(1 3 1 3) 2 + 2
ou
2 (1 3 1 3) + 2

(1 3 1) 3 + 0
ou
3 (1 3 1) + 2

(1 3) 1 + 1
ou
1 (1 3) + 0

(1) 3 + 0
ou
3 (1) + 1

R = 0 + 0 + 0 + 2

so taca num ordered set, ve quantos menores que tem ?
"ordered multiset"
chatinho fazer com isso
melhor ?
de boa na vdd





AC, greedy, data strucutres
>8*/
