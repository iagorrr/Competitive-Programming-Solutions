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

template <typename T>
std::istream &operator>>(std::istream &is, std::vector<T> &vec) {
        for (auto &element : vec) {
                is >> element;
        }
        return is;
}

template <typename T>        // print vector
ostream &operator<<(ostream &os, vector<T> &xs) {
        rep(i, os.iword(0), xs.size()) os << xs[i]
                                          << (i == xs.size() ? "" : " ");
        os.iword(0) = 0;
        return os;
}

template <typename T>
T sumList(vector<T> &xs) {
        return accumulate(all(xs), T());
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
walk eh so pocar tudo sem do
a maior distancia entre dois nós eh no pior caso N

suponha um grafo circular onde o tamanho e N claro

1 -> 2 -> 3 -> 1

e que nesse multiset tenha um valor k que é coprimo
com n então da pra gente visitaar todos os nós...

desde que tenha valores suficientes neh, se tiver só um sambamos

suponha que tenha uma sequencai s que é  quais elementos do multiset
a gent usou pra chegar em um nó v não importa qual permutação dessa
sequencia a gente faça continua dando pra chegar em v, é só fazer o memso
caminho

ent o que importa é o tanho do caminho
e se a gente consegue montar uma soma com o tamanho desse caminho

os valores vao até 10^4

da pra gente ver todas as somas possíveis que a gente
consegue fazer com esse multiset né. ?

nao precisa ficar pensando em andar os ciclos e os krl

simplifica neh

ao invés de ficar andando pra frente,

acho que so precisa olhar pra paridade...

tamo testando se da pra chegar em u, se a gente
chegar em um vizinho de v, basta pegar qualquer valor impar
e ficar repetindo v pra u, u pra v, até acabar esse valor
do multiset e como é impar vai acabar em u

pra responder pra um nó u, só preciso olhar pra todos
os vizinhos dele se da pra chegar neles e consumir
impar vezes.

so precisa ver o shortest path impar pra um nó
e o shortest path par tbm.

seja d(u, 0) a menor distância par pra chegar em u,
seja S(0) todos os valores pares fazíveis a partir de A,
se existe um X pertencente a S(0) tal que X é maior que d(u,0)
eh vapo, gente chega em U, e fica indo e voltando em alguma aresta
par vezes.

seja d(u, 1) a menor distância impar pra chegar em u
seja S(1) todos os valores impares fazíveis a aprtir de A
se existe um X pertencente a S(1) tal que X é maior que d(v, 1)
pra algum
esse caso é a mesma coisa do de cima n é n ?

tah, se tiver um u que d(u) = 3 ? e so tem ela po.

se a gente chegar em u, com uma distância impar
a gente precisa fazer uma quantidade par de movimentos dps.
impar + par = impar, entao basta ter um um valor X em S(1)
que seja maior ou igual d(u, 1), oka, tudo certo

com a gente tá sempre interssado somente em ver se
tem um valor X maior que alguam coisa em S(0) ou S(1)
bora só ver o maior valor possível dos dois sets...

pro par é soh somar todos os valores pares,
e uma quantidade par dos maiores impares

pros impares, se não tiver nenhum valor impar é 0,
caso contrário é a soma de todos os pares junto
dos maiores valores impares (em quantidade impar)

e pegar a menor distância impar e distancia par
da com uma bfs né ?

se não dé lanço um dijksra e fodase

precisou do dijkstra

WA, acho que esse getD é zuado
*/

void __init() {}

void __pre_run() {}

array<ll, 2> getss(vll &as) {
        vll2d pps(2);
        for (auto ai : as) {
                pps[ai & 1].eb(ai);
        }

        auto &odd = pps[1];
        auto &even = pps[0];

        sort(all(even)), sort(all(odd));

        dbg(even, odd);
        ll s0 = sumList(even) + sumList(odd);
        if (len(odd) & 1) s0 -= odd.front();

        ll s1 = sumList(odd) + sumList(even);
        if (!len(odd)) s1 = 0;
        if (!(len(odd) & 1) and len(odd)) s1 -= odd.front();

        return {s0, s1};
}

const ll oo = 1e10;

vll2d getD(vll2d &g) {
        int n = len(g);

        vll2d d(2, vll(n, oo));

        using st = tuple<ll, ll, ll>;
        pqmn<st> pq;
        pq.emp(0, 0, 0);

        d[0][0] = 0;

        while (len(pq)) {
                auto [du, u, p] = pq.top();
                pq.pop();

                if (du > d[p][u]) continue;

                trav(v, g[u]) {
                        if (d[!p][v] > du + 1) {
                                d[!p][v] = du + 1;
                                pq.emp(d[!p][v], v, !p);
                        }
                }
        }

        return d;
}

void __run() {
        ll n, m, l;
        cin >> n >> m >> l;

        vll as(l);
        cin >> as;
        dbg(as);

        vll2d gs(n);
        rep(i, 0, m) {
                ll u, v;
                cin >> u >> v;
                u--, v--;
                gs[u].eb(v), gs[v].eb(u);
        }

        auto s = getss(as);

        auto d = getD(gs);

        rep(u, 0, n) {
                bool ans = d[1][u] <= s[1] or d[0][u] <= s[0];
                cout << (ll)ans;
        }
        cout << endl;
}

/*8<
 * AC, graphs, greedy, shortest paths, dfs and similar
>8*/
