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
        int N, M;
        cin >> N >> M;

        string s;
        cin >> s;
        vi as(N + 1);
        rep(i, 1, N + 1) { as[i] = as[i - 1] + (s[i - 1] == '+' ? 1 : -1); }

        vi mx_prefix(N + 1);
        vi mn_prefix(N + 1);
        vi mx_suffix(N + 1);
        vi mn_suffix(N + 1);

        mx_prefix[0] = mn_prefix[0] = as[0];
        mx_suffix.back() = mn_suffix.back() = as.back();
        rep(i, 1, N + 1) {
                mx_prefix[i] = max(mx_prefix[i - 1], as[i]);
                mn_prefix[i] = min(mn_prefix[i - 1], as[i]);
        }

        rrep(i, N + 1 - 1 - 1, 0 - 1) {
                mx_suffix[i] = max(mx_suffix[i + 1], as[i]);
                mn_suffix[i] = min(mn_suffix[i + 1], as[i]);
        }

        dbg(as);
        dbg(mn_prefix);
        dbg(mx_prefix);
        dbg(mn_suffix);
        dbg(mx_suffix);

        rep(i, 0, M) {
                int l, r;
                cin >> l >> r;

                int l1 = mn_prefix[l - 1];
                int r1 = mx_prefix[l - 1];

                int v = as[r];
                int l2 = (r + 1 <= N ? mn_suffix[r + 1] - v : 0) + as[l - 1];
                int r2 = (r + 1 <= N ? mx_suffix[r + 1] - v : 0) + as[l - 1];

                int cur = 0;

                dbg(l1, r1, l2, r2);

                if (l2 < l1) {
                        swap(l1, l2);
                        swap(r1, r2);
                }

                dbg(l1, r1, l2, r2);
                if (l1 == l2) {
                        cur = (max(r1, r2) - l1 + 1);
                } else if (r1 >= l2) {
                        cur = (max(r2, r1) - min(l1, l2) + 1);
                } else {
                        cur = (r1 - l1 + 1) + (r2 - l2 + 1);
                }

                cout << cur << endl;
        }
}

/*8<
 * AC, prefix sums
>8*/
