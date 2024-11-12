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

/*8<
  @Title: Max \& Min Check

  @Description: Returns the min/max value in range
  [l, r] that satisfies the lambda function check,
  if there is no such value the 'nullopt' is
  returned.

  @Usage: check must be a function that receives
  an integer and return a boolean.

  @Time: $O(\log{r-l+1})$
>8*/

template <typename T>
optional<T> maxCheck(T l, T r, auto check) {
    optional<T> ret;
    while (l <= r) {
        T m = midpoint(l, r);
        if (check(m))
            ret ? chmax(ret, m) : ret = m, l = m + 1;
        else
            r = m - 1;
    }
    return ret;
}

template <typename T>
optional<T> minCheck(T l, T r, auto check) {
    optional<T> ret;
    while (l <= r) {
        T m = midpoint(l, r);
        if (check(m))
            ret ? chmin(ret, m) : ret = m, r = m - 1;
        else
            l = m + 1;
    }
    return ret;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, K, Q;
	cin >> N >> K >> Q;
	vector GRID(N, vector(K, 0));

	for (auto &i : GRID) {
		for (auto &j : i) {
			cin >> j;
		}
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < K; j++) {
			GRID[i][j] |= GRID[i-1][j];
		}
	}

	while (Q--) {
		int M;
		cin >> M;

		unordered_map<int,int> ls, rs;
		unordered_set<int> toConsidere;
		while (M--) {
			int c;
			cin >> c;
			c--;
			toConsidere.emplace(c);

			char o;
			cin >> o;

			int v;
			cin >> v;

			if (o == '<') {
				if (rs.count(c)) {
					rs[c] = min(rs[c], v);
				}
				else rs[c] = v, ls[c] = INT_MIN;
			}
			else {
				if (ls.count(c)) {
					ls[c] = max(ls[c], v);
				}
				else ls[c] = v, rs[c] = INT_MAX;
			}
		}

		for (auto i  : toConsidere)  {
			dbg(i, ls[i], rs[i]);
		}

		bool ok = true;
		vector<pair<int,int>> intervals;
		for (auto i  : toConsidere) {
			auto l = minCheck(0, N-1, [&](int m) {
					return ls[i] < GRID[m][i];
					});

			auto r = maxCheck(0, N-1, [&](int m) {
					return GRID[m][i] < rs[i];
					});

			if (!l or !r or (*l > *r)) {
				ok = false;
				break;
			}

			intervals.eb(*l,*r);
		}

		if (!ok) {
			cout << -1 << '\n';
			continue;
		}

		dbg(intervals);
		sort(all(intervals));
		pair<int,int> intersection = intervals.front();
		for (int i = 1; i < len(intervals); i++) {
			auto &[il, ir] = intersection;
			auto [l, r] = intervals[i];
			if (l > ir) {
				ok = false;
				break;
			}
			il = l;
			ir = min(ir, r);
		}


		cout << (ok ? intersection.first+1 : -1) << '\n';
	}
}
