#include <bits/stdc++.h>
using namespace std;

string s;
auto solve() {
	string stk;
	int ans =  0;
	for (auto c : s) {
		if (c == 'B') {
			if (!stk.empty() and stk.back() == 'S')
				stk.pop_back(), ans++;
			else stk.push_back(c);
		}
		else if (c == 'S') {
			if (!stk.empty() and stk.back() == 'B')
				stk.pop_back(), ans++;
			else stk.push_back(c);
		}
		else if (c == 'C') {
			if (!stk.empty() and stk.back() == 'F')
				stk.pop_back(), ans++;
			else stk.push_back(c);
		}

		else {
			if (!stk.empty() and stk.back() == 'C')
				stk.pop_back(), ans++;
			else stk.push_back(c);
		}
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> s) {
		solve();
	}

}

// AC. strings, stack
