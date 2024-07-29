#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	set<int> a;
	for(int i = 0; i <n ; i++) {
		int x;
		cin >>x;
		a.insert(x);
	}
	int win = 0, nxt = 1;
	for (auto x : a) {
		if(x == nxt) win^=1, nxt++;
	}
	cout << (win ? "Bobius" : "Alicius") << '\n';
}

// AC, game theory
