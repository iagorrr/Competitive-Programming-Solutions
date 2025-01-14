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

const ll MAXB = 61;

vi get_bits(ll U) {
        vi ret;

        bitset<MAXB> bu(U);

        rep(i, 0, MAXB) {
                if (bu[i]) ret.eb(i);
        }

        return ret;
}

void run() {
        ll U, V;
        cin >> U >> V;

        dbg(U, V);

        if (U > V or ((V - U) & 1)) {
                cout << -1 << endl;
                return;
        }

        vll hist(MAXB);

        auto bits_u = get_bits(U);
        trav(b, bits_u) hist[b]++;

        auto bs = get_bits((V - U) / 2ll);
        trav(b, bs) hist[b] += 2;

        dbg(hist);

        vll ans(*max_element(all(hist)));
        rep(i, 0, MAXB) {
                rep(j, 0, hist[i]) { ans[j] |= (1ll << i); }
        }

        cout << len(ans) << endl;
        trav(ai, ans) { cout << ai << ' '; }
        cout << endl;
}

/*8<
 * bitwise, greedy, constructive algorithms
>8*/
