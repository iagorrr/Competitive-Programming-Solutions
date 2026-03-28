/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define fastio                                                                 \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#define all(j) j.begin(), j.end()
#define rall(j) j.rbegin(), j.rend()
#define len(j) (int)j.size()
#define rep(i, a, b)                                                           \
  for (common_type_t<decltype(a), decltype(b)> i = (a); i < (b); i++)
#define rrep(i, a, b)                                                          \
  for (common_type_t<decltype(a), decltype(b)> i = (a); i > (b); i--)
#define repn(i, b) for (auto i = 0; i < (b); i++)
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) for (auto &xi : ranges::views::reverse(xs))
#define loop while (1)
using ll = long long;
#define endl '\n'
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define ef emplace_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define emp emplace
#define ins insert
#define divc(a, b) ((a) + (b) - 1ll) / (b)
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

#define TT template <typename T>
#define TTU template <typename T, typename U>

TTU using umap = unordered_map<T, U>;
TT using pqmn = priority_queue<T, vector<T>, greater<T>>;
TT using pqmx = priority_queue<T, vector<T>>;

TTU inline bool chmax(T &a, U const &b) { return (a < b ? a = b, 1 : 0); }
TTU inline bool chmin(T &a, U const &b) { return (a > b ? a = b, 1 : 0); }

// read vector
// TODO: abstract this to any container.
TT std::istream &operator>>(std::istream &is, std::vector<T> &vec) {
  for (auto &element : vec) {
    is >> element;
  }
  return is;
}

// print vector
// TODO: abstract this to any container.
TT ostream &operator<<(ostream &os, vector<T> &xs) {
  rep(i, os.iword(0), xs.size()) os << xs[i] << (i == xs.size() ? "" : " ");
  os.iword(0) = 0;
  return os;
}

// print multiset
// TODO: abstract this to any container.
TT ostream &operator<<(ostream &os, multiset<T> &xs) {
  for (auto it = xs.begin(); it != xs.end(); it++)
    os << *it << (next(it) == end(xs) ? "" : " ");
  return os;
}

// sum a vector, using the default constructor as initial value
// TODO: abstract this to any container.
TT T sumList(vector<T> &xs) { return accumulate(all(xs), T()); }

/*
 * verify if a `predicate` is valid for
 * values in range [l, r]
 *
 * TODO: put a type in predicate ??
 * */
// bool all_of_in_range(T l, T r, auto predicate) {
//     return ranges::all_of(views::iota(l, r + 1),
//                           [&](T v) { return predicate(v); });
// }

// checks if a  value v is the interval [l, r]
TT bool inline between(T v, T l, T r) { return clamp(v, l, r) == v; }

/*8<============~ END TEMPLATE ~============}>8*/
void __init();
void __run();
void __pre_run();

int32_t main() {
#ifndef LOCAL
  fastio;
#endif
  __init();

  int T = 1;

  rep(t, 0, T) {
    dbg(t);
    __pre_run();
    __run();
  }
}

/*
 *
 *
 *
 *
 *
 * */

void __init() {}

void __pre_run() {}
struct FunctionalGraph {
  int cur_id;
  vector<int> par;
  vector<int> pos, pos_inv;
  vector<int> depth;
  vector<int> head;

  FunctionalGraph(int n)
      : cur_id(0), par(n), pos(n, -1), pos_inv(n, -1), depth(n), head(n) {}

  FunctionalGraph(const vector<int> &p) : FunctionalGraph((int)p.size()) {
    copy(p.begin(), p.end(), par.begin());
    build();
  }

  // Assumes `u` is in a cycle, O(1)
  int cycle_size(int u) const {
    assert(depth[u] == 0);
    return pos[cycle_end(u)] - pos[cycle_begin(u)] + 1;
  }
  // Assumes `u` is in a cycle, O(1)
  int cycle_begin(int u) const {
    assert(depth[u] == 0);
    return par[head[u]];
  }
  // Assumes `u` is in a cycle, O(1)
  int cycle_end(int u) const {
    assert(depth[u] == 0);
    return head[u];
  }
  // Assumes `u` is in a cycle, O(1)
  int cycle_relative_pos(int u) const {
    assert(depth[u] == 0);
    return pos[u] - pos[cycle_begin(u)];
  }

  // k-th ancestor, O(log V)
  int kth_parent(int u, ll k) const {
    while (depth[u]) {
      int h = head[u], len = depth[u] - depth[h];
      if (len >= k)
        return pos_inv[pos[u] - k];
      k -= len + 1, u = par[h];
    }

    int start = cycle_begin(u);
    int relative_pos = cycle_relative_pos(u);
    return pos_inv[pos[start] + (relative_pos + k) % cycle_size(u)];
  }

  // Distance to root, O(log V)
  // {root vertex, number of moves}
  pair<int, int> dist_to_root(int u) const {
    int dist = 0;
    while (depth[u]) {
      int h = head[u], len = depth[u] - depth[h];
      dist += len + 1, u = par[h];
    }
    return {u, dist};
  }

  // Distance until repeat, O(log V)
  // {root vertex, number of moves}
  pair<int, int> dist_to_repeat(int u) const {
    auto [root, dist] = dist_to_root(u);
    return {root, dist + cycle_size(root)};
  }

  // Distance to reach `v` from `u`, O(log V)
  int reach(int u, int v) const {
    if (depth[u] < depth[v])
      return -1;
    int dist = depth[u] - depth[v];
    u = kth_parent(u, dist);

    if (u == v)
      return dist;

    if (depth[u] or head[u] != head[v])
      return -1;

    // only go forward
    if (pos[u] <= pos[v])
      return dist + pos[v] - pos[u];

    // do cycle
    return dist + cycle_relative_pos(v) + pos[cycle_end(u)] - pos[u] + 1;
  }

  // data[i] = value of vertex i
  template <class T> vector<T> segtree_rearrange(const vector<T> &data) const {
    assert(data.size() == size(par));
    vector<T> ret;
    ret.reserve(size(par));
    for (int i = 0; i < (int)size(par); i++)
      ret.emplace_back(data[pos_inv[i]]);
    return ret;
  }

  // Query for vertices on path [u, v] (INCLUSIVE)
  // If u and v are not LCA of each other, returns immediately
  bool for_each_vertex(int u, int v, const auto &f) const {
    static_assert(std::is_invocable_r_v<void, decltype(f), int, int>);

    auto path = vertex_path(u, v);
    if (path.empty())
      return false;
    for (auto [l, r] : path)
      f(l, r);
    return true;
  }

  // Reach first vertex in cycle, O(log V)
  // Returns the first vertex in cycle
  int for_each_vertex_to_root(int u, const auto &f) const {
    static_assert(std::is_invocable_r_v<void, decltype(f), int, int>);

    int last = u;
    while (depth[u]) {
      int v = head[u];
      if (pos[u] > pos[v])
        swap(u, v);
      f(pos[u], pos[v]);
      u = par[head[u]];
      last = u;
    }

    return last;
  }

  // Reach first repeating vertex, O(log V)
  // Returns the first repeating vertex
  int for_each_vertex_to_repeat(int u, const auto &f) const {
    static_assert(std::is_invocable_r_v<void, decltype(f), int, int>);

    int last = for_each_vertex_to_root(u, f);
    if (last != cycle_end(last))
      f(pos[par[last]], pos[cycle_end(last)]);
    f(pos[cycle_begin(last)], pos[last]);
    return last;
  }

  // Path ranges from `u` to `v` [INCLUSIVE], O(log V)
  vector<pair<int, int>> vertex_path(int u, int v) const {
    vector<pair<int, int>> path;
    if (depth[u] < depth[v])
      return {};

    int k = depth[u] - depth[v];
    while (depth[u]) {
      int h = head[u], len = depth[u] - depth[h];
      if (len >= k) {
        path.emplace_back(pos[pos_inv[pos[u] - k]], pos[u]);
        u = pos_inv[pos[u] - k];
        break;
      }
      path.emplace_back(pos[h], pos[u]);
      k -= len + 1, u = par[h];
    }

    if (u == v) {
      if (!depth[u])
        path.emplace_back(pos[v], pos[v]);
      return path;
    }

    if (depth[u] or head[u] != head[v])
      return {};

    if (pos[u] <= pos[v]) {
      path.emplace_back(pos[u], pos[v]);
      return path;
    }

    path.emplace_back(pos[u], pos[cycle_end(u)]);
    path.emplace_back(pos[cycle_begin(u)], pos[v]);
    return path;
  }

private:
  void build() {
    vector<vector<int>> g(par.size());
    for (int i = 0; i < (int)par.size(); i++)
      g[par[i]].push_back(i);

    vector<int> subtree_sz(par.size()), heavy_child(par.size());
    stack<pair<int, int>> dfs_st;
    queue<int> bfs_q;
    auto dfs_build = [&]() {
      while (not dfs_st.empty()) {
        auto &[u, c] = dfs_st.top();
        if (c < (int)g[u].size()) {
          int nxt = g[u][c++];
          if (nxt == par[u] or pos[nxt] != -1)
            continue;
          depth[nxt] = depth[u] + 1;
          dfs_st.emplace(nxt, 0);
        } else {
          dfs_st.pop();
          int max_subtree_sz = 0;
          subtree_sz[u] = 1;
          heavy_child[u] = -1;
          for (auto nxt : g[u])
            if (nxt != par[u] and pos[nxt] == -1) {
              subtree_sz[u] += subtree_sz[nxt];
              if (subtree_sz[nxt] > max_subtree_sz)
                max_subtree_sz = subtree_sz[nxt], heavy_child[u] = nxt;
            }
        }
      }
    };
    auto bfs_build = [&]() {
      while (not bfs_q.empty()) {
        auto h = bfs_q.front();
        bfs_q.pop();
        if (pos[h] != -1) {
          for (auto nxt : g[h])
            if (pos[nxt] == -1) {
              bfs_q.push(nxt);
            }
          continue;
        }

        for (int u = h; u != -1; u = heavy_child[u]) {
          pos[u] = cur_id++;
          pos_inv[pos[u]] = u;
          head[u] = h;
          for (auto nxt : g[u])
            if (par[u] != nxt and nxt != heavy_child[u] and pos[nxt] == -1)
              bfs_q.push(nxt);
        }
      }
    };

    for (int i = 0; i < (int)par.size(); i++)
      if (pos[i] == -1) {
        auto cycle = _cycle_start(i);
        int c = cycle;
        do {
          c = par[c];
          pos[c] = cur_id++;
          pos_inv[pos[c]] = c;
          head[c] = cycle;
          dfs_st.emplace(c, 0);
          bfs_q.push(c);
        } while (c != cycle);

        dfs_build();
        bfs_build();
      }
  }

  int _cycle_start(int i) {
    int tortoise = i, hare = i;
    do {
      tortoise = par[tortoise];
      hare = par[par[hare]];
    } while (tortoise != hare);
    tortoise = i;
    while (tortoise != hare) {
      tortoise = par[tortoise];
      hare = par[hare];
    }

    return hare;
  }
};
void __run() {
  int n;
  cin >> n;

  vll as(n);
  cin >> as;

  trav(ai, as) ai--;

  vi dgin(n);
  repn(i, n) { dgin[as[(i)]]++; }

  vi vis(n, -1);

  int id = 0;
  auto dfs = [&](auto &&self, int i) -> void {
    vis[i] = id;
    i = as[i];
    if (vis[i] == -1)
      self(self, i);
  };

  repn(i, n) {
    if (dgin[i] == 0 and vis[i] == -1) {
      dfs(dfs, i);
      id++;
    }
  }

  repn(i, n) {
    if (vis[i] == -1) {
      dfs(dfs, i);
      id++;
    }
  }

  dbg(vis);

  assert(*max_element(all(vis)) > -1);

  vi2d byId(n);
  repn(i, n) { byId[vis[i]].eb(i); }
  dbg(byId);

  // tem que saber computar issoa qui mais faácil
  vi aux(all(as));
  FunctionalGraph fc(aux);
  vll cycleSize(n, -1), cycleTail(n, -1);
  repn(i, n) {
    int x = vis[i];
    int root = fc.dist_to_root(i).first;
    chmax(cycleTail[x], fc.dist_to_root(i).second);
    cycleSize[x] = fc.cycle_size(root);
  }

  // não sei codar !
  // vll tss(n, -1);
  // int ts = 0;
  // repn(i, n) {
  //   if (!len(byId[i]))
  //     continue;
  //
  //   int u = byId[i].front();
  //   ll sz = 0;
  //   while (1) {
  //     tss[u] = ts++;
  //
  //     int v = as[u];
  //     if (tss[v] != -1) {
  //       sz = tss[u] - tss[v] + 1;
  //       break;
  //     }
  //   }
  //
  //   cycleSize[i] = sz;
  //
  //   // ta errado isso aqui, tem que ser o "largest tail"
  //   // cycleTail[i] = len(byId[i]) - sz;
  // }

  // tem que ser um multiplo de todos os cyclesize !
  // e tem que ser maior que todos os cycletail !
  // tira o lcm e talvez aumenta um cadin !
  ll ans = 1;
  trav(ci, cycleSize) {
    if (ci != -1)
      ans = lcm(ans, ci);
  }

  // falta garaintir que é mairo que a galera la
  // otimiza isso aqiu dps
  ll l = ans;
  trav(ti, cycleTail) {
    if (ti != -1) {
      if (ti > ans) {
        ans = ((ti + l - 1) / l) * l;
      }
    }
  }

  cout << ans << endl;
}

/*8<
 * pra um subgrafo que tem um ciclo e uma cauda (grafo funcional)
 * o tamanho do ciclo sendo SZ e o tamanho da cauda sendo C, todos
 * os multiplos de SZ maiores ou iguais a C resolvem
 *
 *
 * agora quando se tem vários grafos desses não é só o LCM ?
 *
 * supondo que esteja certo tem que codar ainda né
>8*/
