#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define endl '\n'

#define fastio                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);

#define int long long

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define rep(i, a, b) for (common_type_t<decltype(a), decltype(b)> i = a; i != b; (a < b) ? ++i : --i)
#define sz(x) (int)x.size()
#define pb push_back
#define eb emplace_back 

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;

int T = 1;

using ll = long long;

struct Node {
  ll value;
  Node() : value(numeric_limits<ll>::min()){};  // Neutral element
  Node(ll v) : value(v){};
};

Node combine(Node l, Node r) {
  Node m;
  m.value = max(l.value, r.value);
  return m;
}

template <typename T=Node, auto F=combine>
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

template<typename SegT=Node, auto SegOp=combine>
struct HeavyLightDecomposition {
        int n;
        vi parent, depth, size, heavy, head, pos;

        SegTree<SegT, SegOp> seg;

        HeavyLightDecomposition(
            const vi2d &g,
            const vector<SegT> &v, int root = 0)
            : 
                n(sz(g)),
                parent(n),
              depth(n),
              size(n),
              heavy(n, -1),
              head(n),
              pos(n),
              seg(n) {

                dfs(g, root);
                int cur_pos = 0;

                decompose(g, root, root, cur_pos);

                rep(i, 0, n) {
                        seg.assign(pos[i], v[i]);
                }
        }

        SegT query_path(int a, int b) {
                SegT res;
                for (; head[a] != head[b];
                     b = parent[head[b]]) {
                        if (depth[head[a]] > depth[head[b]])
                                swap(a, b);

                        res =
                           SegOp(res, seg.query(pos[head[b]],
                                              pos[b]));
                }
                if (depth[a] > depth[b]) swap(a, b);
                return SegOp(res, seg.query(pos[a], pos[b]));
        }

        SegT query_subtree(int a) const {
                return seg.query(pos[a],
                                 pos[a] + size[a] - 1);
        }

        void assign(int a, SegT x) { seg.assign(pos[a], x); }

       private:
        void dfs(const vi2d &g, int u) {
                size[u] = 1;
                int mx_child_size = 0;
                for (auto x : g[u])
                        if (x != parent[u]) {
                                parent[x] = u;
                                depth[x] = depth[u] + 1;
                                dfs(g, x);
                                size[u] += size[x];
                                if (size[x] > mx_child_size)
                                        mx_child_size =
                                            size[x],
                                        heavy[u] = x;
                        }
        }

        void decompose(const vi2d &g, int u,
                       int h, int &cur_pos) {
                head[u] = h;
                pos[u] = cur_pos++;
                if (heavy[u] != -1)
                        decompose(g, heavy[u], h, cur_pos);

                for (auto x : g[u])
                        if (x != parent[u] and
                            x != heavy[u]) {
                                decompose(g, x, x, cur_pos);
                        }
        }
};

auto run() {
        int N, Q;
        cin >> N >> Q;

        vector<Node> VS(N);
        rep(i, 0, N) {
                int vi;
                cin >> vi;
                VS[i] = Node(vi);
        }

        vi2d ADJ(N);
        rep(i, 0, N-1) {
                int a, b;
                cin >> a >> b;
                a--, b--;

                ADJ[a].eb(b);
                ADJ[b].eb(a);
        }

        HeavyLightDecomposition  hld(ADJ, VS);

        rep(q, 0, Q) {
                int o;
                cin >> o;

                if (o&1) {
                        int s, x;
                        cin >> s >> x;
                        s--;
                        hld.assign(s, Node(x));
                }
                else {
                        int a, b;
                        cin >> a >> b;
                        a--, b--;
                        auto res = hld.query_path(a, b);
                        cout << res.value << ' ';
                }
        }

        cout << endl;
}

int32_t main() {
#ifndef LOCAL
	fastio;
#endif

	// cin >> T;

	rep(t, 0, T) {
                dbg(t);
		run();
  	}
}


/*
 * AC, trees, heavy light decomposition
 */
