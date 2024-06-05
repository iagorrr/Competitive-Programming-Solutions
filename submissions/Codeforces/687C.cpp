#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500;
int N, K;
int CS[MAXN];

bool memo1[MAXN+1][MAXN+1];
bool memo2[MAXN+1][MAXN+1];

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >>  K;
	for (int i = 0; i < N; i++) {
		cin >> CS[i];
	}

	memo1[0][0] = memo1[CS[0]][0] = memo1[CS[0]][CS[0]] = true;
	for (int i = 1; i < N; i++) {
		auto ci = CS[i];
		for (int j = 0; j <= 500; j++) {
			for (int k = 0; k <= 500; k++) {
				memo2[j][k] = (j == 0 and k == 0);
				memo2[j][k] |= memo1[j][k];
				if (j-ci >= 0) {
					memo2[j][k] |= memo1[j-ci][k];
					if (k-ci >= 0)
						memo2[j][k] |= memo1[j-ci][k-ci];
				}
			}

		}
		memcpy(memo1, memo2, sizeof memo2);
	}


	vector<int> ans;
	for (int i = 0; i <= K; i++) {
		if (memo1[K][i]) ans.emplace_back(i);
	}

	cout << ans.size() << '\n';
	for (auto ai : ans) cout << ai << ' ';
	cout << '\n';
}

// AC, dynamic programming
