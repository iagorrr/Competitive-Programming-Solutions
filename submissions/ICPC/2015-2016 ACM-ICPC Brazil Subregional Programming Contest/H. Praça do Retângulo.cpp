#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	using pii = pair<int,int>;
	vector<pii> pts(N);

	for (auto &[a, b] : pts) {
		cin >> a >> b;
	}

	sort(pts.begin(), pts.end());

	int ans = 0;
	const int oo =  numeric_limits<int>::max();
	for (int i = 0; i + 1 < N; i++) {
		auto [x1, y1] = pts[i];

		int yu = pts[i+1].second >= y1 ? pts[i+1].second : oo;
		int yl = pts[i+1].second <= y1 ? pts[i+1].second : oo;

		ans++;

		for (int j = i + 2; j < N; j++) {
			auto [x2, y2] = pts[j];

			int inc = 1;
			if (yu != oo)
			inc &= !(min(y2, y1) <= yu and yu <= max(y1, y2));
			if (yl != oo)
			inc &= !(min(y2, y1) <= yl and yl <= max(y1, y2));

			ans += inc;

			if (y2 >= y1) yu = yu == oo ? y2 : min(yu, y2);
			if (y2 <= y1) yl = yl == oo ? y2 : max(yl, y2);
		}
	}
	
	cout << ans << '\n';
}

// AC, geometry, brute

