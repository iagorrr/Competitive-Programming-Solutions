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

void run() {
        int N;
        cin >> N;

        vll AS(N);
        cin >> AS;

        vll final_hist(N + 1), cur_hist(N + 1);
        trav(ai, AS) final_hist[ai]++;

        vi is_single(N);
        rep(i, 0, N) { is_single[i] = (final_hist[AS[i]] == 1); }
        partial_sum(all(is_single), begin(is_single));

        pii ans{-1, -1};
        int ans_sz = 0;
        rep(l, 0, N) {
                auto r = maxCheck(l, N - 1, [&](int x) {
                        int sz = x - l + 1;
                        int tot_single =
                                is_single[x] - (l ? is_single[l - 1] : 0);
                        return sz == tot_single;
                });
                if (r) {
                        int cur_sz = *r - l + 1;
                        if (cur_sz > ans_sz) {
                                ans = {l + 1, *r + 1};
                                ans_sz = cur_sz;
                        }
                }
        }

        if (ans.first == -1) {
                cout << 0 << endl;
        } else
                cout << ans.first << ' ' << ans.second << endl;
}

/*8<
 * remover um subarray equivale a :
 *      - subtrarir da resposta o size dele
 *      - incrementar na resposta a quantidade de elementos
 *      distintos
 *      - no desempate quero um que remova mais elementos
 *
 * se to analisando reomver a partir da posicao i
 * é -1 -1 -1 -1 -1  acumulado
 * mas toda vez que aparece um distinto é++
 *
 * mas tem que considerar as costas...

nao é monotonico

2 1 3 2
0 0 0 1

- deixar o máximo de elementos iguais tbm...
-

sempre vai ser um segmento de valores únicos...
pq vou estar deixando na resposta só valores repetidos...

se aparecer um elemento que ele já tava na array final
significa que dei -- na resposta

a resposta nunca aumenta né


então a pergunta é
qual o maior subarray que consigo remover
tal que todos os elementos que estão ali só estão ali


two pointers safado

AC, binary search, prefix sums, greedy

>8*/
