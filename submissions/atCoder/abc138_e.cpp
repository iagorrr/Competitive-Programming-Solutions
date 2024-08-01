#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int32_t main()  {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string S;
	string T;

	cin >> S;
	cin >> T;

	vector<vector<int>> pos('z'-'a'+1);
	int N = S.size();
	for (int i = 0; i < N; i++) {
		S[i] -= 'a';
		auto si = S[i];

		pos[si].push_back(i);
	}

	int idx = 0;
	ll ans = 0;
	for (auto t : T) {
		t -= 'a';

		if (pos[t].empty()) {
			cout << -1 << '\n';
			return 0;
		}
		auto it = lower_bound(pos[t].begin(), pos[t].end(), idx);
		if (it == pos[t].end()) {
			ans = ans + (N-idx);
			idx = 0;
		}

		int idx2 = *lower_bound(pos[t].begin(), pos[t].end(), idx);
		ans = ans + (idx2-idx+1);
		idx = (idx2 + 1) % N;
	}

	cout << ans << '\n';
}

// AC, strings, binary search
