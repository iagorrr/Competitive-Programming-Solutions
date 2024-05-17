#include <bits/stdc++.h>
using namespace std;


int n, k;
int mx, pmx;

void find_mx() {
	/*
	   	- vai existir um maior valor
		- a resposta tem que ser múltipla desse maior valor, 
		já que no segmento dele ele vai estar no produto
		- pra f(1,n) = n * mx
		- onde mx é o maior valor
		- 
	 */
	for (int i = 1, p; i <= n; i++) {
		cout << "? 1 " << i*n << endl;
		cin >> p;
		if (p == n) {
			mx = i;
			break;
		}
	}
}

bool check(int m) {

	int l = 1;
	for (int i = 0, p; i < k; i++) {
		if (l > n) return false;
		cout << "? " << l << " " << m << endl;
		cin >> p;
		l = p  + 1;
		if (p == n + 1) return false;
	}

	return l == n + 1;
}

auto run() {
	cin >> n >> k;

	find_mx();

	for (int i = 1; i <= n/k; i++) {
		if (check(i*mx)) {
			cout << "! " << i*mx << endl;
			int tmp;
			cin >> tmp;
			return;
		}
	}

	cout << "! " << -1 << endl;
	int tmp;
	cin >> tmp;
}

int32_t main() {
	/*
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	*/
	int tt = 1;
	cin >> tt;

	while(tt--) run();

}

// AC. math, iteractive
