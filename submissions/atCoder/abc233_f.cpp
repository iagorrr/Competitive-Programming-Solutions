#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define endl '\n'

#define fastio                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);

#define int long long

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define rep(i, a, b) for (common_type_t<decltype(a), decltype(b)> i = a; i != b; (a < b) ? ++i : --i)
#define len(x) (int)x.size()
#define pb push_back
#define eb emplace_back 

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;

int T = 1;

auto run() {
	int N;
	cin >> N;

	vi PS(N);
	for(auto& pi : PS) {
		cin >> pi, pi--; 
	}

	int M;
	cin >> M;

	vector<vector<pii>> ADJ(N);
	rep(i, 0, M) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		ADJ[a].eb(b, i);
		ADJ[b].eb(a, i);

	}

	vc vis(N);
	vi qs;
	function<void(int)> dfs = [&](int u) {
		vis[u] = 1;
		qs.eb(u);
		for (auto [v, _] : ADJ[u]) {
			if (!vis[v])
				dfs(v);
		}
	};
	rep(i, 0, N)
		if (!vis[i])
			dfs(i);

	reverse(all(qs));
	vc done(N);
	vi ans;
	for (auto qi  : qs) {
		dbg(qi);
		vis = done;

		function<bool(int)> find = [&](int u) {	
			vis[u] = 1;
			if (PS[u] == qi) return true;
			for (auto [v, idx] : ADJ[u]) {
				if (!vis[v]) {
					if (find(v)) {
						swap(PS[u], PS[v]);
						ans.eb(idx);
						return true;
					}
				}
			}
			return false;
		};

		if (!find(qi)) {
			cout << -1 << endl;
			return;
		}
		done[qi] = true;
	}

	cout << len(ans) << endl;
	for (auto i : ans)
		cout << i + 1 << ' ';
	cout << endl;

}

int32_t main() {
#ifndef LOCAL
	fastio;
#endif

	// cin >> T;

	rep(t, 0, T) {
                dbg(t);
		run();
  	}
}


/*
	AC, graphs, permutations   
 */
