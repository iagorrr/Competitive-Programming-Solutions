#pragma once
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

/*
 * @Description:
 *      merge should be function<T(T,T)>, that
 *      makes the necessary operation between two
 *      nodes in the segment tree
 * */

template <typename T, T identity, auto merge>
struct SegTreeBottomUp {
    int size;
    vector<T> arr;

    SegTreeBottomUp(int n) {
        for (size = 1; size < n; size <<= 1);
        arr.resize(size << 1);
    }

    void assign(int pos, const T &val) {
        for (arr[pos += size] = val; pos >>= 1;)
            arr[pos] = merge(arr[pos << 1], arr[pos << 1 | 1]);
    }

    T query(int l, int r) {
        T ans_l = identity, ans_r = identity;
        for (l += size, r += size + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans_l = merge(ans_l, arr[l++]);
            if (r & 1) ans_r = merge(arr[--r], ans_r);
        }
        return merge(ans_l, ans_r);
    }

    SegTreeBottomUp(const vector<T> &vec) : SegTreeBottomUp(len(vec)) {
        copy(all(vec), begin(arr) + size);
        rrep(i, size - 1, 0) arr[i] = merge(arr[i << 1], arr[i << 1 | 1]);
    }
};


template<typename T>
using SegTreeBottomUpMinQuery = 
	SegTreeBottomUp<T, numeric_limits<T>::min(), [](T a, T b)
{ return max(a, b); }>;
				

template<typename T, typename U>
bool chmin (T& a, U& b) {
	return (a > b ? a = b, 1 : 0);
}

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



signed main() {
	//ios_base::sync_with_stdio(!cin.tie(0));
	int n, q;
	cin >> n >> q;

	vector<int> xs(n);
	for (auto &xi : xs) cin >> xi;

	unordered_map<ll, set<int>> positions;
	for (int i = 0; i < n; i++) {
		if (positions[xs[i]].empty())
			positions[xs[i]].insert(-1);
		positions[xs[i]].insert(i);
	}
	

	auto get_next_idx = [&](int i) {
		int xi = xs[i];
		auto it = positions[xi].lower_bound(i);
		if (next(it) != end(positions[xi])) {
			return *next(it);
		}
		return -1;
	};

	// used just to build the segment tree
	unordered_map<ll, int> prevpos;
	for (auto xi : xs) prevpos[xi] = -1;
	vector<int> vec_seg(n);
	for (int i = 0; i < n; i++) {
		vec_seg[i] = prevpos[xs[i]];
		prevpos[xs[i]] = i;
	}

	SegTreeBottomUpMinQuery<int> seg(vec_seg);

	auto query = [&](int l, int r) {
		l--, r--;
		// tentar achar um par primeiro
		auto p1 = minCheck(l, r, [&](int m) {
				return seg.query(l, m) >= l;
				});
		if (!p1) {
			cout << -1 << '\n';
			return;
		}
		int a = *p1, b = seg.query(*p1, *p1);
		// fazer aquele reset safado
		seg.assign(*p1, -1);
		auto may_nxt = get_next_idx(*p1);
		int prev_nxt_value;
		if (may_nxt != -1) {
			prev_nxt_value = seg.query(may_nxt,may_nxt);
			seg.assign(may_nxt, -1);
		}
	
		// tentar achar um segundo par
		auto p2 = minCheck(l, r, [&](int m) {
				return seg.query(l, m) >= l;
				});
		if (!p2) {
			seg.assign(*p1, b);
			if (may_nxt -1) seg.assign(may_nxt, prev_nxt_value);
			cout << -1 << '\n';
			return;
		}
		int c = *p2;
		int d = seg.query(*p2, *p2);

		seg.assign(*p1, b);
		if (~may_nxt) seg.assign(may_nxt, prev_nxt_value);

		// printar a resposta
		cout << a + 1 << ' ' <<  b + 1 
			<< ' ' << c + 1 << ' '  << d + 1 <<'\n';
	};
	
	auto update = [&](int i, int x) {
		i--;
		// primeiro remover ele, e fazer o anterior ele apontar pro prev
		int xi = xs[i];
		if (xi == x) return;
		auto it = positions[xi].lower_bound(i);
		if (next(it) != positions[xi].end()) {
			auto cit = *next(it);
			if (it != begin(positions[xi]))
				seg.assign(cit, *prev(it));
			else 
				seg.assign(cit, -1);
		}
		positions[xi].erase(it);

		// inserir o novo
		positions[x].insert(i);
		it = positions[x].lower_bound(i);
		if (next(it) != end(positions[x])) {
			auto cit = *next(it);
			seg.assign(cit, i);
		}
		if (it != begin(positions[x]))
			seg.assign(i, *prev(it));
		else
			seg.assign(i, -1);

		// atualizr
		xs[i] = x;

		
	};

	while (q--) {
		int o;
		cin >> o;

		if (o == 1) {
			int l, r;
			cin >> l >> r;
			query(l, r);
		}
		else {
			int i, x;
			cin >> i >> x;
			update(i, x);
		}
	}

}

// da xabu se ele der um valor novo e eu não tiver -1 no positions ooo glória
// ac, range query, binary search
