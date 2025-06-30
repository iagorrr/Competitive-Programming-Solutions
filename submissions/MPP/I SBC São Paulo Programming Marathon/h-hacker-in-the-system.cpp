#include <bits/stdc++.h>
using namespace std;
#define int long long

//{{
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

/*
 * @Description:
 *      merge should be function<T(T,T)>, that
 *      makes the necessary operation between two
 *      nodes in the segment tree
 * */

//}}

//{
template <typename T, T identity, auto merge>
struct SegTreeBottomUp {
        int size;
        vector<T> arr;

        SegTreeBottomUp(int n) {
                for (size = 1; size < n; size <<= 1);
                arr.resize(size << 1);
        }

        void assign(int pos, const T &val) {
                for (arr[pos += size] = val; pos >>= 1;)
                        arr[pos] = merge(arr[pos << 1], arr[pos << 1 | 1]);
        }

        T query(int l, int r) {
                T ans_l = identity, ans_r = identity;
                for (l += size, r += size + 1; l < r; l >>= 1, r >>= 1) {
                        if (l & 1) ans_l = merge(ans_l, arr[l++]);
                        if (r & 1) ans_r = merge(arr[--r], ans_r);
                }
                return merge(ans_l, ans_r);
        }

        SegTreeBottomUp(const vector<T> &vec) : SegTreeBottomUp(len(vec)) {
                copy(all(vec), begin(arr) + size);
                rrep(i, size - 1, 0)
                        arr[i] = merge(arr[i << 1], arr[i << 1 | 1]);
        }
};

template <typename T>
using SegTreeBottomUpSumQuery =
        SegTreeBottomUp<T, T(0), [](T a, T b) { return a + b; }>;

//}
int q, k;
const int maxk = 1'000'000;
int shift = 0;

SegTreeBottomUpSumQuery<int> seg(maxk);

ll translate(ll i) {
        ll im = i % k;
        im = (im + shift) % k;
        return im;
}

void init() {
        rep(i, 0, k) { seg.assign(i, i); }
}

void __swap(int l, int r) {
        l = translate(l);
        r = translate(r);

        ll vl = seg.query(l, l);
        ll vr = seg.query(r, r);

        seg.assign(l, vr);
        seg.assign(r, vl);
}

ll val(ll i) {
        ll b = (i / k);

        i = translate(i);

        return seg.query(i, i) + b * k;
}

ll firstN(ll n) { return (n * (n + 1)) / 2ll; }

ll ap(ll s, ll d, ll n) { return ((s + (s + d * (n - 1))) * n) / 2ll; }

ll formula(ll l, ll r) {
        if (r < l) return 0;

        // is some AP here.

        ll initialValue = firstN(k - 1) + k * l * k;
        ll ratio = k * k;
        ll tot = r - l + 1;

        ll ret = ap(initialValue, ratio, tot);

        return ret;
}

pll rangeVal(ll l, ll r) {
        ll ret = 0;

        ll sz = 0;

        if (l > r) {
                sz += r + 1;
                sz += (k - l);
                ret += seg.query(l, k - 1) + seg.query(0, r);
        } else {
                sz += (r - l + 1);
                ret += seg.query(l, r);
        }

        return {ret, sz};
}

ll fsum(int l, int r) {
        ll ans = 0;

        ll bl = l / k;
        ll br = r / k;

        if ((r % k) != (k - 1)) br--;
        if (l % k != 0) bl++;

        ll apR = formula(bl, br);

        ans += apR;

        bool hasPrefix = l % k != 0 and (l / k + 1) * k - 1 <= r;
        if (hasPrefix) {
                ll lq = l % k;
                ll rq = k - 1;

                lq = translate(lq);
                rq = translate(rq);

                auto [prefixVal, sz] = rangeVal(lq, rq);
                prefixVal += sz * ((l / k) * k);

                ans += prefixVal;
        }

        // suffixo na borda
        // na verdade o prefixo de um bloco nékk
        bool hasSuffix = r % k != k - 1 and ((r / k) * k) >= l;

        if (hasSuffix) {
                ll lq = translate(0);
                ll rq = translate(r % k);

                auto [suffixVal, sz] = rangeVal(lq, rq);
                suffixVal += sz * ((r / k) * k);

                ans += suffixVal;
        }

        // pode ser que não inclua porra nenhuma kkk
        if (!hasSuffix and !hasPrefix and l % k != 0 and r % k != k - 1) {
                ll lq = translate(l % k);
                ll rq = translate(r % k);
                auto [meiuca, sz] = rangeVal(lq, rq);
                meiuca += sz * ((l / k) * k);

                ans += meiuca;
        }

        return ans;
}

void solve() {
        cin >> q >> k;
        init();
        while (q--) {
                int o;
                cin >> o;

                if (o == 1) {
                        ll p;
                        cin >> p;
                        shift = (shift + p) % k;
                } else if (o == 2) {
                        int s, t;
                        cin >> s >> t;

                        __swap(s, t);
                } else {
                        int l, r;
                        cin >> l >> r;
                        cout << fsum(l, r) << '\n';
                }
        }
}

signed main() {
        ios_base::sync_with_stdio(0);
        cin.tie();
        solve();
        return 0;
}

/*
0 1 2 3 4 5 6 7 8 | 9 10 11 12 13 14 15 16 17

AC, range query, number theory
*/
