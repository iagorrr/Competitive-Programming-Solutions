/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>

#include <cinttypes>
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

#define TT template <typename T>
#define TTU template <typename T, typename U>

TTU using umap = unordered_map<T, U>;
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

    // cin >> T;

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

ll f(vll &xs) {
    ll ret = 0;
    for (auto &xi : xs) {
        ret *= 10ll;
        ret += xi;
    }
    return ret;
}
void __run() {
    // read
    int n;
    cin >> n;
    vll xs(n);
    cin >> xs;

    // perform the operation
    vector<pll> ans;
    auto op = [&](int i, int j) -> void {
        if (i == j) return;

        int a = xs[i];
        int b = xs[i + 1];
        int c = xs[i + 2];

        int d = xs[j];

        xs.erase(find(all(xs), a));
        xs.erase(find(all(xs), b));
        xs.erase(find(all(xs), c));

        xs.insert(find(all(xs), d), a);
        xs.insert(find(all(xs), d), b);
        xs.insert(find(all(xs), d), c);

        ans.eb(i, find(all(xs), a) - begin(xs));
    };

    auto op2 = [&](int i, int j, vll vec) -> vll {
        int a = vec[i];
        int b = vec[i + 1];
        int c = vec[i + 2];

        int d = vec[j];

        vec.erase(find(all(vec), a));
        vec.erase(find(all(vec), b));
        vec.erase(find(all(vec), c));

        vec.insert(find(all(vec), d), a);
        vec.insert(find(all(vec), d), b);
        vec.insert(find(all(vec), d), c);

        return vec;
    };

    // greedy
    int cur = n;
    while (cur >= 6) {
        int pos = find(all(xs), cur) - begin(xs);

        if (pos == 0) {
            op(1, 0);
        } else if (pos == 1) {
            op(2, 0);
        } else {
            op(pos - 2, cur);
            cur--;
        }
    }

    // brute
    xs.resize(min(len(xs), 5));
    vll sorted(all(xs));
    sort(all(sorted));
    dbg(sorted);
    set<ll> vis;
    vis.insert(f(xs));
    vector<pll> steps;
    bool done = false;
    auto brute = [&](auto &&self, vll ys) -> void {
        dbg(ys);
        if (ys == sorted) {
            for (auto x : steps) ans.eb(x);
            done = true;
            return;
        }

        repn(i, len(ys)) {
            if (i + 2 >= len(ys)) break;
            repn(j, len(ys)) {
                if (j == i or j == i + 1 or j == i + 2 or j == i + 3) continue;
                auto ys2 = op2(i, j, ys);
                if (!vis.count(f(ys2))) {
                    vis.insert(f(ys2));
                    int x = ys[i];
                    steps.eb(i, find(all(ys2), x) - begin(ys2));
                    self(self, ys2);
                    if (done) return;
                    steps.ppb();
                }
            }
        }
    };
    brute(brute, xs);

    // print ans
    cout << len(ans) << endl;
    for (auto &[i, j] : ans) {
        cout << i + 1 << ' ' << j + 1 << endl;
    }
    dbg(len(vis));
}

/*8<
 * AC, greedy, brute force
>8*/
