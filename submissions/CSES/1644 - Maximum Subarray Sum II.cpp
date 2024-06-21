#include <bits/stdc++.h>
using namespace std;
 
 
using ll = long long;
const ll oo = 1e15;
 
 
struct Node {
  ll value;
  Node() : value(-oo){};  // Neutral element
  Node(ll v) : value(v){};
};
 
Node combine(Node &l, Node &r) {
  Node m;
  m.value = max(l.value, r.value);
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
 
	int n, a, b;
	cin >> n >> a >> b;
 
	vector<ll> xs(n), psum;
	psum.reserve(n);
	for (auto &xi : xs) {
		cin >> xi;
		psum.emplace_back((psum.empty() ? 0 : psum.back()) + xi);
	}
 
	SegTree st(n);
	for (int i = 0; i < n; i++) {
		st.assign(i, psum[i]);
	}
 
 
	ll cursum = accumulate(xs.begin(), xs.begin()+a, 0ll);
	ll ans = cursum;
 
	for (int l = 0, r = a; r < n; l++, r++) {
		auto q = st.query(r,min(n-1, r + (b-a-1))).value;
		q = max(q - (r ? psum[r-1] : 0), 0ll);
		ans = max(ans, cursum+q);
		cursum += xs[r];
		cursum -= xs[l];
	}
 
	ans = max(ans, cursum);
 
	cout << ans << '\n';
}

// AC, slide window, segment tree
