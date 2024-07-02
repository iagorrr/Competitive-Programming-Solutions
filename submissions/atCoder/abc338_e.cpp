#include <bits/stdc++.h>
using namespace std; 

using ll = long long;

const ll oo = 1e18;

struct Node1 {
  ll value;
  Node1() : value(oo){};  // Neutral element
  Node1(ll v) : value(v){};
};

Node1 combine1(Node1 &l, Node1 &r) {
  Node1 m;
  m.value = min(l.value, r.value);
  return m;
}

struct SegTree1 {
  int n;
  vector<Node1> st;
  SegTree1(int _n) : n(_n), st(n << 1) {}

  void assign(int p, const Node1 &k) {
    for (st[p += n] = k; p >>= 1;)
      st[p] = combine1(st[p << 1], st[p << 1 | 1]);
  }

  Node1 query(int l, int r) {
    Node1 ansl, ansr;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ansl = combine1(ansl, st[l++]);
      if (r & 1) ansr = combine1(st[--r], ansr);
    }
    return combine1(ansl, ansr);
  }
};

/*====================================================================================================*/
struct Node2 {
  ll value;
  Node2() : value(-oo){};  // Neutral element
  Node2(ll v) : value(v){};
};

Node2 combine2(Node2 &l, Node2 &r) {
  Node2 m;
  m.value = max(l.value, r.value);
  return m;
}

struct SegTree2 {
  int n;
  vector<Node2> st;
  SegTree2(int _n) : n(_n), st(n << 1) {}

  void assign(int p, const Node2 &k) {
    for (st[p += n] = k; p >>= 1;)
      st[p] = combine2(st[p << 1], st[p << 1 | 1]);
  }

  Node2 query(int l, int r) {
    Node2 ansl, ansr;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ansl = combine2(ansl, st[l++]);
      if (r & 1) ansr = combine2(st[--r], ansr);
    }
    return combine2(ansl, ansr);
  }
};
/*====================================================================================================*/


int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;		
	cin >> n;

	SegTree1 st1(2*n+1);
	SegTree2 st2(2*n+1);
	vector<int> xs(2*n+1);
	for (int i = 0, a, b; i < n; i++) {
		cin >> a >> b;
		xs[a] = b;
		xs[b] = a;
		
		st1.assign(a, b);
		st1.assign(b, a);

		st2.assign(a, b);
		st2.assign(b, a);
	}

	bool ok = true;
	for (int i = 1; i <= 2*n; i++) {
		auto [l, r] = minmax({i, xs[i]});
		ok &= st1.query(l, r).value >= l;
		ok &= st2.query(l, r).value <= r;
	}

	cout << (ok ? "No" : "Yes") << '\n';
}

// AC, data structures, range queries, segment tree
