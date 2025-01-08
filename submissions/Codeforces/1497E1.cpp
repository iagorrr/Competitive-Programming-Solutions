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

/*8<
  @Title: Factorization (Pollard's Rho)
  @Description:
    Factorizes a number into its prime factors.
  @Time: $O(N^{(\frac{1}{4})} * \log (N))$.
>8*/
ll mul(ll a, ll b, ll m) {
        ll ret = a * b - (ll)((ld)1 / m * a * b + 0.5) * m;
        return ret < 0 ? ret + m : ret;
}

ll pow(ll a, ll b, ll m) {
        ll ans = 1;
        for (; b > 0; b /= 2ll, a = mul(a, a, m)) {
                if (b % 2ll == 1) ans = mul(ans, a, m);
        }
        return ans;
}

bool prime(ll n) {
        if (n < 2) return 0;
        if (n <= 3) return 1;
        if (n % 2 == 0) return 0;

        ll r = __builtin_ctzll(n - 1), d = n >> r;
        for (int a : {2, 325, 9375, 28178, 450775, 9780504, 795265022}) {
                ll x = pow(a, d, n);
                if (x == 1 or x == n - 1 or a % n == 0) continue;

                for (int j = 0; j < r - 1; j++) {
                        x = mul(x, x, n);
                        if (x == n - 1) break;
                }
                if (x != n - 1) return 0;
        }
        return 1;
}

ll rho(ll n) {
        if (n == 1 or prime(n)) return n;
        auto f = [n](ll x) { return mul(x, x, n) + 1; };

        ll x = 0, y = 0, t = 30, prd = 2, x0 = 1, q;
        while (t % 40 != 0 or gcd(prd, n) == 1) {
                if (x == y) x = ++x0, y = f(x);
                q = mul(prd, abs(x - y), n);
                if (q != 0) prd = q;
                x = f(x), y = f(f(y)), t++;
        }
        return gcd(prd, n);
}

vector<ll> fact(ll n) {
        if (n == 1) return {};
        if (prime(n)) return {n};
        ll d = rho(n);
        vector<ll> l = fact(d), r = fact(n / d);
        l.insert(l.end(), r.begin(), r.end());
        return l;
}

void run() {
        int N, K;
        cin >> N >> K;

        vll AS(N);
        trav(ai, AS) cin >> ai;

        set<vll> st;
        int ans = 1;
        trav(ai, AS) {
                auto ps = fact(ai);
                map<int, int> cnt;
                trav(pi, ps) { cnt[pi]++; }
                vll vs;
                for (auto [v, q] : cnt) {
                        if (q & 1) {
                                vs.eb(v);
                        }
                }
                if (st.count(vs)) {
                        ans++;
                        st.clear();
                }
                st.insert(vs);
        }

        cout << ans << endl;
}

/*8<
>8*/
