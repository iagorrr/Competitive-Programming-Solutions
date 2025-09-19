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

void __run() {
	int n;
	cin >> n;


	string s, t;
	cin >> s >> t;

	map<pair<char,char>, int> q;
	repn(i, n) { q[{s[i],t[i]}]++; }

	int ans = INT_MAX;

	int a = q[{'0', '0'}];
	int b = q[{'0', '1'}];
	int c = q[{'1', '0'}];
	int d = q[{'1', '1'}];

	dbg(a, b, c, d);

	if (c == b) chmin(ans, b + c);
	if (a + 1 == d) chmin(ans, a + d);

	cout << (ans == INT_MAX ? -1 : ans) << endl;
}

/*
 * a cada duas operações meio que tanto faz
 * se tenho que fazer O operações on O é par:
 * 	dá pra setar cada uma individualmente
 *
 *
 * só da pra fixar uma que já esteja ascesa !
 *
 * se tenho uma que que quero que saia de um 0 -> 1
 * preciso fazer em cima de algum 1 qualquer
 * mas anyway é uma operação a ser feita
 *
 *

01
11

basta segurar um 1 que eu já queria e fazer a op
isso pode flipar outros que não queria
ai fudeo

000
101

impossible se tudo for zero, e quero algo com algum 1 cc sempre dá ?


1 0 0 0 1 0 1 1 1 
1 0 1 1 0 1 1 0 0 

*

o o I I O I O I I

tenho que arrumar 6 (0 -> 1 : 3, 1 -> 0: 3)
nesse caso é tudo igual da pra fazer em 3 ?

1 O I I O I O I I




em uma operação todos os O viram I e vice versa
com exeção de um deles que ou permanece I, ou permanece O

suponha que tenha algum valor que mantem em O
vou dar toggle em geral

qtd de bits pra arrumar tem que ser impar ?
e tem um +1 -1 se não não tiver um matc já feito
"operação" ce setup

lsat case é 2 2 e não da 2 po

0 0 1 0 1 1 0 1 1 
0 1 1 0 1 0 1 0 1 


o que é importa é a qtd de cada chave

pq os dois ultimos casos não são equivalentes

da pra so simualr tbm

AC, ad-hoc

 * */

