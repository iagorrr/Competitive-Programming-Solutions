#include <bits/stdc++.h>
using namespace std;

using ll = long long;


template<typename T>
struct LR {
	struct SegTree {
	  int n;
	  vector<T> st;
	  SegTree(int _n) : n(_n), st(n << 1, numeric_limits<T>::min()) {}

	  void assign(int p, const T &k) {
	    for (st[p += n] = k; p >>= 1;)
	      st[p] = max(st[p << 1], st[p << 1 | 1]);
	  }

	  T query(int l, int r) {
	    T ansl, ansr;
	    ansl = ansr = numeric_limits<T>::min();
	    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
	      if (l & 1) ansl = max(ansl, st[l++]);
	      if (r & 1) ansr = max(st[--r], ansr);
	    }

	    return max(ansl, ansr);
	  }
	};

	int n;
	SegTree st;

	LR(int _n) : n(_n), st(n) {}
	LR(const vector<T> &xs) : n(xs.size()), st(n){
		for (int i = 0; i < n; i++) {
			st.assign(i, xs[i]);
		}
	}

	void assign(int p, const T &x) {
		st.assign(p, x);
	}

	pair<int,int> query(int i) {
		int L = -1;

		auto vi = st.query(i,i);
		for (int l = 0, r = i -1; l <= r; ) {
			int m = midpoint(l, r);
			ll vm = st.query(m, i-1);
			if (vm >= vi) {
				L = max(L, m);
				l = m + 1;
			}
			else r = m - 1;
		}



		int R = n*2;
		for (int l = i+1, r = n-1; l <= r; ) {
			int m = midpoint(l, r);

			ll vm = st.query(i+1, m);
			if (vm >= vi) {
				r = m - 1;
				R = min(R, m);
			}
			else  l = m + 1;
		}

		return {L, R==n*2 ? -1 : R};
	}
};

auto run() {

	int n;
	cin >> n;
	vector<ll> xs(n);

	for (auto &xi : xs) {
		cin >> xi;
	}

	LR st(xs);
	for (int i = 0; i < n; i++) {
		auto [l, r] = st.query(i);
		l = l == -1 ? -1 : l;
		r = r == -1 ? n : r;
		int dl = i-l-1;
		if (dl and (dl&1)) return 0;
		int dr = r-i-1;
		if (dr and (dr&1)) return 0;
	}

	return 1;
}


int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	// cin >> tt;

	while (tt--) {
		cout << (run() ? "YES" : "NO") << '\n';
	}
}

// AC, data structures, greddy
