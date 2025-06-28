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

// read vector
// TODO: abstract this to any container.
template <typename T>
std::istream &operator>>(std::istream &is, std::vector<T> &vec) {
        for (auto &element : vec) {
                is >> element;
        }
        return is;
}

// print vector
// TODO: abstract this to any container.
template <typename T>
ostream &operator<<(ostream &os, vector<T> &xs) {
        rep(i, os.iword(0), xs.size()) os << xs[i]
                                          << (i == xs.size() ? "" : " ");
        os.iword(0) = 0;
        return os;
}

// sum a vector, using the default constructor as initial value
// TODO: abstract this to any container.
template <typename T>
T sumList(vector<T> &xs) {
        return accumulate(all(xs), T());
}

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
 * */

void __init() {}

void __pre_run() {}

const str yes = "YES";
const str no = "NO";

#define loop while (1)

str solve(ll a, const vll &ps, const vll &ds, ll k) {
        int n = len(ps);

        vi2d vis(2, vi(n + 1));
        int dir = 1;
        ll t = 0;

        int idx = -1;
        // talvez já comece em cima de algum.
        {
                auto it = lower_bound(all(ps), a);
                if (it != end(ps) and *it == a) {
                        idx = it - begin(ps);
                }
        }

        while (a > 0 and a <= 1e15) {
                dbg(idx, t, a);

                // may turn around
                if (~idx and t % k == ds[idx]) {
                        if (vis[dir][idx]) return no;
                        vis[dir][idx] = 1;
                        dir ^= 1;
                }

                // advance to the closest one
                if (dir) {
                        // primeiro maior que a
                        auto it = lower_bound(all(ps), a + 1);

                        if (it == end(ps)) break;

                        // ver quanto andou e incrementar
                        ll dt = *it - a;
                        t += dt;

                        // mover de fato
                        a = *it;

                        idx = it - begin(ps);

                } else {
                        // ultimo maior que a
                        auto it = lower_bound(all(ps), a);
                        if (it == begin(ps)) break;
                        it = prev(it);

                        ll dt = a - *it;
                        t += dt;
                        a = *it;

                        idx = it - begin(ps);
                }
        }

        return yes;
}

void __run() {
        ll n, k;
        cin >> n >> k;

        vll ps(n);
        cin >> ps;

        vll ds(n);
        cin >> ds;

        ll q;
        cin >> q;

        while (q--) {
                ll pi;
                cin >> pi;

                cout << solve(pi, ps, ds, k) << endl;
        }
}

/*8<
* red at : di, k + di, 2k + di...
* resto tuod green

é simulavel

mas quando sei a hora de parar ???
se eu visitar algum que ja visitei né ??

pq nesse ciclo dali pra frente é previsiǘel ??

se tem ciclo é vapo né ?

acho que é.

acho que to errado pra krai

pode visitar o mesmo sim desde que não seja na mesma dieração.

a gente pode passar mais uma vez por um cara, o ponto é que não pode bater nele
mais de uma vez... na mesma diereção. eu acho

caso de borda quando já começa em cima de um cara...

tava certo kk

AC
>8*/
