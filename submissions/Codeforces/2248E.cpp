/*
...
- Eu posso resetar a qualquer momento, ele sempre da ++
menos quando chega no N o invés de ir pro n+1 ele volta para o 1 direto
- para mim só faz sentido incrementar se eu for chegar no próximo valor
então c1 -> x, onde x é o próximo valor que me acresce em algo, ou c1 -> 0
por que resetei e é isso
- e novamente se vou resetar é por que quero chegar no primeiro valor disponível
então não tem por que ficar nessa de ir para o zero antes


então apara um par (i, j) = (c1, c2), eu sei que c1 assume o próximo valor
disponível que incrementa ou o primeiro, com isso para um par (c1, c2), eu tenho
duas transições (t1(c1), t1(c1, c2)), e (t2(c1), t2(c1, c2)), transição tá em
O(1) nem precisa mas da pra pré computar essas transições.


eu só quero que em algum momento essa DP dê maior que zero

mas como caralhas isso vai chegar em uma DP

se eu quiser definir quantos movimentos vou fazer eu sei a hora de parar mas
minha DP cresce too much


(i, j, k), on de é a quantidade de movimentos que faltam fazer, deve ter algum
trick para resolver isso sem precisar do K


acho que tem um sweet spot que eu consiga ganhar,
> não  nada a ver


Eu meio que não preciso saber os movimentos lá do colega
> dá pra saber o F(I(A)) em O(bom), vai sempre loopar pelos valores que dão
score + o tamanho de a vezes d
mas o meu em específico é chatinho de saber quando que fica


como é a cara de uma resposta que eu ganho ??


seu eu fizer tudo igual a 1 é a mesma coisa portanto não vai ser maior
tem que compensar resetar e pegar algum prefixo

estratégia 1: 1111 ... 0 ... 111
    > fazer um único reset e terminar em uma posição favorável
então vai ser tudo de 1, depois 0, e depois tudo 1, de modo que esse reset + o
prefixo que eu vá pegar é melhor do que o que o inimigo vai pegar
desse modo se eu brutar onde quero terminar no prefixo e brutar em que momento
vou resetar daria pra saber...
até o momento antes do reset vai ser tudo igual então foda-se
eu vou ganhar aquele prefixo em questão, e ele vai continuar a resposta dele...
> mas parecem muito simples isso aí

algo mais complexo que isso seria fazer múltiplos resets
o que rola a cada reset ??
    - eu perco um D por que vou voltar para o começo
    e ganho o prefixo lá
    - enquanto isso o outro lá vai torando

    - se ganho o prefixo, e até o momento do prefixo a gente
    ganhou tudo a mesma coisa eu meio que posso escolher
    que o adversário comece de qualquer lugar
    então basta ter um prefixo maior que o seu subarray equivalente...


    "Sabendo que vou pegar até o prefixo I, qual seria o melhor momento
    para eu resetar"


    Cheguei no valor X, meu inimigo também então a gente pode ignorar
    a soma até o momento por que vai ser igual para os dois. Nesse ponto
    vou escolher que o próximo valor seja um zero e depois dissos 1's
    suficientes para eu chegar em Y, com isso o inimigo vai chegar em X + Y + 1
    (não tenho certeza desse 1 e tem que considerar os mods tbm....), e eu vou
    chegar em X, é só ver se a minha soma dá maior que adele


    parece certo a idéia

    pra codar é N^2 pra brutar os pares + um logzinho pra ver o custo do segundo
    embora eu acho que dá pra fazer linear com two pointers.


    f(S, X) -> "quanto o inimigue ganha se estando em S ele for incremtado X
    vezes", só responder isso em O(Bom)
        X * D né
        busca binária na diferençå né
        pode ser que dê a volta mas sempre no máximo 1 flip
        da pra eu duplicar isso aí n dá n ?
        dai os duplicados ficam e N + Pi, daí fica uma busca binária clean



...
 */
#pragma once
/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>

#include <locale>
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
#define found(x, y) ((x).find((y)) != (x).end())
#define rall(j) j.rbegin(), j.rend()
#define len(j) (int)j.size()
/*
#define rep(i, a, b) \
    for (common_type_t<decltype(a), decltype(b)> i = (a); i < (b); i++)
#define rrep(i, a, b) \
    for (common_type_t<decltype(a), decltype(b)> i = (a); i > (b); i--)
#define repn(i, b) for (auto i = 0; i < (b); i++)
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) for (auto &xi : ranges::views::reverse(xs))
#define loop while (1)
#define iter(x) repn(__, x)
*/
// https:trap.jp/post/1224/
#define rep1(a) for (int _ = 0; _ < int(a); ++_)
#define rep2(i, a) for (int i = 0; i < int(a); ++i)
#define rep3(i, a, b) for (int i = int(a); i < int(b); ++i)
#define rep4(i, a, b, c) for (int i = int(a); i < int(b); i += int(c))
#define rep1_R(a) for (int i = int(a) - 1; i >= 0; --i)
#define rep2_R(i, a) for (int i = int(a) - 1; i >= 0; --i)
#define rep3_R(i, a, b) for (int i = int(b) - 1; i >= int(a); --i)
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rep_R(...) overload3(__VA_ARGS__, rep3_R, rep2_R, rep1_R)(__VA_ARGS__)

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

// bit operations, i may remove this soon
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using i128 = __int128;
using u128 = unsigned __int128;
// using f128 = __float128;
int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(u32 x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int popcnt(u64 x) { return __builtin_popcountll(x); }
int popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 : 1); }
int popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }
int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }
int popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
int lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

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
/*8<
@Title: Max \& Min Check

@Description: Returns the min/max value in range
[l, r] that satisfies the lambda function check,
if there is no such value the 'nullopt' is
returned.

@Usage: check must be a function that receives
an integer and return a boolean.

@Time: $O(\log{r-l+1})$
>8*/

template <typename T>
optional<T> maxCheck(T l, T r, auto check) {
    optional<T> ret;
    while (l <= r) {
        T m = midpoint(l, r);
        if (check(m))
            ret ? chmax(ret, m) : ret = m, l = m + 1;
        else
            r = m - 1;
    }
    return ret;
}

template <typename T>
optional<T> minCheck(T l, T r, auto check) {
    optional<T> ret;
    while (l <= r) {
        T m = midpoint(l, r);
        if (check(m))
            ret ? chmin(ret, m) : ret = m, r = m - 1;
        else
            l = m + 1;
    }
    return ret;
}

void __run() {
    ll n, m, d;
    cin >> n >> m >> d;

    vll ps(m), rs(m);
    rep(i, m) cin >> ps[i] >> rs[i];

    rep(i, m) {
        ps.pb(ps[i] + n);
        rs.pb(rs[i]);
    }

    vll psumPs(all(ps));
    partial_sum(all(psumPs), begin(psumPs));

    vll psumRs(all(rs));
    partial_sum(all(psumRs), begin(psumRs));

    auto f = [&](ll l, ll inc) {
        ll ret = inc * d;

        auto mayR = maxCheck(l + 1, m * 2 - 1,
                             [&](ll r) { return ps[r] - ps[l] <= inc; });

        if (mayR) {
            ret += (psumRs[*mayR] - psumRs[l]);
        }

        return ret;
    };

    rep(i, m) {
        rep(j, m) {
            ll a = psumRs[j] + ps[j] * d;
            ll b = f(i, ps[j] + 1);

            if (a > b) {
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
}

/*8<
>8*/
