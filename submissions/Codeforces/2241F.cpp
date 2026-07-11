/*

- tá é uma subsec de binary string
- dá pra acabar sempre em 1 movimento ou nem ?


como que faço pra quantidade de inversões ser nula ne


1 0 -> count é 1, safe
pra continuar assim, preciso colocar de 2 em 2 zeros
colocar um 1 na frente não muda em nada

mas se eu colocar um 0 1 e ficar 0 1 0 1 é safe tbm pq vai pra 3 inversões
ent sempre começo com 1 0 e pego de 2 em 2 0 10 + 00 + 00 + 00

na verdade um prefixo de tamanho ímpar de 1 (1) + 0 + 00 +00 + 00

ou tipo (111) + (0) + (00) + (00)
se não for crescer assim tem que adicinoar novamente uma quantidade impar de 1


1 + 0,  1 + 0


o player que nao consegue mexer se tora entao se n tiver inversao é safe tbm


pq bob ganha aqui ?

011001
011001


da pra alice ganhar se tiver quantidade ímpar de 1
e depois do último 1 tiver pelo menos um 0
ou o último 1 estiver no final

se torar todos os 1 é xapa


se for par vai ter de tirar algo ímpar
e aí vai ficar impar e bob pode tirar tudo


sempre 1 ou 2 moves

se for alice ....


posso só ignorar o último 1

feito isso preciso ver se consigo remover tudo


se so posso quantidade iímpar de 1 e depois 0
da pra eu deixar algo pra t'ras ?

tem uns casos que tipo




1 1 1 1 0

posso pegar 1 1 1 0
e deixar um 1


então posso tolerar no máximo um negócio par de 1
por que daí deiso esse último 1 pra trás

na verdade posso deixar pra trás toos os 1's que não possuem um 0 depois


posso tirar todos os 1 e foda-se

1 1 1 0

- só posso deixar algum 1 pra trás se não for ter zero depois dele
com isso eu to resolvido, tenho essa folga aí



só tenho os 1 que possuem um zero após

então blau


peguei todos


se for impar vapo só pegar um zero qualquer


se for par tenho que arrumar
    - posso deixar 1 pra trás se for pegar todos os zeros
    depois do último 1
        - qual eu deixo pra t'ras


        ... 000000 1 0000

        se eu deixar ele pra t'ras tenho que tirar todos 00000 zeros lá
        - e aí meu trem virou par
        - ai tenho que pegar mais 1 zero...
        - muuuito casinho n é dp n ?
        - decompoem em token

        - to na posicao i, minha quantidade de inversoes % 2 é j, a quantidade
de 1's pra trás % 2 k, e eu já deixei ou não 1 pra trás, daí sou obrigado a
pegar todo os zeros






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

int solve(int idx, int qtd1Mod2, int invMod2, int jaLarguei, const string &s,
          auto &mem) {
    if (idx == len(s)) {
        return invMod2 == 1;
    }

    auto &ret = mem[idx][qtd1Mod2][invMod2][jaLarguei];
    if (ret != -1) return ret;

    bool got = false;
    if (s[idx] == '1') {
        // pegar
        got |= solve(idx + 1, !qtd1Mod2, invMod2, jaLarguei, s, mem);
        // largar
        got |= solve(idx + 1, qtd1Mod2, invMod2, true, s, mem);
    } else {
        if (jaLarguei) {
            // pegar
            got |= solve(idx + 1, qtd1Mod2, (invMod2 + qtd1Mod2) % 2, jaLarguei,
                         s, mem);
        } else {
            // pegar
            got |= solve(idx + 1, qtd1Mod2, (invMod2 + qtd1Mod2) % 2, false, s,
                         mem);

            // largar
            got |= solve(idx + 1, qtd1Mod2, invMod2, false, s, mem);
        }
    }

    return ret = got;
}

void __run() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector mem(n, vector(2, vector(2, vector<int>(2, -1))));
    rrep(i, n - 1, 0 - 1) {
        repn(j, 2) repn(k, 2) repn(l, 2) solve(i, j, k, l, s, mem);
    }
    auto ans = solve(0, 0, 0, 0, s, mem);
    cout << (ans ? "Alice" : "Bob") << endl;
}

/*8<
>8*/
