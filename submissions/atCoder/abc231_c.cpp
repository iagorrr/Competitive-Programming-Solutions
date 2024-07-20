#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	ordered_set<pair<int,int>> st;
	int id = 0;
	 for (int i =0; i < n; i++) {
		int hi;
		cin >> hi;
		st.insert((pair<int,int>){hi, id++});
	}

	while (q--) {
		int hq;
		cin >> hq;
		cout << n - st.order_of_key((pair<int,int>){hq, -1}) << '\n';
	}
}


// AC, data structures, binary search, lower bound
