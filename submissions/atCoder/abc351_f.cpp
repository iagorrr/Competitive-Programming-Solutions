#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node {
  ll value;
  Node() : value(0){};  // Neutral element
  Node(ll v) : value(v){};
};

Node combine(Node &nl, Node &nr) {
  Node m;
  m.value = nl.value + nr.value;
  return m;
}

Node combine(Node &nl, Node &nr);

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

	int n;
	cin >> n;

	vector<ll> xs(n);
	set<ll> ordered;
	for (auto& xi : xs) {
		cin >> xi;
		ordered.emplace(xi);
	}

	map<ll,int> id;
	int curid = 0;
	for (auto xi : ordered) {
		id[xi] = curid++;
	}

	ll ans = 0;

	SegTree st(n);
	SegTree hs(n);
	for(auto& xi : xs) {
		auto xiid = id[xi];
		ll qtd = hs.query(0, xiid).value;
		ll v = st.query(0, xiid).value;
		ans = ans + qtd*xi - v;

		auto p = hs.query(xiid,xiid);
		p.value++;
		hs.assign(xiid, p);

		auto p2 = st.query(xiid,xiid);
		p2.value += xi;
		st.assign(xiid, p2);
	}

	cout << ans << '\n';


}

// AC, coordinate compression, segment tree, range queries
