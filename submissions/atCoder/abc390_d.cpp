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

void process_all_sorted_partitions(int tot_size, function<void(const vi &)> f) {
        vi sizes;
        function<void(int, int)> dfs = [&](int prev_size, int cur_sum) {
                if (cur_sum == tot_size) {
                        f(sizes);
                        return;
                }
                for (int inc = 0; prev_size + inc + cur_sum <= tot_size;
                     inc++) {
                        sizes.eb(prev_size + inc);
                        dfs(prev_size + inc, cur_sum + prev_size + inc);
                        sizes.ppb();
                }
        };
        dfs(1, 0);
}

void process_all_partitions_of_a_set(
        const int N, const function<void(const vi2d &)> process) {
        vi2d groups;
        groups.reserve(N);

        function<void(int)> _dfs = [&](int idx) {
                if (idx == N) {
                        process(groups);
                        return;
                }

                rep(i, 0, len(groups)) {
                        groups[i].eb(idx);
                        _dfs(idx + 1);
                        groups[i].ppb();
                }

                groups.pb({idx});
                _dfs(idx + 1);
                groups.ppb();
        };
        _dfs(0);
}

void run() {
        int N;
        cin >> N;

        vll AS(N);
        trav(ai, AS) cin >> ai;

        unordered_set<ll> ans;

        process_all_partitions_of_a_set(len(AS), [&](const vi2d &groups) {
                dbg(groups);
                ll full_xor = 0;
                for (auto &group : groups) {
                        ll s = 0;
                        trav(i, group) { s += AS[i]; }
                        full_xor ^= s;
                        dbg(s);
                }
                ans.insert(full_xor);
        });

        dbg(ans);
        cout << len(ans) << endl;
}

/*8<
 * if you sum two numbers A1 and A2
 *
 * suppose
 *
 * 0  0         1
 * 1  1         1
 * 1  0 ->      0
 * 1  1         0
 * 0  0         0
 *
 * vai dando carry nos bits ...
 *
 * N = 12
 *
 * posso estraçalar 2^todos nékkkkk
 *
 * bell number pocando só brutar tudo kkkk
 *
 * combinatorics, bell number, brute force
>8*/
