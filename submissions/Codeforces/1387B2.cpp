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

  // cin >> T;

  rep(t, 0, T) {
    dbg(t);
    run();
  }
}


/*8<
  @Title: Centroid Decomposition
  @Description:
        Builds a vector $fat$ where $fat_i$ is who is the father of the node $i$
in the centroid decomposed tree. >8*/
//#pragma once
//#include "../Contest/template.cpp"
vi centroidDecomposition(const vi2d &g) {
  int n = len(g);
  vi fat(n, -1), szt(n), tk(n);
  function<int(int, int)> calcsz = [&](int x, int f) {
    szt[x] = 1;
    for (auto y : g[x])
      if (y != f && !tk[y]) szt[x] += calcsz(y, x);
    return szt[x];
  };
  function<void(int, int, int)> cdfs = [&](int x, int f, int sz) {
    if (sz < 0) sz = calcsz(x, -1);
    for (auto y : g[x])
      if (!tk[y] && szt[y] * 2 >= sz) {
        szt[x] = 0;
        cdfs(y, f, sz);
        return;
      }
    tk[x] = true;
    fat[x] = f;
    for (auto y : g[x])
      if (!tk[y]) cdfs(y, x, -1);
  };
  cdfs(0, -1, -1);
  return fat;
}


void run() {
	int N; cin >> N;
	vi2d TREE(N);
	rep(i, 0, N - 1) {
		int u, v; cin >> u >> v;
		u--, v--;
		TREE[u].eb(v);
		TREE[v].eb(u);
	}

	auto ps = centroidDecomposition(TREE);
	int centroid = find(all(ps), -1) - begin(ps);

	deque<vector<int>> subtrees;
	ll ansPts = 0;
	function<int(int ,int)> dfs = [&](int u, int p) {
		subtrees.back().pb(u);
		int sz = 1;
		for (auto v : TREE[u]) {
			if (v != p) {
				int vsz = dfs(v, u);
				ansPts += vsz;
				sz += vsz;
			}
		}
		return sz;
	};

	for(auto &v : TREE[centroid]) {
		subtrees.eb();
		ansPts += dfs(v, centroid);
	}

	sort(all(subtrees), [&](const vector<int>&a, const vector<int>&b) {
			return len(a) < len(b);
			});

	ansPts <<= 1ll;
	
	vi ansPerm(N);
	iota(all(ansPerm), 0);
	dbg(centroid);
	dbg(subtrees);
	while (len(subtrees) > 1) {
		int u = subtrees.back().back();
		int v = subtrees.front().back();

		swap(ansPerm[u],ansPerm[v]);

		subtrees.back().pop_back();
		subtrees.front().pop_back();

		if(subtrees.back().empty())
			subtrees.pop_back();
		if(subtrees.front().empty())
			subtrees.pop_front();


	}

	if (len(subtrees)) 
		swap(ansPerm[centroid], ansPerm[subtrees.back().back()]);
	else 
		swap(ansPerm[centroid], ansPerm[(centroid+1)%N]);
	
	cout << ansPts << endl; 
	for(auto p : ansPerm) cout << p + 1 << ' ';
	cout << endl;
}

/*8<
  AC, centroid
>8*/
