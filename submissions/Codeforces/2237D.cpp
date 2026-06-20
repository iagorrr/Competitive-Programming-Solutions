/*
Como que eu sei se uma string é "bonitável"


de tamanho 1 sempre é


sair da string final pra inicial


0 -> (11)


Se S -> A


S2 continua sendo belo se



flipou mas fica bonito ainda

S + BB -> A + BB -> A + A -> B

mesma coisa pro contrário e pro prefixo


A + S + B

B + S + A

A + S + A

B + S + B


sol linear ou log po

psum e olha pros valores de trás ??

xor ?


todo array de tamnho 1 é um belo


depois a gente pode expandir pra um de taanho dois se o char que
a gente tá colocando é igual ao anterior

pra um de tamanho 3 se é oposto ...


A
 --- A + A
 --- A + BB
 --- A + AA
 --- BB + A


 N^2 sai ?

pensando em segmentos pra cada um a gente tem "reducoes"

pode virar um A, B, AA ou BB
esses ai a gente sabe operar
ou só A e B ?


A + B foda-se
A + A ok
B + B

e daí a gente opera em cima desses segmentos

se considerando a string qeu termina em i
eu sei todos as transformações possiveis dos "suffixos próprios de I-1"
eu só preciso saber quantos deles são iguais ao S[i] ?

não por que taria considerando que vou operar o S[i]
com o resultado daquela string toda
mas meio que é isso, não ?
o final sempre opera com o último valor de qualquer jeito


A + B -> AB
A + A -> B
AB + A -> ABA (já é inoperável)
AB + B -> AA -> B
BA + A -> BAA -> BB -> A
BA + B -> BAB (inoperável)
B + A -> BA
B + B -> A

vai acumulando e xaaapa




*/
/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>

#include <cinttypes>
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
        int N;
        cin >> N;

        string S;
        cin >> S;

        vll m(3);
        ll ans = 0;
        ll chain = 0;
        char prevC = 'X';
        rtrav(c, S) {
                vll m2(3);
                int v = c == '1';
                repn(i, 3) { m2[(i + v + 1) % 3] += m[i]; }
                m2[v + 1]++;
                swap(m2, m);
                ans += m[1] + m[2];

                chain = (c != prevC) * chain + 1;
                prevC = c;

                if (chain >= 3) {
                        ans -= (chain + 1) / 2 - 1;
                }
        }

        cout << ans << endl;
}

/*8<
>8*/
