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

const int MAXAI = 26;

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
        trav(ai, AS) cin >> ai;

        vll2d psum(MAXAI + 1, vll(N));
        psum[AS[0]][0] = 1;
        rep(j, 1, MAXAI + 1) {
                rep(i, 1, N) { psum[j][i] = psum[j][i - 1] + (AS[i] == j); }
        }

        vll2d ssum(MAXAI + 1, vll(N));
        ssum[AS.back()].back() = 1;
        rep(j, 1, MAXAI + 1) {
                rrep(i, N - 2, 0 - 1) {
                        ssum[j][i] = ssum[j][i + 1] + (AS[i] == j);
                }
        }

        dbg(psum[1]);
        dbg(ssum[1]);

        ll ans = 1;
        rep(j, 1, MAXAI + 1) {
                ll jmx = 0;
                rep(sz, 0, N / 2 + 1) {
                        auto l = minCheck(0, N - 1, [&](int m) {
                                return psum[j][m] >= sz;
                        });
                        auto r = maxCheck(0, N - 1, [&](int m) {
                                return ssum[j][m] >= sz;
                        });
                        if (!l or !r) continue;
                        if (*l > *r) continue;
                        if (*l == *r) {
                                chmax(ans, 1);
                                continue;
                        }
                        dbg(j, sz, *l, *r);

                        ll qtdMid = 0;

                        rep(k, 1, MAXAI + 1) {
                                ll qtd = (*r ? psum[k][*r - 1] : 0) -
                                         (*l < N ? psum[k][*l] : 0);
                                chmax(qtdMid, qtd);
                        }

                        chmax(jmx, sz * 2 + qtdMid);
                }
                dbg(j, jmx);
                chmax(ans, jmx);
        }

        cout << ans << endl;
}

/*8<
 * AC, binary search, prefix sums, brute force
>8*/
