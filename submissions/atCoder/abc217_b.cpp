#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	set<string> st({"ABC", "ARC", "AGC", "AHC"});

	for (int i = 0; i < 3; i++) {
		string s;
		cin >> s;
		st.erase(s);
	}

	cout << *st.begin() << '\n';
}

// AC, ad-hoc
