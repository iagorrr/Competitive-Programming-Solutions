#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int,int>;

int det (int a, int b, int c, int d, int e, int f) {
	return a*d + b*e + c * f - (b*c + d*e + f*a);
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pii> xs(n);
	for (auto& [a,b] : xs) {
		cin >> a >> b;
	}

	int mx = 0;

	for (int i = 0; i < n; i++) {
		auto [x1, y1] = xs[i];
		for (int j = 0; j < i; j++) {
			auto [x2, y2] = xs[j];
			int in = 0;
			for (int k = 0; k < n; k++) {
				auto [x3, y3] = xs[k];

				in += !det(x1, y1, x2, y2, x3, y3);
			}

			mx = max(mx, in);
		}
	}

	cerr << mx << '\n';
	cout << min(n/3, n - mx) << '\n';
}

// AC, geometry
