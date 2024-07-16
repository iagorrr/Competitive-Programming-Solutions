#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define int long long

const ll oo = numeric_limits<ll>::max();

// max
struct Node1 {
  ll value;
  Node1() : value(-oo){};  // Neutral element
  Node1(ll v) : value(v){};
};

Node1 combine1(Node1 &l, Node1 &r) {
  Node1 m;
  m.value = max(l.value, r.value);
  return m;
}

// min
struct Node2 {
  ll value;
  Node2() : value(oo){};  // Neutral element
  Node2(ll v) : value(v){};
};

Node2 combine2(Node2 &l, Node2 &r) {
  Node2 m;
  m.value = min(l.value, r.value);
  return m;
}

template <typename T, auto F>
struct SegTree {
  int n;
  vector<T> st;
  SegTree(int _n) : n(_n), st(n << 1) {}

  void assign(int p, const T& k) {
    for (st[p += n] = k; p >>= 1;)
      st[p] = F(st[p << 1], st[p << 1 | 1]);
  }

  T query(int l, int r) {
    T ansl, ansr;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ansl = F(ansl, st[l++]);
      if (r & 1) ansr = F(st[--r], ansr);
    }
    return F(ansl, ansr);
  }
};

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, x, y;
	cin >> n >> x >> y;

	SegTree <Node1, combine1> segmax(n);
	SegTree <Node2, combine2> segmin(n);
	vector<int> as(n);
	for (int i = 0; i < n; i++) {
		cin >> as[i];
		segmax.assign(i, as[i]);
		segmin.assign(i, as[i]);
	}

	auto find_a = [&](int idx) -> int {
		int ans = oo;
		for (int l = idx, r = n-1; l <= r; ) {
			int mid = midpoint(l, r);
			int mv = segmin.query(idx, mid).value;
			if (mv <= y) {
				ans = mv == y ? min(ans, mid) : ans;
				r = mid - 1;
			}
			else l = mid + 1;
		}

		return ans;
	};


	auto find_b = [&](int idx) -> int {
		int ans = -1;
		for (int l = idx, r = n-1; l <= r; ) {
			int mid = midpoint(l, r);
			int mv = segmin.query(idx, mid).value;
			if (mv >= y) {
				ans = mv == y ? max(ans, mid) : ans;
				l = mid + 1;
			}
			else r = mid - 1;
		}

		return ans == -1 ? oo : ans;

	};


	auto find_c = [&](int idx) -> int {
		int ans = oo;
		for (int l = idx, r = n-1; l <= r; ) {
			int mid = midpoint(l, r);
			int mv = segmax.query(idx, mid).value;
			if (mv >= x) {
				ans = mv == x ? min(ans, mid) : ans;
				r = mid - 1;
			}
			else l = mid + 1;
		}

		return ans;
	};


	auto find_d = [&](int idx) -> int {
		int ans = -1;
		for (int l = idx, r = n-1; l <= r; ) {
			int mid = midpoint(l, r);
			int mv = segmax.query(idx, mid).value;
			if (mv <= x) {
				ans = mv == x ? max(ans, mid) : ans;
				l = mid + 1;
			}
			else r = mid - 1;
		}

		return ans == -1 ? oo : ans;
	};

	using pii = pair<int,int>;
	auto intersection = [](pii a, pii b) -> int {
		if (a > b) swap(a,b);
		if (a.second < b.first) return 0;
		int l = max(a.first, b.first);
		int r = min(a.second, b.second);
		return r - l  + 1;
	};

	int ans = 0;

	for (int i = 0; i < n; i++) {
		int a = find_a(i);
		int b = find_b(i);
		int c = find_c(i);
		int d = find_d(i);
		if (a == oo or b == oo or c == oo or d == oo)
			continue;
		int sz = intersection({a, b}, {c, d});
		ans += sz;
	}

	cout << ans << '\n';
}

// AC, range queries, binary search, segment tree
