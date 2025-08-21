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
#define repn(i, b) for (auto i = 0; i < (b); i++)
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) for (auto &xi : ranges::views::reverse(xs))
#define loop while (1)
using ll = long long;
#define endl '\n'
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define ef emplace_back
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

#define TT template <typename T>
#define TTU template <typename T, typename U>

TTU using umap = unordered_map<T, U>;
TT using pqmn = priority_queue<T, vector<T>, greater<T>>;
TT using pqmx = priority_queue<T, vector<T>>;

TTU inline bool chmax(T &a, U const &b) { return (a < b ? a = b, 1 : 0); }
TTU inline bool chmin(T &a, U const &b) { return (a > b ? a = b, 1 : 0); }

// read vector
// TODO: abstract this to any container.
TT std::istream &operator>>(std::istream &is, std::vector<T> &vec) {
    for (auto &element : vec) {
        is >> element;
    }
    return is;
}

// print vector
// TODO: abstract this to any container.
TT ostream &operator<<(ostream &os, vector<T> &xs) {
    rep(i, os.iword(0), xs.size()) os << xs[i] << (i == xs.size() ? "" : " ");
    os.iword(0) = 0;
    return os;
}

// print multiset
// TODO: abstract this to any container.
TT ostream &operator<<(ostream &os, multiset<T> &xs) {
    for (auto it = xs.begin(); it != xs.end(); it++)
        os << *it << (next(it) == end(xs) ? "" : " ");
    return os;
}

// sum a vector, using the default constructor as initial value
// TODO: abstract this to any container.
TT T sumList(vector<T> &xs) { return accumulate(all(xs), T()); }

/*
 * verify if a `predicate` is valid for
 * values in range [l, r]
 *
 * TODO: put a type in predicate ??
 * */
// bool all_of_in_range(T l, T r, auto predicate) {
//     return ranges::all_of(views::iota(l, r + 1),
//                           [&](T v) { return predicate(v); });
// }

// checks if a  value v is the interval [l, r]
TT bool inline between(T v, T l, T r) { return clamp(v, l, r) == v; }

/*8<============~ END TEMPLATE ~============}>8*/
void __init();
void __run();
void __pre_run();

int32_t main() {
#ifndef LOCAL
    fastio;
#endif
    __init();

    int T = 1;

    rep(t, 0, T) {
        dbg(t);
        __pre_run();
        __run();
    }
}

/*
 *
 *
 *
 *
 *
 * */

void __init() {}

void __pre_run() {}

/*8<
  @Title: Linear Recurrence
  @Description:
    Find the n-th term of a linear recurrence,
    given the recurrence $rec$ and the first $K$
    values of the recurrence, remember that
    first\_k[i] is the value of $f(i)$,
    considering 0-indexing.
  @Usage:
    Suppose you want the N-th term of Fibonacci
    the first $k$ should be {1,1}, and the rec
    should be {{0,1},{1,1}}.
  @Time: $O(K^{3} \log{N})$
>8*/
template <typename T>
vector<vector<T>> prod(vector<vector<T>> &a, vector<vector<T>> &b,
                       const ll mod) {
    assert(a.back().size() == b.size());
    int n = a.size();
    int m = a.back().size();
    vector<vector<T>> c(n, vector<T>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                c[i][j] = (c[i][j] + ((a[i][k] * b[k][j]) % mod)) % mod;
            }
        }
    }

    return c;
}

template <typename T>
vector<vector<T>> fpow(vector<vector<T>> &xs, ll p, ll mod) {
    vector<vector<T>> ans(xs.size(), vector<T>(xs.size()));
    for (int i = 0; i < (int)xs.size(); i++) ans[i][i] = 1;

    for (auto b = xs; p; p >>= 1, b = prod(b, b, mod))
        if (p & 1) ans = prod(ans, b, mod);

    return ans;
}

void __run() {
	int h, o;
	cin >> h >> o;

	vector<string> grid(h);
	cin >> grid;

	dbg(grid);

	vll strip(h*h);
	repn(i, h) {
		repn(j, h) {
			strip[i*h + j] = 
				grid[i][j] == '#' ? 
				0 :
				grid[i][j] - '0';
		}
	}
	dbg(strip);

#define idx(x, y) x*h + y

	vll2d rec(h*h, vll(h*h));

	repn(i, h) {
		repn(j, h) {
			if (grid[i][j] == '#') continue;

			vi adj_idx;
			vi dxs {0, 1, -1};
			vi dys {0, 1, -1};
			trav(dx, dxs) {
				trav(dy, dys) {
					int i2 = i + dx;
					int j2 = j + dy;
					if (between(i2, 0, h-1) and
							between(j2, 0, h-1) ) {
						adj_idx.eb(idx(i2,j2));

					}
				}
			}

			trav(adj, adj_idx) {
				rec[idx(i,j)][adj] = 1;
			}
		}
	}

	rec = fpow(rec, o, 2);

	vll2d strip2(1);
	strip2[0] = strip;
	strip2 = prod<ll>(strip2, rec, 2ll);


	repn(i, h) {
		repn(j, h) {
			cout << char(grid[i][j] == '#' ? '#' : '0' + strip2[0][idx(i,j)]);
		}
		cout << endl;
	}

}

/*8<
>8*/
