#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxn = 1'000'000;
int hist[maxn + 1];
int xs[maxn + 1];

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		xs[i] = x;

		hist[x]++;

	}

	for (int i = maxn; i >= 1; i--) {
		int cnt = 0;
		for (int j = i; j <= maxn; j += i) {
			cnt += hist[j];
		}

		if (cnt >= 3) {
			cnt = min(cnt, 3);
			for (int j = 0; j < n and cnt; j++) {
				if (xs[j] % i == 0) {
					cout << j + 1 << ' ' ;
					cnt--;
				}
			}
			return 0;
		}
	}
}

// AC, number theory
