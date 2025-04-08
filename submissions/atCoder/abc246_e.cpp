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

template <typename T>        // print vector
ostream &operator<<(ostream &os, vector<T> &xs) {
        rep(i, os.iword(0), xs.size()) os << xs[i]
                                          << (i == xs.size() ? "" : " ");
        os.iword(0) = 0;
        return os;
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

const int MAXN = 1500;
int vis[MAXN][MAXN][4];
vector<pii> dirs = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void run() {
        int N;
        cin >> N;

        rep(i, 0, N) rep(j, 0, N) rep(d, 0, 4) vis[i][j][d] = INT_MAX >> 2;

        int startX, startY;
        cin >> startX >> startY;
        startX--, startY--;

        int endX, endY;
        cin >> endX >> endY;
        endX--, endY--;

        vs grid(N);
        cin >> grid;
        dbg(grid);

        using t4 = tuple<int, int, int, int>;
        pqmn<t4> q;
        rep(i, 0, 4) {
                vis[startX][startY][i] = 1;
                q.push(t4{1, startX, startY, i});
        }

        while (len(q)) {
                auto [m1, x1, y1, d1] = q.top();
                q.pop();

                if (vis[x1][y1][d1] < m1) continue;

                if (x1 == endX and y1 == endY) {
                        cout << m1 << endl;
                        return;
                }

                rep(d, 0, 4) {
                        auto [dx, dy] = dirs[d];
                        int x2 = x1 + dx, y2 = y1 + dy;
                        int m2 = (d != d1) + m1;
                        if (clamp(x2, 0, N - 1) == x2 and
                            clamp(y2, 0, N - 1) == y2 and
                            grid[x2][y2] != '#' and vis[x2][y2][d] > m2) {
                                vis[x2][y2][d] = m2;
                                q.push(t4{m2, x2, y2, d});
                        }
                }
        }

        cout << -1 << endl;
}

/*8<
 * sort of bfs 01 ??
 * maybe a dijkstra
 *
 * we are at position (i, j) and reached here with a movement of kind k
 * were it may be one of the four directions in the diagonal, to keep the same
 * move increase the coust by 0 and to change it by one, just run the bfs-0-1
until
 * you find it
 *
 * corner case at the first one where the cost is always 1, so you may insert
starint with the four moves
* ta dando xabu vou fazer um dijkstra po
*
* AC, dijkstra
>8*/
