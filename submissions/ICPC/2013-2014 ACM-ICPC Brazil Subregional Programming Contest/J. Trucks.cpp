/*8<{==========~ BEGIN TEMPLATE ~============>8*/
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
#define all(j) j.begin(), j.end()
#define rall(j) j.rbegin(), j.rend()
#define len(j) (int)j.size()
#define rep(i, a, b)                           \
  for (common_type_t<decltype(a), decltype(b)> \
           i = (a);                            \
       i < (b); i++)
#define rrep(i, a, b)                          \
  for (common_type_t<decltype(a), decltype(b)> \
           i = (a);                            \
       i > (b); i--)
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) \
  for (auto &xi : ranges::views::reverse(xs))
using ll = long long;
#define inte ll
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define emp emplace
#define ins insert
#define divc(a, b) ((a) + (b)-1ll) / (b)
using str = string;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vc = vector<char>;
using vs = vector<str>;
template <typename T, typename T2>
using umap = unordered_map<T, T2>;
template <typename T>
using pqmn =
    priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using pqmx = priority_queue<T, vector<T>>;
template <typename T, typename U>
inline bool chmax(T &a, U const &b) {
  return (a < b ? a = b, 1 : 0);
}
template <typename T, typename U>
inline bool chmin(T &a, U const &b) {
  return (a > b ? a = b, 1 : 0);
}
/*8<============~ END TEMPLATE ~============}>8*/
void run();

int32_t main() {
#ifndef LOCAL
  fastio;
#endif

  int T = 1;

//  cin >> T;

  rep(t, 0, T) {
    dbg(t);
    run();
  }
}

using Edge=pair<ll,int>;
/*8<
  @Title:
    Kruskal

  @Description:

    Find the minimum spanning tree of a graph.

  @Time:

    $O(E \log E)$
>8*/
struct UFDS {
  vector<int> ps, sz;
  int components;

  UFDS(int n)
      : ps(n + 1), sz(n + 1, 1), components(n) {
    iota(all(ps), 0);
  }

  int find_set(int x) {
    return (x == ps[x]
                ? x
                : (ps[x] = find_set(ps[x])));
  }

  bool same_set(int x, int y) {
    return find_set(x) == find_set(y);
  }

  void union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);

    if (x == y) return;

    if (sz[x] < sz[y]) swap(x, y);

    ps[y] = x;
    sz[x] += sz[y];

    components--;
  }
};

vector<tuple<ll, int, int>> kruskal(
    int n, vector<tuple<ll, int, int>> &edges) {
  UFDS ufds(n);
  vector<tuple<ll, int, int>> ans;

  sort(rall(edges));
  for (auto [a, b, c] : edges) {
    if (ufds.same_set(b, c)) continue;

    ans.emplace_back(a, b, c);
    ufds.union_set(b, c);
  }

  return ans;
}
struct HLD {
  int V;
  int id;
  int nb_heavy_path;
  std::vector<std::vector<int>> g;
  std::vector<pair<int, int>>
      edges;             // edges of the tree
  std::vector<int> par;  // par[i] = parent of
                         // vertex i (Default: -1)
  std::vector<int>
      depth;  // depth[i] = distance between root
              // and vertex i
  std::vector<int>
      subtree_sz;  // subtree_sz[i] = size of
                   // subtree whose root is i
  std::vector<int>
      heavy_child;  // heavy_child[i] = child of
                    // vertex i on heavy path
                    // (Default: -1)
  std::vector<int>
      tree_id;  // tree_id[i] = id of tree vertex
                // i belongs to
  std::vector<int> aligned_id,
      aligned_id_inv;  // aligned_id[i] =  aligned
                       // id for vertex i
                       // (consecutive on heavy
                       // edges)
  std::vector<int>
      head;  // head[i] = id of vertex on heavy
             // path of vertex i, nearest to root
  std::vector<int>
      head_ids;  // consist of head vertex id's
  std::vector<int>
      heavy_path_id;  // heavy_path_id[i] =
                      // heavy_path_id for vertex
                      // [i]

  HLD(const std::vector<std::vector<int>> &e,
      vector<int> roots = {0})
      : HLD((int)e.size()) {
    g = e;
    build(roots);
  }
  HLD(int sz = 0)
      : V(sz),
        id(0),
        nb_heavy_path(0),
        g(sz),
        par(sz),
        depth(sz),
        subtree_sz(sz),
        heavy_child(sz),
        tree_id(sz, -1),
        aligned_id(sz),
        aligned_id_inv(sz),
        head(sz),
        heavy_path_id(sz, -1) {}

  void add_edge(int u, int v) {
    edges.emplace_back(u, v);
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  void _build_dfs(int root) {
    std::stack<std::pair<int, int>> st;
    par[root] = -1;
    depth[root] = 0;
    st.emplace(root, 0);
    while (!st.empty()) {
      int now = st.top().first;
      int &i = st.top().second;
      if (i < (int)g[now].size()) {
        int nxt = g[now][i++];
        if (nxt == par[now]) continue;
        par[nxt] = now;
        depth[nxt] = depth[now] + 1;
        st.emplace(nxt, 0);
      } else {
        st.pop();
        int max_sub_sz = 0;
        subtree_sz[now] = 1;
        heavy_child[now] = -1;
        for (auto nxt : g[now]) {
          if (nxt == par[now]) continue;
          subtree_sz[now] += subtree_sz[nxt];
          if (max_sub_sz < subtree_sz[nxt])
            max_sub_sz = subtree_sz[nxt],
            heavy_child[now] = nxt;
        }
      }
    }
  }

  void _build_bfs(int root, int tree_id_now) {
    std::queue<int> q({root});
    while (!q.empty()) {
      int h = q.front();
      q.pop();
      head_ids.emplace_back(h);
      for (int now = h; now != -1;
           now = heavy_child[now]) {
        tree_id[now] = tree_id_now;
        aligned_id[now] = id++;
        aligned_id_inv[aligned_id[now]] = now;
        heavy_path_id[now] = nb_heavy_path;
        head[now] = h;
        for (int nxt : g[now])
          if (nxt != par[now] and
              nxt != heavy_child[now])
            q.push(nxt);
      }
      nb_heavy_path++;
    }
  }

  void build(std::vector<int> roots = {0}) {
    int tree_id_now = 0;
    for (auto r : roots)
      _build_dfs(r), _build_bfs(r, tree_id_now++);
  }

  // data[i] = value of vertex i
  template <class T>
  std::vector<T> segtree_rearrange(
      const std::vector<T> &data) const {
    assert(int(data.size()) == V);
    std::vector<T> ret;
    ret.reserve(V);
    for (int i = 0; i < V; i++)
      ret.emplace_back(data[aligned_id_inv[i]]);
    return ret;
  }
  // data[i] = weight of edge[i]
  template <class T>
  std::vector<T> segtree_rearrange_weighted(
      const std::vector<T> &data) const {
    assert(data.size() == edges.size());
    vector<T> ret(V);
    for (int i = 0; i < (int)edges.size(); i++) {
      auto [u, v] = edges[i];
      if (depth[u] > depth[v]) swap(u, v);
      ret[aligned_id[v]] = data[i];
    }
    return ret;
  }

  int segtree_edge_index(int i) const {
    auto [u, v] = edges[i];
    if (depth[u] > depth[v]) swap(u, v);
    return aligned_id[v];
  }

  // query for vertices on path [u, v] (INCLUSIVE)
  void for_each_vertex(int u, int v,
                       const auto &f) const {
    static_assert(
        std::is_invocable_r_v<void, decltype(f),
                              int, int>);
    assert(tree_id[u] == tree_id[v] and
           tree_id[u] >= 0);
    while (true) {
      if (aligned_id[u] > aligned_id[v])
        std::swap(u, v);
      f(std::max(aligned_id[head[v]],
                 aligned_id[u]),
        aligned_id[v]);
      if (head[u] == head[v]) break;
      v = par[head[v]];
    }
  }

  void for_each_vertex_noncommutative(
      int from, int to, const auto &fup,
      const auto &fdown) const {
    static_assert(
        std::is_invocable_r_v<void, decltype(fup),
                              int, int>);
    static_assert(
        std::is_invocable_r_v<
            void, decltype(fdown), int, int>);
    assert(tree_id[from] == tree_id[to] and
           tree_id[from] >= 0);
    int u = from, v = to;
    const int lca = lowest_common_ancestor(u, v),
              dlca = depth[lca];
    while (u >= 0 and depth[u] > dlca) {
      const int p =
          (depth[head[u]] > dlca ? head[u] : lca);
      fup(aligned_id[p] + (p == lca),
          aligned_id[u]),
          u = par[p];
    }
    static std::vector<std::pair<int, int>> lrs;
    int sz = 0;
    while (v >= 0 and depth[v] >= dlca) {
      const int p =
          (depth[head[v]] >= dlca ? head[v]
                                  : lca);
      if (int(lrs.size()) == sz)
        lrs.emplace_back(0, 0);
      lrs.at(sz++) = {p, v}, v = par.at(p);
    }
    while (sz--)
      fdown(aligned_id[lrs.at(sz).first],
            aligned_id[lrs.at(sz).second]);
  }

  // query for edges on path [u, v]
  void for_each_edge(int u, int v,
                     const auto &f) const {
    static_assert(
        std::is_invocable_r_v<void, decltype(f),
                              int, int>);
    assert(tree_id[u] == tree_id[v] and
           tree_id[u] >= 0);
    while (true) {
      if (aligned_id[u] > aligned_id[v])
        std::swap(u, v);
      if (head[u] != head[v]) {
        f(aligned_id[head[v]], aligned_id[v]);
        v = par[head[v]];
      } else {
        if (u != v)
          f(aligned_id[u] + 1, aligned_id[v]);
        break;
      }
    }
  }

  // lowest_common_ancestor: O(log V)
  int lowest_common_ancestor(int u, int v) const {
    assert(tree_id[u] == tree_id[v] and
           tree_id[u] >= 0);
    while (true) {
      if (aligned_id[u] > aligned_id[v])
        std::swap(u, v);
      if (head[u] == head[v]) return u;
      v = par[head[v]];
    }
  }

  int distance(int u, int v) const {
    assert(tree_id[u] == tree_id[v] and
           tree_id[u] >= 0);
    return depth[u] + depth[v] -
           2 * depth[lowest_common_ancestor(u,
                                            v)];
  }

  // Level ancestor, O(log V)
  // if k-th parent is out of range, return -1
  int kth_parent(int v, int k) const {
    if (k < 0) return -1;
    while (v >= 0) {
      int h = head.at(v),
          len = depth.at(v) - depth.at(h);
      if (k <= len)
        return aligned_id_inv.at(
            aligned_id.at(v) - k);
      k -= len + 1, v = par.at(h);
    }
    return -1;
  }

  // Jump on tree, O(log V)
  int s_to_t_by_k_steps(int s, int t,
                        int k) const {
    if (k < 0) return -1;
    if (k == 0) return s;
    int lca = lowest_common_ancestor(s, t);
    if (k <= depth.at(s) - depth.at(lca))
      return kth_parent(s, k);
    return kth_parent(t,
                      depth.at(s) + depth.at(t) -
                          depth.at(lca) * 2 - k);
  }
};
template <typename T = ll,
          auto cmp =
              [](T &src1, T &src2, T &dst) {
                dst = min(src1, src2);
              }>
class SparseTable {
 private:
  int sz;
  vi logs;
  vector<vector<T>> st;

 public:
  SparseTable(const vector<T> &v)
      : sz(len(v)), logs(sz + 1) {
    rep(i, 2, sz + 1) logs[i] = logs[i >> 1] + 1;
    st.resize(logs[sz] + 1, vector<T>(sz));
    rep(i, 0, sz) st[0][i] = v[i];
    for (int k = 1; (1 << k) <= sz; k++) {
      for (int i = 0; i + (1 << k) <= sz; i++) {
        cmp(st[k - 1][i],
            st[k - 1][i + (1 << (k - 1))],
            st[k][i]);
      }
    }
  }
  T query(int l, int r) {
    r++;
    const int k = logs[r - l];
    T ret;
    cmp(st[k][l], st[k][r - (1 << k)], ret);
    return ret;
  }
};

void run() {
  int N,M,S;cin>>N>>M>>S;
  vector<tuple<ll,int,int>> edges(M);
  for(auto&[w,u,v]:edges){
    cin>>u>>v>>w;
    u--,v--;
  }
  auto edges2=kruskal(N,edges);
  HLD hld(N);
  vll ws;
  for(auto&[w,u,v]:edges2){
    hld.add_edge(u,v);
    ws.eb(w);
  }
  dbg(edges2);
  hld.build();
  auto vetorzinho=hld.segtree_rearrange_weighted(ws);
  SparseTable st(vetorzinho);
  rep(s,0,S){
    int u,v;cin>>u>>v;
    u--,v--;
    ll ans=LLONG_MAX;
    auto f=[&](int l, int r){
      chmin(ans,st.query(l,r)); 
    };
    dbg(u,v);
    hld.for_each_edge(u,v,f);
    cout<<ans<<endl;
  }
}

/*8<
  AC, heavy light decomposition
>8*/
