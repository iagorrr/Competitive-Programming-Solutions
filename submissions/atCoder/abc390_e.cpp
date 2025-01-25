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

const int MAXN = 5000;
const int MAXX = 5000;

ll memo[MAXN][MAXX + 1];

void run() {
        memset(memo, -1, sizeof memo);        // pode isso ?
        int N, X;
        cin >> N >> X;

        vector<vector<ll>> AS(N);
        rep(i, 0, N) {
                ll vi, ai, ci;
                cin >> vi >> ai >> ci;
                vi--;
                AS[i] = {vi, ai, ci};
        }

        sort(all(AS));

        vi f(3, -1);
        rrep(i, N - 1, 0 - 1) { f[AS[i][0]] = i; }

        dbg(AS, f);

        AS.pb({-1, -1, -1});

        function<ll(int, int)> solve = [&](int i, int j) {
                if (i < 0) return 0ll;
                auto &ret = memo[i][j];
                if (~ret) return ret;

                if (j >= AS[i][2]) {
                        ll cur = AS[i][1];
                        ll nxt = AS[i + 1][0] == AS[i][0]
                                         ? solve(i + 1, j - AS[i][2])
                                         : 0;
                        cur += nxt;
                        ret = cur;
                }

                ll nxt = AS[i + 1][0] == AS[i][0] ? solve(i + 1, j) : 0;

                ret = max(ret, nxt);

                return ret;
        };

        ll ans = 0;

        rep(q0, 0, X + 1) {
                for (int q1 = 0; q1 + q0 <= X; q1++) {
                        int q2 = X - q1 - q0;
                        ll ans0 = solve(f[0], q0);
                        ll ans1 = solve(f[1], q1);
                        ll ans2 = solve(f[2], q2);
                        chmax(ans, min({ans0, ans1, ans2}));
                }
        }

        cout << ans << endl;
}

/*8<
 * dpzinha ??
 *
 * da pra modelar dp(i, j) estou ná iésima e já ainda posso consumir j calorias
?
 *
 * daí só toro todas as opções não ?
 *
 * não sei se pode ser assim...
 *
 * busca binária na resposta ?
 *
 * mas como que coloca no estado né
 *
 * bora torar uma dp ai então
 *
 * se for fazer bb na resposta da meio que pra ordenar eles pelo tipo...
 *
 * ta estranho isso aqui
 *
 * pensando aqui
 *
 * rodar tudo da  DP seria N*X
 *
 * mas fica meio torado né
 *
 * pq ficar mexendo com os tipos e tal
 *
 *
 * e se
 *
 * eu fizer em N^2  a quantidade que posso gastar
 *
 * com a vitamina 1, a quantidade da vitamina 2 e por consequencia a da 3 né
 *
 *
 * dai chamo as DP maximizando cada uma idependente ...
 *
 * X^2 + N*X
 *
 * vapo vapo ?
 *
 * AC, dynamic programming, brute force
>8*/
