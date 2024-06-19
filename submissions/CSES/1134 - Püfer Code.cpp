#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> restore_tree_from_pufer_code(const vector<int> &code) {
	vector<int> degree(code.size() + 2, 1);

	for (auto c : code) {
		degree[c]++;
	}

	int ptr = find(degree.begin(), degree.end(), 1) - degree.begin();
	int leaf = ptr; 
	vector<pair<int, int>> edges;

	for (auto c : code) {
		edges.emplace_back(c, leaf);
		if (--degree[c] == 1 and c < ptr) {
			leaf = c;
		}
		else {
			while (ptr++, degree[ptr] != 1);
			leaf = ptr;
		}
	}
	
	edges.emplace_back(code.size() + 1, leaf);

	return edges;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> seq(n-2);
	for (auto &xi : seq) {
		cin >> xi;
		xi--;
	}

	auto ans = restore_tree_from_pufer_code(seq);
	for (auto &[u, v] :  ans) {
		cout << u + 1 << ' ' << v + 1 << '\n';
	}
}

// AC, pufer code
