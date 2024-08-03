#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int one = 0, two = 0;
	multiset<pair<int, string>> st;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;

		one += (x == 1);
		two += (x == 2);

		if (x > 2)
			st.emplace(x, to_string(x));
	}

	while (one and two) {
		if (one == 2 and two == 1) {
			st.emplace(4, "1+1+2");
			one = two = 0;
			break;
		}

		one--;
		two--;
		st.emplace(3, "1+2");
	}

	while (one) {
		if (one == 4) {
			one = 0;
			st.emplace(2, "1+1");
			st.emplace(2, "1+1");
			break;
		}

		if (one == 2) {
			one = 0;
			st.emplace(2, "1+1");
			break;
		}

		if (one == 1) {
			if (st.empty()) {
				st.emplace(1, "1");
			}
			else {
				auto [v, s] = *st.begin();
				st.erase(st.begin());
				v += 1;
				s = s + "+1";
				st.emplace(v, s);
			}
			break;
		}

		one -= 3;
		st.emplace(3, "1+1+1");
	}

	while (two) {
		st.emplace(2, "2");
		two--;
	}

	bool first = true;
	for (auto [_, s] : st) {
		if (!first) cout << '*';
		first = false;
		cout << '(' << s << ')';
	}
}

// AC, greddy
