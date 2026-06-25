/*
Seja Px os primos que estão em X

quando eu estiver buildando os P's
os primos que estão em X em que aparecer na mesma
potencia de x, fora do lcm, esparso
e essa divisão cada potencia precisa ser menor do que a do
gcd se não vai passar, então tem um limite máximo para fazer
essa distrib ai

e os que não estão em X, só podem aparecer uma única
vez então é so somar as potencias de cada 1

produtório dos jeitos de distribuir cada primo


os que não estao X é só somar as potencias que aparecem...

e para os que estão:
    - itero pela potencia que ele vai ter no lcm
        - assumindo que aquela vai ser a máxima eu preciso
        distribuir a potencia do primo em X nas demais posicoes
        sem que alguma delas passe dessa máxima.
        - qtd que tem essa potencia que estou considerando
        - pau bola né quantas maneiras consigo somar X com tananan
        variáveis e cada uma tem um valor máximo.
            - complexidade dessa bomba é só o binom né ?
            - e como atualizo o valor de cada variável conforme
            aumento o max
            - acho que é fácil:
            - aparentemente não é seria uma Dpzinha
            - ou da pra brutar ?
            - pior caso cada um tem uns 20 primos.
            - então no pior caso cada primo (20) tem N
            caras
            - da pra ficar pior ?
            - resolvendo por primo...
            - a complexidade do primo é
            - dp(i, k), estou no iéismo valor e quero que a soma dê K
            - essa soma é pequena, por que X é pequeno, os fatores de X
espalhados
            - E tem que dar no máximo algo...
            - Esse algo da pra ser só estado ? ou roda várias vezes pra cada um
            - Da pra rodar uma dpzinha melhor
            - Eu tô no dp(i, s, m)
            - To no iésimo, preciso que a soma seja s, o maior valor seja m, e
um bool se eu já peguei esse valor.
            - por que preciso que esteja setado.
            - o m é 20, e a soma é 20 tbm
            - 40 * 40 * N, para alguns primos
            - da tle cabuloso


    - se essa parada de iterar :
        - Tenho N caixas cada uma com um valor máximo
        - Quero que a soma de todas elas, com exceção da maior
        seja X


    - eu sei que preciso de K distribuído pra geral lá
    - soma S, o maior valor foi M
    - M pode ser o maior valor que eu já setei.
    - daí se eu setar alguém maior M, eu devolvo os M pra soma e tiro o que
    - eu estou colocando
    dp(i,s,m), soma dando s, desonsiderando o maior valor que foi M

    - passa em tempo ?
    - Tenho que rodar uma vez para cada primo de X
    - Por que os que não são de X é só fazer
    - Então no pior dos piores casos é 20 vezes que tenho que rodar uma parada
    essa parada é :
        dp(i, s, m) -> N * 20 * 20 -> 10^5 * 4 * 10^2 -> 4 * 10^7  ... 8 * 10^8
        tá beeem apertatdin, acho que recursivo não passa...



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

void __init() {}

void __pre_run() {}

vll build_spf(ll n) {
        vll spf(n + 1);
        rep(i, 2, n + 1) if (!spf[i]) for (ll j = i; j <= n;
                                           j += i) if (!spf[j]) spf[j] = i;
        return spf;
}

auto SPF = build_spf(5 * 1e5 + 2);
vll prime_factors(ll x) {
        vll fs;
        while (x > 1) {
                fs.eb(SPF[x]);
                x /= SPF[x];
        }
        return fs;
}

const ll mod = 1'000'000'000 + 7;

const int maxn = 1e5 + 1;
const int maxmx = 19;
const int maxs = 19;

void lol(vll &AS) {
        umap<ll, ll> aa;
        trav(ai, AS) {
                umap<ll, ll> hs;
                auto ps = prime_factors(ai);
                for (auto pi : ps) {
                        aa[pi]++;
                }
        }

        dbg(aa);
        ll ans = 1;
        for (auto &[p, q] : aa) {
                ans = (ans * (q + 1)) % mod;
        }
        cout << ans << endl;
}

ll dp(const vll &ps, ll S) {
        const ll MX = *max_element(all(ps));
        vll2d nxt(S + 1, vll(MX + 1)), cur(S + 1, vll(MX + 1));

        repn(mx, MX + 1) nxt[0][mx] = 1;

        rtrav(pi, ps) {
                repn(s, S + 1) {
                        repn(mx, MX + 1) {
                                cur[s][mx] = 0;
                                repn(q, pi + 1) {
                                        if (q <= mx) {
                                                if (s - q >= 0)
                                                        (cur[s][mx] +=
                                                         nxt[s - q][mx]) %= mod;
                                        } else {
                                                if (s - mx >= 0)
                                                        (cur[s][mx] +=
                                                         nxt[s - mx][q]) %= mod;
                                        }
                                }
                        }
                }

                // no final !
                swap(nxt, cur);
        }

        return nxt[S][0];
}

void __run() {
        ll N, X;
        cin >> N >> X;

        auto pfX = prime_factors(X);
        umap<ll, ll> histX;
        trav(x, pfX) histX[x]++;
        set<ll> setX(all(pfX));

        vll AS(N);
        cin >> AS;
        dbg(N, X, AS);

        if (X == 1) return lol(AS), (void)0;

        // isso dava pra ser um vector
        umap<ll, ll> hist;

        // isso dava pra ser um vector
        umap<ll, vll> bounds;
        trav(ai, AS) {
                umap<ll, ll> bnd;
                trav(pi, prime_factors(ai)) {
                        if (!setX.count(pi))
                                hist[pi]++;
                        else
                                bnd[pi]++;
                }
                for (auto &[pi, q] : bnd) {
                        bounds[pi].eb(q);
                }
        }

        // fold ?
        ll ans1 = 1;
        trav(q, views::values(hist)) { ans1 = (ans1 * (q + 1)) % mod; }

        ll ans2 = 1;
        for (auto &[p, ps] : bounds) {
                dbg(ans2);
                ll S = histX[p];

                ans2 = (ans2 * dp(ps, S)) % mod;
        }

        if (bounds.empty()) ans2 = 0;
        trav(xi, setX) {
                if (bounds[xi].empty()) ans2 = 0;
        }

        dbg(ans1, ans2);
        ll ans = (ans1 * ans2) % mod;
        cout << ans << endl;
}

/*8<
>8*/
