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

        vector<string> S(2);
        cin >> S[0];
        cin >> S[1];

        S[0].pb('#'), S[1].pb('#');

        vector memo(N, vector(2, vector(2, -1)));
        function<int(int, bool, bool)> solve = [&](int idx, bool up,
                                                   bool down) {
                if (idx == N) return 1;

                auto &ret = memo[idx][up][down];
                if (~ret) return ret;

                bool up2 = S[0][idx + 1] == '.';
                bool down2 = S[1][idx + 1] == '.';

                int tot = 0;

                // hori up
                tot += (up and up2 and !down) * solve(idx + 1, false, down2);

                // hori down
                tot += (down and down2 and !up) * solve(idx + 1, up2, false);

                // both hori
                tot += (up and down and up2 and down2) *
                       solve(idx + 1, false, false);

                // vert
                tot += (up and down) * solve(idx + 1, up2, down2);

                // nothing meu fi
                tot += (!up and !down) * solve(idx + 1, up2, down2);

                tot = min(tot, 2);

                return ret = tot;
        };

        int ans = solve(0, S[0][0] == '.', S[1][0] == '.');

        cout << vector<string>{"None", "Unique", "Multiple"}[ans] << endl;
}

/*8<
 * if you have a 2x2 with no restrictions
 * then it can be like --       ||
 *                     --  or   ||
 *
 *
 *
 *
4





10
#----.--##
##--#.##--

no 2x2 at the end ony one way

and no 1x1 so is not none

is unique !


6
...#..
..#...
8
........
........
3
###
###

AC, dynamic programming
>8*/
