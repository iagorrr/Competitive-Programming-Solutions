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
/*8<
  @Title: Binomial MOD
  @Description: find $\binom{n}{k} \pmod{MOD}$
  @Time:
    \begin{compactitem}
      \item precompute: on first call it takes
      $O(MAXNBIN)$ to precompute the factorials
      \item query: $O(1)$.
    \end{compactitem}
  @Memory: $O(MAXNBIN)$
  @Warning: Remember to set $MAXNBIN$ properly !
>8*/
const ll MOD = 1'000'000'000 + 7;
inline ll binom(ll n, ll k) {
        static const int BINMAX = 2'000'000;
        static vll FAC(BINMAX + 1), FINV(BINMAX + 1);
        static bool done = false;
        if (!done) {
                vll INV(BINMAX + 1);
                FAC[0] = FAC[1] = INV[1] = FINV[0] = FINV[1] = 1;
                for (int i = 2; i <= BINMAX; i++) {
                        FAC[i] = FAC[i - 1] * i % MOD;
                        INV[i] = MOD - MOD / i * INV[MOD % i] % MOD;
                        FINV[i] = FINV[i - 1] * INV[i] % MOD;
                }
                done = true;
        }

        if (n < k || n < 0 || k < 0) return 0;
        return FAC[n] * FINV[k] % MOD * FINV[n - k] % MOD;
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
        int N, M, K;
        cin >> N >> M >> K;

        vi AS(N);
        trav(ai, AS) cin >> ai;
        sort(all(AS));

        vi cnt(N + 1);
        trav(ai, AS) cnt[ai]++;

        // remove the log from binary search later
        ll ans = 0;
        rep(i, 1, N + 1) {
                auto r = maxCheck(0, N - 1, [&](int x) { return AS[x] < i; });

                optional<int> l;

                if (r) {
                        l = minCheck(0, *r, [&](int x) -> bool {
                                return i - AS[x] <= K;
                        });
                }

                ll sz = (r and l ? *r - *l + 1 : 0);
                dbg(i, sz, cnt[i]);

                rep(c, 1, min(M, cnt[i]) + 1) {
                        ll q1 = binom(cnt[i], c);
                        ll q2 = binom(sz, M - c);
                        ll inc = (q1 * q2) % MOD;
                        ans = (ans + inc) % MOD;
                }
        }

        cout << ans << endl;
}

/*8<
 * combinatorics, binary search, two pointers, sortings
>8*/
