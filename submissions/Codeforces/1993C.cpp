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
#define sz(x) (int)x.size()
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
	int N, K;
	cin >> N >> K;
	vector<int> AS(N);
	for (auto& ai : AS)
		cin >> ai;

	sort(all(AS));

	if (N == 1) {
		cout << AS.back() << '\n';
		return;
	}


	ll tot = accumulate(all(AS), 0ll);
	int mxai = *max_element(all(AS));
	int mnai = *min_element(all(AS));
	const ll OO = 1e18;
	ll ans = OO;

	// x minutos depois do 
	// mxai ter ligado
	// se satisfazer a primeira e a última equação é vapo

	// quantos ciclos inteiros passaram pra cada ?
	// tem que ter passado quantidade par

	bool ok = true;
	ll f = 0;
	for (auto ai  : AS) {
		ll cycles = (mxai - ai)/K;
		if (cycles&1) {
			ok = false;
			ll nxt =  (cycles+1)*K + ai;
			dbg(ai, K, cycles, nxt);
			f = max(f, nxt - mxai);
		}
	}


	if (ok) ans = mxai;
	else {

		dbg(f);
		ok = true;
		for (auto ai  : AS) {
			ll cycles = (f+ mxai - ai)/K;
			if (cycles&1)
				ok = false;
		}

		if(ok) ans = (f+mxai);
		
	}


	if (ans == OO) {
		cout << -1 << '\n';
	}
	else cout << ans << endl;

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
   fixado o i qual a minha melhor resposta ?
   fazer busca binária nisso ??

   Tá sempre no início do primeiro intervalo
   em que o que mais demorou a ligar foi
   se não tiver lá não vai estar em lugar algum

   então tá entre mx ... mx + K

   so preciso testar até K

   parece um puta chute


   AC, math
*/
