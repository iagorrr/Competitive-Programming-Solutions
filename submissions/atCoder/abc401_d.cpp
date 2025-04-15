#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	string S;
	cin >> S;

	for (int i = 0; i < N-1; i++) {
		if (S[i] == '?' and S[i+1] == 'o')
			S[i] = '.';

		if (S[i] == 'o' and S[i+1] == '?')
			S[i+1] = '.';
	}

	K -= count(S.begin(), S.end(), 'o');

	vector<pair<int,int>> rngs;
	for (int i = 0; i < N; ) {
		int r = i;
		while (r < N and S[i] == S[r]) {
			r++;
		}

		if (S[i] == '?') {
			rngs.emplace_back(i, r-1);
		}

		i = r;
	}

	int maximumPossible = 0;

	for (auto &[l, r] : rngs) {
		maximumPossible += (1+(r-l+1))/2;
	}

	if (K == 0) {
		replace(S.begin(), S.end(), '?', '.');
	}

	if (maximumPossible == K) {
		for (auto &[l ,r] : rngs) {
			if ((r - l + 1) & 1)
				for (int i = l, k = 1; i <= r; i++, k = !k) {
					S[i] = ".o"[k];
				}
		}
	}

	cout << S << '\n';
}


/*
 * 1. os que já estão setados é vapo
 * 2. todo ? ao lado de um 'o' é .
 *
 * fora isso a gente é obrigado a colocar mais coisa quando ??
	  1. o K que falta é 0, daí tudo tem que ser .
	  2. quando o K que falta só pode ser obtido colocando o máximo

 * AC, greedy, strings
 * */

