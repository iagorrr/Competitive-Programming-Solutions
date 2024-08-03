#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, S;
	cin >> N >> S;

	if (S == 1 or N == 1) {
		cout << 1 << '\n';
		return 0;
	}

	vector<int> XS(N);
	for (auto& xi : XS)
		cin >> xi;

	sort(XS.begin(), XS.end());
	XS.pop_back();
	XS.pop_back();

	int ans = 2;
	N -= 2;
	S -= 2;

	for (int l = 0, r = N; l <= r; ) {
		int k = midpoint(l, r);

		vector<vector<int>> permod(3);
		for (int i = 0; i < k; i++) {
			auto xi = XS[i];
			permod[xi%3].emplace_back(xi);
		}

		int s = 0;
		for (auto x : permod[0])
			s += x/3;

		while (!permod[1].empty() and !permod[2].empty()) {
			auto m1 = permod[1].back(); permod[1].pop_back();
			auto m2 = permod[2].back(); permod[2].pop_back();
			s += (m1+m2)/3;

		}

		while (!permod[1].empty()) {
			auto a = permod[1].back(); permod[1].pop_back();
			if (!permod[1].empty()) {
				int b = permod[1].back(); permod[1].pop_back();
				s += (a+b+1)/3;
			}
			else s += (a+2)/3;

		}

		while (!permod[2].empty()) {
			auto a = permod[2].back(); permod[2].pop_back();
			s += (a+1)/3;
		}

		if (s <= S) {
			ans = max(ans, k + 2);
			l = k + 1;
		}
		else r = k - 1;

	}

	cout << ans << '\n';
}

// AC, greddy, binary search
