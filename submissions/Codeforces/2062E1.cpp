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

template <typename T = ll,
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

void run() {
        int N;
        cin >> N;

        vll WS(N);
        cin >> WS;

        vi2d ADJ(N);
        rep(i, 0, N - 1) {
                int u, v;
                cin >> u >> v;
                u--, v--;
                ADJ[u].eb(v), ADJ[v].eb(u);
        }

        vi L(N), R(N);
        vi ws_order;
        function<void(int, int)> dfs = [&](int u, int p) {
                ws_order.eb(WS[u]);
                L[u] = len(ws_order) - 1;
                trav(v, ADJ[u]) {
                        if (v != p) {
                                dfs(v, u);
                        }
                }

                R[u] = len(ws_order) - 1;
        };
        dfs(0, -1);

        SparseTable st(ws_order);
        int ans = 0, ansmx = -1;
        rep(i, 0, N) {
                int mx = -1;
                int l = L[i], r = R[i];
                if (l) chmax(mx, st.query(0, l - 1));
                if (r + 1 < N) chmax(mx, st.query(r + 1, N - 1));
                if (WS[i] < mx and WS[i] > ansmx) {
                        ansmx = WS[i];
                        ans = i;
                }
        }

        cout << (~ansmx ? ans + 1 : 0) << endl;
}

/*8<
 * N = 4 * 10^5
 *
 * algo linear se pá né
 *
 * da pra quebrar em subárvores e fazer um dpzinha ?
 *
 * e só dar merge dos filhos, tipo nim mesmo
 *
 * quais são so lose states:
 *      1. Todos os valores da subárvore são iguais
 *      2. Só tem um nó
 *
 * Se eu remover o segundo maior valor o outro é obrigado
 * a remover o maior e eu ganho.
 *      Casos de borda ?
 *              1. Todos os valores iguais, sempre loose !
 *              2. O segundo maior valor só tem na raiz
 *                      > Tira o terceiro maior, daí o outro
 *                      vai ter que tirar a raiz
 *                              > E se não tiver 3 valores distintos?
 *                                      > É Lose
 *              3. O segundo maior valor só tem sendo
 *              parent do maior valo, sempre acaba removendo os dois juntos
 *                      > Se eu tirar o terceiro maior
 *                              Ou ele tira o maior e eu ganho na proxima
 *                              ou ele tira o segundo maior e por consequência
 *                              o maior tbm
 *                              dai eu ganho :D
 *                              > E se não tiver o terceiro maior valor ?
 *                                      É loose
 *                              > E se o terceiro maior só tiver como
 *                              seno parent de do segundo maior e do maior ?
 *                              .... acho que é DP então (tá marcado como
greedy)

 *              Acho que o terceiro caso já tá dentro do segundo...
 *                      Traduz pra :    "Não tenho nenhum second_greater
 *                                      que não seja pai do greater"
 *
 * Remover pode ser literalmente remover o nó e forçar o
 * próximo maior valor
 *
 * ? Porque o peso de cada um vai até N e não 10^9 ???
 * Da pra pegar uma posição qualquer em O(1)
 *
 * Small to large ?
 *
 * Acho que não rola um guloso assim
 *
 * Olhando pra dfs order da pra fazer algo ??
 *
 * X-ésimo maior....
 *
 * Se eu tenho um valor X, e ele contém os todos os valores de X+1,
 * Então quando eu remover esse X em específico eu preciso ir pro X+2...
 *
 * AC, greedy, data structures, dfs and similar, trees
>8*/
