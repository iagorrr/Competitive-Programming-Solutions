#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> xs(n);
	bool allNeg, allPos;
	allNeg = allPos = true;
	vector<int> sign; sign.reserve(n);
	for (auto& xi : xs) {
	       	cin >> xi;

		sign.push_back(xi < 0 ? -1 : 1);

		allNeg &= (xi < 0);
		allPos &= (xi >= 0);
	}



	if (allNeg or allPos) {
		int x = 0;
		for (int i = 0; i < n; i++) {
			if (abs(xs[i]) < abs(xs[x]))
				x = i;
		}
		sign[x] *= -1;
	}

	int s = 0;
	for (int i = 0; i < n; i++)
		s += xs[i] * sign[i];

	int p = find(sign.begin(), sign.end(), 1) - sign.begin();
	int q = find(sign.begin(), sign.end(), -1) - sign.begin();

	cout << s << '\n';
	for (int i = 0; i < n; i++) {
		if (not (i == p or i == q)) {
			if (sign[i] == 1) {
				cout << xs[q] << ' ' << xs[i] << '\n';
				xs[q] -= xs[i];
			}
			else {
				cout << xs[p] << ' ' << xs[i] << '\n';
				xs[p] -= xs[i];
			}
		}
	}

	cout << xs[p] << ' ' << xs[q] << '\n';
}

// AC, greddy
