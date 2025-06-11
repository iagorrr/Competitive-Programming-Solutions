/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>

#include <numeric>
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

// read vector
// TODO: abstract this to any container.
template <typename T>
std::istream &operator>>(std::istream &is, std::vector<T> &vec) {
        for (auto &element : vec) {
                is >> element;
        }
        return is;
}

// print vector
// TODO: abstract this to any container.
template <typename T>
ostream &operator<<(ostream &os, vector<T> &xs) {
        rep(i, os.iword(0), xs.size()) os << xs[i]
                                          << (i == xs.size() ? "" : " ");
        os.iword(0) = 0;
        return os;
}

// sum a vector, using the default constructor as initial value
// TODO: abstract this to any container.
template <typename T>
T sumList(vector<T> &xs) {
        return accumulate(all(xs), T());
}

/*
 * verify if a `predicate` is valid for
 * values in range [l, r]
 *
 * TODO: put a type in predicate ??
 * */
template <typename T>
bool all_of_in_range(T l, T r, auto predicate) {
        return ranges::all_of(views::iota(l, r + 1),
                              [&](T v) { return predicate(v); });
}

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

        cin >> T;

        rep(t, 0, T) {
                dbg(t);
                __pre_run();
                __run();
        }
}

/*
 * quantidade de jeitos de dar assign de valores
 * numa ávore dada tal que a soma os valores
 * das somas das subárvores são todos distintos
 *
 * cada nó é ou 1 ou 2...
 *
 * soma máxima é 2 N
 *
 * seja sz(u) a quantidade de nós na subárvore de u
 *
 * uma subárvore com sz(u) assume uma soma entre sz(u), e sz(u) * 2...
 * e ai a gente precisa so saber de quantas maneiras a gente vai distribuir os
 * 2's.
 *
 * quantas somas distintas a gente pra subárvores de tamanho:
 *      0. 1
 *      1. 2
 *      2. 4
 *      3. 6
 *      ....
 *      x. 2x
 *
 * então se tenho mais ávores de tamanho t do que jeitos de fazer
 * somas de t, é impossível fazer um assign válido.
 *
 * é sempre duas folhas no máximo, então é ou um bambu, ou um negócio com no
 * máximo uma bifurcação
 *
 * ávore bambu é trivial de resolve é só 2^k onde k é o tamanho do bambu
 *
 * então agente tá sempre resolvendo um bambu + uma paradinha bifurcada
 *
 * se uma paradinha bifurcada tecnicamente é um bambu dividido em 2 né
 *
 * onde a soma das bordas de tamanho ingual nao pode ser ingual
 *
 * até um tamanho do menor deles....<D-g>
 *
 * entendi o problema errado :([
 *
 *
 * e de boassa então.
 * */

const ll maxn = 2'00'000 + 2;
const ll mod = 1'000'000'007;
ll p2[maxn + 1];

void __init() {
        p2[0] = 1;
        rep(i, 1, maxn + 1) { p2[i] = (p2[i - 1] * 2ll) % mod; }
}

void __pre_run() {}

ll solve(vi2d adj) {
        int lca = -1;
        vi leafs;

        vi ds(len(adj), 1);
        auto dfs = [&](auto _dfs, int u, int p) -> void {
                if (len(adj[u]) == 1 and u) leafs.pb(u);
                if (len(adj[u]) > 2 and u) lca = u;

                for (auto v : adj[u])
                        if (v != p) {
                                ds[v] = ds[u] + 1;
                                _dfs(_dfs, v, u);
                        }
        };
        dfs(dfs, 0, -1);

        ll ret = 0;
        if (len(leafs) > 2) return ret;

        if (len(leafs) == 2 and lca == -1) lca = 0;

        dbg(len(leafs), lca);

        if (len(leafs) == 2) {
                int d0 = ds[leafs[0]];
                int d1 = ds[leafs[1]];
                if (d1 < d0) swap(d1, d0);

                ll bi = 0;
                if (d1 == d0)
                        bi = 2;
                else {
                        ll c1 = p2[d1 - d0];
                        ll c0 = p2[d1 - d0 - 1];
                        bi = (c1 + c0) % mod;
                }

                ll c = p2[ds[lca]];
                ret = (c * bi) % mod;
        } else
                ret = p2[len(adj)];

        return ret;
}

void __run() {
        int n;
        cin >> n;

        vi2d adj(n);
        rep(i, 0, n - 1) {
                int u, v;
                cin >> u >> v;
                u--, v--;
                adj[u].eb(v);
                adj[v].eb(u);
        }

        cout << solve(adj) << endl;
}

/*8<
 * ac, combinatorics, tree
>8*/
