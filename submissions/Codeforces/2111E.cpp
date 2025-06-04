#pragma once
/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>

#include <algorithm>
#include <iterator>
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
        int n, m;
        cin >> n >> m;

        string s;
        cin >> s;

        map<pii, set<int>> mp;
        rep(i, 0, m) {
                char u, v;
                cin >> u >> v;
                mp[{u - 'a', v - 'a'}].insert(i);
        }

        vi as(n);
        transform(all(s), begin(as), [](char c) { return c - 'a'; });

        /*
         * 3 - > 1
         * 3 -> 2 -> 1
         * 3 -> 2
         *
         * 2 -> 1
         * 2 -> 3 -> 1
         */
        auto ok = [&](vi lst) {
                int min_idx = -1;
                rep(i, 0, len(lst) - 1) {
                        int u = lst[i], v = lst[i + 1];
                        auto it = mp[{u, v}].lower_bound(min_idx);

                        if (it == end(mp[{u, v}])) return false;

                        min_idx = *it;
                }
                return true;
        };

        auto rm = [&](vi lst) {
                int min_idx = -1;
                rep(i, 0, len(lst) - 1) {
                        int u = lst[i], v = lst[i + 1];
                        auto it = mp[{u, v}].lower_bound(min_idx);

                        if (it == end(mp[{u, v}])) return false;

                        min_idx = *it;

                        mp[{u, v}].erase(it);
                }
                return true;
        };

        string ans;
        trav(ai, as) {
                dbg(mp, ai);
                if (ai == 2) {
                        auto c1 = vi{2, 0};
                        auto c2 = vi{2, 1, 0};
                        auto c3 = vi{2, 1};

                        if (ok(c1)) {
                                rm(c1);
                                ai = 0;
                        } else if (ok(c2)) {
                                rm(c2);
                                ai = 0;
                        } else if (ok(c3)) {
                                rm(c3);
                                ai = 1;
                        }
                } else if (ai == 1) {
                        auto c1 = vi{1, 0};
                        auto c2 = vi{1, 2, 0};
                        if (ok(c1)) {
                                rm(c1);
                                ai = 0;
                        } else if (ok(c2)) {
                                rm(c2);
                                ai = 0;
                        }
                }
                dbg(ai);
                ans.pb(char(ai + 'a'));
        }

        cout << ans << endl;
}

/*8<
 * um único path pra um char menor que o as[i] é só pegar
 *
 * se tiver mais de um, qual é o melhor ?
 *
 *
 * 3 - > 1
 * 3 -> 2 -> 1
 * 3 -> 2
 *
 * 2 -> 1
 * 2 -> 3 -> 1
 *
 *
 * a ordem em que as queries são dadas importa duh
 *
 * entao pra fazer as queries de "ordem 1", é de boa, só precisa estar com o
char
 * mas pra fazer as de ordem 2 tipo b-> c, c-> a, eu preciso necessariamente
 * que exista uma query to tipo (b, c) que apareça antes do tipo (c, a)
 * a gente pode manter uma estrutura com as queries, e ao invés da gente
simplesmente
 * ver se tem, precisa na verdade ver se tem an ordem (pras de ordem 2)
 *
 * valida essa ideia com um tle, e ai a gente queima uns neorônios

 * da pra otimizar fácill , guardando as queris de cada tipoe e fazendo um lower
bound no index delas...

 * 3 - > 1
 * 3 -> 2 -> 1
 * 3 -> 2
 *
 * 2 -> 1
 * 2 -> 3 -> 1
 *
 *
 * essa ordem tá quebrada, acho que precisa pegar de alguma que tem mais
 *
 * se fizermos 2->1, e la na frenteter
 *
 * tava remoendo antes de ver se opath é fazível até o fim :P
 *
 * AC, greedy, data structures :))

>8*/
