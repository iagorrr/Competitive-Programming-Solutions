
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define endl '\n'

#define fastio                                                                 \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);

#define int long long

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define rep(i, a, b)                                                           \
  for (common_type_t<decltype(a), decltype(b)> i = a; i != b;                  \
       (a < b) ? ++i : --i)
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
auto run() {
        int N;
        cin >> N;

        vi2d ADJ(N);
        rep(i, 1, N) {
                int u, v;
                cin >> u >> v;
                u--, v--;
                ADJ[u].eb(v);
                ADJ[v].eb(u);
        }

        vi2d vis(N, vi(2, -1));
        auto dfs = [&](auto&& self, int u, bool m, int p) -> int {
                if (~vis[u][m])
                        return vis[u][m];

                vi sons(sz(ADJ[u]));
                int tot = 0;

                rep(i, 0, sz(ADJ[u])) {
                        auto v = ADJ[u][i];
                        if (v != p) {
                                tot += sons[i] = self(self, v, 0, u);
                        }
                }

                int best = tot;

                if (!m) {
                        rep(i, 0, sz(ADJ[u])) {
                                auto v = ADJ[u][i];
                                if (v != p)
                                        best = max(best, 1 + tot - sons[i] + self(self, v, 1, u));
                        }
                }

                return vis[u][m] = best;
        };

        cout << dfs(dfs, 0, 0, -1) << '\n';
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
        AC, trees, dynamic programming
 */

