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

template <typename T>  // print vector
ostream& operator<<(ostream& os, vector<T>& xs) {
    rep(i, os.iword(0), xs.size()) os << xs[i] << (i == xs.size() ? "" : " ");
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

void run() {
	int H, W;
	cin >> H >> W;

	vs GRID(H);
	cin >> GRID;

	dbg(GRID);

	int ans = 0;

	static int dx[] = {0, 0, -1, 1};
	static int dy[] = {1, -1, 0, 0};

	using t3 = tuple<int,int,int>;
	queue<t3> q;

	rep(i, 0, H) {
		rep(j, 0, W) {
			if(GRID[i][j] == '#') {
				q.push(t3{i, j, 0});
			}
		}
	}

	while(len(q)) {
		auto [x, y, d] = q.front();
		q.pop();

		chmax(ans, d);

		rep(idx, 0, 4) {
			int x2 = x + dx[idx];
			int y2 = y + dy[idx];

			if (	x2 >= 0 and
				y2 >= 0 and
				x2 < H and
				y2 < W and
				GRID[x2][y2] == '.') {
				q.push({x2, y2, d+1});
				GRID[x2][y2] = '#';

			}
		}
	}

	cout << ans << endl;
}

/*8<
 * AC, dfs and related
>8*/
