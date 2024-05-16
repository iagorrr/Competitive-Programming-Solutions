#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN(2'00'000);
int N;
int ST[MAXN << 1], XS[MAXN];

struct Node {
  ll value;
  Node() : value(0){};  // Neutral element
  Node(ll v) : value(v){};
};

Node combine(Node &nl, Node &nr, int l, int r, int ql,
             int qr) {
  Node m;
  m.value = nl.value + nr.value;
  return m;
}
struct SegTree {
  int n;
  vector<Node> st;
  SegTree(int n) : n(n), st(n << 2) {}

  void assign(int p, const Node &v) {
    assign(1, 0, n - 1, p, v);
  }
  void assign(int node, int l, int r, int p,
              const Node &v) {
    if (l == r) {
      st[node] = v;
      return;
    }

    int m = midpoint(l, r);
    if (p <= m)
      assign(node << 1, l, m, p, v);
    else
      assign(node << 1 | 1, m + 1, r, p, v);

    st[node] =
      combine(st[node << 1], st[node << 1 | 1], l, r, l, r);
  }

  inline Node query(int l, int r) {
    return query(1, 0, n - 1, l, r);
  }

  inline Node query(int node, int nl, int nr, int l,
                    int r) const {
    if (r < nl or nr < l) return Node();
    if (l <= nl and nr <= r) return st[node];

    int m = midpoint(nl, nr);
    auto a = query(node << 1, nl, m, l, r);
    auto b = query(node << 1 | 1, m + 1, nr, l, r);

    return combine(a, b, nl, nr, l, r);
  }
};
int main() {
  cin >> N;
  SegTree st(N);
  for (int i = 0; i < N; i++) {
    st.assign(i, 1);
    cin >> XS[i];
  }

  for (int i = 0; i < N; i++) {
    int p;
    cin >> p;

    int l = 0, r = N - 1;
    int ans = N;

    while (l <= r) {
      int mid = midpoint(l, r);
      int sum = st.query(0, mid).value;

      if (sum >= p) {
        ans = min(ans, mid);
        r = mid - 1;
      } else
        l = mid + 1;
    }

    cout << XS[ans] << " \n"[i == N - 1];
    st.assign(ans, 0);
  }
}

/*
 * AC
 * Segtree
 * Range sum query
 * Binary Search
 * https://cses.fi/problemset/task/1749/
 * */
