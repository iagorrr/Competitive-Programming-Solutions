#include <bits/stdc++.h>
using namespace std;

/*
	(((())

	((()))

	()(())

	(((())


	 da certo sempre que for possivel diexr o sufixo igual ao reverso do previxo

	 e n pode ter nem uma dessas:
		 pro prefixo )) gente fechando que não vai mais dar certo
		 pro sufixo: ( gente abrindo o que não vai dar pra fechar

 */

auto run() {
	int n;
	cin >> n;

	string s;
	cin >> s;

	// { abrindo, fechando, deu ruim}
	using a3 = array<int, 3>;
	vector<a3> pref(n), suf(n);

	
	// prefixo
	a3 cur = {0, 0, 0};
	string stk;
	for (int i = 0; i < n; i++) {
		if (s[i] == ')') {
			if (stk.empty() or stk.back() == ')') {
				cur[2]++;

			}
			else {
				cur[0]--;
				stk.pop_back();
			}
		}
		else {
			stk.push_back('(');
			cur[0]++;
		}

		//cerr << s[i] << ' ' << cur[0] << ' ' << cur[1] << ' ' << cur[2] << '\n';
		pref[i] = cur;
	}

	// sufixo 
	cur = {0, 0, 0};
	stk = "";
	//cerr << "suf: \n";
	for (int i = n-1; i >= 0; i--) {
		if (s[i] == '(') {
			if (stk.empty() or stk.back() == '(') {
				cur[2]++;

			}
			else {
				cur[1]--;
				stk.pop_back();
			}
		}
		else {
			stk.push_back(')');
			cur[1]++;
		}

		//cerr << s[i] << ' ' << cur[0] << ' ' << cur[1] << ' ' << cur[2] << '\n';
		suf[i] = cur;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		a3 l = {0};
		a3 r = {0};
		if (i) l = pref[i-1];
		if (i+1<n) r = suf[i+1];

		// não arrumo essas bombas
		if (l[2] or r[2]) continue;

		if (s[i] == ')') {
			if (r[1]) r[1]--;
			else continue;
			ans += l[0] == r[1];
		}
		else {
			if (l[0]) l[0]--;
			else continue;
			ans += l[0] == r[1];
			
		}
	}

	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}


// AC, ad-hoc
