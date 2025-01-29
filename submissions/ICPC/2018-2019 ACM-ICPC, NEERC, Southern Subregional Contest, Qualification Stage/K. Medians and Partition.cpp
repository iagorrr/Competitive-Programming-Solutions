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
inline void read(auto &xs) { trav(xi, xs) cin >> xi; }

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

void run() {
        int N, M;
        cin >> N >> M;

        vll AS(N);
        read(AS);

        vll psum(N + 1);
        rep(i, 1, N + 1) { psum[i] = psum[i - 1] + (AS[i - 1] < M); }
        dbg(psum);

        vll2d memo(N, vll(N, -1));

        auto is_good = [&](int l, int r) {
                int sz = r - l + 1;
                int lm = psum[r + 1] - psum[l];
                int mx = sz - sz / 2 - 1;
                return lm <= mx;
        };

        const ll oo = 1e8;
        function<ll(ll, ll)> solve = [&](ll l, ll r) {
                if (r == N) return -oo;

                if (r == N - 1) {
                        return is_good(l, r) ? 1ll : -oo;
                }

                auto &ret = memo[l][r];
                if (~ret) return ret;

                ll ans = -oo;

                if (is_good(l, r)) {
                        ans = 1 + solve(r + 1, r + 1);
                }

                chmax(ans, solve(l, r + 1));

                return ret = ans;
        };

        cout << max(solve(0, 0), 0ll) << endl;
}

/*8<
 * m-good means that the median is greater then or equal to M
 * AC, dynamic programming
>8*/
