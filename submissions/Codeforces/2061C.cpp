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

        cin >> T;

        rep(t, 0, T) {
                dbg(t);
                run();
        }
}

const ll MOD = 998244353;

void run() {
        int N;
        cin >> N;

        vll AS(N);
        cin >> AS;

        vll memo(N, -1);
        function<ll(int)> solve = [&](int i) {
                if (i == 0) return (ll)(AS[0] == 0);

                auto &ret = memo[i];
                if (~ret) return ret;

                ll c1 = (i and AS[i - 1] == AS[i]) ? solve(i - 1) : 0ll;
                ll c2 = (i >= 2 and AS[i - 2] == AS[i] - 1) ? solve(i - 2)
                                                            : 0ll;
                if (i == 1 and AS[1] == 1) c2 = 1;

                return ret = (c1 + c2) % MOD;
        };

        ll c1 = solve(N - 1);
        ll c2 = N >= 2 ? solve(N - 2) : 0;
        if (N == 1) c2 = 1;
        cout << (c1 + c2) % MOD << endl;
}

/*8<
 * So i tá falando verdade e o i-1 tbm
 * então A[i-1] == A[i]
 *
 * Se o i tá falando verdade e o i-1 é mentiroso
 * então o A[i-1] == A[i] - 1
 *
 * ja que não tem dois liars seguidos
 *
 * AC, dynamic programming, combinatorics
>8*/
