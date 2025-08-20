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

vll divisors(ll x) {
	vll ret;

	for (ll d = 1; d * d <= x; d++) {
		if (x % d == 0) {
			ret.eb(d);
			if (x / d != d) ret.eb(x/d);
		}
	}

	return ret;
}

int valid(int di, const vi& xs) {
	unordered_set<int> st;
	trav(xi, xs) st.emp(xi % di);
	if (len(st) < 3) {
		dbg(di);
	}
	return len(st) < 3;
}
	
void __run() {
	const int maxm = 1'000'000'000;
	int n;
	cin >> n;

	vi xs(n); cin >> xs;
	sort(all(xs));

        xs.erase(unique(all(xs)), end(xs));

	if (len(xs) == 1) {
		cout << 1 << ' ' << maxm - 1 << endl;
		return;
	}

	int g = xs[1] - xs[0];
	repn(i, len(xs)-1) {
		g = gcd(g, xs[i+1] - xs[i]);
	}

	if (g != 1) {
		cout << 1 << ' ' << len(divisors(g)) - 1 << endl;
		return;
	}

	// two elements with gcd of differences
	// equals 1 means one of difference
	// so any two pair of numbers will be enough
	if (len(xs) == 2) {
		cout << 2 << ' ' << maxm - 1 << endl;
		return;
	}

	// otherwise, is there anyway to divide in
	// two groups ?
	// why this don't explode in many groups ??
	// it may be so just test each one...
	vi as(begin(xs), begin(xs)+3);
	assert(len(as) == 3);
	vi all_ds;
	trav(ai1, as) {
		trav(ai2, as) {
			if (ai1 >= ai2) continue;
			int mod1 = ai2 - ai1;

			auto ds = divisors(mod1);
			dbg(ds, mod1);
			all_ds.insert(end(all_ds), all(ds));
		}
	}

	sort(all(all_ds));
	all_ds.erase(unique(all(all_ds)), end(all_ds));

	dbg(all_ds);

	assert(find(all(all_ds), 2) != end(all_ds));

	int ans = accumulate(all(all_ds), 0, [&](int acc, int di){
			return acc + (di != 1 and valid(di, xs));
			});

	
	// otherotherwise, just use 2 and ban
	cout << 2 << ' ' << ans << endl;
	
}

/*8<
 * the gcd of differences is different of 1, we can make the divisors of such diff
 * number theory
>8*/
