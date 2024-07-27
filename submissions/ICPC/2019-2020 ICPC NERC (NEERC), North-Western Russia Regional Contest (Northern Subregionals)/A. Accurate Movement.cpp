#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int A, B, N;
	cin >> A >> B >> N;

	int l1 = 0, r1 = B;
	int l2 = 0, r2 = A;

	int ans = 0;

	while (r2 != N or r1 != N) {
		if (r2 < r1) {
			r2 = r1;
			l2 = r2-A;
		}
		else if (l1 < l2) {
			l1 = l2;
			r1 = min(N,l1 + B);
		}
		ans++;
	}

	cout << ans << '\n';

	
}

// AC, implementation
