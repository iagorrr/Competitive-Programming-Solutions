#include<bits/stdc++.h>

using namespace std;

using ld = long double;

pair<int,int> C(int idx) { return {idx / 3 , idx % 3}; }

map<int, string> idx_s( {
		{0, ""},
		{1, "abc"},
		{2, "def"},
		{3, "ghi"},
		{4, "jkl"},
		{5, "mno"},
		{6, "pqrs"},
		{7, "tuv"},
		{8, "wxyz"},
		{9, ""},
		{10, " "},
		{11, "#"},
});

map<char,int> _p;
int P(char c) {
	return _p[c];
}

map<char,int> _v;
int V(char c) {
	return _v[c];
}

void precomp() {
	for (auto [k, s] : idx_s) {
		for (int i = 0; i < s.size(); i++) {
			_v[s[i]] = i+1;
			_p[s[i]] = k;
		}
	}
}

ld D(int i1, int i2) { 
	auto [x1, y1] = C(i1);
	auto [x2, y2] = C(i2);

	return hypot(x2-x1, y1-y2) / (ld)30.00000;
}

string S;
ld press = (ld)0.20000000000000000;

bool done[140 + 1][12][12];
ld memo[140+1][12][12];

int n;
ld solve(int i, int p1, int p2) {
	if (i >= n) return (ld)0.0;
	if (done[i][p1][p2]) return memo[i][p1][p2];

	auto &ans = memo[i][p1][p2];
	ans = press * (ld)V(S[i]);


	if (i + 1 < n and P(S[i]) == P(S[i+1])) {
		auto c1 = solve(i+1, P('#'), p2) + press + D(p1, P(S[i])) + D(P(S[i]), P('#'));
		auto c2 = solve(i+1, p1, P('#')) + press + D(p2, P(S[i])) + D(P(S[i]), P('#'));
		auto c3 = solve(i+1, P('#'), P(S[i])) + press + D(p1, P('#')) + D(p2, P(S[i]));
		auto c4 = solve(i+1, P(S[i]), P('#')) + press + D(p1, P(S[i])) + D(p2, P('#'));
		ans += min({c1, c2, c3, c4});
	}
	else {
		auto c1 = solve(i+1, P(S[i]), p2) + D(P(S[i]), p1);
		auto c2 = solve(i+1, p1, P(S[i])) + D(P(S[i]), p2);
		ans += min(c1, c2);
	}

	done[i][p1][p2] = true;
	return ans;
}


void run() {
	for (int i = 0; i <= S.size(); i++) {
		for (int j = 0; j < 12; j++) {
			for (int k = 0; k < 12; k++) {
				done[i][j][k] = 0;
			}
		}
	}

	n = S.size();
	cout << fixed << setprecision(2) << solve(0, 3, 5) << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	precomp();

	while (getline(cin, S)) {
		run();
	}
}


// AC, dynamic programming
