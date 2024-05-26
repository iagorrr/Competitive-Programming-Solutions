#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct CVGT {
  struct SegTree {
    int n;
    vector<T> st;
    SegTree(int _n)
      : n(_n), st(n << 1, numeric_limits<T>::max()) {}

    void assign(int p, const T &k) {
      for (st[p += n] = k; p >>= 1;)
        st[p] = min(st[p << 1], st[p << 1 | 1]);
    }

    T query(int l, int r) {
      T ansl, ansr;
      ansl = ansr = numeric_limits<T>::max();
      for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ansl = min(ansl, st[l++]);
        if (r & 1) ansr = min(st[--r], ansr);
      }

      return min(ansl, ansr);
    }
  };

  int n;
  SegTree st;

  CVGT(int _n) : n(_n), st(n) {}
  CVGT(const vector<T> &xs) : n(xs.size()), st(n) {
    for (int i = 0; i < n; i++) {
      st.assign(i, xs[i]);
    }
  }

  void assign(int p, const T &x) { st.assign(p, x); }

  pair<int, int> query(int i) {
    int L = i;

    auto vi = st.query(i, i);
    for (int l = 0, r = i; l <= r;) {
      int m = midpoint(l, r);
      T vm = st.query(m, i);
      if (vm >= vi) {
        L = min(L, m);
        r = m - 1;
      } else l = m + 1;
    }

    int R = i;
    for (int l = i, r = n - 1; l <= r;) {
      int m = midpoint(l, r);

      T vm = st.query(i, m);
      if (vm >= vi) {
        l = m + 1;
        R = max(R, m);
      } else r = m - 1;
    }

    return {L, R};
  }
};


int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> xs(n);
	for (auto &xi : xs) cin >> xi;
	
	CVGT st(xs);

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		auto [l, r] = st.query(i);
		long long a = (long long) xs[i] * (r-l+1ll);
		// cerr << i << ' ' << l << ' ' << r <<  ' ' << a << '\n';
		ans = max(ans, a);
	}

	cout << ans << '\n';
}

// AC, segment tree, binary search
