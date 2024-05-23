#include<bits/stdc++.h>

using namespace std;

void solve() {
	for (int n; cin >> n;) {
		vector<array<int, 2>> v(61);
		for (auto &x :  v) x = {0};

		int res = 0;
		for (int i = 0; i < n; i++) {
			int x; char c;
			cin >> x >> c;
			auto side = c == 'D';
			if (v[x][1 - side]) ++res, v[x][1 - side]--;
			else v[x][side]++;
		}
		cout << res << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
}

// AC, ad-hoc

