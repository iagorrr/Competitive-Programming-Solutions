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

        string S;
        cin >> S;

        vll2d GRID(N, vll(M));
        rep(i, 0, N) {
                rep(j, 0, M) { cin >> GRID[i][j]; }
        }

        vll sum_row(N, 0);
        vll sum_col(M, 0);

        rep(i, 0, N) {
                rep(j, 0, M) {
                        sum_row[i] += GRID[i][j];
                        sum_col[j] += GRID[i][j];
                }
        }

        ll X = 0;
        vector<set<int>> left_row(N);
        vector<set<int>> left_col(M);

        {
                int x, y;
                x = y = 0;
                for (auto c : S) {
                        dbg(x, y);
                        left_row[x].emplace(y);
                        left_col[y].emplace(x);

                        if (c == 'D')
                                x++;
                        else
                                y++;
                }

                left_row[x].emplace(y);
                left_col[y].emplace(x);
        }

        // lembar pra ver se não precisa de um vis
        //
        // id, is_row
        dbg(left_row);
        dbg(left_col);
        queue<pair<int, int>> q;
        vll2d vis(N, vll(M));
        rep(i, 0, N) {
                if (len(left_row[i]) == 1) {
                        vis[i][*left_row[i].begin()] = 1;
                        q.emplace(i, *left_row[i].begin());
                }
        }

        rep(i, 0, M) {
                if (len(left_col[i]) == 1) {
                        vis[*left_col[i].begin()][i] = 1;
                        q.emplace(*left_col[i].begin(), i);
                }
        }

        dbg(q);
        dbg("after");
        while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                dbg(x, y);

                if (len(left_row[x]) and !len(left_col[y])) continue;

                bool is_row = len(left_row[x]) == 1;
                ll sum = is_row ? sum_row[x] : sum_col[y];

                GRID[x][y] = X - sum;

                sum_row[x] += GRID[x][y];
                sum_col[y] += GRID[x][y];

                left_row[x].erase(y);
                left_col[y].erase(x);

                if (len(left_row[x]) == 1) {
                        int nx = x, ny = *left_row[x].begin();
                        if (!vis[nx][ny]) {
                                q.emplace(nx, ny);
                                vis[nx][ny] = 1;
                        }
                }

                if (len(left_col[y]) == 1) {
                        int nx = *left_col[y].begin(), ny = y;
                        if (!vis[nx][ny]) {
                                vis[nx][ny] = 1;
                                q.emplace(nx, ny);
                        }
                }
        }

        /*rep(i, 0, N) { assert(sum_row[i] == X); }*/
        /**/
        /*rep(i, 0, M) { assert(sum_col[i] == X); }*/

        rep(i, 0, N) {
                rep(j, 0, M) { cout << GRID[i][j] << ' '; }
                cout << endl;
        }
}

/*8<
 * Constructive algorithms, math
>8*/
