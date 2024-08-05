#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define endl '\n'

#define fastio                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);

#define int long long

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define rep(i, a, b) for (common_type_t<decltype(a), decltype(b)> i = a; i != b; (a < b) ? ++i : --i)
#define _sz(x) (int)x.size()
#define pb push_back
#define eb emplace_back 

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;

int T = 1;

auto run() {
	int K;
	cin >> K;

	vi SZS(K);
	rep(k, 0, K) {
		cin >> SZS[k];

		rep(i, 0, SZS[k]-1) {
			int _; cin >> _;
		}
	}

	sort(rall(SZS));

	int ans = 0;
	const int maxb = 23;
	bitset<maxb> dont_have;
	dont_have.set();

	for (auto& szi : SZS) {
		rep(b, maxb-1, 0-1) {
			if (dont_have[b] and (1ll<<b) <= szi) {
				dont_have[b] =0;
				szi -= (1ll<<b);
				ans |= (1ll<<b);
			}
		}
	}

	cout << ans << '\n';
}

int32_t main() {
#ifndef LOCAL
	fastio;
#endif

	cin >> T;

	rep(t, 0, T) {
                dbg(t);
		run();
  	}
}



/*
	Remover a maior árvore inteira pois ela possúi o maior bit

	Depois dos bit que ela não posśui eu tento ligar do maior pro menor ??

	n - > 10^6

	então a resposta vai até 10^6 tbm

	Se eu planar todas as árvores da pra saber o size de cada subárvore
	e ainda por cima atualizar quando eu removo uma sub árvore
	Acho que não da pra fazer update na verdade

	da pra pensar que na verdade a gente tá construindo as árvores
	ao invés de tirar de outras

	pq se uma subárvore tem X nós consigo remover de 1 em 1
	e fazer com que quando eu remover ela de fato ela tenha X - K nós

	vejo qual é o maior bit possível alcançável

	subo as folhas pique lenhador enquanto eu não atingir uma folha que tenha pelo menos 2^mxb filhos

	dai vou ter nós que conseguem colocar o maior bit lá

	com isso eu sei também que se eles tem pelo menos 2^mxb filhos eu posso tirar de 1 em 1 e fazer 
	eles terem de 1 ... 2^mxb filhos, então consigo ligar qualquer outro bit que eu quiser

	melhor ainda

	posso tirar somente até ficar  com 2^mxb  - 1, que é  a maior máscara

	se eu tiver 2 nós com pelo menos 2 ^ mxb a resposta é 2^mxb + (2^mxb   -  1) = (2 ^{mxb+1} - 1)

	vai quebrar em algum caso com árvores de size 8 2 1
	vai pegar a de 8 e a de 2 e não vai considerar a de 1

	acho que o correto é passar de árvore em árvore e ver se ela consegue dar
	algum bit que ainda não tenho na mask

	AC, greddy
 */
