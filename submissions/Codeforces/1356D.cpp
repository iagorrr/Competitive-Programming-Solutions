/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define fastio                    \
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
#define divc(a, b) ((a) + (b)-1ll) / (b)
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
/*8<{=============~ BEGIN DSU ~===============>8*/
/*8<
  @Title:

    DSU / UFDS

  @Usage:

    You may discomment the commented parts to
    find online which nodes belong to each
    set, it makes the $union\_set$ method cost
    $O(log^2)$ instead $O(A)$

>8*/

struct DSU {
    vi ps, sz;

    // vector<unordered_set<int>> sts;

    DSU(int N)
        : ps(N + 1),
          sz(N, 1) /*, sts(N) */
    {
        iota(ps.begin(), ps.end(), 0);
        // for (int i = 0; i < N; i++)
        // sts[i].insert(i);
    }
    int find_set(int x) { return ps[x] == x ? x : ps[x] = find_set(ps[x]); }
    int size(int u) { return sz[find_set(u)]; }
    bool same_set(int x, int y) { return find_set(x) == find_set(y); }
    void union_set(int x, int y) {
        if (same_set(x, y)) return;

        int px = find_set(x);
        int py = find_set(y);

        if (sz[px] < sz[py]) swap(px, py);

        ps[py] = px;
        sz[px] += sz[py];
        // sts[px].merge(sts[py]);
    }
};

/*8<===============~ END DSU ~===============}>8*/

void run() {
    int N, M;
    cin >> N >> M;

    vector<string> grid(N);
    for (auto &s : grid)
        cin >> s;


    static const pair<int,int> D[] = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };

    rep(i, 0, N) {
        rep(j, 0, M) {
            if (grid[i][j] == 'B') {
                for (auto [di, dj] : D) {
                    int i2 = i + di, j2 = j + dj;
                    if (i2 >= 0 and i2 < N and j2 >= 0 and j2 < M and grid[i2][j2] == '.') {
                        grid[i2][j2] = '#';
                    }
                }
            }
        }
    }

    DSU dsu(N*M);

    rep(i, 0, N) {
        rep(j, 0, M) {
            if (grid[i][j] != '#') {
                for (auto [di, dj] : D) {
                    int i2 = i + di, j2 = j + dj;
                    if (i2 >= 0 and i2 < N and j2 >= 0 and j2 < M and grid[i2][j2] != '#') {
                        dsu.union_set(i * M + j, i2 * M + j2);
                    }
                }
            }
        }
    }

    bool ok = true;

    rep(i, 0, N) {
        rep(j, 0, M) {
            if (grid[i][j] == 'G') {
                ok &= (dsu.same_set(i * M + j, N*M-1));
            }

            if (grid[i][j] == 'B') {
                ok &= !(dsu.same_set(i * M + j, N*M-1));
            }
        }
    }

    cout << (ok ? "YES" : "NO") << endl;
}

/*8<
  AC, greedy, graphs, dsu
>8*/
