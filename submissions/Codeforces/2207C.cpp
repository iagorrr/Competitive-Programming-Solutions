/*
- Só faz sentido colocar o bagulho em uma das célula que é o bottom daquela
coluna...
- São no máximo 2000 colunas, eu posso brutar qual vai ser o par
- Sabendo que vou colocar na posição i eu pego tudo entre as duas paredes
esquerda e direita
    - e o que fica acima ? pra parede da direita eu pego tudo que estiver acima
dela
    - pra da esquerda mesma coisa
    - e o meio é tudo né... já tá incluso no "dreno"

- coloca duas paredes oo na esquerda e na direita
- o lance é sempre ir pegando enquanto for crescente, e acumular a soma
- dai eu sei o quant otem naquele "vale"
- daí posso pegar 2 vales
- e a interseção da parte de cima dos vales ?


- rodo o flood a partir de um ponto, depois rodo para todos
- e vejo o que tem o maior componente, tenho de começar dos
- se depois de rodar esse flood eu sei exatamente quantas
- colunas de água cada posição vai ter
- então para os demais pontos da coluna basta eu vero
- se cada um for rodar esse flood aí fudeo fica mt caro
- pra cada (i,j) eu posso guardar quantos ele ve a esquerda e a dieria
- daí pra aquela coluna j o mais baixo tem a soma dessas posicoes a cima
- consigo saber pra um ponto quanto que ele peg
- baseado na distancia entre a ultima vez que teve algum bloco naquela altura
- dá pra, com isso conseguir iterar pelos outros bottom e saber qual o valor
deles desconsiderando o que já peguei ?
- n da pra fazer assim porque a altura é do krl
*/
/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>

#include <algorithm>
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
using vpll = vector<pll>;
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
        rep(i, os.iword(0), xs.size()) os << xs[i]
                                          << (i == xs.size() ? "" : " ");
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

void __run() {
        ll N, H;
        cin >> N >> H;

        vll AS(N);
        cin >> AS;

        vll XS(N);

        repn(i, N) {
                ll &cur = XS[i];

                ll mx = AS[i];
                rep(j, i, N) {
                        chmax(mx, AS[j]);
                        cur += H - mx;
                }

                mx = AS[i];
                rrep(j, i - 1, 0 - 1) {
                        chmax(mx, AS[j]);
                        cur += H - mx;
                }
        }

        ll ans = *max_element(all(XS));

        repn(i, N) {
                ll hmx = i + 1;
                rep(j, i + 1, N) {
                        if (hmx == -1 or AS[j] > AS[hmx]) hmx = j;

                        chmax(ans, XS[i] + XS[j] - XS[hmx]);
                }
        }

        cout << ans << endl;
}

/*8<
>8*/
