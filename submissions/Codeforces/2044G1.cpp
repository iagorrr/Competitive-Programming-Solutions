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

template <typename T>
std::istream &operator>>(std::istream &is, std::vector<T> &vec) {
        for (auto &element : vec) {
                is >> element;
        }
        return is;
}

template <typename T>
int _msb_(T x) {
        int ret = 0;
        for (; x; x >>= 1, ret++);
        return ret - 1;
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

        vi nxt(N), in_dg(N);
        rep(i, 0, N) {
                cin >> nxt[i];
                nxt[i]--;
                in_dg[nxt[i]]++;
        }

        vi vis(N), head_cycle(N), in_cycle(N), dist(N);
        function<int(int)> dfs = [&](int u) {
                vis[u] = 1;

                int v = nxt[u];

                if (vis[v] == 1) {
                        in_cycle[u] = 1;
                        head_cycle[u] = v;
                        dist[u] = 0;

                } else if (vis[v] == 0) {
                        int d = dfs(v);
                        head_cycle[u] = head_cycle[v];
                        in_cycle[u] = in_cycle[v] and v != head_cycle[v];
                        dist[u] = in_cycle[u] ? 0 : d + 1;
                } else {
                        head_cycle[u] = head_cycle[v];
                        in_cycle[u] = false;
                        dist[u] = dist[v] + 1;
                }
                vis[u] = 2;
                return dist[u];
        };

        int mx_len = 0;
        rep(i, 0, N) {
                if (in_dg[i] == 0) chmax(mx_len, dfs(i));
        }

        dbg(head_cycle);

        dbg(mx_len);

        cout << mx_len + 2 << endl;
}

/*8<
 * AC, graphs, functional/successor graph
>8*/
