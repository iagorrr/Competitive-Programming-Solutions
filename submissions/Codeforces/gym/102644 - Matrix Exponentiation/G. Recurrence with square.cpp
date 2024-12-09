#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 1'000'000'000 + 7;


using Matrix = vector<vector<ll>>;

#define sum(a, b) (((a)+(b))%MOD)
#define mul(a, b) (((a)*(b))%MOD)


Matrix prod(const Matrix &a, const Matrix &b) {
	int n = a.size(), m = b.front().size(); 
	Matrix p(n, vector<ll>(m));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < m; k++) {
				p[i][j] = sum(p[i][j], mul(a[i][k],b[k][j]));
			}
		}
	}

	return p;
}


Matrix fpow(Matrix a, ll b) {
	int n = a.size();
	Matrix ret (n, vector<ll>(n,0));
	for (int i = 0; i < n; i++)
		ret[i][i] = 1;

	while (b) {
		if (b & 1) ret = prod(a, ret);
		a = prod(a, a);
		b >>= 1;
	}
	
	return ret;
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(0));
	ll N, K;
	cin >> N >> K;

	vector<ll> AS(N);
	for (auto &ai : AS)
		cin >> ai;

	vector<ll> CS(N);
	for(auto &ci : CS)
		cin >> ci;

	ll P, Q, R;
	cin >> P >> Q >> R;

	AS.push_back(1);
	AS.push_back(N);
	AS.push_back(mul(N,N));

	vector t(N+3, vector<ll>(N+3));
	for (int i = 0; i < N - 1; i++) {
		t[i+1][i] = 1;
	}

	for (int i = 0; i < N; i++) {
		t[i][N-1] = CS[N-i-1];
	}

	
	t[N][N-1] = P;
	t[N+1][N-1] = Q;
	t[N+2][N-1] = R;
	
	t[N][N] = 1;

	t[N][N+1] = t[N+1][N+1] = 1;

	t[N][N+2] = 1;
	t[N+1][N+2] = 2;
	t[N+2][N+2] = 1;
	


	auto t2 = fpow(t, K-N+1);
	auto a2 = prod(Matrix {AS}, t2);

	cout << a2[0][N-1] << '\n';
}

// AC, linear recurrence, matrix exponentiation
