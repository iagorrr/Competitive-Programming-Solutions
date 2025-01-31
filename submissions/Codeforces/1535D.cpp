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

        rep(t, 0, T) {
                dbg(t);
                run();
        }
}

int brute(const string S, int K) {
        vector<string> per_level(K);
        int p = 0;
        rrep(i, K - 1, 0 - 1) {
                rep(j, 0, (1 << i)) per_level[K - i - 1].pb(S[p++]);
        }

        vector<vector<vector<int>>> matches(K + 1);

        rep(i, 0, (1 << K)) { matches[0].pb({i}); }

        rep(i, 0, K) {
                rep(j, 0, len(per_level[i])) {
                        auto winner = per_level[i][j];
                        matches[i + 1].pb({});

                        if (winner == '0' or winner == '?')
                                matches[i + 1].back().insert(
                                        end(matches[i + 1].back()),
                                        all(matches[i][j * 2]));
                        if (winner == '1' or winner == '?')
                                matches[i + 1].back().insert(
                                        end(matches[i + 1].back()),
                                        all(matches[i][j * 2 + 1]));
                }
        }
        return len(matches.back().back());
}

void run() {
        int K;
        cin >> K;

        string S;
        cin >> S;
        S = "^" + S;

        vi ab(len(S)), ba(len(S));
        {
                vi2d aux(K);
                aux[0] = vi{1};
                rep(i, 0, K - 1) {
                        trav(j, aux[i]) {
                                aux[i + 1].eb(2 * j);
                                aux[i + 1].eb(2 * j + 1);
                        }
                }

                dbg(aux);
                vi aux2 = {0};
                rtrav(i, aux) { aux2.insert(end(aux2), all(i)); }
                dbg(aux2);
                ab = aux2;

                rep(i, 0, len(ab)) { ba[ab[i]] = i; }
        }
        dbg(ab, ba);

        int N = (1 << K);
        vi sz(2 * len(S) + 1, 1);
        rrep(i, N - 1, 1 - 1) {
                sz[i] = 0;
                int idx = ba[i];
                char winner = S[idx];
                if (winner == '1' or winner == '?') sz[i] += sz[i * 2 + 1];
                if (winner == '0' or winner == '?') sz[i] += sz[i * 2];
                dbg(i, sz[i]);
        }

        auto upd = [&](int i) {
                while (i) {
                        sz[i] = 0;
                        int idx = ba[i];
                        char winner = S[idx];
                        if (winner == '1' or winner == '?')
                                sz[i] += sz[i * 2 + 1];
                        if (winner == '0' or winner == '?') sz[i] += sz[i * 2];
                        i >>= 1;
                }
        };

        int Q;
        cin >> Q;
        while (Q--) {
                int p;
                char c;
                cin >> p >> c;
                S[p] = c;
                upd(ab[p]);
                cout << sz[1] << endl;
        }
}

/*8<
 * calcula o f(s) original
 *
 * contador pra cada game pra quantos da esquerda que chegaram no final
 * e quantos da direita tbm
 *
 *
 * quando seta uma resposta só decrementa e incrementa de acordo
 * com as mudanças
 *
 3
0110?11
6
6 ?
7 ?
1 ?
5 ?
1 1

ans:

* não mudou a respota
0110?11
5 1
0110111
1

0110?11
6 ?
2
3
3
5
4

as operações permanecem na sring

AC, data structures, implementation, trees
>8*/
