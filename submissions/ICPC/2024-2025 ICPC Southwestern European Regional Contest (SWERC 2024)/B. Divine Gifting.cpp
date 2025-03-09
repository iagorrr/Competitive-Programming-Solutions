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

template <typename T>        // print vector
ostream &operator<<(ostream &os, vector<T> &xs) {
        rep(i, os.iword(0), xs.size()) os << xs[i]
                                          << (i == xs.size() ? "" : " ");
        os.iword(0) = 0;
        return os;
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

        rep(t, 0, T) {
                dbg(t);
                run();
        }
}

const int MAXN = 5'000 + 1;
const int MAXK = 20 + 1;

ll memo[MAXN][MAXK];
int trans[MAXN][MAXK];

void run() {
        rep(i, 0, MAXN) rep(j, 0, MAXK) memo[i][j] = -1;

        int N, K;
        cin >> N >> K;

        vector<pll> XS(N);
        rep(i, 0, N) {
                cin >> XS[i].first;
                XS[i].second = i;
        }

        sort(all(XS));

        const ll inf = 1e16;
        function<ll(int, int)> solve = [&](int r, int k) {
                if (r < 0) return 0ll;

                auto &ret = memo[r][k];
                if (~ret) return ret;

                ll ans = inf;
                ll acc = 0;
                if (k == K) {
                        rep(i, 0, r) {
                                ll dt = XS[r].first - XS[i].first;
                                dt *= dt;
                                acc += dt;
                        }
                        ans = acc;
                } else {
                        rep(sz, k == K ? r : 0, r + 1) {
                                ll dt = XS[r].first - XS[r - sz].first;
                                dt *= dt;
                                acc += dt;

                                if (chmin(ans,
                                          acc + solve(r - sz - 1, k + 1))) {
                                        trans[r][k] = r - sz;
                                }
                        }
                }
                return ret = ans;
        };

        ll mx_cost = solve(N - 1, 1);

        dbg(mx_cost);

        vll tmp_ans(N, -1);
        int r = N - 1, k = 1;
        tmp_ans[N - 1] = N - 1;
        rrep(i, N - 1, 0 - 1) {
                dbg(i, r);
                if (~tmp_ans[i]) {
                        int l = trans[i][k];
                        if (l) tmp_ans[l - 1] = l - 1;
                        r = i;
                        k++;
                }

                tmp_ans[i] = r;
        }
        dbg(tmp_ans);

        vll ans(N);
        rep(i, 0, N) {
                int r = tmp_ans[i];
                ans[XS[i].second] = XS[r].first;
        }

        cout << ans << endl;
}

/*8<
 * Sort the items by date
 *
 * essentially we want to split these items in atmost
 * K continous segments
 *
 * and for each segment the items will be delivered at
 * the day of the highest element
 *
 * Some dp approach ?
 *
 * But recover the days of each one is a pain
 *
 * Maybe after sorting we can go through an greedy approach ?
 *
 * is possible to brute force ?
 *
 * bar ans stars on the segments
 *
 * N choose K
 * absurdly large
 *
 * ok
 *
 * DP and recover later...
 * F(i, k) estou no item i, e já coloquei k pausinhos
 * a transição fica O(N) pra escolher onde vou colocar
 * esse próximo pauxinho
 *
 * então no pior no pior dos casos tá quadrático isso aqui
 * assumindo que eu consiga somar rápido né.
 *
 * exmplo:
 *
 * 5 2
        50 0 51 10 50

 * some min cost flow ?
 * for each node i just need to choose which one will be
 * his right most node..
 *
 * that quickly sum is bad
 *
 * probably better do some quadratic in states
 *
 *
 * dp(i,j,k)
 *
 * process backwards
 *
 * susspose that i is the right most of the current segment
 * and i'm current anlalyzing what to do with the j-th element
 * and i have k segments already
 *
 * two options
 *
 * let j be in the same segment as i
 *
 * or create a new segment for j (if possible)
 *
 * at the end just take the best transitions...
 *
 * answer will be f(N,N-1,1)
 *
 * transition in O(1)
 *
 * 5*000*5*000*20
 * 25 * 10^6 * 20
 * 2 * 25 * 10^7
 * 50 * 10^7
 * 5 * 10^8
 *
 * apertado demaiiis
 *
 * oia so
 *
 * 5 segudnso cravado
 *
 * bo tentar
 *
 * mas deve precisar se iterativo né
 *
 * desse jeito aqui
 *
 * ooo lasqueira da porra
 *
 * bora pelo menos tentar recursivo
 *
 * e pra recuperar ?
 *
 * just do the bott
 * one observation is that the N-th element will be the right most of his
segment...
 *
 *

 * muita memória, coloca isso pra transição mesmo
 *
 * AC, dp
>8*/
