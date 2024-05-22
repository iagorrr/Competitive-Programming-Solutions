#include<bits/stdc++.h>

using namespace std;

void solve(int A, int B, int C) {
	if(B > C) {
		cout<<"N\n";
		return;
	}

	double timeF = 12.0/B;
	double timeG = hypot(A, 12) / C;
	if(timeF < timeG) {
		cout<<"N";
	} else {
		cout<<"S";
	}
	cout<<"\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int A, B, C;
	while(cin>>A>>B>>C) {
		solve(A, B, C);
	}
}

// AC, math

