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

    //cin >> T;

    rep(t, 0, T) {
        dbg(t);
        run();
    }
}

void run() {
	int N, M;
	cin >> N >> M;
	vector<string> grid(N);

	for (auto &x : grid)
		cin >> x;

	int xs, ys, xt, yt;
	rep(i, 0, N) {
		rep(j, 0, M) {
			if (grid[i][j] == 'S')
				xs = i, ys = j;
			if (grid[i][j] == 'T')
				xt = i, yt = j;
		}
	}

	vector dist (N, vector(M, vector(4,(vector<int>(4, 1e9)))));

	using A4 = array<int, 4>;
	queue<A4> q;

	rep(i, 0, 4) {
		rep(j, 0, 4) {
			q.push({xs, ys, i, j});
			dist[xs][ys][i][j] = 0;
		}
	}

	static const int dx[] = {0, 0, -1 , 1};
	static const int dy[] = {-1 , 1, 0, 0};

	while (len(q)) {
		dbg(q.front());
		auto [x, y, d, k] = q.front();
		int curD = dist[x][y][d][k];
		q.pop();

		if (x == xt and y == yt) {
			cout << curD << '\n';
			return;
		}

		rep(i, 0, 4) {
			int x2 = x + dx[i];
			int y2 = y + dy[i];
			int d2 = i;
			int k2 = d2 == d ? k + 1 : 1;
			if (k2 <= 3 and x2 >= 0 and x2 < N and y2 >= 0 and y2 < M
				   	and dist[x2][y2][d2][k2] > curD + 1 and 
					grid[x2][y2] != '#') {
				dist[x2][y2][d2][k2] = curD + 1;
				q.push({x2, y2 , d2, k2});
			}
		}
	}

	cout << -1 << '\n';
}

/*8<

  AC, graphs, shortest paths
>8*/
