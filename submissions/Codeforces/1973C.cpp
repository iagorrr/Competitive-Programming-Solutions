#include <bits/stdc++.h>
using namespace std;

/*
	n é par !
	permutação p de size n

	locla maximus:
		- em a de sz n tbm
		- a[i] = p[i] + q[i]
		- a[i-1] < a[i] < a[i+1] 
		^^
		^^
		^^
		^^
		^^
		^^ é o número de vezes que isso ocorre
	
	acha essa permutação q ae que maximiza o score !

	p = 	1	2 	3 	4
	q = 
	a =	1	2	3	4



	input 1
	p = 	1 	2 	3 	4
	a = 	2	4	1	3
	q =	3	6*	4	7
	pts =  1


	input 2
	p = 	4	3	1	2
	a =	3 	1 	4	2
	q =	7	4	5*	2
	pts = 1

	input 3
	p =	6	5	1	4	2	3
	a =	2	5	1	4	3	6
	q =	8	10*	2	8*	5	9
	pts =  2

	- ans = n/ 2 -1 ??

	input 4
	p = 	1	2	4	5	7 	6	8	3 	
	a =	5	4	8	2	7	1	6	3
	q = 	6	6	12*	7	14*	7	14*	6
	pts =  3

	oto jeito
	p = 	1	2	4	5	7 	6	8	3 	
	a =	
	q = 	6	6	12*	7	14*	7	14*	6
	pts =  3

	- pra geral a responta é n / 2 - 1
	- ou o primeiro ponto tá na posição 2
	- ou o primiero ponto tá na posição 3

	considera par e impar dois gurpos distintios
	da pros impares o maximo pra deixar geral grandao
	e pros pares o contrário os menores com maiores das jfsodpfs


	coloca os mairoes onde o maior valroe estiver !

	1	2 	3	4
		4		3
 */

auto run() {
	int n;
	cin >> n;

	vector<int> xs(n+1);
	for (int i = 1; i <= n; i++) cin >> xs[i];

	int mpos = 0;
	for (int i = 1; i <= n; i++) {
		if (xs[i] > xs[mpos]) mpos = i;
	}

	vector<int> odds, evens;
	for (int i = 1; i<= n;i++) {
		if (i&1) odds.push_back(xs[i]);
		else evens.push_back(xs[i]);
	}

	map<int,int> ans;
	int q = n;
	if (mpos & 1) {
		sort(odds.begin(), odds.end());
		for (auto o : odds) {
			ans[o] = q;
			q--;
		}
		sort(evens.begin(), evens.end());
		for (auto e : evens) { 
			ans[e] = q;
			q--;
		}

	}
	else {
		sort(evens.begin(), evens.end());
		for (auto e : evens) { 
			ans[e] = q;
			q--;
		}
		sort(odds.begin(), odds.end());
		for (auto o : odds) {
			ans[o] = q;
			q--;
		}
	}

	vector<int> fans;
	for (int i = 1; i <= n; i++) {
		fans.push_back(ans[xs[i]]+xs[i]);
		cout << ans[xs[i]] << " \n"[i==n];
	}

	/*
	int cnt = 0;
	for (int i = 1; i+1 < n; i++) {
		cnt += ((fans[i-1] < fans[i]) and (fans[i] > fans[i+1]));
	}
	assert(cnt == n/2 -1);
	*/
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;

	while (tt--) {
		run();
	}
}
 
// AC, constructive algorithms, math, sortings
