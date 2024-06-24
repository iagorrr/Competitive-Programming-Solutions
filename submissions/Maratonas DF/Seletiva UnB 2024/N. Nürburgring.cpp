#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll calcM(int i) {
	return (3*i)%10;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll N, X; cin>>N>>X;
	ll T1 = X;
	ll T2 = X-calcM(2);
	ll T3;
	if (N == 1) {
		cout << T1 << '\n';
	} else if (N == 2) {
		cout << T2 << '\n';
	} else {
	for(int i=3; i<=N; i++) {
		T3 = (T1+T2)/2-calcM(i);
		T1 = T2;
		T2 = T3;
	}
	cout<<T3<<"\n";
	}
}

// AC, math
