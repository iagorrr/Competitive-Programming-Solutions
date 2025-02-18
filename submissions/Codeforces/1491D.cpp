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

template <typename T>
int _msb_(T x) {
        int ret = 0;
        for (; x; x >>= 1, ret++);
        return ret - 1;
}

/*8<============~ END TEMPLATE ~============}>8*/
void run();

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

void run() {
        ll u, v;
        cin >> u >> v;

        if (u > v) {
                cout << "NO" << endl;
                return;
        }

        set<int> bu, bv;
        for (ll i = 0, p2 = 1; i < 30; i++, p2 *= 2ll) {
                if (p2 & u) {
                        bu.ins(i);
                }

                if (p2 & v) {
                        bv.ins(i);
                }
        }

        rtrav(b, bv) {
                if (bu.empty()) {
                        cout << "NO" << endl;
                        return;
                }

                auto it = bu.lower_bound(b + 1);
                if (it == begin(bu)) {
                        cout << "NO" << endl;
                        return;
                }
                it--;
                bu.erase(it);
        }

        cout << "YES" << endl;
}

/*8<
 * u pra (u+v)
 *
 * se u&v == v
 *
 * então u é uma super máscara de v
 *
 * essencialmente posso somar qualquer bit que esteja em u
 * no próprio u né
 *
 *
 * olhou pro menor bit
 *
 * com oo menor os maires bits são produtos dele
 *
 * mas a gente pode eventualemtne diminuir o menor bit...
 *
 * quer dizer
 *
 * alumentar né
 *
 * pq se a gente soma ele ele soma e vira o da frente....
 *
 *
 *
 * oka
 *
 * entãoka
 *
 *
 * 1  - > 4
 *
 * tem que somar 3
 *
 * como a gente pode montar esse 3 ?
 *
 * 1 + 2
 *
 * 1 -> (2)
 *
 *
 * so vai quebrando
 *
 * se  tiver um no U da pra fazer qualuer número
 * da nada falei merda
 *
 * acho que é log só implementar....

nah

 * olhando pros bits
 *
 *
 *
 * 001
 * 100
 *
 * o 1 não tem an de cima
 *
 * tira ele
 * como né
 * somando duh
 * somando ele mesmo...
 *
 * da implementa assim
 *
 * se o bit tá tá a gente deixa
 * CC empurra ele pra frente...
 *
 * no final tem que estar igual....
 *
 *
 *
 * 3 6
 *
 * 0 1 1
 * 1 1 0
 *
 * 1 0 0
 * 1 1 0
 *
 * da xabu pq meio que fode o da frente
 *
 * ent bó puxar os bits da esquerda...
 *
 * bitmasks, greedy
>8*/
