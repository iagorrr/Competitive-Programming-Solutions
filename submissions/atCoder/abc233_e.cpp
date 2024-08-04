#include <bits/stdc++.h>
using namespace std;

using ll = long long;

auto run() {
	string S;
	cin >> S;
	
	vector<ll> DS;
	ll cs = 0;
	for (auto i : S) {
		DS.emplace_back(i-'0');
		cs  += DS.back();

	}
	reverse(DS.begin(), DS.end());

	int N = DS.size();

	string ans;
	ll sd = cs;
	for (int i = 0; i < N; i++) {
		ans.push_back('0'+(cs%10));

		ll carry = cs / 10;

		sd -= DS[i];
		cs = sd + carry;
	}
	if (cs != 0) {
		ans.push_back(cs + '0');
	}
	while (ans.back() == '0') {
		ans.pop_back();
	}

	reverse(ans.begin(), ans.end());
	cout << ans << '\n';

}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	// cin >> T;

	for (int i = 1; i <= T; i++) {
		run();
	}

}


// AC, math
