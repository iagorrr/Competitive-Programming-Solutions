#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int MOD = 1'000'000'000 + 7;
using Matrix = vector<vector<int>>;


inline int sum(int a, const int b) {
	a += b;
	a -= (a>=MOD)*MOD;
	return a;
}

inline int mul(const int a, const int b) {
	ll ret = (ll)a*b;
	if (ret > MOD)
		ret %= MOD;
	return ret;
}

Matrix prod(const Matrix &a, const Matrix &b) {
	int n = a.size(), m = a.back().size();
	Matrix p (n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < m; k++) {
				p[i][j] = sum(p[i][j], mul(a[i][k], b[k][j]));
			}
		}
	}
	return p;
}

Matrix fpow(Matrix a, int b) {
	int n = a.size();
	Matrix p(n, vector<int>(n,0));
	for (int i = 0; i < n; i++)
		p[i][i] = 1;

	while (b) {
		if (b & 1)  p = prod(p, a);
		a = prod(a, a);
		b >>= 1;
	}
	return p;
}


int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(0));

	int N, M, Q;
	cin >> N >> M >> Q;

	Matrix t (N, vector<int>(N));
	for (int u, v, i = 0; i < M; i++) {
		cin >> u >> v;
		u--, v--;
		t[u][v]++;
	}

	const int LG2 = 30;
	vector<Matrix> bf(LG2 + 1);
	bf[0] = t;
	for (ll e = 1; e <= LG2; e++) {
		bf[e] = prod(bf[e-1], bf[e-1]);
	}

	for (int q = 0; q < Q; q++) {
		int u, v, k;
		cin >> u >> v >> k;
		u--, v--;
	 	Matrix dp(1, vector<int>(N));
		dp[0][u] = 1;
		for (int e = 0; k; e++, k >>= 1) {
			if ((k&1)) {
				dp = prod(dp, bf[e]);
			}
		}

		cout << dp[0][v] << '\n';
			
	}
}

/*
	Matrix exponentiation, divide and conquer
 */

