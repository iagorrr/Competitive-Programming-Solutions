#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int A, B;
	cin >> A >> B;
	int d = (B+A-1) / A;
	if (A <= B and d <= 6) {
		cout << "Yes\n";
	}
	else cout << "No\n";
}

// AC, math
