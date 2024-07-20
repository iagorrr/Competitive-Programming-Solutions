#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	map<string, int> mp;
	while(n--) {
		string s;
		cin >> s;
		mp[s]++;
	}

	int mx = 0;
	string ans;

	for (auto [name, qtd] : mp) {
		if (qtd > mx) {
			ans=  name;
			mx  = qtd;
		}
	}

	cout << ans << '\n';

}


// AC, implementation
