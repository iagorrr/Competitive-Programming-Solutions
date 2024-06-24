#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> p1, p2;

	for (int i = 0; i < 10; i++) {
		int c;
		cin >> c;
		if (i & 1) { // p2
			if (c >= 0) {
				p2.push_back(c);
			}	
			else {
				if (!p1.empty())
					p1.pop_back();
			}
		}
		else {
			if (c >= 0) {
				p1.push_back(c);
			}
			else {
				if (!p2.empty())
					p2.pop_back();
			}
		}
	}

	int s1 = accumulate(p1.begin(), p1.end(), 0ll);
	int s2 = accumulate(p2.begin(), p2.end(), 0ll);

	if (s1 > s2 ){
		cout << 1 << '\n';
	}
	else if (s1 < s2) {
		cout << 2 << '\n';
	}
	else cout << 0 << '\n';
}

// AC, simulation
