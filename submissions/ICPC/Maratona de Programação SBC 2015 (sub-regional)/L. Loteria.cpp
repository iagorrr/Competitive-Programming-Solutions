#include <bits/stdc++.h>
using namespace std;

/*
	- receber N mascarás binárias de tamanho K
	- determinar se é possível montar uma máscara binária de tamanho K
	tal que não exista nem um subconjunto das máscaras fornecidas tal
	que o XOR delas é igual a máscara montada

	consideraa cada número como uma máscara binária

	se não for possível formar a base de um espaço vetorial de 
	tamano K é pq tem alguma máscara que não vai dar pra gerar...
 */
using ll = long long;
const int maxd = 54;
ll basis[maxd]; // basis[i] = vector que possúi o msb = i
int d;
int sz;
int n;

void insertVector(ll mask) {
	for (ll i = 0; i < d; i++) {
		if ((mask & 1ll << i) == 0ll) continue;
		if (!basis[i]) {
			basis[i] = mask;
			sz++;
			return;
		}
		mask ^= basis[i];
	}
}

auto run() {
	cin >> n >> d;

	for (ll i = 0; i < n; i++) {
		ll mask = 0;
		for (ll j = 0, xi; j < d; j++) {
			cin >> xi;
			xi = xi&1ll;
			mask |= (xi * (1ll<<j));
		}
		insertVector(mask);
	}

	// verificar se conseuguem formar o vazio sem ser 
	// um subset vazio...
	bool ans = sz == d and (n != sz);

	cerr << "d: " << d << " sz: " << sz << '\n';
	cout << "SN"[ans] << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}


// AC, gauss elimination, XOR Base
