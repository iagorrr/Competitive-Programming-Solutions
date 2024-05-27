#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int p;
	cin >> p;

	vector<int> fats;
	fats.push_back(1);
	using ll = long long;
	while ((ll)fats.size()*fats.back() <= p) {
		fats.push_back((ll)fats.size()*fats.back());
	}

	int ans = 0;

	while (p) {
		while(fats.back() > p) fats.pop_back();
		p -= fats.back();
		ans++;
	}

	cout << ans << '\n';

}

// AC, greddy, math
