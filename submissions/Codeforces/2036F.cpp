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

inline ll lg2(ll x) {
	return sizeof(ll) * 8ll - (x ? __builtin_clzll(x) : sizeof(ll)*8-1);
}

#define int ll;

ll rangeXOR(ll r) {
	if (r < 0) return 0;
	ll ret[] = {r, 1, r + 1, 0};
	return ret[r%4ll];
}

ll rangeXOR(ll l, ll r) {
	return rangeXOR(r) ^ (l ? rangeXOR(l-1) : 0ll);
}

ll prefixMask(ll mask, ll r, ll i) {
	ll ret = (mask > r ? 0 : (r - mask) / (1ll<<i)+ 1) ;
	dbg(mask, r, ret);
	return ret;
}

ll prefixMask(ll mask, ll l, ll r, ll i) {
	return prefixMask(mask, r, i) - prefixMask(mask, l-1, i);
}

void run() {
	ll l, r, i, k;
	cin >> l >> r >> i >> k;

	if (!i) {
		cout << 0 << '\n';
		return;
	}

	ll XORlr = rangeXOR(l, r); 

	ll totWithk = prefixMask(k, l, r, i);

	if (totWithk & 1ll) XORlr ^= k;
	
	ll lmarked = prefixMask(k, l-1, i);
	ll rmarked = lmarked + totWithk - 1;
	dbg(lmarked, rmarked);
	ll marked = rangeXOR(lmarked, rmarked);
	marked = marked<<(i);

	dbg(marked);

	XORlr ^= marked;

	cout << XORlr << '\n';
}

/*8<
	AC, bitwise, number theory
>8*/
