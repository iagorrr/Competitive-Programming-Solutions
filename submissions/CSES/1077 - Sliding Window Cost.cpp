#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;
#define int long long

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> xs(n);
	for (auto &xi : xs)
		cin >> xi;

	multiset<int> st1, st2;
	int64_t s1 = 0, s2 = 0; 

	ordered_set<pair<int,int>> st;
	for (int i = 0; i < k; i++) {
		st.insert({xs[i], i});
		st1.emplace(xs[i]);
		s1 += xs[i];
	}

	for (int l = 0, r = k; r <= n; l++, r++) {
		auto [a, _] = *st.find_by_order(k/2);
		auto [b, __] = *st.find_by_order((k-1)/2);
		int64_t mid_v = (a+b) / 2ll;
		
		while (st1.size() > 0 and *st1.rbegin() > mid_v) {
			s1 -= *st1.rbegin();
			s2 += *st1.rbegin();

			st2.emplace(*st1.rbegin());
			st1.extract(*st1.rbegin());
		}

		while (st2.size() > 0 and *st2.begin() <= mid_v) {
			s2 -= *st2.begin();
			s1 += *st2.begin();

			st1.emplace(*st2.begin());
			st2.extract(*st2.begin());
		}

		int64_t ans_leq = llabs(st1.size()*mid_v - s1);
		int64_t ans_g = llabs(s2 - (int64_t)st2.size()*mid_v);

		cout << ans_leq + ans_g << " \n"[k==n];

		if (r == n) break;

		st.erase({xs[l], l});
		st.insert({xs[r], r});

		s1 += xs[r];
		st1.emplace(xs[r]);

		if (xs[l] <= mid_v) {
			s1 -= xs[l];
			st1.extract(xs[l]);
		}
		else {
			s2 -= xs[l];
			st2.extract(xs[l]);
		}
	}
}

// AC, sortings, data strucutres


