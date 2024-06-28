#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxxi = 1'000'000;
int hist[maxxi+1];
bool done[maxxi+1];
ll psum[maxxi+1];


int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);



	int n;
	cin >> n;
	
	int mx = 0;
	vector<int> xs(n);
	for (auto &xi : xs) {
		cin >> xi;
		hist[xi]++;
		mx = max(mx, xi);
	}

	for (int i = 0; i <= maxxi; i++) {
		psum[i] = hist[i] + (i ? psum[i-1] : 0);
	}

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		auto xi = xs[i];
		if (done[xi]) continue;
		done[xi] = 1;
		for (int j = 1; j <= mx / xi; j++) {
			int l = xi*j;
			int r = min(xi*(j+1)-1, maxxi);
			long long qtd = (psum[r] - psum[l-1]);
			if (j == 1) {
				qtd -= hist[xi];
			}

			ll inc =  0;
			if (l <= xi and xi <= r) {
				inc += ((ll)(hist[xi]-1)*(hist[xi]))/2;
			}

			inc +=  (ll)qtd * j * hist[xi];
			ans += inc;
		}
	}

	cout  << ans << '\n';
}

// AC, math, psum
