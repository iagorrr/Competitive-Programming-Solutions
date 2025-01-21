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

void run() {
        ll N;
        cin >> N;
        ll ans = 0;
        rep(i, 1, N + 1) {
                ll inc = binom(N - 1, i - 1);
                ans = (ans + inc) % MOD;
        }
        cout << ans << endl;
}

/*8<
>8*/
