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

const int OO = 1'000'000'000;
struct Node {
	int mn, mx;
	Node(int mn, int mx): mn(mn), mx(mx) {};
	Node(int v): mn(v), mx(v) {};
	Node(): mn(OO), mx(-OO) {};
};

inline Node combine(const Node &nl, const Node &nr) {
	Node ret ( min(nl.mn,nr.mn), max(nl.mx, nr.mx));
	return ret;
}

struct SegTree {
    int n;
    vector<Node> st;
    SegTree(int _n) : n(_n), st(n << 1) {}

    void assign(int p, const Node k) {
        for (st[p += n] = k; p >>= 1;)
            st[p] = combine(st[p << 1], st[p << 1 | 1]);
    }

    Node query(int l, int r) {
        Node ansl = Node(), ansr = Node();
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ansl = combine(ansl, st[l++]);
            if (r & 1) ansr = combine(st[--r], ansr);
        }
        return combine(ansl, ansr);
    }
};

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

    vector<set<int>> sts;

    DSU(int N, vi &XS)
        : ps(N + 1),
          sz(N, 1) , sts(N)
    {
        iota(ps.begin(), ps.end(), 0);
        for (int i = 0; i < N; i++)
    		sts[i].insert(XS[i]);
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
        sts[px].merge(sts[py]);
    }
	int mx(int u) {
		int pu = find_set(u);
		return *sts[pu].rbegin();
	}
};

/*8<===============~ END DSU ~===============}>8*/

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


void run() {
	int N;
	cin >> N;

	SegTree seg(N);
	vi XS(N);
	rep(i, 0, N) {
		cin >> XS[i];
		seg.assign(i,XS[i]);
	}

	DSU dsu(N, XS);

	rep(i, 0, N) {
		auto r = maxCheck(i + 1, N-1, [&](int m) {
				return seg.query(m, N-1).mn < XS[i];
				});
		if (r) dsu.union_set(i, *r);

		auto l = maxCheck(0, i-1, [&](int m) {
				dbg(seg.query(m, i-1).mx);
				return seg.query(m, i-1).mx > XS[i];
				});
		dbg(i,l.has_value(),*l);
		if (l) dsu.union_set(i, *l);
	}

	rep(i, 0, N) {
		cout << dsu.mx(i) << " \n"[i==N-1];
	}
}

/*8<
  AC, data structures, range query
>8*/
