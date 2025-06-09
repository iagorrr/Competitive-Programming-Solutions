/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
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
 os numeros andam meio que na diagonal...
 sobe desce, sobe desce....
 ou desce e sobe d....

 andando pra trás


 a gente ve quais numeros da pra por em cima
 e quais numeros da pra por em baixo

 se der match pega a maior posicao que isso ocorre.

10
5 1 2 7 3 9  4 10 6 10
6 2 3 6 4 10 5 1  7  9

5 1 2 7 3 9  4 9 6 9
6 2 3 6 4 10 5 1 7 x

sempre muda o de cima pra dar match com o de baixo

ou o  de baixo pra dar match com o de cima
ve as posicoes do valor em questao

ve se tem como chegar nele considerando so movendo
mesmo, e considerando removendo um tmb...

mudando o de {cima, baixo}
        vindo de {cima, debaixo}
                considerando {remover, n remover}



da pra fazer um solve só, e só inververter o as com bs pra simplificar...

mudando o de {baixo}
        vindo de {cima, debaixo}
                considerando {remover, n remover}

pra vir de ima tem que estar na paridade oposta a cima
se quiser vir de baixo, tem que estar na mesma paridade
que  a minha.

quando remove olho pra paridade oposta da que estava olhando antes.

corner case: nao posso remover a posicao em si né

 * */

void __init() {}

void __pre_run() {}

int solve(const vi &top, const vi &bot) {
        // sempre mudando o de baixo

        vector<umap<int, vector<int>>> haveOnTop(2);
        vector<umap<int, vector<int>>> haveOnBot(2);

        rrep(i, len(top) - 1, 0 - 1) {
                // sem ter que mexer em nada...
                bool ok = top[i] == bot[i];

                int p = i & 1;
                int x = top[i];

                // vindo de cima...
                // tem que estar na paridade oposta a minha e em cima...
                ok |= !haveOnTop[!p][x].empty();

                // vindo de baixo...
                // paridade igual a minha
                ok |= !haveOnBot[p][x].empty();

                // remover

                // vindo de baixo...
                // tem que vir dps da minha posicaom +1, que ai removo o da
                // frente, e vapo..., na paridade oposta a minha
                ok |= !empty(haveOnBot[!p][x]) and
                      haveOnBot[!p][x].front() > i + 1;

                // vindo de cima...
                ok |= !empty(haveOnTop[p][x]) and
                      haveOnTop[p][x].front() > i + 1;

                if (ok) return i + 1;

                haveOnBot[p][bot[i]].push_back(i);
                haveOnTop[p][top[i]].push_back(i);
        }

        return 0;
}

void __run() {
        int n;
        cin >> n;

        vi as(n);
        cin >> as;

        vi bs(n);
        cin >> bs;

        int ans = solve(as, bs);
        swap(as, bs);
        chmax(ans, solve(as, bs));

        cout << ans << endl;
}

/*8<
 * greedy
>8*/
