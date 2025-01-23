/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define fastio                        \
        ios_base::sync_with_stdio(0); \
        cin.tie(0);
#define all(j) j.begin(), j.end()
#define rall(j) j.rbegin(), j.rend()
#define len(j) (int)j.size()
#define rep(i, a, b) \
        for (common_type_t<decltype(a), decltype(b)> i = (a); i < (b); i++)
#define rrep(i, a, b) \
        for (common_type_t<decltype(a), decltype(b)> i = (a); i > (b); i--)
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) for (auto &xi : ranges::views::reverse(xs))
using ll = long long;
#define endl '\n'
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
template <typename T, typename T2>
using umap = unordered_map<T, T2>;
template <typename T>
using pqmn = priority_queue<T, vector<T>, greater<T>>;
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

        cin >> T;

        rep(t, 0, T) {
                dbg(t);
                run();
        }
}

using namespace std;
using ll = long long;
using Node = long long;
inline Node combine(const Node &nl, const Node &nr) { return max(nl, nr); }

struct SegTree {
        int n;
        vector<Node> st;
        SegTree(int _n) : n(_n), st(n << 1) {}

        void assign(int p, const Node &k) {
                for (st[p += n] = k; p >>= 1;)
                        st[p] = combine(st[p << 1], st[p << 1 | 1]);
        }

        Node query(int l, int r) {
                Node ansl = Node(), ansr = Node();
                for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
                        if (l & 1) ansl = combine(ansl, st[l++]);
                        if (r & 1) ansr = combine(st[--r], ansr);
                }
                return combine(ansl, ansr);
        }
};

void run() {
        int N;
        cin >> N;

        vi dg(N);
        vi2d ADJ(N);
        rep(i, 0, N - 1) {
                int u, v;
                cin >> u >> v;

                u--, v--;

                dg[u]++, dg[v]++;
                ADJ[u].eb(v), ADJ[v].eb(u);
        }

        SegTree seg(N);
        rep(i, 0, N) { seg.assign(i, dg[i]); }

        int ans = 0;
        rep(i, 0, N) {
                int cur = 1 + dg[i] - 1;

                seg.assign(i, 0);

                for (auto v : ADJ[i]) {
                        seg.assign(v, seg.query(v, v) - 1);
                }

                cur += seg.query(0, N - 1) - 1;

                dbg(i, cur);

                chmax(ans, cur);

                seg.assign(i, len(ADJ[i]));

                for (auto v : ADJ[i]) {
                        seg.assign(v, seg.query(v, v) + 1);
                }
        }

        cout << ans << endl;
}

/*8<
 * posso iterar pra decidir qual vai ser a primeira iteração
 *
 * dai pra cada subárvore eu guardo qual é o nó com maior número
 * de adjascências, e o segundo maior pq se o maior for um dos
 * que removi teria que dar um -- e tal...
 *
 * dai fica quantidade de componentes dps de remover essa primeira
 *
 * mais a quantidade de componentes depois de remover
 *
 * não da pra fazer uma seg de max
 *
 * dai atualiza o nó que to brutando e as adj dele
 *
 * dps faz uma query e ve qual o que tem mais aresta depois disso ??
 *
 *
 * bazuca mais parece bom
 *
 * caso de borda ?
 *
>8*/

