/*
...

- This is just a knapsack on trees !
- Build the Trie with the strings, and them compute how many nicknames there is
in each sub tree
- Don't make sense to take a node and some ancestor of it only the ancestor
so just stop at the ancestor
- Sum of lengths don't exceed 10^5
- 10^4 strings, but what matters is the amount of nodes, right ? so 10^5, k < n
< 10^4
- Can i make something like dp(i, m) = minimum to sum N considering only nodes
of the subtree of i.
- this overflwos in memory, but we can condensate the trie later i guess, how do
i code this simple version
- i can count how many words end at each node of the trie easily

...
 */
#pragma once
/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>

#include <algorithm>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define all(j) j.begin(), j.end()
#define found(x, y) ((x).find((y)) != (x).end())
#define rall(j) j.rbegin(), j.rend()
#define len(j) (int)j.size()
#define rep(i, a, b) \
    for (common_type_t<decltype(a), decltype(b)> i = (a); i < (b); i++)
#define rrep(i, a, b) \
    for (common_type_t<decltype(a), decltype(b)> i = (a); i > (b); i--)
#define repn(i, b) for (auto i = 0; i < (b); i++)
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) for (auto &xi : ranges::views::reverse(xs))
#define loop while (1)
#define iter(x) repn(__, x)
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
using vpll = vector<pll>;
using vc = vector<char>;
using vs = vector<str>;

#define TT template <typename T>
#define TTU template <typename T, typename U>

TTU using umap = unordered_map<T, U>;
TT using uset = unordered_set<T>;
TT using pqmn = priority_queue<T, vector<T>, greater<T>>;
TT using pqmx = priority_queue<T, vector<T>>;

TTU inline bool chmax(T &a, U const &b) { return (a < b ? a = b, 1 : 0); }
TTU inline bool chmin(T &a, U const &b) { return (a > b ? a = b, 1 : 0); }

// read vector
// TODO: abstract this to any container.
TT std::istream &operator>>(std::istream &is, std::vector<T> &vec) {
    for (auto &element : vec) {
        is >> element;
    }
    return is;
}

// print vector
// TODO: abstract this to any container.
TT ostream &operator<<(ostream &os, vector<T> &xs) {
    rep(i, os.iword(0), xs.size()) os << xs[i] << (i == xs.size() ? "" : " ");
    os.iword(0) = 0;
    return os;
}

// print pair
TTU ostream &operator<<(ostream &os, pair<T, U> &p) {
    os << p.first << " " << p.second;
    return os;
}

// read pair
TTU std::istream &operator>>(std::istream &is, pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
}

// print multiset
// TODO: abstract this to any container.
TT ostream &operator<<(ostream &os, multiset<T> &xs) {
    for (auto it = xs.begin(); it != xs.end(); it++)
        os << *it << (next(it) == end(xs) ? "" : " ");
    return os;
}

// sum a vector, using the default constructor as initial value
// TODO: abstract this to any container.
TT T sumList(vector<T> &xs) { return accumulate(all(xs), T()); }

/*
 * verify if a `predicate` is valid for
 * values in range [l, r]
 *
 * TODO: put a type in predicate ??
 * */
// bool all_of_in_range(T l, T r, auto predicate) {
//     return ranges::all_of(views::iota(l, r + 1),
//                           [&](T v) { return predicate(v); });
// }

// checks if a  value v is the interval [l, r]
TT bool inline between(T v, T l, T r) { return clamp(v, l, r) == v; }

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
 *
 * */

void __init() {}

void __pre_run() {}
/*8<
@Tittle: Trie

@Description:
        \begin{compactitem}
                \item build with the size of the alphabet
                $(sigma)$ and the first char $(norm)$

                \item $insert(s)$ insert the string in the trie
                $O(|s|*sigma)$

                \item $erase(s)$ remove the string from the trie $O(|s|)$

                \item $find(s)$ return the last node from the
                string s, 0 if not found $O(|s|)$
        \end{compactitem}

@Warnings:
Be careful when saving some information for each node, save as you
access the node to don't miss the firs or last node >8*/

struct Trie {
    vi2d to;
    vi end, pref;
    int sigma;
    char norm;

    Trie(int sigma_ = 'z' - 'a' + 1, char norm_ = 'a')
        : sigma(sigma_), norm(norm_) {
        to = {vector<int>(sigma)};
        end = {0}, pref = {0};
    }

    int next(int node, char key) { return to[node][key - norm]; }

    void insert(const string &s) {
        int x = 0;
        for (auto c : s) {
            int &nxt = to[x][c - norm];
            if (!nxt) {
                nxt = len(to);
                to.push_back(vi(sigma));
                end.emplace_back(0), pref.emplace_back(0);
            }
            x = nxt, pref[x]++;
        }
        end[x]++, pref[0]++;
    }

    void erase(const string &s) {
        int x = 0;
        for (char c : s) {
            int &nxt = to[x][c - norm];
            x = nxt, pref[x]--;
            if (!pref[x]) nxt = 0;
        }
        end[x]--, pref[0]--;
    }

    int find(const string &s) {
        int x = 0;
        for (auto c : s) {
            x = to[x][c - norm];
            if (!x) return 0;
        }
        return x;
    }

    pair<vi2d, vi> compress() {
        vi2d compAdj;
        vi compEnd;

        auto dfs = [&](auto &self, int u, int lastValid) -> void {
            int adjCnt = 0;
            for (int v : to[u]) adjCnt += v != 0;

            bool isValid = (u == 0) or (adjCnt > 1) || (end[u] > 0);

            int currentValid = lastValid;

            if (isValid) {
                int newId = len(compAdj);
                compAdj.pb(vi());
                compEnd.pb(pref[u]);

                if (lastValid != -1) {
                    compAdj[lastValid].pb(newId);
                }
                currentValid = newId;
            }

            for (int v : to[u])
                if (v != 0) {
                    self(self, v, currentValid);
                }
        };

        dfs(dfs, 0, -1);
        return {compAdj, compEnd};
    }
};

const int oo = 1e9;

int treeKnapsack(const vector<vector<int>> &adj, const vector<int> &weightOf,
                 int K, int root) {
    auto dfs = [&](auto &self, int u) -> vector<int> {
        vector<int> dp = {0};

        for (int v : adj[u]) {
            vector<int> vDp = self(self, v);

            int lU = min(K, (int)dp.size() - 1);
            int lV = min(K, (int)vDp.size() - 1);
            int newSz = min(K, lU + lV) + 1;

            vector<int> newDp(newSz, oo);

            for (int wU = 0; wU <= lU; wU++) {
                if (dp[wU] == oo) continue;
                for (int wV = 0; wV <= lV; wV++) {
                    if (vDp[wV] == oo) continue;

                    if (wU + wV < newSz) {
                        newDp[wU + wV] = min(newDp[wU + wV], dp[wU] + vDp[wV]);
                    }
                }
            }
            dp = move(newDp);
        }

        int totalW = weightOf[u];

        int reqSize = min(K, totalW) + 1;
        dp.resize(reqSize, oo);

        if (totalW < dp.size()) {
            dp[totalW] = 1;
        }

        return dp;
    };

    vector<int> ans = dfs(dfs, root);

    if (ans.size() <= K or ans[K] >= oo) return -1;

    return ans[K];
}

void __run() {
    int n, k;
    cin >> n >> k;
    vs ss(n);
    cin >> ss;

    Trie trie;
    trav(si, ss) trie.insert(si);

    auto [adj, ws] = trie.compress();
    auto ans = treeKnapsack(adj, ws, k, 0);
    assert(ans != -1);
    cout << ans << endl;
}

/*8<
>8*/
