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
        ll N, M;
        cin >> N >> M;

        if (M < N) {
                cout << 0 << endl;
                return;
        }

        if (M == N) {
                rep(i, 0, 33) {
                        bool on_n = (N & (1ll << i)) != 0;
                        bool on_m = (M & (1ll << i)) != 0;
                        if (!on_n and !on_m) {
                                cout << (1ll << i) << endl;
                                return;
                        }
                }
        }

        if (N == 0) {
                cout << M + 1 << endl;
                return;
        }

        if (__builtin_popcount(M) == 1) {
                cout << M << endl;
                return;
        }

        bitset<33> bn(N), bm(M + 1), ans(0);
        rrep(i, 33, 0 - 1) {
                if (bn[i] == bm[i]) {
                        ans[i] = 0;
                } else if (bn[i] and !bm[i]) {
                        ans[i] = 0;
                        break;
                } else if (!bn[i] and bm[i]) {
                        ans[i] = 1;
                }
        }

        cout << ans.to_ullong() << endl;
}

/*8<
 * MEX N^0, N^1, N^2, ..., N^M
 *
 * MES bro
 *
 * N, M <= 1e9
 *
 * testa todas a p2 e ve sequias ao fazíses
 *
 * nem sempre é só p2
 *    2   │ 167 756
 *
 *       2   │ 167 756

N^M + 1

49 373

34 787

602 993

78 916

307 872

0 2

0 1

0 9

 * if M < N, we will never be able
 * to turn off every bit from N
 * so 0 is never reachable
 *
 *
 *
 * if N == M, i guess that is the first missing bit
 *
 * if N < M ??
 * i can make every number from 0 to N ?
 *
 * if N == 0 é sempre o M + 1, já que todos
 * até M eu fiz né
 *
 * se for uma potência de 2 dá ela mesma
 *
 * if MSB(M) > MSB(N):
 *
 *
 *
>8*/
