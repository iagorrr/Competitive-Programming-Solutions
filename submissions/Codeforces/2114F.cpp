#pragma once
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

template <typename T>
std::istream &operator>>(std::istream &is, std::vector<T> &vec) {
        for (auto &element : vec) {
                is >> element;
        }
        return is;
}

template <typename T>        // print vector
ostream &operator<<(ostream &os, vector<T> &xs) {
        rep(i, os.iword(0), xs.size()) os << xs[i]
                                          << (i == xs.size() ? "" : " ");
        os.iword(0) = 0;
        return os;
}

/*8<============~ END TEMPLATE ~============}>8*/
void run();
void pre();

int32_t main() {
#ifndef LOCAL
        fastio;
#endif

        int T = 1;

        cin >> T;

        rep(t, 0, T) {
                dbg(t);
                run();
        }
}

const ll oo = 1e9;

// primes that are in a, but not in b
ll sub_primes(ll a, ll b) {
        ll g = gcd(a, b);
        return a / g;
}

vll get_divisors(ll x) {
        vll ret;
        for (ll d = 1; d * d <= x; d++)
                if (!(x % d)) ret.eb(d), ret.eb(x / d);
        return ret;
}

ll solve(ll x, ll k) {
        auto dxs = get_divisors(x);
        vll mem(x + 1, -1);
        auto f = [&](auto &&f_, ll v) {
                if (v == 1) return 0ll;
                if (v <= k) return 1ll;
                auto &ret = mem[v];
                if (~ret) return ret;
                ll ans = oo;

                trav(dxi, dxs) {
                        if (dxi != 1 and dxi != v and ((v % dxi) == 0)) {
                                chmin(ans, f_(f_, v / dxi) + f_(f_, dxi));
                        }
                }

                return ret = ans;
        };
        return f(f, x);
}

void run() {
        ll x, y, k;
        cin >> x >> y >> k;

        ll maxx = max({x, y, k});

        ll add = sub_primes(y, x);
        ll rmv = sub_primes(x, y);

        dbg(add, rmv);
        dbg(solve(add, k), solve(rmv, k));

        ll ans = solve(add, k) + solve(rmv, k);

        cout << (ans >= oo ? -1 : ans) << endl;
}

/*8<
 * ja que multiplica ou divide, sempre
 * estamos fazendo "adição" ou "subtração"
 * de primos da fatoração
 *
 * ja que uma multiplicação é uma adição
 *
 * e uma divisão é uma remoçãonce
 *
 * podemos quebrar nessas duas partes...
 *
 * part 1: remover os primos excedentes de x
 *
 * parte 2: adicionar os primos faltando de x
 *
 * as duas são essencialmente a mesma coisa
 *
 * tenho um array P de primos, qual o mínimo
 * de subsequences disjuntas que preciso fazer
 * tal que o produto de cada subsequence
 * individualmente nunca passe de K
 *
 * os números cao ate 10^6
 *
 * da pra fazer uma dp safaada né
 *
 * posso imaginar esse array P como um número qualquer..., sempre menor que
10^6, afinal de contas nunca vou precisar adicionar ou remover um P maior que
10^6.
* se ele já é menor que K a resposta é 1, caso contrário posso quebrar ele em
dois arrays, e somo a resposta dos odis +  1
* * se ele já é menor que K a resposta é 0, caso contrário posso quebrar ele em
dois arrays, e somo a resposta dos odis +  1...
* caso de borda pra quando é 1 né, não tem que remover ou adicionar nada
* e não tem o + 1 do "split"
* tle no 6...
* acho que essa passada de ver em quais divisores quebrar tá me torando um
pouco.
*
* da pra pensar que pra o solve e um determinado V, os divisores de V, tbm
* sao os divisores dos divisores de V. então nao precisa achar esses valores
toda vez...
* da pra ordenar e processar de maneira mais esperta...
*
* sera que da pra abstrair pra masks e subsaks ? com certeza dá mas não sei se é
melhor
* deve ser né, pq a i a gente já tem os divisores explicitamente, não tem que
passar por nada desnecessários
* então se a sol for passando pelos divisores com certeza a melhor seria com
essas masks
* mó, mentira, desse jeito acaba gerando uma coisa ou outra repetida...
*
* AC, então passar nos divisores dos divisores dá bom demais !


10 45

2 * 5                3 * 3 * 5
>8*/
