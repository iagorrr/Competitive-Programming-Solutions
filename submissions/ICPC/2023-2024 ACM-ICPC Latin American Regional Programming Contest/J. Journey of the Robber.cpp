/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define fastio                  \
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
#define inte ll
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

  rep(t, 0, T) {
    dbg(t);
    run();
  }
}

const int MAXN = 2'00'000;
const int OO = 1e8;
int N;
vi ADJ[MAXN];
int sz[MAXN];
bool removed[MAXN];
struct Node {

  ll v;
  int idx;
  Node(ll _v = OO, int i = OO) :
	  v(_v), idx(i) {};  // Neutral element
};

inline Node combine(const Node &nl, const Node &nr) {
  Node m;
  if (nl.v < nr.v) 
	  m = nl;
  else if (nr.v < nl.v)
	  m = nr;
  else
	  m = nr, m.idx = min(nl.idx, nr.idx);

  return m;
}

struct SegTree {
  int n;
  vector<Node> st;

  SegTree(int _n) : n(_n), st(n << 1) {}

  void assign(int p, const Node k) {
    for (st[p += n] = k; p >>= 1;) st[p] = combine(st[p << 1], st[p << 1 | 1]);
  }

  Node query(int l, int r) {
    Node ansl = Node(), ansr = Node();
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ansl = combine(ansl, st[l++]);
      if (r & 1) ansr = combine(st[--r], ansr);
    }
    return combine(ansl, ansr);
  }

  void print() {
	  cerr << "seg: ";
	  rep(i, 0, N) {
		  cerr << query(i,i).v << ' ';
	  }
	  cerr << '\n';
  }
};

vector<Node> ans(MAXN,OO);

int calcSize(int u, int p = -1) {
	sz[u] = 1;
	for (int v : ADJ[u]) {
		if (!removed[v] and v != p)
			sz[u] += calcSize(v, u);
	}
	return sz[u];
}

int findCentroid(int u, int p, int mxSz) {
	for (int v : ADJ[u]) {
		if (v != p and !removed[v] and sz[v] * 2 >= mxSz) {
			return findCentroid(v, u, mxSz);
		}
	}
	return u;
}


SegTree seg(MAXN+2);
void dfs(int u, int p, int d, bool reset = false, bool answer = false) {
	reset ? seg.assign(u, {OO, u}) : seg.assign(u, {d,u});

	if (answer) {
		dbg(u, d);
		//seg.print();
		
		auto q = seg.query(u+1, N-1);
		q.v += d;
		ans[u] = combine(ans[u], q);
	}

	for (int v : ADJ[u]) {
		if (v != p and !removed[v]) 
			dfs(v, u, d+1, reset, answer);
	}
}

void solve(int root) {
	int centroid = findCentroid(root, -1, calcSize(root));

	dbg(centroid);

	dfs(centroid, -1, 0);

	ans[centroid] =
	   	combine(ans[centroid], seg.query(centroid+1, N+1));

	for (int v : ADJ[centroid]) {
		if (!removed[v]) {
			dfs(v, centroid, 1, true);
			dfs(v, centroid, 1, true, true);
			dfs(v, centroid, 1);
		}
	}



	dfs(root, -1, 0, true);

	removed[centroid] = true;

	for (int v : ADJ[centroid])
		if (!removed[v])
			solve(v);

}

void run() {
	cin >> N;
	rep(i, 0, N-1) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		ADJ[u].eb(v);
		ADJ[v].eb(u);
	}

	dfs(0, -1, 0, true, false);
	solve(0);
	ans[N-1]  = {0, N -1};
	rep(i, 0, N) {
		cout << ans[i].idx + 1 << ' ';
	}
	cout << '\n';

}

/*8<
>8*/
