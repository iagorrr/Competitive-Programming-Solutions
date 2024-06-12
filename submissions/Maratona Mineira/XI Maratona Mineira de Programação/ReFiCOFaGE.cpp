#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, p;
	cin >> n >> p;

	vector<int> xs(n);
	for (auto &xi : xs) {
	       	cin >> xi;
		xi = p-xi-1;
	}

	if (count(xs.begin(), xs.end(), -1) > 1) {
		cout << -1 << '\n';
		return 0;
	}


	using T = tuple<int, string, int>;
	vector<T> words(p);
	for (int i = 0; i < p; i++) {
		auto &[o, s, idx] = words[i];
		cin >> o >> s;
		idx = i;
	}

	sort(words.begin(), words.end());
	vector<int> prox(n), ant(n);

	iota(prox.begin(), prox.end(), 1);
	prox.back() = 0;

	for (int i = 1; i < n; i++) {
		ant[i] = i-1;

	}
	ant[0] = n-1;

	int i = 0, pi = 0, rmcnt = 0;;
	for (;prox[i] != i;) {
		auto &[_, s, idx] = words[pi];
		auto rem = xs[i];


		if (idx <= rem) {
			prox[ant[i]] = prox[i];
			ant[prox[i]] = ant[i];
			rmcnt++;
			if (rmcnt == n-1) {
				cout << prox[i] + 1 << '\n';
				cout << s << '\n';
				return 0;
			}
		}

		i = prox[i];
		pi = (pi + 1) % p;

	}
}

// AC, number theory, implementation

