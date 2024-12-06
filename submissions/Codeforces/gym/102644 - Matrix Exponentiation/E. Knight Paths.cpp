#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned int;

/*
   Graph like approach but with the technique
   to accumulate all answers until K
*/

const pair<int,int> D[] = {
	{2, 1},
	{2, -1},
	{-2, 1},
	{-2, -1},
	{1, 2},
	{1, -2},
	{-1, 2},
	{-1,-2},
};

const int MAXN = 8;
constexpr int MAXID = (MAXN+1) * (MAXN+1);
inline int id(int i, int j) {
	return i * (MAXN+1)+ j;
}

using Matrix = vector<vector<u32>>;

Matrix prod(const Matrix &a, const Matrix &b) {
	assert(a.front().size() == b.size());
	int n = a.size();
	int m = a.front().size();
	Matrix ret(n, vector<u32>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < m; k++) {
				ret[i][j] += (a[i][k] * b[k][j]);
			}
		}
	}
	return ret;
}

Matrix fpow(const Matrix &a, u32 b) {
	int n = a.front().size();
	Matrix ret(n, vector<u32>(n));
	for (int i = 0; i < n; i++)
		ret[i][i] = 1;

	auto a2 = a;
	while (b) {
		if (b&1) ret = prod(ret, a2);
		a2 = prod(a2, a2);
		b >>= 1;
	}

	return ret;
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(0));

	int K;
	cin >> K;

	// Build adj
	vector<vector<u32>> adj(MAXID+1, vector<u32>(MAXID+1));
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			for (auto &[di, dj] : D) {
				int i2 = i + di, j2 = j + dj;
				if (i2 >= 0 and j2 >= 0 and i2 < MAXN and j2 < MAXN) {
					adj[id(i, j)][id(i2, j2)]++;
				}
			}
			adj[id(i, j)][id(MAXN, MAXN)] = 1;
		}
	}
	adj[id(MAXN,MAXN)][id(MAXN, MAXN)] = 1;

	vector<u32> cur(MAXID+1);
	cur[0] = 1;

	auto trans = fpow(adj, K);
	auto f = prod(vector<vector<u32>> { cur }, trans);

	u32 ans = 0;
	for (auto v : f[0])
		ans += v;
	cout << ans << '\n';
}

/*
	AC, Matrix exponentiation, linear recurrence
 */
