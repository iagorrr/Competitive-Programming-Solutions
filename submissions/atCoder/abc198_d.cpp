#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s[3];
	cin >> s[0] >> s[1] >> s[2];

	set<char> unc;
	for (int i = 0; i < 3; i++)
		for (auto c : s[i])
			unc.emplace(c);

	if (unc.size() > 10) {
		cout << "UNSOLVABLE\n";
		return 0;
	}

	vector<char> chs;
	for (auto c : unc) chs.push_back(c);

	map<char,int> idc;
	for (int i = 0; i < chs.size(); i++) idc[chs[i]] = i;

	vector<int> vcs(10);
	iota(vcs.begin(), vcs.end(), 0);

	do {
		ll v[3];
		bool ok = true;
		for (int i = 0; i < 3; i++) {
			v[i] = 0;
			for (ll j = 0, p10 = 1; j < s[i].size(); j++, p10*=10ll) {
				auto c = s[i][j];
				auto cid = idc[c];
				ll d = vcs[cid];
				if (j == 0 and d == 0) ok = false;
				v[i] = v[i]*10 + d;
			}
		}

		if (ok and v[0] > 0 and v[1] > 0 and v[2] > 0 and v[0] + v[1] == v[2]) {
			cout << v[0] << '\n' << v[1] << '\n' << v[2] << '\n';
			return 0;		
		}
	} while(next_permutation(vcs.begin(), vcs.end()));

	cout << "UNSOLVABLE\n";
}

// AC, math, brute force
