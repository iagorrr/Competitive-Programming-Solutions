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

void run() {
        int N, M;
        cin >> N >> M;

        vi2d ADJ(2 * N);
        rep(i, 0, M) {
                int u, v;
                cin >> u >> v;
                u--, v--;
                u *= 2, v *= 2;
                string s;
                cin >> s;
                if (s == "imposter") v |= 1;
                ADJ[u].eb(v), ADJ[v].eb(u);
                ADJ[u ^ 1].eb(v ^ 1), ADJ[v ^ 1].eb(u ^ 1);
        }

        ll ans = 0;

        vi vis(N * 2);

        function<pii(int, int)> dfs = [&](int u, int idx) -> pair<int, int> {
                vis[u] = idx;
                int tot, bad;
                tot = 1, bad = u & 1;

                for (auto v : ADJ[u]) {
                        if (!vis[v]) {
                                auto [q, qbad] = dfs(v, idx);
                                tot += q, bad += qbad;
                        }
                }

                return {tot, bad};
        };

        int idx = 1;
        rep(i, 0, 2 * N) {
                if (!vis[i]) {
                        auto [tot, bad] = dfs(i, idx++);
                        ans += max(bad, tot - bad);
                }
        }

        rep(i, 0, N) {
                if (vis[i * 2] == vis[i * 2 + 1]) ans = -2;
        }

        cout << ans / 2ll << endl;
}

/*8<
 * AC, graphs, dfs and similar, dsu
>8*/
