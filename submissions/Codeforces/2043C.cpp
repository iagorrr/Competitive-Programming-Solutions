/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>

#include <algorithm>
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

        cin >> T;

        rep(t, 0, T) {
                dbg(t);
                run();
        }
}

using SegT = ll;

struct QueryT {
        SegT mx, mn;
        QueryT()
                : mx(numeric_limits<SegT>::min()),
                  mn(numeric_limits<SegT>::max()) {}
        QueryT(SegT _v) : mx(_v), mn(_v) {}
};

inline QueryT combine(QueryT ln, QueryT rn, pii lr1, pii lr2) {
        chmax(ln.mx, rn.mx);
        chmin(ln.mn, rn.mn);
        return ln;
}

using LazyT = SegT;

inline QueryT applyLazyInQuery(QueryT q, LazyT l, pii lr) {
        if (q.mx == QueryT().mx) q.mx = SegT();
        if (q.mn == QueryT().mn) q.mn = SegT();
        q.mx += l, q.mn += l;
        return q;
}

inline LazyT applyLazyInLazy(LazyT a, LazyT b) { return a + b; }

using UpdateT = SegT;

inline QueryT applyUpdateInQuery(QueryT q, UpdateT u, pii lr) {
        if (q.mx == QueryT().mx) q.mx = SegT();
        if (q.mn == QueryT().mn) q.mn = SegT();
        q.mx += u, q.mn += u;
        return q;
}

inline LazyT applyUpdateInLazy(LazyT l, UpdateT u, pii lr) { return l + u; }

template <typename Qt = QueryT, typename Lt = LazyT, typename Ut = UpdateT,
          auto C = combine, auto ALQ = applyLazyInQuery,
          auto ALL = applyLazyInLazy, auto AUQ = applyUpdateInQuery,
          auto AUL = applyUpdateInLazy>
struct LazySegmentTree {
        int n, h;
        vector<Qt> ts;
        vector<Lt> ds;
        vector<pii> lrs;

        LazySegmentTree(int _n)
                : n(_n),
                  h(sizeof(int) * 8 - __builtin_clz(n)),
                  ts(n << 1),
                  ds(n),
                  lrs(n << 1) {
                rep(i, 0, n) lrs[i + n] = {i, i};
                rrep(i, n - 1, 0) {
                        lrs[i] = {lrs[i << 1].first, lrs[i << 1 | 1].second};
                }
        }

        LazySegmentTree(const vector<Qt> &xs) : LazySegmentTree(len(xs)) {
                copy(all(xs), ts.begin() + n);
                rep(i, 0, n) lrs[i + n] = {i, i};
                rrep(i, n - 1, 0) {
                        ts[i] = C(ts[i << 1], ts[i << 1 | 1], lrs[i << 1],
                                  lrs[i << 1 | 1]);
                }
        }

        void set(int p, Qt v) {
                ts[p + n] = v;
                build(p + n);
        }

        void upd(int l, int r, Ut v) {
                l += n, r += n + 1;
                int l0 = l, r0 = r;
                for (; l < r; l >>= 1, r >>= 1) {
                        if (l & 1) apply(l++, v);
                        if (r & 1) apply(--r, v);
                }
                build(l0), build(r0 - 1);
        }

        Qt qry(int l, int r) {
                l += n, r += n + 1;
                push(l), push(r - 1);
                Qt resl = Qt(), resr = Qt();
                pii lr1 = {l, l}, lr2 = {r, r};
                for (; l < r; l >>= 1, r >>= 1) {
                        if (l & 1) resl = C(resl, ts[l], lr1, lrs[l]), l++;
                        if (r & 1) r--, resr = C(ts[r], resr, lrs[r], lr2);
                }
                return C(resl, resr, lr1, lr2);
        }

        void build(int p) {
                while (p > 1) {
                        p >>= 1;
                        ts[p] = ALQ(C(ts[p << 1], ts[p << 1 | 1], lrs[p << 1],
                                      lrs[p << 1 | 1]),
                                    ds[p], lrs[p]);
                }
        }

        void push(int p) {
                rrep(s, h, 0) {
                        int i = p >> s;
                        if (ds[i] != Lt()) {
                                apply(i << 1, ds[i]), apply(i << 1 | 1, ds[i]);
                                ds[i] = Lt();
                        }
                }
        }

        inline void apply(int p, Ut v) {
                ts[p] = AUQ(ts[p], v, lrs[p]);
                if (p < n) ds[p] = AUL(ds[p], v, lrs[p]);
        }
};

void run() {
        int N;
        cin >> N;

        vll AS(N);
        trav(ai, AS) cin >> ai;

        vll psum(N);
        psum.front() = AS.front();
        rep(i, 1, N) { psum[i] += psum[i - 1] + AS[i]; }

        vector<QueryT> aux(all(psum));
        LazySegmentTree seg(aux);

        vi rs(N);
        int posX = N;
        rrep(i, N - 1, 0 - 1) {
                rs[i] = posX;
                if (abs(AS[i]) != 1) posX = i;
        }

        // o after i é fixo

        vector<pll> intervals;
        intervals.eb(0, 0);
        rep(i, 0, N) {
                auto q1 = seg.qry(i, rs[i] - 1);
                dbg(q1.mn, q1.mx);
                intervals.eb(q1.mn, q1.mx);

                if (rs[i] < N) {
                        auto q2 = seg.qry(rs[i], N - 1);
                        dbg(q2.mn, q2.mx);
                        intervals.eb(q2.mn, q2.mx);
                }

                seg.upd(i, N - 1, -AS[i]);
        }

        sort(all(intervals), [&](const pll &a, const pll &b) {
                return a.first == b.first ? a.second > b.second
                                          : a.first < b.first;
        });

        vector<pll> merged{intervals.front()};
        rep(i, 1, len(intervals)) {
                auto &[pl, pr] = merged.back();
                auto [l, r] = intervals[i];

                if (l <= pr)
                        pr = max(pr, r);
                else
                        merged.eb(l, r);
        }

        vll ans;
        for (auto [l, r] : merged) {
                rep(i, l, r + 1) { ans.eb(i); }
        }

        cout << len(ans) << endl;
        trav(ai, ans) cout << ai << ' ';
        cout << endl;
}

/*8<
 * Essencialmente achar todas as somas de subarrays distintas
 *
 * Obs: Em segmentos de 1 e -1 a soma varia de 1 em 1, entã
 *      se considerar o maiore o menor elemento naquele range a gente tá safo
 *
 * OBS: vai sempre ser 1 ou 2 intervalos de soma [V1, ... V2], [V3, ..., V4], pq
 *      quando pega o valor X só da um saltinho meio cabuloso
 *
 * OBS: Gerar uns 3N intervalos e mergear eles parece fazível
 *
 * Seja MNi, e MXi o menor e maior valor do [i, posX], MXi = N-1 se X está antes
do i,
 * Toda subarray começando no I pode ir de [MNi, MXi], [valor nox, valornox +
X].
 *
 * Algo assim
 * Ovo lançar uma SEG heheheh
 * vo nada
 * vo sim
 *
 * greedy, prefix sum
>8*/
