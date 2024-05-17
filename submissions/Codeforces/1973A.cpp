#include <bits/stdc++.h>
using namespace std;

auto run() {
	int p1, p2, p3;
	cin >> p1 >> p2 >> p3;

	int s = p1 + p2 + p3;
	if (s&1) {
		cout << -1 << '\n';
		return;
	}

	int ans = 0;
	multiset<int> st;
	if (p1)
	st.emplace(p1);
	if(p2)
	st.emplace(p2);
	if(p3)
	st.emplace(p3);

	while (st.size() >= 2)  {
		int l = *st.begin();
		int r = *st.rbegin();

		// cerr << l << ' ' << r << '\n';
		st.erase(st.find(l));
		st.erase(st.find(r));

		l--,r--;
		if(l) st.emplace(l);
		if(r) st.emplace(r);
		ans++;
	}

	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;

	while (tt--) {
		run();
	}
}
 
// AC, greddy, brute force
