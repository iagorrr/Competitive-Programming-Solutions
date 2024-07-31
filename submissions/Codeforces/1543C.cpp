#include <bits/stdc++.h>
using namespace std;

using ld = long double;

const ld EPS = 1e-9;

ld solve(ld a, ld b, ld c, ld v) {
	ld ret = (ld)1;

	if (a > EPS) {
		ld inc = min(a, v) / (ld)(1+(b>EPS));
		ld na = max(a-v, (ld)0);
		ld nb = (b > EPS ? b + inc : 0);
		ld nc = c + inc;
		ret += ( a * (solve(na,nb,nc,v)));
	}

	if (b > EPS) {
		ld inc = min(b, v) / (ld)(1+(a>EPS));
		ld na = (a > EPS ? a + inc : 0);
		ld nb = max(b-v, (ld)0);
		ld nc = c + inc;
		ret += (b * (solve(na,nb,nc,v)));
	}

	return ret;
}

auto run() {
	ld a, b, c, v;
	cin >> a >> b >> c >> v;

	cout << fixed << setprecision(12) << solve(a, b, c, v) << '\n';

}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
for (int t = 1; t <= T; t++)  { run();
	}

}

// AC, expected value, brute force
