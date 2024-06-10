#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;

	deque<int> back;
	multiset<int> st;

	while (q--) {
		int o;
		cin >> o;

		if (o == 1) {
			int xi;
			cin >> xi;
			back.push_back(xi);
		}
		else if (o == 2) {
			if (st.empty()) {
				cout << back.front() << '\n';
				back.pop_front();
			}
			else {
				cout << *st.begin() << '\n';
				st.erase(st.find(*st.begin()));
			}
		}
		else {
			st.insert(back.begin(), back.end());
			back.clear();
		}

	}
}

// AC, implementations, data structures
