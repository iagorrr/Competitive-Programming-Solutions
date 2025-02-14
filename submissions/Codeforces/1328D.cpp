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

void run() {
        int N;
        cin >> N;

        vll AS(N);
        cin >> AS;

        int distinct = len(set<ll>(all(AS)));
        vi ans(N);

        if (distinct == 1) {
                fill(all(ans), 1);
        } else {
                rep(i, 0, N) ans[i] = (i & 1) + 1;

                int eqs = 0;
                rep(i, 0, N) { eqs += (AS[i] == AS[(i + 1) % N]); }

                if ((N & 1)) {
                        if (eqs) {
                                bool done = false;
                                rep(i, 0, N) {
                                        ans[i] = i ? (ans[i - 1] & 1) + 1 : 1;
                                        if (!done and
                                            AS[i] == AS[(i + 1) % N]) {
                                                ans[(i + 1) % N] = ans[i];
                                                done = true;
                                                i++;
                                        }
                                }
                        } else
                                ans.back() = 3;
                }
        }

        cout << *max_element(all(ans)) << endl;

        rep(i, 0, N) cout << ans[i] << ' ';
        cout << endl;
}
/*8<
 * tudo 1 se só tem um tipo
 * alterna entre 1 e 2 se for quantidade par
 *
 * se for impar :
 *      tem algum com dois seguidos iguais seguidos
 *      faz eles dois serem iguais e dps continua
 *
 *      cc:
 *              alterna entre 1 e 2 e o último vai ser 3
 *
*              lê a porra do problema !
*
* AC, ad-hoc
>8*/
