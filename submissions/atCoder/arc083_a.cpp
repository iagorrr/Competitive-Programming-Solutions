#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, d, e, f;

	cin >> a >> b >> c >> d >> e >> f;

	swap(c,d) ;
	int answ=-1, anss=-1;
	for (int qa = 0; qa*a*100ll <= f; qa++) {
		for (int qb = 0; qa*a*100ll+qb*b*100ll <= f; qb++) {
			for (int qd = 0; qa*a*100ll+qb*b*100ll + qd*d <= f; qd++) {
				int water = qa*a*100ll + qb*b*100ll;
				int sugar = qd*d;

				for (int l = 0, r = f - water - sugar; l <= r; ) {
					int mid = midpoint(l, r);
					sugar += mid*c;
					if (water + sugar <= f and e*(water) >= sugar*(100ll)) {
						if (anss==-1 or anss*(sugar+water) <= sugar*(answ+anss)){
							answ = water, anss = sugar;
						}
						l = mid + 1;
					}
					else r = mid -1;
					sugar -= mid*c;
				}


			}
		}
	}

	cout << answ + anss << ' ' << anss << '\n';
}


// AC, math, bruteforce
