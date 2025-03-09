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

template <typename T>
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

void run() {
        int N;
        cin >> N;

        map<ll, vll> per_x;
        vll y0;
        vector<pll> PTS(N);
        ll min_x = LLONG_MAX;
        ll max_x = -1;
        for (auto &[x, y] : PTS) {
                cin >> x >> y;

                per_x[x].eb(y);

                if (y == 1) y0.eb(x);

                chmin(min_x, x);
                chmax(max_x, x);
        }

        set<pll> in_ans;
        vector<pll> ans;

        ll min_x_put = LLONG_MAX;
        ll max_x_put = -1;
        auto add_to_ans = [&](pll x) {
                if (in_ans.count(x)) return;
                in_ans.insert(x);
                ans.eb(x);
                chmax(max_x_put, x.first);
                chmin(min_x_put, x.first);
        };

        ll previousX = min_x - 1;
        bool right = true;

        if (min_x != 1 and max_x == 1'000'000'000) right = false;

        bool first_right = right;

        for (auto &[x, ys] : per_x) {
                sort(all(ys));
                if (previousX + 1 != x and right) {
                        right = false;
                }
                dbg(right);

                if (right) {
                        if (x != min_x) add_to_ans({x, 2});
                        trav(y, ys) {
                                if (y != 1) add_to_ans({x, y});
                        }
                        add_to_ans({x + 1, 2});

                } else {
                        add_to_ans({x - 1, 2});
                        rtrav(y, ys) {
                                if (y != 1) add_to_ans({x, y});
                        }
                        if (first_right or x != max_x) add_to_ans({x, 2});
                }

                previousX = x;
        }

        if (first_right)
                y0.eb(min_x);
        else
                y0.eb(max_x);

        sort(rall(y0));
        trav(x, y0) { add_to_ans({x, 1}); }

        cout << len(ans) << endl;
        for (auto &[x, y] : ans) {
                cout << x << ' ' << y << endl;
        }
}

/*8<
 * da pra decidir o ponto de quebra
 * e quais as translocações ?
 *
 * e como faz esse shape de "contornar ?"
 * meio que reduzir o plígono um cadin
 *
 * nada
 *
 * é bem mais trivial que isso...
 *
 * o ultimo tem que vir pra dentro
 *
 * pelo principio da casa dos pombos vai ter uma
 * posicao vazia
 * a partir dela a gente faz os opntos virarem pra esquerda
 *
 * pra não fazer o 10^9 + 1
 *
 * xablau
 *
 * AC, implementation, geometry
>8*/
