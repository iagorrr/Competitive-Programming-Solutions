#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int k;
	cin >> k;


	int n = s.size();
	vector<int> psum(n);
	psum[0] = s[0] == '.';
	for (int i = 1; i < n; i++) {
		psum[i] = psum[i-1]  + (s[i] == '.');
	}



	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int l = i, r = n -1; l <= r; ) {
			int mid = midpoint(l, r);
			if (psum[mid] - (i ? psum[i-1] : 0) <= k) {
				ans = max(ans, mid - i + 1);
				l = mid + 1;
			}
			else r = mid - 1;
		}



	}
	cout << ans << '\n';

}


// AC, binary search, two pointers, strings
