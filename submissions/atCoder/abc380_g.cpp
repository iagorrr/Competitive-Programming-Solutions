/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
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
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) for (auto &xi : ranges::views::reverse(xs))
using ll = long long;
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
#define divc(a, b) ((a) + (b)-1ll) / (b)
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

/*8<{=========~ BEGIN ORDERED SET ~===========>8*/
/*8<
     @Title:

          Orderd Set (GNU PBDS)

     @Usage:

          If you need an ordered \textbf{multi}
          set you may add an id to each value.
          Using greater\_equal, or less\_equal
          is considered undefined behavior.


          \begin{compactitem}
            \item  \textbf{order\_of\_key (k)}:
            Number of items strictly
            smaller/greater than k .
            \item  \textbf{find\_by\_order(k)}:
K-th element in a set (counting from zero).
          \end{compactitem}


     @Time:

          Both $O(\log{N})$

     @Warning:

          Is 2 or 3 times slower then a regular
set/map. >8*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*8<===========~ END ORDERED SET
 * ~============}>8*/

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


const ll MOD = 998244353;
template <ll _mod = MOD>
struct mint {
    ll value;
    static const ll MOD_value = _mod;

    mint(ll v = 0) {
        value = v % _mod;
        if (value < 0) value += _mod;
    }
    mint(ll a, ll b) : value(0) {
        *this += a;
        *this /= b;
    }

    mint &operator+=(mint const &b) {
        value += b.value;
        if (value >= _mod) value -= _mod;
        return *this;
    }
    mint &operator-=(mint const &b) {
        value -= b.value;
        if (value < 0) value += _mod;
        return *this;
    }
    mint &operator*=(mint const &b) {
        value = (ll)value * b.value % _mod;
        return *this;
    }

    friend mint mexp(mint a, ll e) {
        mint res = 1;
        while (e) {
            if (e & 1) res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }
    friend mint inverse(mint a) { return mexp(a, _mod - 2); }

    mint &operator/=(mint const &b) { return *this *= inverse(b); }
    friend mint operator+(mint a, mint const b) { return a += b; }
    mint operator++(int) { return this->value = (this->value + 1) % _mod; }
    mint operator++() { return this->value = (this->value + 1) % _mod; }
    friend mint operator-(mint a, mint const b) { return a -= b; }
    friend mint operator-(mint const a) { return 0 - a; }
    mint operator--(int) {
        return this->value = (this->value - 1 + _mod) % _mod;
    }

    mint operator--() { return this->value = (this->value - 1 + _mod) % _mod; }
    friend mint operator*(mint a, mint const b) { return a *= b; }
    friend mint operator/(mint a, mint const b) { return a /= b; }
    friend std::ostream &operator<<(std::ostream &os, mint const &a) {
        return os << a.value;
    }
    friend bool operator==(mint const &a, mint const &b) {
        return a.value == b.value;
    }
    friend bool operator!=(mint const &a, mint const &b) {
        return a.value != b.value;
    }
};


const int MAXN = 1'000'000;
mint<> FAT[MAXN];

mint<> S(int k) {
	mint n = k;
	return (n * (n-1) * FAT[k])/mint<>(4);
}

mint<> EV(int k) {
	return S(k)/FAT[k];
}


void run() {
	FAT[0] = 1;
	rep(i, 1, MAXN) {
		FAT[i] = FAT[i-1] * i;
	}

	int N, K;
	cin >> N >> K;

	vi XS(N);
	for (auto &xi : XS)
		cin >> xi;

	mint I = 0;
	{
		ordered_set<int> ost;
		rtrav(xi, XS) {
			I += ost.order_of_key(xi);
			ost.insert(xi);
		}
		dbg(I);
	}

	mint ans = 0;
	mint inv = 0;
	ordered_set<int> ost;
	{
		rrep(i, K-1, 0-1) {
			auto xi = XS[i];
			inv += ost.order_of_key(xi);
			ost.insert(xi);
		}
	}
	int m = 0;
	for (int l = 0, r = K; r <= N; l++, r++) {
		m++;
		dbg(l,r,inv);
		ans += (I - inv + EV(K));
		if (r < N) {
			ost.erase(XS[l]);
			inv -= ost.order_of_key(XS[l]);
			inv += (K-1-ost.order_of_key(XS[r]));
			ost.insert(XS[r]);
		}
	}

	ans /= m;

	cout << ans << '\n';


}

/*8<
  AC, expected value
>8*/
