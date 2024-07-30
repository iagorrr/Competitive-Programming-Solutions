#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int cg = 0;
	int n = s.size();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'p') {
			if (cg > 0) {
				cg--;
			}
			else {
				ans--;
				cg++;
			}
		}
		else {
			if (cg > 0) {
				cg--;
				ans++;
			}
			else cg++;
		}
	}
	cout << ans << '\n';
}

/*
	gulosamente ??

	p > g
	ggppgggpgg
	gpgpgpgpgp
	0100010002

	AC, strings, greddy
 */
