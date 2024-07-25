#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<typename T = ll>
struct VeniceSet {
	using T2 = pair<T, ll>;
	priority_queue<T2, vector<T2>, greater<T2>> pq;
	
	T acc;
	VeniceSet(): acc() {}

	void add_element(const T& e, const ll q) {
		pq.emplace(e-acc, q);
	}

	void update_all(const T& x) {
		acc += x;
	}

	T2 best() {
		auto ret = pq.top();
		ret.first += acc;
		return ret;
	}

	void pop() {
		pq.pop();
	}

	void pop_k( int k) {
		auto [e, q] = pq.top();
		pq.pop();
		q -= k;
		if (q) pq.emplace(e, q);
	}

};

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> DS(n);
	for (auto& di : DS)
		cin >> di;

	vector<int> QS(n);
	for (auto& qi : QS)
		cin >> qi;

	vector<int> CS(n);
	for (auto& ci : CS)
		cin >> ci;

	vector<int> AS(n);
	for (auto& ai : AS)
		cin >> ai;

	ll ans = 0;
	VeniceSet st;

	for (int i = 0; i < n; i++) {
		st.add_element(CS[i], QS[i]);

		while (DS[i]) {
			auto [v, q] = st.best();
			ans += min(q, (ll)DS[i]) * v;
			st.pop_k(min(q, (ll)DS[i]));
			DS[i] = max(DS[i]-q, 0ll);
		}

		st.update_all(AS[i]);
	}

	cout << ans << '\n';
}

// AC, greddy, data structures
