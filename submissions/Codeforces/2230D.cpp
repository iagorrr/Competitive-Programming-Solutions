/*

se pra cada i eu tiver um l que seria o maior l antes i tal que
se eu ver de l ate i - 1 eu posso ver i, eu sei quantos episodios
eu "posso" ver, desconsiderando os repetidos.

para os repetidos daria pra guardar o l daquele episodio tbm...

entao pra saber se um ep seria visto pelo os dois


considerando que vou estar em L R

lasttAppA[i]
lasttAppB[i]

tipo uma chain, se quero saber se vejo i,
a ultima aparicao de um (i-1) valido tem que ser depois de L
e dai preciso guardar qual o menor indice dessa chain ?

dai esse indice tem que ser apos L
isso diz se eu veria desconsiderando repeticao

o que importa eh o inicio da cadeia


sobre a repeticao, eu guardo tbm, onde foi que aconteceu um

i válido que seria assistido, ai eu sei quando que seria repetido


se eu nao consigo achar os 'pre req' de uma posicao
apos alguma dela que ja tenha fechado eu nao consigo ver ela anyway

o que tenho é : pra cada i, eu sei o maior l que eu preciso
ter pra conseguir assistir ele

pra um [L, R] ser válido a primeira ocorrência do 1
tem que ser igual.

depois a primeira do 2 tbm tem que ser igual

e xalala....


quando eu to com um L fixo, eu posso ir até a primeira posicao
que teve mismatch, guardo isso e sei todos os R's possiveis pra cada L

e como que atualiza isso faz como essa bomba ?

se iterar com o R, e tentar saber quantos l válidos existem ?o


iterando com o L fixo, eu quero saber a primeira posicao que da mismatch.


meio que fixando o primeiro 1, a gente tem as demais posicoes

o que preciso saber é se dado um 1 de cima a cadeia dele eh equivalente
com a do outro
*/
#pragma once
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

void __run() {
  int N;
  cin >> N;

  vll AS(N);
  cin >> AS;
  trav(ai, AS) ai--;

  vll BS(N);
  cin >> BS;
  trav(bi, BS) bi--;

  vll nxtA(N, N);
  vll nxtB(N, N);

  {
    vll fa(N + 1, N);
    vll fb(N + 1, N);
    rrep(i, N - 1, 0 - 1) {
      nxtA[i] = fa[AS[i] + 1];
      nxtB[i] = fb[BS[i] + 1];
      fa[AS[i]] = i;
      fb[BS[i]] = i;
    }
  }

  vll mem(N + 1, -1);
  mem[N] = N;
  rrep(i, N - 1, 0 - 1) {
    if (AS[i] != BS[i])
      continue;

    int ia = nxtA[i], ib = nxtB[i];

    auto &ret = mem[i];
    if (ia != ib) {
      ret = min(ia, ib);
    } else
      ret = mem[ia];
  }

  ll ans = 0;

  int f1a = N;
  int f1b = N;
  rrep(i, N - 1, 0 - 1) {

    if (AS[i] == 0)
      f1a = i;
    if (BS[i] == 0)
      f1b = i;

    if (f1a != f1b) {
      ans += min(f1a, f1b) - i;
    } else {
      ans += mem[f1a] - i;
    }
  }

  cout << ans << endl;
}

/*8<
>8*/
