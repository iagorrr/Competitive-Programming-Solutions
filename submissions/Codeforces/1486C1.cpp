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
//#define endl '\n'
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
 * @Title: Max \& Min Check
 *
 * @Description: Returns the min/max value in range
 * [l, r] that satisfies the lambda function check,
 * if there is no such value the 'nullopt' is
 * returned.
 *
 * @Usage: check must be a function that receives
 * an integer and return a boolean.
 *
 * @Time: $O(\log{r-l+1})$
 * >8*/

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

int n;
map<pair<int, int>, int> cs;
int get(int l, int r) {
	if (cs[{l, r}] != 0) return cs[{l, r}];

	cout << "? " << l << ' ' << r << endl;
	int ret;
	cin >> ret;
	return cs[{l, r}] = ret;
}

void solve_left(int s) {
	int ans = *maxCheck(1, s-1, [&](int m) {
			return get(m, s) == s;
	});
	cout << "! " << ans << endl;
	exit(0);
}

void solve_right(int s) {
	int ans = *minCheck(s+1, n, [&](int m) {
			return get(s, m) == s;
	});
	cout << "! " << ans << endl;
	exit(0);
}

void __run() {
	cin >> n;

	int s = get(1, n);

	if (s == 1) solve_right(s);
	if (s == n) solve_left(s);

	int right = get(s, n);
	if (right == s) {
		solve_right(s);
	}
	else solve_left(s);
}

/*8<
 * AC, interactive, binary search
>8*/
