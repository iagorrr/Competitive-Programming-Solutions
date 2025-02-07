/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>

#include <algorithm>
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

        cin >> T;

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

using mint = modint<998244353>;

mint calc(vector<vector<mint>> XS) {
        sort(all(XS[0]));
        sort(all(XS[1]));

        deque a(all(XS[0]));
        deque b(all(XS[1]));

        mint prod(1);
        rep(i, 0, len(a)) prod *= min(a[i], b[i]);
        /*while (len(a) and len(b)) {*/
        /*        if (a.back() > b.back()) {*/
        /*                prod *= a.back();*/
        /*                a.pop_back();*/
        /*                b.pop_front();*/
        /*        } else if (a.back() == b.back()) {*/
        /*                prod *= a.back();*/
        /*                if (a.front() < b.front()) {*/
        /*                        a.pop_front();*/
        /*                        b.pop_back();*/
        /*                } else {*/
        /*                        a.pop_back();*/
        /*                        b.pop_front();*/
        /*                }*/
        /*        } else {*/
        /*                prod *= b.back();*/
        /*                b.pop_back();*/
        /*                a.pop_front();*/
        /*        }*/
        /*}*/

        return prod;
}

void run() {
        int N, Q;
        cin >> N >> Q;

        vector<vector<mint>> XS(2, vector<mint>(N));
        cin >> XS[0];
        cin >> XS[1];

        mint prod = 1;
        auto aux = XS;
        sort(all(aux[0])), sort(all(aux[1]));
        rep(i, 0, N) { prod *= min(aux[0][i], aux[1][i]); }

        auto upd = [&](int o, int idx) {
                dbg(aux[0]);
                dbg(aux[1]);

                int lst = prev(upper_bound(all(aux[o]), XS[o][idx])) -
                          begin(aux[o]);

                dbg(lst);

                auto old = min(aux[0][lst], aux[1][lst]);

                prod /= old;

                aux[o][lst]++, XS[o][idx]++;

                auto cur = min(aux[0][lst], aux[1][lst]);

                prod *= cur;

                dbg(old, cur);
        };

        cout << calc(XS) << ' ';

        while (Q--) {
                int o, x;
                cin >> o >> x;

                o--, x--;

                upd(o, x);

                cout << prod << " \n"[Q == 0];
        }
}

/*8<
 * greedy approachs don't work here usually
 *
 * if we have something like a * b such that a < b
 *
 * is always optimal to increase a, because (a+1) * b = a*b + b
 * which is greater than a * (b+1) = a*b + a
 * as b > a
 *
 * tá em módulo essa bomba, dá uma complicada legal...
 *
 * so for the first query we sort both a and b
 *
 * suppose that the maixmum is in A, so we use this
 * maximum and remove the smallest of B
 *
 * for the rest of the queries we keep the values used
 * from both
 *
 * and always increase the smallest
 *
 *
 * funfas ?
 * but he will increase an arbitrary value...
 *
 * this will move a value a few positions to right
 *
 * as it may increase...
 *
 * is this "move" small enought to actually make it ?
 *
 * as it always increase by one it will only walk one
 * position in the sorted vector
 *
 * unless there are multiple copies of the same value
 *
 * but we can simply take the last appearing positin
 * of that value swap, and update the answer....
 *
 * so it's O(1) to move the value to the right
 * a rodo
 *
 * just map whre the i-th element is mapped in the original
 * vector....
 *
 * first this greedy calculus must be right
 *
 * lemesee
 *
 * se ofr igual ?
 *
 * is the minimum so just sort it...
 *
 * works for the bases cases
 *
 * so is much easier...
 *
 * find the last occurence of the same A[x] in the sorted vector
 *
 * increase it
 *
 * change the answer :D
 *
 * if it becomes larger than the next value
 *
 *
 * swap and chage it
 *
 * AC, greedy, binary search
>8*/
