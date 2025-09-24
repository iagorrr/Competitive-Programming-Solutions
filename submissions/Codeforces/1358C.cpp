/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
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


#define s(x) ((x * (x+1))/2)

void __run() {
	ll x1, y1;
	cin >> x1 >> y1;

	ll x2, y2;
	cin >> x2 >> y2;

	ll dx = x2 - x1;
	ll dy = y2 - y1;

	ll ans = dx * dy + 1;


	cout << ans << '\n';
}

/*8<
 * onde começa não faz diferença alguma...
 * somente pra baixo ou pra direita !
 * faz sim, tá doido
 *
 * como não precisa de mod ?
 *
 * pra baixo
 * 	xs[i][j] +	(i + j)  	= xs[i+1][j]
 *
 * pra direita
 * 	xs[i][j] + 	(i + j -1) 	= xs[i][j+1] 7
 *
 *
 * obrigatoriamente vai ter que fazer dx pra frente
 * e dy pra  baixo...
 *
 * então o i é um fator que vai sempre se manter anyway
 * 	x1, x1 +1, x1 + 2, ..., x2
 *
 * e mesma coisa pro lado tbm...
 * 	y1, y1 + 1, y1 + 2 , ..., y2 
 *
 * se tu ir pra direita no (x1 + 1) tu vai tá somando o (x1+1) 
 * e se tiver no (x1+3) vai estar somando ele...
 *
 * e a mesma coisa pra coluna tbm...
 *
 * o que muda então é quantas operações de lado eu fiz em cada linha
 * e quantas operações de baixo eu fiz em cada coluna
 *
 * x1 * n0  + (x1 + 1) * n1 + (x1 + 2) * n2
 *
 * somatorio de n vai dar o dx e os carai...
 *
 * esse -1 tbm não importa pq vai pra direita uma qtd fixa de vezes
 * tb então vai estar dos dois lados
 *
 *
 *
 * 1:	1	1	1	1	
 * 2:					2
 *
 * (1, 1, 1, 2)
 * (2, 2, 2, 2)
 *
 * da pouco conflito pok
 * a sequência das somas é estritamente crescente
 *
 * ou seja quase tudo é diferente
 * quantidade iguais valores diferentes vai ficar[
 * diferente provavelmente.
 *
 * comparando somente a soma das linhas, todas vão ser diferentes
 * o lance é quantas dá conflito com as das colunas tbm
 *
 * (1,2) (2, 4)
 *
 * 	A	S*	A	A
 * 	A	A	A	T*
 * 	A	A	A	A
 * 	A	A	A	A
 * 	A	A	A	A
 *
 * DX (1, 1, 1, x)  máximo é 2, dx = 1
 * DY (2, 2, 2, x)  máximo é 4, dy = 2 // obrigado 
 *
 * movimentos laterias = 2 
 * 	vetor de dx = () sz = 2 
 * 	(1, 1), (1, 2), (2, 2)
 * 	2, 3, 4
 * 	[2, 4]
 *
 * movimentos verticais = 1
 * 	vetor de dy = (2), (3), (4)
 * 	[2, 4]
 *
*  min = 2 + 2
*  max = 4 + 4
*  4 -> 8
*
*  não deveria ser 4 valores ?? -1 e foda-se ?
*  como tenho que terminar em um valor, e tem que ser gradativo
*  tem uma restricao ai né
*
*  meio que tanto faz onde a gente comeca então
*
*  o lance é
*
*  preciso aumentar A em P passos, qual o min e o max
*  pega os dois
*
*  e ve a diff do min com o max -1
*
*
 *
 *
 *
 * se tenho que aumentar 3 vezes
 * 0 > 1 > 2 > 3 e o resto tudo de X
 * e o resto tudo de 0
 *
 * então é 3 movimentos
 *
 *
 * 
 *
 *
 *
 *
 *         1        2        4        7       11        A
 *         3        5        8       12        A        A
 *         6        9       13        A        A        A
 *        10       14        A        A        A        A
 *        15        A        A        A        A        A
 *         A        A        A        A        A        A
 *
 *
 * x[i][j] = 
 *
 *
 *
 * (1,1) -> (2, 2)
 *
 * movimento vertical = 1
 * 	(1), (2)
	
 * movimento lateral = 1
 * 	(1), (2)
	
	min = 1 + 1, max = 2 + 2
	4 - 2 = 2 ok
>8*/
