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

template <ll Mod>
struct modint {
        static constexpr ll mod = Mod;
        ll v;
        modint() : v(0) {}
        template <ll Mod2>
        modint(const modint<Mod2> &x) : v(x.value()) {}
        modint(ll x) : v(safe_mod(x)) {}
        ll &value() { return v; }
        const ll &value() const { return v; }
        static ll safe_mod(ll x) {
                return x >= 0 ? x % mod : ((x % mod) + mod) % mod;
        }
        template <typename T>
        explicit operator T() const {
                return (T)v;
        }
        bool operator==(const modint rhs) const noexcept { return v == rhs.v; }
        bool operator!=(const modint rhs) const noexcept { return v != rhs.v; }
        bool operator<(const modint rhs) const noexcept { return v < rhs.v; }
        bool operator<=(const modint rhs) const noexcept { return v <= rhs.v; }
        bool operator>(const modint rhs) const noexcept { return v > rhs.v; }
        bool operator>=(const modint rhs) const noexcept { return v >= rhs.v; }
        modint operator++(int) {
                modint res = *this;
                *this += 1;
                return res;
        }
        modint operator--(int) {
                modint res = *this;
                *this -= 1;
                return res;
        }
        modint &operator++() { return *this += 1; }
        modint &operator--() { return *this -= 1; }
        modint operator+() const { return modint(*this); }
        modint operator-() const { return mod - modint(*this); }
        friend modint operator+(const modint lhs, const modint rhs) noexcept {
                return modint(lhs) += rhs;
        }
        friend modint operator-(const modint lhs, const modint rhs) noexcept {
                return modint(lhs) -= rhs;
        }
        friend modint operator*(const modint lhs, const modint rhs) noexcept {
                return modint(lhs) *= rhs;
        }
        friend modint operator/(const modint lhs, const modint rhs) noexcept {
                return modint(lhs) /= rhs;
        }
        modint &operator+=(const modint rhs) {
                v += rhs.v;
                if (v >= mod) v -= mod;
                return *this;
        }
        modint &operator-=(const modint rhs) {
                if (v < rhs.v) v += mod;
                v -= rhs.v;
                return *this;
        }
        modint &operator*=(const modint rhs) {
                v = v * rhs.v % mod;
                return *this;
        }
        modint &operator/=(modint rhs) { return *this *= rhs.inv(); }
        modint pow(ll p) const {
                static_assert(mod < static_cast<ll>(1) << 32,
                              "Modulus must be less than 2**32");
                modint res = 1, a = *this;
                while (p) {
                        if (p & 1) res *= a;
                        a *= a;
                        p >>= 1;
                }
                return res;
        }
        modint inv() const { return pow(mod - 2); }
        modint sqrt() const {
                modint b = 1;
                while (b.pow((mod - 1) >> 1) == 1) b += 1;
                ll m = mod - 1, e = 0;
                while (~m & 1) m >>= 1, e++;
                auto x = pow((m - 1) >> 1);
                auto y = *this * x * x;
                x *= *this;
                auto z = b.pow(m);
                while (y != 1) {
                        ll j = 0;
                        for (modint t = y; t != 1; t *= t, ++j);
                        z.pow(1ll << (e - j - 1));
                        x *= z;
                        z *= z;
                        y *= z;
                        e = j;
                }
                return x;
        }
        friend ostream &operator<<(ostream &s, const modint &x) {
                s << x.value();
                return s;
        }
        friend istream &operator>>(istream &s, modint &x) {
                ll value;
                s >> value;
                x = {value};
                return s;
        }
};

const ll MOD = 1'000'000'000 + 7;
using mint = modint<MOD>;

const int MAXN = 1'000'000;
mint memo[MAXN + 1][2];
bool done[MAXN + 1][2];

mint solve(int n, bool any) {
        if (n == 0) return mint(1);

        if (done[n][any]) return memo[n][any];

        mint ans = 0;

        if (any) {
                rep(j, 1, n + 1) {
                        ans += solve(n - j, false) * mint(2).pow(2 * (j - 1));
                }
        }

        rep(j, 1, n + 1) { ans += solve(n - j, true); }

        return done[n][any] = true, memo[n][any] = ans;
}

void run() {
        mint acc1 = 1, acc0 = 1;
        rep(i, 1, MAXN + 1) {
                memo[i][0] = acc1;
                memo[i][1] = acc1 + acc0;

                acc0 *= 4;

                acc0 += memo[i][0];

                acc1 += memo[i][1];
        }

        int t;
        cin >> t;
        while (t--) {
                int n;
                cin >> n;
                cout << memo[n][1] << endl;
        }
}

/*8<
 * AC, dynamic programing, math
>8*/
