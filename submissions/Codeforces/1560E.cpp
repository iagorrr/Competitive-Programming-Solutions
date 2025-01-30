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
        string S;
        cin >> S;

        int N = len(S);

        vi found('z' - 'a' + 1);
        string removal_order;
        rrep(i, N - 1, 0 - 1) {
                int c = S[i] - 'a';
                if (!found[c]) removal_order.pb(S[i]);
                found[c] = 1;
        }

        reverse(all(removal_order));
        dbg(removal_order);

        if (len(removal_order) == 1) {
                cout << S << ' ' << S.back() << endl;
                return;
        }

        ll times_N = len(removal_order);
        vll coef('z' - 'a' + 1);
        rep(i, 0, len(removal_order)) {
                int c = removal_order[i] - 'a';
                coef[c] = times_N - i - 1;
        }

        vi candidates_sizes;
        int l = S.find_last_of(removal_order.front());
        int r = S.find_last_of(removal_order[1]);
        dbg(l, r);

        ll eq = (l)*times_N;
        rep(i, 0, l) { eq -= coef[S[i] - 'a']; }
        dbg(eq);

        rep(i, l, r + 1) {
                eq -= coef[S[i] - 'a'];
                eq += times_N;
                dbg(i, eq);
                if (eq == N) {
                        candidates_sizes.eb(i + 1);
                }
        }

        dbg(candidates_sizes);
        if (!len(candidates_sizes)) {
                cout << -1 << endl;
                return;
        }

        int ans_sz = candidates_sizes.back();
        bool ok = true;
        string os = S.substr(0, ans_sz);
        int p = 0;
        vi removed('z' - 'a' + 1);
        trav(c, removal_order) {
                ok &= S.substr(p, len(os)) == os;
                p += len(os);
                removed[c - 'a'] = 1;
                string os2;
                trav(c2, os) {
                        if (!removed[c2 - 'a']) {
                                os2.pb(c2);
                        }
                }
                swap(os2, os);
        }

        if (!ok) {
                cout << -1 << endl;
                return;
        }

        cout << S.substr(0, candidates_sizes.back()) << ' ' << removal_order
             << endl;
}

/*8<
 * o
abacabaaacaac
     3     21

BAC

o o
abacabaaacaac nao pode ser aqui...
     ^


aqui ja pode, então a gente já achou  o size da string...
mas tá N^2 ?
abacaba a*aca*a c
      ^

a ordem de remoção é izi n ?

eh sim, só pegar a ordem que aparece de trás pra
frente.

sz = 13
N -> N - #B -> N - #B - #A

N + (N - #B) + (N - #B - #A) = 13
3*N - 2 #B - #A = 13
abacabaaacaa c
         ^
chutar N = 5 a gnet já ganha a qtd de cada char né, mas n pode ser 5 tbm...
tem que ser >= a ultima aparição do primiero
N = 6, #B = 2, #A = 3, #c = 1
3 * 6 - 2*2 - 3 = 18 - 4 - 3 = 11 fail
baratin checar né 26 char só, O(1), na real só torar o coeficiente...
N = 7, #B = 2, #A = 4, #C = 1
3*7 - 2*2 - 4 = 21 - 4 - 4 = 13
vapo
esse tamanho é matematicamente possível
mas só isso basta ?
acho que no

desconsideramos a ordem...



ABCDEFG

N
N - #A
N - #A - #B
N - #A - #B - #C
N - #A - #B - #C - #D
...

AC, strings, math
>8*/
