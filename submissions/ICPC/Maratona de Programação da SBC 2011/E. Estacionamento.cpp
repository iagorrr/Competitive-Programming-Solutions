#include<bits/stdc++.h>

using namespace std;

const int maxc = 1000;
int c, n; 

vector<int> est(maxc);

void solve() {
	for (int i = 0; i < c; i++) est[i] = 0;
	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < c; j++) {
		}
		char op;
		int p, q;

		cin >> op;;

		if (op == 'C') {
			cin >> p >> q;
			for (int i = 0; i < c; ) {
				if (est[i]) {
					i++;
					continue;
				}

				int l = i;
				int r = i;
				while (r + 1 < c and est[r+1] == 0 and (r+1-l+1 <= q)) {
					r++;
				}

				if (r-l + 1 >= q) {
					ans += 10;
					for (int j = l; j <= r; j++)
						est[j] = p;

					break;
				}

				i = r + 1;
			}
		}
		else {
			cin >> p;
			for (int i = 0; i < c; i++) {
				if (est[i] == p)
					est[i] = 0;
			}
		}
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> c >> n) {
		solve();
	}
}

// AC, implementation
