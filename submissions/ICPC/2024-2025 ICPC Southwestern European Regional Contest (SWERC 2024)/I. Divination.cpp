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

        rep(t, 0, T) {
                dbg(t);
                run();
        }
}

void run() {
        int N;
        cin >> N;

        vi2d ADJ(N);
        vi dgIn(N);
        rep(i, 0, N) {
                int ci;
                cin >> ci;
                ADJ[i].resize(ci);
                trav(xi, ADJ[i]) { cin >> xi, xi--, dgIn[xi]++; }
        }

        vi mx_depth(N, -1);
        function<void(int)> dfs = [&](int u) {
                if (~mx_depth[u]) return;

                mx_depth[u] = 1;
                trav(v, ADJ[u]) {
                        chmax(mx_depth[u], (dfs(v), mx_depth[v] + 1));
                }
        };

        rep(i, 0, N) dfs(i);
        cout << (*max_element(all(mx_depth)) == N) << endl;
}

/*8<
 * pra isso rolar a gente tem que começar em um nó
 * e conseguir visitar todos
 * portanto
 * só pode ter um único nó com grau de entrada zero
 * só fazer uma dfs desse nó e ve se chegou em tudo ?
 *
 * mentira né
 * acho que é vdd
 *
 * AC, graphs
>8*/
