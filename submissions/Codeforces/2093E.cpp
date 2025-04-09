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

/*8<{=============~ BEGIN MEX ~===============>8*/
/*8<
  @Title:

    Mex with update

  @Description:

    This DS allows you to mantain an array of
    integers, insert, and remove, and query
    the MEX at any time.

  @Usage:

    \begin{compactitem}
      \item \textbf{$Mex(mxsz)$}: Initialize
      the DS, $mxsz$ must be the maximum number
      of elements that the structure may have.

      \item \textbf{$add(x)$}: just adds one
      copy of $x$.

      \item \textbf{$rmv(x)$}: just remove a copy
      of $x$.

      \item \textbf{$mex$}:  stores the current mex.
    \end{compactitem}

    @Time:
        It's all $O(1)$, $add$ and $rmv$ are amortized.
>8*/

struct Mex {
        int maximumSize, currentMex;
        vi hs;

        Mex(int _mx_sz)
                : maximumSize(_mx_sz), currentMex(0), hs(maximumSize + 1) {}

        void add(ll x) {
                if (x <= maximumSize) {
                        hs[x]++;
                        while (hs[currentMex]) currentMex++;
                }
        }

        void rmv(ll x) {
                if (x <= maximumSize) {
                        hs[x]--;
                        while (currentMex and !hs[currentMex]) currentMex--;
                }
        }
};

/*8<===============~ END MEX ~===============}>8*/

void run() {
        int N, K;
        cin >> N >> K;

        vll XS(N);
        cin >> XS;

        Mex mex(N * 2);
        vi added;
        auto ans = maxCheck(0, N, [&](int minMex) {
                if (minMex == 0) return true;

                dbg(minMex);
                int segs = 0;
                for (int l = 0; l < N;) {
                        int r = l;
                        while (len(added)) {
                                mex.rmv(added.back());
                                added.pop_back();
                        }
                        while (r < N and mex.currentMex < minMex) {
                                mex.add(XS[r]);
                                added.eb(XS[r]);
                                r++;
                        }

                        if (mex.currentMex < minMex) return false;
                        segs++;
                        if (segs >= K) return true;
                        l = r;
                }
                return segs >= K;
        });

        cout << *ans << endl;
}

/*8<
>8*/
