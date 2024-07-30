#include <bits/stdc++.h>
using namespace std;

auto run() {
	string s;
	cin >> s;

	if (s.size() == 1) {
		if (s == "a") {
			cout << "b" << s << '\n';
		}
		else cout << "a" << s << '\n';
		return;
	}

	int p = 0;
	int n = s.size();
	for (int i = 0; i + 1 < n; i++) {
		if (s[i] == s[i+1]) {
			p = i;
		}
	}

	for (int i = 0; i <= p; i++){
		cout << s[i];
	}
	for (char c = 'a'; c <= 'z'; c++)  {
		if (c != s[p] and c != s[p+1]) {
			cout << c;
			break;
		}
	}
	cout << s.substr(p+1) << '\n';;

}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		run();
	}

}

// AC, strings
