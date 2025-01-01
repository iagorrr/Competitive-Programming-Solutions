/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define fastio                    \
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
#define divc(a, b) ((a) + (b)-1ll) / (b)
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

const int MAXN = 100;
const int MAXAI = 2000;
int memo[MAXN][MAXAI*MAXN+1];

void run() {
    memset(memo, -1, sizeof memo);
    int N;
    cin >> N;

    vector<int> XS(N);
    for (auto &xi : XS)
        cin >> xi;


    ll tot_sum = accumulate(all(XS), 0ll);
    if (tot_sum & 1) {
        cout << 0 << '\n';
        return;
    }

    function<int(int ,int)> solve = 
        [&](int i, int s) {
            if (s == 0) return 1;
            if (s < 0) return 0;
            if (i == N) return 0;


            int &ret = memo[i][s];
            if (~ret) return ret;

            ret = solve(i + 1, s) or solve(i + 1, s - XS[i]);
            return  ret;
        };

    bool is_possible = solve(0, tot_sum/2);
    if (!is_possible) {
        cout << 0 << '\n';
        return;
    }
    int ans = 0;

    rep(i, 0, N) {
        if (__builtin_ffs(XS[i]) < __builtin_ffs(XS[ans])) {
            ans = i;
        }
    }

    cout << 1 << '\n';
    cout << ans + 1<< '\n';
}

/*8<
  AC, math, dynamic programming
>8*/
