#include <bits/stdc++.h>
using namespace std;

map<pair<int,int>, int> answered;
int ask(int l, int r) {
	if (answered.count({l,r}))
		return answered[{l,r}];

	cout << "? " << l << ' ' << r << endl;
	int x;
	cin >> x;
	return answered[{l,r}] = x;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int SMX = ask(1, N);
	
	int left =  SMX == 1 ? -1 : ask(1, SMX);	
	int right = left == SMX ? -1 : SMX;

	if (left == SMX) {
		int ans = 1;
		for (int l = 1, r = SMX-1;  l <= r; ) {
			int mid = (l+ r)/2;
			int q = ask(mid, SMX);
			if (q == SMX) {
				ans = max(ans, mid);
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}

		cout << "! " << ans << endl;
	}
	else if (right == SMX) {
		int ans = N;
		for (int l = SMX+1, r = N;  l <= r; ) {
			int mid = (l+r)/2;
			int q = ask(SMX, mid);
			if (q == SMX) {
				ans = min(ans, mid);
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}

		cout << "! " << ans << endl;
	}
	else
		assert(0);


}

/*
   AC, interactive, binary search
 */
