#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b, k;
	cin >> a >> b >> k;

	for (int i = 1; i <= k; i++) {
		cout << a*i + b << ' ';
	}
	cout << '\n';
}

// AC, implementation
