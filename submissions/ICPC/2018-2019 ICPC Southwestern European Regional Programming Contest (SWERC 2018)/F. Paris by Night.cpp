/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>

#include <algorithm>
#include <climits>
#include <vector>
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

using ld = long double;
template <typename T>
using Point = pair<T, T>;
#define x first
#define y second

const double EPS{1e-6};
const ld PI = acos(-1);

template <typename T>
bool equals(T a, T b) {
    if (std::is_floating_point<T>::value)
        return fabs(a - b) < EPS;
    else
        return a == b;
}

template <typename T>
bool equals(Point<T> a, Point<T> b) {
    if (std::is_floating_point<T>::value)
        return fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS;
    else
        return a == b;
}

/*
 * if `a` and `b` are equal c will always be
 * colinear, you may want to treat that.
 * */
template <typename T>
int orientation(Point<T> a, Point<T> b, Point<T> c) {
    long long v =
        1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (b.y - a.y) * (c.x - a.x);
    if (v == 0) return 0;     // colinear
    return (v > 0 ? 1 : -1);  // 1 = CCW, -1 = CW
}

template <typename T>
vector<Point<T>> sortByAngle(vector<Point<T>> pts, Point<T> pivot) {
    sort(pts.begin(), pts.end(), [&](const Point<T> &a, const Point<T> &b) {
        int o = orientation(pivot, a, b);
        if (o == 0) {
            // colinear → sort by distance to pivot
            long long da = (a.x - pivot.x) * (a.x - pivot.x) +
                           (a.y - pivot.y) * (a.y - pivot.y);
            long long db = (b.x - pivot.x) * (b.x - pivot.x) +
                           (b.y - pivot.y) * (b.y - pivot.y);
            return da < db;
        }
        return o > 0;  // counter-clockwise first
    });
    return pts;
}

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

void __run() {
    int n;
    cin >> n;

    vector<pair<Point<ll>, int>> pts(n);
    vll gs(n);
    repn(i, n) {
        cin >> pts[i].x.x >> pts[i].x.y >> gs[i];
        pts[i].y = i;
    }

    ll ans = LLONG_MAX;

    repn(i, n) {
        auto pi = pts[i].x;
        dbg(i, pi);

        // get the points sorted by angle
        // and remove the pi
        auto pts2 = pts;
        pts2.erase(find(all(pts2), pts[i]));
        sort(pts2.begin(), pts2.end(), [&](const auto &_a, const auto &_b) {
            auto a = _a.x;
            auto b = _b.x;

            int o = orientation(pi, a, b);
            if (o == 0) {
                // colinear → sort by distance to pivot
                long long da =
                    (a.x - pi.x) * (a.x - pi.x) + (a.y - pi.y) * (a.y - pi.y);
                long long db =
                    (b.x - pi.x) * (b.x - pi.x) + (b.y - pi.y) * (b.y - pi.y);
                return da < db;
            }
            return o > 0;  // counter-clockwise first
        });

        // quando tiver vários colienares
        // onde o first_cc para ?
        // tem o critério de sempate teria que ser qual ??
        repn(j, len(pts2)) {
            auto pj = pts2[j];
            auto first_cc = j;
            while (orientation(pi, pj, pts2[(j + 1) % len(pts2)]))
                auto last_cc = 0;

            auto first_c = 0;
            auto last_c = 0;
        }
    }

    cout << ans << endl;
}

/*8<
  o pivot é i e estamos com o outro ponto em j
  todo mundo antes de j, ou está abaixo ou é colinear

  existem alguns pontos depois de j que estão acima,
  depois um segmento que é colinear, e depois um segmento que está abaixo

   could not solve with this approach

>8*/
