/*
- Joguinho em grafo com update e múltiplos starts
- é um DAG amem
- Se não tivesse o update dos nós ajudaria a gente em algo ?
- player 1 -> ganha quando chega em red
- player 2 -> ganha quando chega em sync
- Se não tivesse o update o player 2 sempre ganha pq sempre chega em sink
- Pra todo nó U eu sei os sync que ele pode potencialmente chegar
- Para todo nó U eu guardar todos os syncs que ele consegue chegar é torado ?
- Na verdade não é só o sink né, é se ele é obrigado a passar por um nó red
eventualmente
- Pra todo nó eu preciso saber quais são os nós que ele é obrigado a passar
- E daí se tiver algum nó que é red é vitória do player 1, cc player 2
- Tá quadrático isso aí, melhor dos casos /64 com bitset que é too much ainda
- Qual a complexidade de propagar esse update ?
- ignorando a complexidade como que eu sei que um nó U é nó que todo mundo passa
por ele ? ponto de articulação
- são só esses nós que importa uai
- pro player 2 é só evitar esses nós red aí
- se ele conseguir evitar é win, se não é player 1
- daria pra responder offline ? meio que considerar o tempo de cada
query no dag, e aí um query de consulta só é impactada por um nó red que foi
marcado antes da consulta...
- cada query "entra" e "sai" no máximo uma vez nessa dfs aí, daí seria safe
atuzlizar...
- como seria se eu fosse pagar O(N) toda vez ?
- dp(i, p) -> to no nó i, e é a vez do player p

dp i p -> se o player p consegue ganhar

dp i p
    if is red:
        return p == 1

    if is sink:
        return p == 2

    for j in adj[i]:
        if not dp j !p return true

    false

se nessa dp / dfs, eu respondesse todas as queries de uma vez...

guardo todas as queries de consulta em um set ordenado pelo timestamp

quando eu entro em um novo nó ele vai ter uma query de update nele
ordenadas, dai essa query de update vai ter efeito somente nas de consulta que
rolaram dps, aí já respondo algumas dessas query se for o caos se não só propaga

tem que processar no toposrot do grafo
cada nó tem que guaradr o set de consultas dele tbm

dps so printar tudo...

coda essa bomba logo

como que eu replico os nós de query de um nó para todos os vizinhos ???
fudeu-se

tomar um mle ali e tentar resovler...

acho que da pra resolver com algo que funcione com um dsu mas com remoção
pq daí da pra eu saber todos os nós de um mano simplesmente olhando para os
componentes dele na vdd n né


isso eu só responde pra aquela consulta chegando naquele nó
como que faz pra checar todas as opções em O(bom).




algo bottom up ?


toda query tem um set de nós que ela alcança
eu deixo ela em todos os sink dela e propago par cima se for ocaso


O(N^tudo) se for tipo um chubeiro

- se eu processase na ordem de dependencias do grafo
e toda vez que eu to em um nó eu saber dizer quais queries que não
foram respondidas que afetam ele
- tem a chance de todo nó ter que reponder toda query ainda.
- se eu guardasse pra cada nó na verdade o maior tempo que ele ganha
ou coisa assim

aí era safe é ?
tenho poucos chutes a serem feitos em teoria


só preciso saber para cada nó i o maior tempo que ele ganha
dai quando eu faço a consulta se for maior que aquele tempo é loss

vapo ?


dp(i, p) -> ate que tempo o player p ganha se começar no nó i
- não tem que inverter o menor/maior n ?
- pro player 1 quanto mais pra frente melhor
- pro player 2 quanto menor o ts melhor


dp(u, 1) -> Qual o menor tempo necessário para que um jogo
começando em u, e sendo a vez do player 1 ele ganha, se ele ganha e m X vai
ganhar em x+1 x+2, .... por isso guarda o menor


dp(u, 2) -> qual o maior tempo que um jogando começando em u e sendo
a vez do player 2 ele ganha, por que se ele perde em T1, vai perder em todo T2
tal que T2 >= T1

só codar ??

as transicoes estão estranhas

se não for essa dp acho que é algo proessando os nós por ordem das queries, dos
updates mais antigos para os maios novos ??
*/
/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>

#include "stdint.h"
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define all(j) j.begin(), j.end()
#define rall(j) j.rbegin(), j.rend()
#define len(j) (int)j.size()
#define rep(i, a, b) \
    for (common_type_t<decltype(a), decltype(b)> i = (a); i < (b); i++)
#define rrep(i, a, b) \
    for (common_type_t<decltype(a), decltype(b)> i = (a); i > (b); i--)
#define repn(i, b) for (auto i = 0; i < (b); i++)
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) for (auto &xi : ranges::views::reverse(xs))
#define loop for (;;)
#define iter(x) repn(__, x)
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
using vpll = vector<pll>;
using vc = vector<char>;
using vs = vector<str>;

#define TT template <typename T>
#define TTU template <typename T, typename U>

TTU using umap = unordered_map<T, U>;
TT using uset = unordered_set<T>;
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

// print pair
TTU ostream &operator<<(ostream &os, pair<T, U> &p) {
    os << p.first << " " << p.second;
    return os;
}

// read pair
TTU std::istream &operator>>(std::istream &is, pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
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

    cin >> T;

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

const int oo = INT_MAX >> 2;
int dp(int curNode, int player, vi2d &mem, const vi &updTs, const vi2d &adj) {
    auto &ret = mem[curNode][player];
    if (ret != -1) return ret;

    if (player == 0) {
        if (len(adj[curNode]) == 0) {
            return ret = updTs[curNode];
        }

        ret = updTs[curNode];

        trav(nxtNode, adj[curNode]) {
            chmin(ret, dp(nxtNode, 1, mem, updTs, adj));
        }
    } else if (player == 1) {
        if (len(adj[curNode]) == 0) {
            if (updTs[curNode] == oo)
                return ret = oo;
            else
                return ret = updTs[curNode] - 1;
        }

        ret = 0;

        auto upperBound = updTs[curNode] - 1;

        trav(nxtNode, adj[curNode]) {
            chmax(ret, min(upperBound, dp(nxtNode, 0, mem, updTs, adj)));
        }
    }

    return ret;
}

int token = 0;
void __run() {
    int n, m, q;
    cin >> n >> m >> q;

    vi2d adj(n);

    iter(m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
    }

    vi updTs(n, oo);

    vpii cons;
    repn(ts, q) {
        int t, u;
        cin >> t >> u;
        u--;

        if (t == 1) {
            updTs[u] = ts + 1;
        } else {
            cons.eb(ts + 1, u);
        }
    }

    dbg(updTs);
    vi2d mem(n, vi(2, -1));
    for (auto &[ti, ui] : cons) {
        auto mx = dp(ui, 1, mem, updTs, adj);
        dbg(mx, ti);

        if (mx >= ti) {
            cout << "YES" << endl;
        } else
            cout << "NO" << endl;
        token++;
        dbg(token);
        if (token == 71) {
            dbg(adj);
            dbg(updTs);
            dbg(ti, ui);
        }
    }
}

/*8<
>8*/
