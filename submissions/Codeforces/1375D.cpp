#include <bits/stdc++.h>
using namespace std;

auto run() {
	int N;
	cin>> N;

	vector<int> XS(N);
	vector<int> hist(N+1);
	for (auto& xi : XS) {
		cin >> xi;
		hist[xi]++;
	}

	vector<int> ans;
	for (;;) {


		bool non_decreasing = true;
		int last_wrong = 0;
		for (int i = 0; i+1 < N; i++) {
			non_decreasing &= (XS[i] <= XS[i+1]);

			if (XS[i] != i)
				last_wrong = i;
		}

		if (XS[N-1] != N-1)
			last_wrong = N-1;

		int mex = find(hist.begin(), hist.end(), 0) - hist.begin();


		/*
		for (auto xi  : XS)
			cerr << xi << ' ';
		cerr << "	mex: 	" << mex;
		cerr << '\n';
		*/

		if (non_decreasing)
			break;

		if (mex == N) {
			hist[XS[last_wrong]]--;
			hist[N]++;
			XS[last_wrong] = N;
			ans.emplace_back(last_wrong+1);
		}
		else  {
			hist[XS[mex]]--;
			hist[mex]--;
			XS[mex] = mex;
			ans.emplace_back(mex+1);
		}


	}

	assert(ans.size() <= 2*N);
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " \n"[i+1==ans.size()];
	}

}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		run();
	}
}

/*
	non-decrecing

	""""increasing""""

	quadraticuzinho
	

	5

	3
	2 2 3
	vapo

	3
	2 1 0 		M = 3
	2 1 3 		M = 0
	0 1 3 		M = 2
	vapo

	uma vez que coloco o mex no array o mex nao volta a ser ele então se o mex é 
	i eu preciso por um i na posição i, ou i - 1 se o mex for n (0 indexado)

	7
	colocando gulosamente : 
	0 7 3 1 3 7 7 	m = 2  o = 1
	0 2 3 1 3 7 7 	m = 4  o = 3
	0 2 3 4 3 7 7 	m = 1  o = 0
	1 2 3 4 3 7 7 	m = 0  o = 0 // se ficar gulosamente vaoficar se repondo ai 

	// colocando namoral...
	0 7 3 1 3 7 7 	m = 2  o = 2
	0 7 2 1 3 7 7 	m = 4  o = 4
	0 7 2 1 4 7 7 	m = 3  o = 3
	0 7 2 3 4 7 7 	m = 1  o = 1
	0 1 2 3 4 7 7 	
	vapo ! fiz 4 tbm...


	namoral : 
	9
	2 0 1 1 2 4 4 2 0 	m = 3	o = 3
	2 0 1 3 2 4 4 2 0 	m = 5	o = 5
	2 0 1 3 2 5 4 2 0 	m = 6	o = 6
	2 0 1 3 2 5 6 2 0 	m = 4	o = 4
	2 0 1 3 4 5 6 2 0 	m = 7	o = 7
	2 0 1 3 4 5 6 7 0 	m = 8	o = 8
	2 0 1 3 4 5 6 7 8 	m = 9	o = 2 // pode acontecer isso aqui 6 operacoes
						acho que agora sai "concertando" coloca o N na última posicao errada
	2 0 9 3 4 5 6 7 8 	m = 1	o = 1
	2 1 9 3 4 5 6 7 8 	m = 0	o = 0
	0 1 2 3 4 5 6 7 8 	m = 2	o = 2 // concertado só coloca o MEX na última posição errada e ele sai se arrumando
						pior caso N-1 operações ??




	// namoral
	9
	8 4 7 6 1 2 3 0 5 	mex = 9  o = 8
	8 4 7 6 1 2 3 0 9 	mex = 5  o = 5
	8 4 7 6 1 5 3 0 9 	mex = 2  o = 2
	8 4 2 6 1 5 3 0 9 	mex = 7  o = 7



	AC, constructive algorithms, mex
 */

