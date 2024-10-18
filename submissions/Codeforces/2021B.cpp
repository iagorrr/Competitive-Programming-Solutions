#include <bits/stdc++.h>
using namespace std;

void run() {
	int n, x;
	cin >> n >> x;
	vector<int> hist(n+2);
	for (int i = 0; i < n; i++) {
		int xi;
		cin >> xi;
		if(xi <= n+1)
			hist[xi]++;
	}
	for (int i = 0; i <= n+1; i++) {
		if (hist[i] >= 2 and i + x <= n + 1) {
			hist[i+x] += hist[i] - 1;
			hist[i] = 1;
		}
	}

	int ans = min_element(hist.begin(), hist.end()) - hist.begin();
	cout << ans << '\n';

}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(0));
	int t;
	cin >> t;
	while (t--) {
		run();
	}
}

// AC, mex, greedy
