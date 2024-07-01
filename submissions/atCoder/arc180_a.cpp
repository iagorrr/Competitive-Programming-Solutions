#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string s;
	cin >> s;

	const int mod = 1'000'000'000 + 7;
	int ans =  1;
	
	int cur = 1;
	s.push_back(s.back());
	for (int i = 1; i < n+1; i++) {
		if (s[i] != s[i-1]) {
			cur++;
		}
		else {
			cur = (cur+1)/2;
			ans = (ans*(long long)cur) % mod;
			cur = 1;
		}
	}

	cout << ans << '\n';
}

// AC, strings, combinatorics
