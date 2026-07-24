/*
...

- Supondo que seja uma DP como podemos modelar algo mais simples ?
- Tenho N^500 pra torar
- DP de range ??

- é uma BST então limita muito os valores que posso ter....
- DP(i, l, r), estou considerando o nó I, e posso colocar valores nos ranges de
l até r (mas aí se eu colocar o filho da esquerda) pra um valor

- Se eu escolher uma raiz qualquer X, eu sei garantidamente quais valores
estão a esquerda dela e quis estão a direita e sei o quanto que ele vai
incrementar na resposta é só fazer todos os valores
- dá pra gente brutar a cada passo ? é meio que recursivo né ?
- Se estou brutando o filho de 3
- brute(i, l, r), testar i sendo a raiz sendo que preciso considerar os valores
de L até R
    - se estou considerando os valores de L até R, então eu sei quais vão para a
esquerda e quais vai para a direita de i, é só ver a orderm pra ver o custo dele
    - dái itera pra ver quem vai ser o filho da esuqerda e epga o max
    - e mesma coisa pra direita

pra fazer iterativa, teria que quando to olhando pra um (l, r), já ter olhado
todos os prefixos e todos os sufixos...

solve(i, l, r) pega sempre solve(j, l, i-1), solve(k, i+1, r)

pra esse daqui : solve(j, l, i-1)
            o l é o mesmo mas o r é garantidamentem menor
            então o for do R é crescente

pra esse daqui : solve(j, i+1, r)
            o r é o mesmo mas o l é maior
            então o for do l é decrescente


e o i ?? torou-se, por que olha tanto pra trás quant pra frente, mas é coo se a
as dimensãoes primáiras fosse o l e or dai szei qeu pros intervalos contidos e
mim eu já calculei tudo ent foda-se o i


como que otimiza isso daqui ??

int bestLeft = 0;
rep(lChild, l, i) { chmax(bestLeft, mem[l][i - 1][lChild]); }


pra um [l][r] fixo tenho um vetor certo ?
    pra esse vetor eu sepre começo de l por que não
    faz sentido por um valor menor que l
    então é sempre uma query de prefixo começando em l
    xaaaaapa

daí quero o melhor valor entre [l, i]

int bestRight = 0;
rep(rightChild, i + 1, r + 1) {
    chmax(bestRight, mem[i + 1][r][rightChild]);
}


é um ax em cima de mem[i+1][r][rightChild] rightChild vai de [i+1,r]
então se tiver os máximos por prefixo nisso ai eu to safe

...
 */
#pragma once
/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>

#include <iterator>
#include <ranges>
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
#define rep(i, a, b) \
    for (common_type_t<decltype(a), decltype(b)> i = (a); i < (b); i++)
#define rrep(i, a, b) \
    for (common_type_t<decltype(a), decltype(b)> i = (a); i > (b); i--)
#define repn(i, b) for (auto i = 0; i < (b); i++)
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) for (auto &xi : ranges::views::reverse(xs))
#define loop while (1)
#define iter(x) repn(__, x)
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

const int maxn = 500;
int mem[maxn][maxn][maxn];
int maxAux[maxn][maxn][maxn];
// l, (i -1),i
int max2[maxn][maxn];
int max3[maxn][maxn];

template <typename T>
int tCmp(T a, T b) {
    if (a == b) return 0;
    return a < b ? -1 : 1;
}

void __run() {
    int n;
    cin >> n;

    vi permutation(n);
    cin >> permutation;

    auto calcCost = [&](int l, int r) {
        vi costs(n, 0);

        vi inRange;
        vi pos(n, -1);

        for (int x : permutation) {
            if (l <= x && x <= r) {
                pos[x] = len(inRange);
                inRange.pb(x);
            }
        }

        int k = len(inRange);
        if (k == 0) return costs;

        vi cmp(k, 1);
        cmp[pos[l]] = 0;

        int curCost = 0;
        rep(j, 0, k - 1) {
            if (cmp[j] != cmp[j + 1]) curCost++;
        }

        auto rmv = [&](int p) {
            if (k <= 1) return 0;
            int c = curCost;
            if (p > 0) c -= (cmp[p - 1] != cmp[p]);
            if (p < k - 1) c -= (cmp[p] != cmp[p + 1]);
            if (p > 0 && p < k - 1) c += (cmp[p - 1] != cmp[p + 1]);
            return c;
        };

        costs[l] = rmv(pos[l]);

        rep(i, l + 1, r + 1) {
            int p = pos[i];

            if (p > 0) curCost -= (cmp[p - 1] != cmp[p]);
            if (p < k - 1) curCost -= (cmp[p] != cmp[p + 1]);

            cmp[p] = 0;

            if (p > 0) curCost += (cmp[p - 1] != cmp[p]);
            if (p < k - 1) curCost += (cmp[p] != cmp[p + 1]);

            costs[i] = rmv(p);
        }

        return costs;
    };

    repn(r, n) {
        rrep(l, r, 0 - 1) {
            vi costs = calcCost(l, r);
            repn(i, n) {
                auto &x = mem[l][r][i];

                int bestLeft = (i ? max2[l][i - 1] : 0);

                int bestRight = maxAux[i + 1][r][r];

                x = bestLeft + bestRight + costs[i];
            }

            rep(j, l, n) {
                maxAux[l][r][j] =
                    max((j ? maxAux[l][r][j - 1] : 0), mem[l][r][j]);
                max2[l][j] = maxAux[l][j][j + 1];
            }
        }
    }

    int ans = 0;
    repn(root, n) {
        int v = mem[0][n - 1][root];
        chmax(ans, v);
    }
    cout << ans << endl;
}

/*8<
>8*/
