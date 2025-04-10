#include <bits/stdc++.h>
using namespace std;

const int MAXBIT = 29;
using bitmask = bitset<MAXBIT+1>;

void solve() {
	int N, K;
	cin >> N >> K;

	bitmask bitsOfK(K);

	vector<int> XS(N);
	for (int i = 0; i < N; i++) {
		cin >> XS[i];
	}

	if (K == 0) {
		cout << 1 << '\n';
		return;
	}

	int ans = INT_MAX;

	vector<vector<int>> trieAdj(1, vector<int>(2, -1));
	vector<int> maxOnSubTrie(1,-1);

	// maxOnSubTrie ta errado
	auto add = [&](int idx) {
		auto bits = bitmask(XS[idx]);

		int node = 0;
		for (int b = MAXBIT; b >= 0; b--) {
			int bit = bits[b];

			maxOnSubTrie[node] = idx;

			if (trieAdj[node][bit] == -1) {
				trieAdj[node][bit] = maxOnSubTrie.size();
				trieAdj.push_back(vector<int>(2, -1));
				maxOnSubTrie.push_back(idx);
			}

			node = trieAdj[node][bit];
			maxOnSubTrie[node] = idx;
		}

	};


	auto search = [&](int idx) {

		auto bits = bitmask(XS[idx] ^ K);
		auto bitsOfIdx = bitmask(XS[idx]);

		int node = 0;
		for (int b = MAXBIT; b >= 0; b--) {
			int bit = bits[b];

			if (bitsOfK[b] == 0 and bitsOfIdx[b] == 0 and trieAdj[node][1] != -1) {
				int newV = min(ans, idx-maxOnSubTrie[trieAdj[node][1]] + 1);
				ans = newV;
			}

			if (bitsOfK[b] == 0 and bitsOfIdx[b] == 1 and trieAdj[node][0] != -1) {
				int newV = min(ans, idx-maxOnSubTrie[trieAdj[node][0]] + 1);
				ans = newV;
			}

			if (trieAdj[node][bit] == -1) {
				return;
			}

			node = trieAdj[node][bit];
		}

		int newV = min(ans, idx-maxOnSubTrie[node] + 1);
		ans = newV;
	};

	auto dbg = [&]() {
		cerr << "\n\nmaxOnSubTrie: ";
		for (int i = 0; i < maxOnSubTrie.size(); i++) {
			cerr << maxOnSubTrie[i] << ' ';
		}
		cerr << '\n';

		cerr << "adj:";
		for (int i = 0; i < trieAdj.size(); i++) {
			cerr << "(" << trieAdj[i][0] << ", " << trieAdj[i][1] << ") ";
		}
		cerr << '\n';
	};

	for (int i = 0; i < N; i++){
		//dbg();
		search(i);
		add(i);

	}

	cout << (ans == INT_MAX ? -1 : ans) << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(0));
	int T;
	cin >> T;

	while(T--) {
		solve();
	}
}

/*
 * fixar um mano ??
 *
 * pro valor ser maior :
 * 	tem algum bit maior
 * 	ou
 * 	eventualmente tem um bit amior e dps tudo é igual
 *
 * 1. par mais próximo de inteiros ai aj, tal que ai ^ aj >= k
 * 2. considerar os números como strings binárias com leading zero
 * 3. comparação dessas strings é equivalente a comparação de inteiros
 * 4. fixando o valor de x, k i:
 *
 * vapooo
 *
 * AC, strings, trie, bitwise
 * */
