#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node {
  ll value;
  Node() : value(0){};  // Neutral element
  Node(ll v) : value(v){};
};

inline Node combine(const Node &nl, const Node &nr) {
  Node m;
  m.value = nl.value + nr.value;
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


int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, Q;
	cin >> N >> Q;

	vector<int> XS(N);
	for (auto &xi : XS)
		cin >> xi;

	vector<int> min_x(N);
	SegTree seg(N+1);
	for (int i = 0; i < N; i++) {
		int cur_k = N;
		for (int l = 1, r = N; l <= r; ){
			int mi = (l+r)/2;
			int tot = seg.query(0, mi).value;
			if ((tot / mi) < XS[i]) {
				cur_k = min(cur_k, mi);
				r = mi - 1;
			}
			else l = mi + 1;
		}
		min_x[i] = cur_k;
		seg.assign(cur_k, seg.query(cur_k,cur_k).value + 1);
	}


	while (Q--){
		int ii, xi;

		cin >> ii >> xi; ii--;
		cout << (min_x[ii] <= xi ? "YES" : "NO") << '\n';
	}
}

// AC, data structures, binary search
