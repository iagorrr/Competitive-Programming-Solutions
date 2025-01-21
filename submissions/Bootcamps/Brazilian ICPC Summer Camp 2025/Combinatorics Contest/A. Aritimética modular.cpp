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

        /*cin >> T;*/

        rep(t, 0, T) {
                dbg(t);
                run();
        }
}

const ll MOD = 1'000'000'000 + 7;

ll sub(ll a, ll b, ll m = MOD) { return (a - b + m) % m; }

ll add(ll a, ll b, ll m = MOD) { return (a + b) % m; }

ll mul(ll a, ll b, ll m = MOD) { return (a * b) % m; }

ll pow(ll a, ll b, ll m = MOD) {
        ll ret = 1;
        while (b) {
                if (b & 1) ret = mul(ret, a, m);
                b >>= 1;
                a = mul(a, a, m);
        }
        return ret;
}

ll num(const string &s, ll m) {
        ll ret = 0;
        trav(c, s) {
                ret = mul(ret, 10, m);
                ret = add(ret, c - '0', m);
        }

        return ret;
}

void run() {
        string x, o, y;
        cin >> x >> o >> y;

        ll a = num(x, MOD);
        ll b = num(y, MOD);

        dbg(a, b);

        ll ans = 0;
        if (o == "+") ans = add(a, b);
        if (o == "-") ans = sub(a, b);
        if (o == "^") ans = pow(a, num(y, MOD - 1));
        if (o == "*") ans = mul(a, b);

        cout << ans << endl;
}

/*8<
 * AC, math, number theory
>8*/
