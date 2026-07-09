/*
- n <= 15
- não tem restrição em cima do M
- Mas o pior seria um grafo bamboo onde todo nó liga em todos os vértices abaixo
ou a cima dele
- Mas ele limitou em 2^30
- os caminhos que mais me dizem algo são os maiores ?
- É uma busca binária claro...

- da pra otimizar um pouco essa query hein, da pra cair 1 na frente de quando a
gente chga em uma pos que a gente conhece

Os caminhos em ordem são sempre algo do tipo


A
A -> B
A -> B -> C
A -> C

coisas assim
Como é um dag os nós não se repetem
Cada nó pode ter até 15 arestas  sendo bem exagerado....
Da pra fazer busca binária pra achar a priemira posicao tal que o primeiro é U e
o outro V, e deopis diferente de V .... e xalala

pra cada um acahr todas as arestas...

quao caro é isso ?

N, N-1, N-2, N-3 , ... 1
N^2 / 2  arestas

32 * (n+m) é certamente maior que N ^2
E 32 pq eu pago no máximo 32 pra cada aresta que eu quero achar
no caos 32 * m né

tá com folga

pra cada 1 eu vejo a ultima posica em que U->V, e a próxima se começar em U,
U->X tal que X é diferente de V

sempre olho só para os 2 primeiros nós da query...


agora é só N + M
fudeu-se


é somo se eu pudesse pra cada nó fazer uma query
e dps ter que acertar todas as arestas dele

achar um caminho grande é vantajoso por que nos dá várias arestas de uma vez



se tenho A -> B -> C
Se eu olhar todas as queries que comecam em A
eu acho todas as de C
por que pra todo caminho de C ele vai estar inlucso aí
- o maior caminho de um nó é menor do que o maior caminho de um que liga nele...
- em vez de acertar em A->B acertar logo em A->B->C

- deduzir essas coisas fazendo continha ?
- da pra matar a busca binária fazendo continhas !

- Se sei que tenho C[i] caminhos que começam em i
- Se to olhando o primeiro par j -> i e ele é o K em K+C[i] j -> v, e v != i
- se fizer bottom up eu consigo pegar todos os caminhos de um qualquer
- e a partir dele propagar para os pais...


C[i] =  sum(C[j] | j é vizin de i)
- como que faz esse role topdown aí
- acho que dá pra fazer mais simples


Se eu simplesmente ir andando eu meio que acho as arestas né ?
E aí quando eu chegar em uma posicao que eu já conheço o nó eu skipo pra prox
que desconheço


A
A B             ( (A->B))
A B C            ( (A->B), (B -> C))
B               (já visitei tudo de B) e sei que ele tem (1 caminho) pulo pro
atual + (1) B C     skip C (ja visitei tudo pulo pro atual mais 0) aqui...
final...


é meio que rodando uma dfs se estou em K e quando leio K + 1 ele só difere na
última posicao
- De um K pra um K + 1 pode rolar o que :
    - Aumentar em 1, que seria adicionar um novo nó ao fim desse path
    - Diminuir o path algumas posicoes e trocar o start

    se termina do ti po ... U -> V
    se u não tem mais adj vai remover U
    A -> U
    se a não tem mais adj vai remover A ..
    e assim por diante


    os dois caminhos sempre tem um prefixo em comum se não é um novo source
    meio uqe ignoro quando é esses caminhos novos


    quando olho o anterior

    por isso que tem um N + M
    pra poder ignorar o que vem sozinho

    ent pego o do K atual
    pego o do próximo
    pelo o prefixo em coumn deles

    daí vai ter uma posicao que difere

    cur : ... U -> V
    nxt : ... U -> X

    se já conheço X eu pulo C[X]
    caso contrário adiciono e bola que segue


    como que calcula esses C[i] da pra pagar um O(N) sempre pra saber
    isso daí C[i] = soma lá e foda-se todos começam com 1
    codar ?
>> COMPILING 2196C2.cpp <<
1
5
  2.24s user 0.20s system 96% cpu 2.536 total
>> DONE <<
[t] = [0]
? 2
2
1 2
[adj, alreadySeen] = [{{},{},{},{},{}}, {0,0,0,0,0}]
[curPath] = [{0,1}]
[adj] = [{{1},{},{},{},{}}]
? 3
3
1 2 4
[adj, alreadySeen] = [{{1},{},{},{},{}}, {0,0,0,0,0}]
[curPath] = [{0,1,3}]
[adj] = [{{1},{3},{},{},{}}]
? 4
3
1 2 5
[adj, alreadySeen] = [{{1},{3},{},{},{}}, {0,0,0,0,0}]
[curPath] = [{0,1,4}]
[adj] = [{{1},{4,3},{},{},{}}]
? 5
2
1 3
[adj, alreadySeen] = [{{1},{4,3},{},{},{}}, {0,0,0,0,0}]
[curPath] = [{0,2}]
[adj] = [{{2,1},{4,3},{},{},{}}]
? 6
3
1 3 4
[adj, alreadySeen] = [{{2,1},{4,3},{},{},{}}, {0,1,0,0,1}]
[curPath] = [{0,2,3}]
[adj] = [{{2,1},{4,3},{3},{},{}}]
? 7
2
1 3
[adj, alreadySeen] = [{{2,1},{4,3},{3},{},{}}, {0,1,0,0,1}]
[curPath] = [{0,2}]
[u, dpPaths[u]] = [3, 1]
[u, dpPaths[u]] = [2, 2]
[adj] = [{{2,1},{4,3},{3},{},{}}]
? 9
2
2 4
[adj, alreadySeen] = [{{2,1},{4,3},{3},{},{}}, {0,1,1,1,1}]
[curPath] = [{1,3}]
[u, dpPaths[u]] = [3, 1]
[adj] = [{{2,1},{4,3},{3},{},{}}]
? 10
2
2 5
[adj, alreadySeen] = [{{2,1},{4,3},{3},{},{}}, {0,1,1,1,1}]
[curPath] = [{1,4}]
[u, dpPaths[u]] = [4, 1]
[adj] = [{{2,1},{4,3},{3},{},{}}]
? 11
1
3
[adj, alreadySeen] = [{{2,1},{4,3},{3},{},{}}, {0,1,1,1,1}]
[curPath] = [{2}]
[u, dpPaths[u]] = [2, 2]
? 13
1
4
[adj, alreadySeen] = [{{2,1},{4,3},{3},{},{}}, {0,1,1,1,1}]
[curPath] = [{3}]
[u, dpPaths[u]] = [3, 1]
? 14
1
5
[adj, alreadySeen] = [{{2,1},{4,3},{3},{},{}}, {0,1,1,1,1}]
[curPath] = [{4}]
[u, dpPaths[u]] = [4, 1]
? 15
0
[totQueries] = [12]
5
1 3
1 2
2 5
2 4
3 4
  0.01s user 0.02s system 0% cpu 53.923 total

*/
/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
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
// #define endl '\n'
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

umap<ll, vi> cache;
int totQueries;
vi query(ll k) {
    if (cache.count(k)) return cache[k];

    cout << "? " << k << endl;
    totQueries++;
    int q;
    cin >> q;
    vi xs(q);
    cin >> xs;
    trav(xi, xs) xi--;
    cache[k] = xs;
    return xs;
}

void __run() {
    cache.clear();
    totQueries = 0;

    ll n;
    cin >> n;

    cache[1] = {0};

    if (n == 1) {
        cout << "! " << 0 << endl;
        return;
    }

    vector<unordered_set<int>> adj(n);
    vector<bool> alreadySeen(n);  // must be to when we pop it from the new path

    vll dpPaths(n, -1);
    function<ll(int)> totPaths = [&](int u) {
        if (dpPaths[u] != -1) {
            dbg(u, dpPaths[u]);
            return dpPaths[u];
        }
        dpPaths[u] = 1;
        trav(v, adj[u]) { dpPaths[u] += totPaths(v); }

        dbg(u, dpPaths[u]);
        return dpPaths[u];
    };

    ll curIdx = 2;
    vi prevPath(1, 0);
    while (len(query(curIdx))) {
        auto curPath = query(curIdx);

        int lcp = 0;
        while (lcp < len(curPath) && lcp < len(prevPath) &&
               curPath[lcp] == prevPath[lcp]) {
            lcp++;
        }
        for (int i = lcp; i < len(prevPath); i++) {
            alreadySeen[prevPath[i]] = 1;
        }

        int newNode = curPath.back();

        if (curPath.size() >= 2) {
            adj[curPath[len(curPath) - 2]].ins(newNode);
        } else if (curPath.size() == 1) {
            alreadySeen[prevPath.front()] = 1;
        }

        if (alreadySeen[newNode]) {
            curIdx = curIdx + totPaths(newNode);
        } else
            curIdx++, prevPath = curPath;
    }

    vpii ans;
    repn(i, n) {
        trav(j, adj[i]) { ans.pb({i + 1, j + 1}); }
    }

    dbg(totQueries);
    cout << "! " << len(ans) << endl;
    for (auto &[u, v] : ans) cout << u << ' ' << v << endl;
}

/*8<
>8*/
