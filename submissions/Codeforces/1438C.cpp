#include <bits/stdc++.h>
using namespace std;

const int OO =  1e9 + 1;

#define sz(x) (int)x.size()
#define rep(i,s,e) for (int i = s; i < e; i++)
using vi = vector<int>;

/**
 * Author: Emil Lenngren, Simon Lindholm
 * Date: 2011-11-29
 * License: CC0
 * Source: folklore
 * Description: Calculates a valid assignment to boolean variables a, b, c,... to a 2-SAT problem,
 * so that an expression of the type $(a||b)\&\&(!a||c)\&\&(d||!b)\&\&...$
 * becomes true, or reports that it is unsatisfiable.
 * Negated variables are represented by bit-inversions (\texttt{\tilde{}x}).
 * Usage:
 *  TwoSat ts(number of boolean variables);
 *  ts.either(0, \tilde3); // Var 0 is true or var 3 is false
 *  ts.setValue(2); // Var 2 is true
 *  ts.atMostOne({0,\tilde1,2}); // <= 1 of vars 0, \tilde1 and 2 are true
 *  ts.solve(); // Returns true iff it is solvable
 *  ts.values[0..N-1] holds the assigned values to the vars
 * Time: O(N+E), where N is the number of boolean variables, and E is the number of clauses.
 * Status: stress-tested
 */
struct TwoSat {
	int N;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2*n) {}

	int addVar() { // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return N++;
	}

	void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f].push_back(j^1);
		gr[j].push_back(f^1);
	}
	void setValue(int x) { either(x, x); }

	void atMostOne(const vi& li) { // (optional)
		if (sz(li) <= 1) return;
		int cur = ~li[0];
		rep(i,2,sz(li)) {
			int next = addVar();
			either(cur, ~li[i]);
			either(cur, next);
			either(~li[i], next);
			cur = ~next;
		}
		either(cur, ~li[1]);
	}

	vi val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		for(int e : gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = low;
			if (values[x>>1] == -1)
				values[x>>1] = x&1;
		} while (x != i);
		return val[i] = low;
	}

	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		rep(i,0,2*N) if (!comp[i]) dfs(i);
		rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};

auto run() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> GRID(N, vector<int>(M));
	for (auto& i : GRID) 
		for (auto& j : i)
			cin >> j;

	static const int dx[] = {1, -1, 0, 0};
	static const int dy[] = {0, 0, -1, 1};

	auto idx = [&](int x, int y) -> int {
		return x * M + y;
	};

	TwoSat ts(N*M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int v1 = GRID[i][j];
			for (int d = 0; d < 4; d++) {
				int i2 = i + dx[d];
				int j2 = j + dy[d];

				if (i2 >= 0 and j2 >= 0 and i2 < N and j2 < M) {
					int v2 = GRID[i2][j2];
					int id1 = idx(i, j);
					int id2 = idx(i2, j2);

					if (v1 == v2) {
						ts.atMostOne({~id1,~id2});	
					}
					if (v1 == v2+1) {
						ts.atMostOne({~id1,id2});
					}
					if (v1+1 == v2) {
						ts.atMostOne({id1,~id2});
					}
					if (v1+1 == v2+1) {
						ts.atMostOne({id1,id2});
					}
				}
			}
		}
	}

	ts.solve();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			auto& v = GRID[i][j];
			v += ts.values[idx(i,j)];
			cout << v << ' ';
		}
		cout << '\n';
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		run();
	}
}

// AC, graphs, two sat
