#include <bits/stdc++.h>
using namespace std;

using vi2d = vector<vector<int>>;

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(0));
	int N;
	cin >> N;

	vi2d ASS(N, vector<int>(N));
	for (auto &as : ASS)
		for (auto &ai : as)
			cin >> ai;

	vi2d srs = ASS;
	for (auto &sri : srs)
		sort(sri.begin(), sri.end());

	vi2d scs = ASS;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scs[i][j] = ASS[j][i];
		}
	}

	for (auto &sci : scs)
		sort(sci.begin(), sci.end());

	long long ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			long long u = lower_bound(srs[i].begin(), srs[i].end(), ASS[i][j]) - srs[i].begin();
			long long v = lower_bound(scs[j].begin(), scs[j].end(), ASS[i][j]) - scs[j].begin();

			//cerr << i << ' ' << j << ' ' << ASS[i][j] << ' ' << u << ' ' << v << '\n';
			ans += v * (N-1-u) + u * (N-1-v);
		}
	}


	cout << (ans>>1ll) << '\n';
}
/*
 * problem:
 * 	- n x n square
 * 	- only distinct numbers
 * 	- build an axis-aligned rectangle
 * 	- two younger on one side of the banner and
 *	the two oldest on the other side
 *	- how many ways to do it
 *
 *
 * idea:
 * 	solve for one specific way of building the
 * 	rectanlge and rotate/mirror the matrix to count the other ways...
 *
 * 	n = 1500	
 *
 * 	what all numbers being distinct actually help me ?
 *
 * 	nada ver com nada
 *
 * AC, ad-hoc
 * */
