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
        int N, Q;
        cin >> N >> Q;

        string S;
        cin >> S;

        vi2d psum(2, vi(N + 1));
        rep(i, 1, N + 1) {
                if (i & 1) {
                        psum[0][i] = psum[0][i - 1] + (S[i - 1] == '+');
                        psum[1][i] = psum[1][i - 1] + (S[i - 1] == '-');
                } else {
                        psum[0][i] = psum[0][i - 1] + !(S[i - 1] == '+');
                        psum[1][i] = psum[1][i - 1] + !(S[i - 1] == '-');
                }
        }

        rep(q, 0, Q) {
                int l, r;
                cin >> l >> r;
                l--, r--;
                int qp = psum[0][r + 1] - psum[0][l];
                int qn = psum[1][r + 1] - psum[1][l];
                dbg(qp, qn);
                if (abs(qp - qn) & 1) {
                        cout << 1 << endl;
                } else if (qp == qn) {
                        cout << 0 << endl;
                } else
                        cout << 2 << endl;
        }
}

/*8<
 * AC, greedy
>8*/
