#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
  ll value;
  bool undef;
  Node() : value(1), undef(1){};  // Neutral element
  Node(ll v) : value(v),undef(0){};
};

inline Node combine(const Node &nl, const Node &nr) {
	if(nl.undef) return nr;
	if(nr.undef) return nl;
  Node m;
  m.value = gcd(nl.value , nr.value);
  m.undef = false;
  return m;
}

struct SegTree {
  int n;
  vector<Node> st;
  SegTree(int _n) : n(_n), st(n << 1) {}

  void assign(int p, const Node &k) {
    for (st[p += n] = k; p >>= 1;)
      st[p] = combine(st[p << 1], st[p << 1 | 1]);
  }

  Node query(int l, int r) {
    Node ansl, ansr;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ansl = combine(ansl, st[l++]);
      if (r & 1) ansr = combine(st[--r], ansr);
    }
    return combine(ansl, ansr);
  }
};

auto run() {
	int N;
	cin >> N;

	SegTree seg(N*2);
	for (int i = 0; i < N; i++) {
		int xi;
		cin >> xi;
		seg.assign(i, xi);
		seg.assign(i+N, xi);
	}

	auto check = [&](int k) -> bool {
		int v = seg.query(0, k-1).value;
		for (int i = 1; i < N; i++) {
			if (v != seg.query(i, i+k-1).value)
				return false;
		}
		return true;
	};

	int ans = N;
	for (int l = 1, r = N; l <= r; ) {
		int mid =  (l+r)/2;
		if (check(mid)) {
			ans = min(ans, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}

	cout << ans - 1 << '\n';

}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++)
		run();
}


// AC, data structures, binary search, number theory
