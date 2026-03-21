/*8<
 * quero que vire 0
 * divisao eh shift pra esquerda
 * e -1 é removero lsb
 * nem sempre né
 * mas sera que o minimo é isso mesmo ?
 *
 * a resposta é sempre o maior bit + o popcount
 *
 *
 * entao a partir de um certo ponto em que o maior
 * bit e (k+1) alice já nao ganha
 *
 * como é em cima dos bits deve da pra fazer algo log
 *
 *
 * tipo, sabendo que o maior bit é x, quantos valores
 * tenho com + de y bits no pop count, essa quantidade
 * eu sei que nao vai ganahr
 *
 * e como to limitando pelo maior valor nao conta repetido assim
 *
 * acho que tem formula fechada para
 *
 * quantos numeros tem entere 2^i e 2^k com x bits...
 * tentar pegar num brute aqui...
 *
 *
 *
 *
 *         v
 * 000000001
 *
 * binomial né
 *
 * de quantas maneiras consigo esclher Y bits
 * de um subset de X bits...
 *
 * X é pequeno por que vai até 10^9 ~ 32
 * mas o Y é grande, porém da se passar de um certo valor
 * em sempre ture..., no caso se passar de X


    X! / (X-Y)! * Y!


    n ! / N-k! * k !




  3 =
        011
        010
        001
        000


        o highest é zero indexado






 *
 * os fatoriais vao se cancelar valendo por que*/

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

const int maxn = 30;

vll2d dp(maxn, vll(maxn, -1));

ll f(ll n, ll k) {
  // TODO: review this !
  if (k > n or k < 0 or n < 0)
    return 0;
  if (k == n or k == 0)
    return 1;

  auto &ans = dp[n][k];
  if (~ans)
    return ans;

  return ans = f(n - 1, k - 1) + f(n - 1, k);
}

void __run() {
  ll n, k;
  cin >> n >> k;

  dbg(n, k);

  ll at_left = 0;

  ll ans = 0;
  while (1 << (at_left) <= n) {

    if (1 << (at_left) == n) {
      if (at_left + 1 > k) {
        ans += 1;
      } else
        ans += 0;

    } else {

      ll cur_cost = at_left + 1;
      ll to_choose = (k + 1) - cur_cost;

      while (to_choose <= at_left) {
        ans += f(at_left, to_choose);
        to_choose++;
      }
    }

    at_left++;
  }

  cout << ans << endl;
}

// AC, bitwise, math, combinatorics
