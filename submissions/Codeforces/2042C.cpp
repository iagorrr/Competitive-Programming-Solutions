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
        int N, K;
        cin >> N >> K;

        string S;
        cin >> S;

        vector<ll> xs;
        ll q[2]{0, 0};
        ll p[2]{0, 0};
        rrep(i, N - 1, 0 - 1) {
                xs.pb(q[1] - q[0]);
                p[0] += q[0], p[1] += q[1];
                q[S[i] - '0']++;
        }

        ll d = p[1] - p[0];

        dbg(xs);

        ll ans = LLONG_MAX;
        int seg = N + 1;
        sort(all(xs));
        dbg(d);
        dbg(xs);
        rep(i, 0, N) {
                dbg(seg, d);
                if (d >= K) chmin(ans, seg);
                d -= xs[i];
                seg--;
                if (d >= K) chmin(ans, seg);
        }

        cout << (ans == LLONG_MAX ? -1 : ans) << endl;
}

/*8<
 * corner:
 *      9 4
 *      011100011
 *      0|11100011
 *      011100011
 *      0|111000|11 3 segs é ótimo
 *
 *      0|1|1|1|0|0|0|1|1 (1+2+3+7+8) (4+5+6)
 *      0|1|1|1|0|0|0|1|1 (21) (15) (6)
 *      0|1|1|10|0|0|1|1 (19) (12) (7)
 *      0|1|110|0|0|1|1 (16) (9) (7)
 *      0|1|1100|0|1|1 (14) (7) (7)
 *      0|11100|0|1|1 (10) (4) (6)
 *      0|11100|0|11 (9) (4) (6)
 *      0|111000|11 (7) (3) (4)
 *      0111000|11 (2) (0) (4)
 *
 *      4 1
 *      1001
 *
 *      1|0|0|1 (3) (3) (0)
 *      10|0|1 (2) (1) (1)
 *      100|1 (1) (0) (1)
 *      1001 (0) (0) (1)
 *
 *      Tira sempre o que remove o minimo possível enquanto
 *      lembrando que "remover" pode adicionar
 *      é bom fazer esses tbm...
 *
 *      a diferença for maior que K ?
 *
 *      só remove tudo na 'ordem boa' e quando for maior que K
 *      faz um CHMIN/CHMAX...
 *
 *
 *      AC, greedy
>8*/
