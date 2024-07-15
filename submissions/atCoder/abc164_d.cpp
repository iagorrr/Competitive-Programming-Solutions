#include <bits/stdc++.h>
using namespace std;

const int mod = 2019;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int n = s.size();

	vector<int> ds(n);
	for (int i =0 ; i < n; i++) {
		ds[i] = s[i] - '0';
	}


	vector<int> cong(n);
	vector<int> hist(mod);
	int cur = 0;
	for (int i = n - 1, p10 = 1; i >= 0; i--, p10 = (p10*10) % mod) {
		cur = (cur + ds[i] * p10) % mod;
		cong[i] = cur;
		hist[cur]++;
	}

	int ans = 0;
	cur = 0;
	ans += hist[0];
	for (int i = n - 1, p10 = 202; i >= 2; i--, p10 = (p10*202) % mod) {
		hist[cong[i]]--;
		ans += hist[cong[i]];
		/*
		for (int m = 0; m < mod; m++) {
			int x = (m - cong[i] + mod) % mod;
			x = (x*p10) % mod;
			if (x == 0) ans += hist[x];
		}
		*/
	}

	cout << ans << '\n';
}

// AC, math, number theory
