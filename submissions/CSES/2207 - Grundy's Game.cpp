#include <bits/stdc++.h>
using namespace std;


const int maxn = 1'000'000;
int memo[maxn+1];
bool flag[maxn+1];

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	memo[1] = memo[2] = 0;
	for (int i = 3; i <= 1'0'000; i++) {
		memset(flag, 0, sizeof flag);

		for (int j = 1; j < (i+1)/2; j++) {
			flag[memo[j] ^ memo[i-j]] = 1;
		}

		for (int j = 0; j <= i +1; j++) {
			if (!flag[j]) {
				memo[i] = j;
				break;
			}
		}
	}

	int t;
	cin >> t;

	while(t--) {
		int n;
		cin >> n;

		int ans = n <= 1'0'000 ? memo[n] : 1;
		cout << (ans ? "first" : "second") << '\n';
	}
}

// AC, game theory
