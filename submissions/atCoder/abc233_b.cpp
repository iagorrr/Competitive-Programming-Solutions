#include <bits/stdc++.h>
using namespace std;

auto run() {
	int l, r;
	cin >> l >> r;
	l-- ,r;

	string s;
	cin >> s;

	reverse(s.begin()+l, s.begin()+r);

	cout <<s << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	// cin >> T;

	for (int i = 1; i <= T; i++) {
		run();
	}

}


// AC, ad-hoc
