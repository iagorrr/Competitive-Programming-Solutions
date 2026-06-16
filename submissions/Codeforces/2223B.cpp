/*
Se pra cada bi a gente brutar em qual i ele vai ficar
nisso a gente sabe



Pra cada par (i,j), i != j eu conseguir saber
quantas vezes (i,j) é uma inversão, i < j.


so somar tudo e dividir pelo total

então se pra um par i e j eu saber quantas vezes
else sao inversao um do outro tá mec


se eu processar da esquerda pra direita
eu sei todos os valores que da pra fazer com i,
eu taco isso numa estrutura ou sla, e dai eu sei
que pra aquele A[i] * A[j], eu já sei quantos valores
maiores que ele eu conseguia fazer, porq ue já processei
os anteriores e processei os histogramas deles


o duro é que nessa to considerando os valores anteriores que já
utilizava o j

posso iterar pelo j, e depois pelo i !
ai eu sei que a galera anterior a mim nao usou o j que tô considerando agora pra
serem feitos


processa o j no foaase
e o i de trás pra frente

passa duas vezes e foda-se

da pra fazer melhor

eu considero que os valores antes de mim foram feitos com um J fixo

e daí eu sei


da pra fugir dessa seg aí ou sla


só preciso decrementar os valores que estão antes
de mim e são maior que eu porque com aquele mesmo j
eles já vão ser maior que eu


agora os valroes menores com o mesmo j vão estar antes
então não vai entrar na conta

da pra bazucar


considerar os valores que são menores ou iguais tbm...
e eu mesmo tbm


pra aquele par lá tenho que sondierar que posso permutar todo o resto...


essa parte da seg acho que é removível por que sempre pego a soma
do suffixo
e são sempre alguns suffixos

daria pra cada "pós" processing eu só atualizar essa psum

já vai tirar alguns logs...


a psum é em cima de N^2 aí nao fica barato nao
*/
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

void __pre_run() {}

const ll mod = 998244353;

ll fpow(ll a, ll b, ll m) {
        ll ret = 1;
        while (b) {
                if (b & 1) ret = (ret * a) % m;
                b >>= 1;
                a = (a * a) % m;
        }
        return ret;
}

const ll maxn = 2000 + 2;
ll FS[maxn];
void __init() {
        FS[0] = 1;

        rep(i, 1, maxn) { FS[i] = (FS[i - 1] * i) % mod; }
}

bool cmp(const pll &a, const pll &b) {
        return a.first * b.second < b.first * a.second;
}

void __run() {
        int N;
        cin >> N;

        vll AS(N);
        cin >> AS;

        vll BS(N);
        cin >> BS;

        dbg(N);
        dbg(AS);
        dbg(BS);

        vpll as;
        repn(i, len(AS)) {
                rep(j, i + 1, len(AS)) { as.eb(AS[i], AS[j]); }
        }

        sort(all(as), cmp);

        vpll bs;
        repn(i, len(BS)) {
                repn(j, len(BS)) {
                        if (i != j) {
                                bs.eb(BS[i], BS[j]);
                        }
                }
        }
        sort(rall(bs), cmp);

        ll ans = 0;

        dbg(as);
        dbg(bs);
        ll poped = 0;
        trav(ai, as) {
                while (len(bs) and cmp(bs.back(), ai)) {
                        poped++;
                        bs.pop_back();
                }
                ll v = (poped * FS[N - 2]) % mod;
                ans = (ans + v) % mod;
        }
        dbg(ans);

        ans = (ans * fpow(FS[N], mod - 2, mod)) % mod;

        cout << ans << endl;
}

/*8<
>8*/
