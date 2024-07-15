#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;

	t += "__";
	s += "__";

	set<string> vis;
	vis.emplace(s);

	using T = tuple<string, int, int>;
	queue<T> q;
	q.emplace(s, n, 0);

	while (!q.empty()) {
		auto [cur_s, cur_i, cur_m] = q.front();
		q.pop();

		if (cur_s == t) {
			cout << cur_m << '\n';
			return 0;
		}

		for (int i = 0; i + 1 < cur_s.size(); i++) {
			if (cur_s[i] != '_' and cur_s[i+1] != '_') {
				string new_s = cur_s;
				swap(new_s[i], new_s[cur_i]);
				swap(new_s[i+1], new_s[cur_i+1]);

				if (!vis.count(new_s)) {
					vis.emplace(new_s);
					q.emplace(new_s, i, cur_m+1);
				}
			}
		}
	}

	cout << -1 << '\n';
}

// AC, strings, brute force
