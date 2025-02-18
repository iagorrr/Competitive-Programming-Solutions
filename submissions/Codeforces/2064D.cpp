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

template <typename T = int,
          auto cmp = [](T &src1, T &src2, T &dst) { dst = max(src1, src2); }>
class SparseTable {
       private:
        int sz;
        vi logs;
        vector<vector<T>> st;

       public:
        SparseTable(const vector<T> &v) : sz(len(v)), logs(sz + 1) {
                rep(i, 2, sz + 1) logs[i] = logs[i >> 1] + 1;
                st.resize(logs[sz] + 1, vector<T>(sz));
                rep(i, 0, sz) st[0][i] = v[i];
                for (int k = 1; (1 << k) <= sz; k++) {
                        for (int i = 0; i + (1 << k) <= sz; i++) {
                                cmp(st[k - 1][i], st[k - 1][i + (1 << (k - 1))],
                                    st[k][i]);
                        }
                }
        }
        T query(int l, int r) {
                r++;
                const int k = logs[r - l];
                T ret;
                cmp(st[k][l], st[k][r - (1 << k)], ret);
                return ret;
        }
};

const int MAXB = 29;
void run() {
        int N, Q;
        cin >> N >> Q;

        vll AS(N);
        cin >> AS;

        vll acc_xor = AS;
        rep(i, 1, N) acc_xor[i] ^= acc_xor[i - 1];

        auto msb_as = AS;
        transform(all(msb_as), begin(msb_as), [&](ll x) { return _msb_(x); });

        SparseTable st(msb_as);

        dbg(msb_as);

        while (Q--) {
                ll X;
                cin >> X;
                int r = N - 1;

                while (r >= 0) {
                        // until where can i win
                        auto bb_l = minCheck(0, r, [&](int m) {
                                return st.query(m, r) < _msb_(X);
                        });

                        int l = bb_l.value_or(r);
                        dbg(l);

                        int pr = r;

                        // won something
                        r = l;

                        dbg(X, AS[l]);

                        if (X >= AS[l]) {        // *l - 1 have someone
                                                 // which may kill me
                                X ^= (acc_xor[pr] ^ (l ? acc_xor[l - 1] : 0));
                                r--;
                        } else
                                break;
                }

                cout << N - r - 1 << " \n"[!Q];
        }
}

/*8<
 * o primeiro ponto:
 *  pra conseguir comer o sufixo até a posicao l
                precisa que o (XOR(l+1, N) ^x) >= AS[l]
                > pq idenpendente de serem maior ou naõ,
                supondo que seja antes de comer o i ele vai
                ter esse peso ok
                é um check top
                mas n é suficiente
 *
 *  tem cara de que da pra precomputar sem o X
 *  e ver qual impacto o X tem no que já ta pronto...
 *
 *
 *

10      4       3       9       7       4       6       1       9       4
0       0       1       1       1       0       0       1       1       0 1 1 0
1       1       1       0       1       0       0       0       2 0       1 0 0
1       1       1       0       0       1       4 1       0       0       1 0 0
0       0       1       0       8


10      4       3       9       7       4       6       1       9       4
6       1       -6


acho que da pra fazer por bit !

pra cada bit a gente faz o seguinte

da porra nem uma

e algo do tipo:

considerando os i primeiros bits...


pra cada bit a gente em quais posições ele fica
ligado e desligado

pra dar certo pra um suffixo l
não pode ter nem uma posição que a soma
dos bits que ficam ligado da menor do que
o valor no A[i] pra i >= l

tem como a gente juntar as queries pra
meio que ligar e desligar cad bit poucoas vezes ?


passar só pelas masks da resposta

se a cada bit aparecer ligado e desligado pelo menos uma vez
já torou tudo ?

seg com rollback ?

só gerar as mácaras válidas vai dar
O(Q) não ?

como poda isso

só continua o brute se existe pelo menos uma máscara com esse prefixo...


pra um numero ser maior que outro em binário

implica que A tem um bit maior que B não tem
se ambos tem, foda-se

as gente olha pro maior bit do X,

 * oi sumido
 *
 * a gente sempre pode olhar pro MSB
 *
 * MSB igual o MSB decresce
 * MSB menor o MSB se mantém
 * MSB maior ele cresceria, mas se o MSB é maior a gente n come né
 *
 * então como ele não cresce de volta
 *
 * é montônico no MSB !
 *
 * então, se o MSB é maior é vapo
 *
 * tem que se preocupar quando ele fica igual !
 * se ele fica maior morre ali mesmo
 *
 * se ele fica igual tem 2 caos
 *      ou morre ali mesmo
 *      ou continua porém com outro MSB né
 *
 *      e o problema continua....
 *
 *      ate o MSB ser zero ou achar alguem maior né
 *
 *      então se a gente sabe achar essa posicao de pico
 *      em O(bom) o problema fica O(bits) por query
 *
 *      trintinha
 *
 *      vapo pvapo
 *
 *      o krai
 *
 *      se esse ponto crítico ai se repetir
 *
 *      n repete né
 *
 *      sempre cai,kk
 * AC, bitmasks, data structures, prefix sum, binary seach
>8*/
