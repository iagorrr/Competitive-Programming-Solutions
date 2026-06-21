/*
Se der ruim eu posso sempre colocar 1 naquela posicao
no 1 primo so aparece em uma unica posicao
mas pode variar a potencia a vontade


meio que quando eu quero usar um primo
ele ele já foi usado
eu to roubando ele da posicao da frente que usou ele

3 9 1 6 4 5

        0   1   2
3
2           2   1
5
*/
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
#define repn(i, b) for (auto i = 0; i < (b); i++)
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) for (auto &xi : ranges::views::reverse(xs))
#define loop while (1)
using ll = long long;
#define endl '\n'
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define ef emplace_back
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
using vpll = vector<pll>;
using vc = vector<char>;
using vs = vector<str>;

#define TT template <typename T>
#define TTU template <typename T, typename U>

TTU using umap = unordered_map<T, U>;
TT using pqmn = priority_queue<T, vector<T>, greater<T>>;
TT using pqmx = priority_queue<T, vector<T>>;

TTU inline bool chmax(T &a, U const &b) { return (a < b ? a = b, 1 : 0); }
TTU inline bool chmin(T &a, U const &b) { return (a > b ? a = b, 1 : 0); }

// read vector
// TODO: abstract this to any container.
TT std::istream &operator>>(std::istream &is, std::vector<T> &vec) {
        for (auto &element : vec) {
                is >> element;
        }
        return is;
}

// print vector
// TODO: abstract this to any container.
TT ostream &operator<<(ostream &os, vector<T> &xs) {
        rep(i, os.iword(0), xs.size()) os << xs[i]
                                          << (i == xs.size() ? "" : " ");
        os.iword(0) = 0;
        return os;
}

// print pair
TTU ostream &operator<<(ostream &os, pair<T, U> &p) {
        os << p.first << " " << p.second;
        return os;
}

// read pair
TTU std::istream &operator>>(std::istream &is, pair<T, U> &p) {
        is >> p.first >> p.second;
        return is;
}

// print multiset
// TODO: abstract this to any container.
TT ostream &operator<<(ostream &os, multiset<T> &xs) {
        for (auto it = xs.begin(); it != xs.end(); it++)
                os << *it << (next(it) == end(xs) ? "" : " ");
        return os;
}

// sum a vector, using the default constructor as initial value
// TODO: abstract this to any container.
TT T sumList(vector<T> &xs) { return accumulate(all(xs), T()); }

/*
 * verify if a `predicate` is valid for
 * values in range [l, r]
 *
 * TODO: put a type in predicate ??
 * */
// bool all_of_in_range(T l, T r, auto predicate) {
//     return ranges::all_of(views::iota(l, r + 1),
//                           [&](T v) { return predicate(v); });
// }

// checks if a  value v is the interval [l, r]
TT bool inline between(T v, T l, T r) { return clamp(v, l, r) == v; }

/*8<============~ END TEMPLATE ~============}>8*/
void __init();
void __run();
void __pre_run();

int32_t main() {
#ifndef LOCAL
        fastio;
#endif
        __init();

        int T = 1;

        cin >> T;

        rep(t, 0, T) {
                dbg(t);
                __pre_run();
                __run();
        }
}

/*
 *
 *
 *
 *
 *
 * */

void __init() {}

void __pre_run() {}

vll build_spf(ll n) {
        vll spf(n + 1);
        rep(i, 2, n + 1) if (!spf[i]) for (ll j = i; j <= n;
                                           j += i) if (!spf[j]) spf[j] = i;
        return spf;
}

vll prime_factors(vll &spf, ll x) {
        vll fs;
        while (x > 1) {
                fs.eb(spf[x]);
                x /= spf[x];
        }
        return fs;
}

auto SPF = build_spf(6 * 1e5);

const ll mod = 1'000'000'000 + 7;
void __run() {
        ll N, X;
        cin >> N >> X;

        vll AS(N);
        cin >> AS;

        umap<ll, ll> aa;
        trav(ai, AS) {
                umap<ll, ll> hs;
                auto ps = prime_factors(SPF, ai);
                for (auto pi : ps) {
                        aa[pi]++;
                }
        }

        dbg(aa);
        ll ans = 1;
        for (auto &[p, q] : aa) {
                ans = (ans * (q + 1)) % mod;
        }

        cout << ans << endl;
}

/*8<
>8*/
