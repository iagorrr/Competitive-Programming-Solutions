#include <bits/stdc++.h>
using namespace std;

auto run() {
	int n;
	cin >> n;

	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			if (i&1) {
				cout << "Aoki\n";
			}
			else {
				cout << "Takahashi\n";
			}
			return;
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}


// AC, ad-hoc
