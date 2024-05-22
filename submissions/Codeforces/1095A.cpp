#include <bits/stdc++.h>
using namespace std;

auto run() {
	int n;
	cin >> n;

	string s;
	cin >> s;

	cerr << s << '\n';
	for (int i = 0, p = 1; i < n; i += p, p++){
			cout << s[i];
	}
	cout <<'\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}

// AC, ad-hoc
