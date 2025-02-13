/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>

#include <numeric>
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

const int MAXN = 1'00'000;
const int MAXM = 10;
constexpr int MAXK = MAXN * MAXM;

void run() {
        int N, M, K;
        cin >> N >> M >> K;

        vll AS(N);
        cin >> AS;

        vll BS(M);
        cin >> BS;

        vll2d best(N, vll(M + 1, LLONG_MAX));
        rep(i, 0, N) best[i][0] = AS[i];

        ll and_mask = -1;
        int sz = 0;
        function<void(int)> brute = [&](int j) {
                if (j == M) {
                        rep(i, 0, N) chmin(best[i][sz], AS[i] & and_mask);
                        return;
                }

                ll pmask = and_mask;
                and_mask = and_mask == -1 ? BS[j] : (and_mask & BS[j]);
                sz++;

                brute(j + 1);

                and_mask = pmask, sz--;
                brute(j + 1);
        };
        brute(0);

        vll reds;
        rep(i, 0, N) {
                rep(j, 0, M) { reds.eb(best[i][j] - best[i][j + 1]); }
        }
        dbg(best);

        sort(rall(reds));
        ll ans = accumulate(all(AS), 0ll) -
                 accumulate(begin(reds), begin(reds) + K, 0ll);
        cout << ans << endl;
}

/*8<
 * WA no 2
 * Critério de desempate ?
 * Tipo se tem como tirar a mesma coisa de duas
 * posições diferentes, tanto faz né, ambas desligam
 * os mesmos bits
 *
 * so se for dp mesmo
 * e nao tiver solução gulosa
 *
 * muita pouca mágica mesmo
 *
 *
 * bó um 2^m
 *
 * dp[k][2^m]
 *
 * na real
 *
 * da pra pensar
 *
 * que pra cada número qual o máximo
 * que consigo reduzir ele com x operações...
 * com x de 1..10
 *
 * depois é só ver quantas operações vou fazer
 * em cada número
 *
 * sempre com i operações é menor ou igual do que i+1
 *
 * depois é só um knapsack
 *
 * com n*m items e peso máximo n*m
 *
 * dp[i][c]
 * to no i e tenho c operações
 * sempre olha pra i - 1
 * então da pra fazer O(C) em memória
 * 2^m custos pra posição i
 *
 * minimiza a soma ?
 *
 * da pra fazer isso
 *
 * isso eh uma dp válida ?
 *
 * acho que não
 *
 * acho que sim
 *
 * maximizar na verdade
 *
 * dai soma os bits que foram removidos
 *
 * ta
 *
 * mantem a ideia de pra cada número
 * saber quanto eu consigo tirar pagando 1,2,3,...,10
 *
 * solucao do editorial mt foda
 *
 * so uma observacao q faltokjggkj
 *
 * brute force, sortings, greedy
 *
>8*/
