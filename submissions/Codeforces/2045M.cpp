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

const int MAXRC = 200;
int vis[MAXRC][MAXRC];
void run() {
        int R, C;
        cin >> R >> C;
        vector<string> S(R);
        cin >> S;

        int tot_mirros = 0;
        for_each(all(S), [&](const string &si) {
                tot_mirros += C - count(all(si), '.');
        });

        static const vector<pair<int, int>> dt{
                {-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        unordered_map<char, vi> find_d{
                {'.', {0, 1, 2, 3}},
                {'/', {1, 0, 3, 2}},
                {'\\', {3, 2, 1, 0}},
        };

        int tot = 0;
        function<void(int, int, int)> cnt = [&](int i, int j, int d) {
                if (i < 0 or j < 0 or i == R or j == C) return;

                tot += (S[i][j] != '.' and !vis[i][j]);
                vis[i][j] = 1;

                int d2 = find_d[S[i][j]][d];
                int i2 = i + dt[d2].first, j2 = j + dt[d2].second;

                cnt(i2, j2, d2);
                return;
        };

        vector<str> ans;

        // N
        rep(i, 0, C) {
                tot = 0;
                memset(vis, 0, sizeof vis);
                cnt(0, i, 2);
                if (tot == tot_mirros) ans.eb("N" + to_string(i + 1));
        }

        // E
        rep(i, 0, R) {
                tot = 0;
                memset(vis, 0, sizeof vis);
                cnt(i, C - 1, 3);
                if (tot == tot_mirros) ans.eb("E" + to_string(i + 1));
        }

        // S
        rep(i, 0, C) {
                tot = 0;
                memset(vis, 0, sizeof vis);
                cnt(R - 1, i, 0);
                if (tot == tot_mirros) ans.eb("S" + to_string(i + 1));
        }

        // W
        rep(i, 0, R) {
                tot = 0;
                memset(vis, 0, sizeof vis);
                cnt(i, 0, 1);
                if (tot == tot_mirros) ans.eb("W" + to_string(i + 1));
        }

        cout << len(ans) << endl;
        trav(ai, ans) cout << ai << ' ';
        cout << endl;
}

/*8<
>8*/
