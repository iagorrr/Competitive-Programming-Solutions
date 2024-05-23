#include<bits/stdc++.h>

using namespace std;


int n;
void solve() {
	vector<pair<int,int>> xs(n);
	for (auto &[a, b] : xs) {
		cin >> a >> b;
	}


	auto it = unique(xs.begin(), xs.end());
	xs.erase(it, xs.end());
	sort(xs.begin(), xs.end());

	vector<pair<int,int>> merged;
	merged.push_back(xs[0]);

	for (int i = 1; i < xs.size(); i++) {
		auto &[pl, pr] = merged.back();
		auto &[cl, cr] = xs[i];

		if (cl <= pr) 
			pr = min(pr, cr);
		else merged.push_back({cl, cr});
	}

	cout << merged.size() << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n) {
		solve();
	}
}

