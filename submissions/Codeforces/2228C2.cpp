/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>

#include <cmath>
#include <string>
#include <type_traits>
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
using vpll = vector<pll>;
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
        rep(i, os.iword(0), xs.size()) os << xs[i]
                                          << (i == xs.size() ? "" : " ");
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

        cin >> T;

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

void __run() {
        ll A, N;
        cin >> A >> N;

        vll aux(N);
        cin >> aux;

        set<ll> D(all(aux));

        ll ans = LLONG_MAX;

        string SA = to_string(A);

        // da pra igual
        bool ok = 1;
        for (auto si : SA) {
                ok &= D.count(si - '0');
        }
        if (ok) return cout << 0 << endl, (void)0;

        // um digito a menos, bota o maior com thudo
        [&] {
                if (len(SA) == 1) return;
                string sb = string(len(SA) - 1, aux.back() + '0');
                ll b = stoll(sb);
                chmin(ans, abs(A - b));
        }();

        // um a mais
        // bota primeiro o menor valor diferente de zero
        // depois disso o menor valor de fato
        [&] {
                if (len(aux) == 1 and aux.back() == 0) return;
                ll fd = aux[0] == 0 ? aux[1] : aux[0];
                ll sd = aux[0];
                string sb = string(1, fd + '0') + string(len(SA), sd + '0');
                ll b = stoll(sb);
                chmin(ans, abs(A - b));
        }();

        // que não tenha como fazer um prefixo válido
        // o primeiro que não tiver como eu teria que
        // esclher entre errar pra cima e errar pra baixo
        // erra sempre no máximo um pra cima ou pra baixo

        string prefix;
        repn(i, len(SA)) {
                for (auto d : D) {
                        string prefix2 = prefix;
                        prefix2.push_back(d + '0');

                        for (auto d2 : D) {
                                string b =
                                        prefix2 + string(len(SA) - len(prefix2),
                                                         d2 + '0');
                                chmin(ans, abs(A - stoll(b)));
                        }
                }

                if (D.count(SA[i] - '0'))
                        prefix.push_back(SA[i]);
                else
                        break;
        }

        cout << ans << endl;
}

/*8<
>8*/
