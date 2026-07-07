/*
 bazucar:
    - fazer virtual tree pra cada valor e depois
    rodar uma dp em cima disso...
    - cada nó guarda quantos elementos tem diferente dele
    a cima dele
    - dai pra cada valor na hora de rodar a dp eu só preciso
    pegar os dois que esse valor é "máximo" e somar dai pra aquele nó
    com aquela "cor" esse seria o melhor.
    - tem que ter um -1 se o nó em si não é da cor que tamo analisando
    - e o caso em que o nó é da cor e daí é só pegar um dos filhos...

- mais simples
- o mais trivial é : A A daí é é maioral
- pra cada valor diferente de b que eu adicionar tenho que adicionar um de A
depois A B B B A A
- sempre começa e termina com o mesmo valor
- nao tem por que adicionar um valor nada a ver lá
era só ter pego os dois A da direita antes
- então pra cada nó basta checar num raio de ~3 ??
- se for maior que 3 vai ter que pegar uns valores e depois mais valores de a
- esse svalroes difernetes ai era só começar do segemento de A
- oka
- sempre 3 nós
- caro ?
- ele mesmo e dois adj sempre
- é só o pai ou um dos filhos ter a mesma cor
- quadrático ?
n né
- pra cada nó guardo as cores dos filhos assume que o nó vai ser sempre o meio
- basta ver se o do pai é igual a um ddos filhos
- ou se ele é igual a um dos filhos/pai
A B A

- pra ser da maioria sempre começa


A B A B A B A
 * */
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
    int n;
    cin >> n;

    vi as(n);
    cin >> as;
    trav(ai, as) ai--;

    vi2d adj(n);
    repn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<multiset<int>> cs(n);
    repn(i, n) {
        trav(v, adj[i]) {
            if (cs[i].count(as[v]) <= 1) cs[i].ins(as[v]);
        }
    }

    string ans(n, '0');

    function<void(int, int)> dfs = [&](int u, int p) {
        if (p != -1) {
            cs[u].erase(as[p]);
        }

        dbg(u, p);

        int au = as[u];

        trav(v, adj[u]) {
            if (v != p) {
                int av = as[v];
                if (av == au) {
                    ans[av] = '1';
                }

                if (p != -1 and as[p] == as[v]) {
                    ans[av] = '1';
                }

                if (cs[u].count(av) >= 2) ans[av] = '1';

                dfs(v, u);
            }
        }
    };

    dfs(0, -1);

    cout << ans << endl;
}

/*8<
>8*/
