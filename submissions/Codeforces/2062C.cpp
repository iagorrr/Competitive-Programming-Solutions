/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>

#include <numeric>
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

        vll AS(N);
        trav(ai, AS) cin >> ai;

        vector<valarray<ll>> vec(N);

        rep(i, 0, N) {
                vec[i].resize((N));
                vec[i][i] = 1;
        }

        ll ans = accumulate(all(AS), 0ll);

        while (len(vec) > 1) {
                vector<valarray<ll>> vec2;

                rep(i, 0, len(vec) - 1) {
                        auto a = vec[i + 1];
                        auto b = vec[i];
                        vec2.emplace_back(a - b);
                }

                vec = vec2;

                auto coef = accumulate(all(vec), valarray<ll>(N));
                ll a, b;
                a = b = 0;
                rep(i, 0, N) {
                        a += coef[i] * AS[i];
                        b += coef[i] * -AS[i];
                }
                chmax(ans, a);
                chmax(ans, b);
        }

        cout << ans << endl;
}

/*8<
 * pq N = 50 ??
 * O An sempre fica n soma positivo :D
 *
 * reverter é equivalemnte a negar os valores ?
 *
 * AC, math, brute force
>8*/
