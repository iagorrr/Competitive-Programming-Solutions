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


    rep(t, 0, T) {
        dbg(t);
        run();
    }
}

/*8<
  @Title: Factorization (Pollard's Rho)
  @Description:
    Factorizes a number into its prime factors.
  @Time: $O(N^{(\frac{1}{4})} * \log (N))$.
>8*/
ll mul(ll a, ll b, ll m) {
    ll ret = a * b - (ll)((ld)1 / m * a * b + 0.5) * m;
    return ret < 0 ? ret + m : ret;
}

ll pow(ll a, ll b, ll m) {
    ll ans = 1;
    for (; b > 0; b /= 2ll, a = mul(a, a, m)) {
        if (b % 2ll == 1) ans = mul(ans, a, m);
    }
    return ans;
}

bool prime(ll n) {
    if (n < 2) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0) return 0;

    ll r = __builtin_ctzll(n - 1), d = n >> r;
    for (int a : {2, 325, 9375, 28178, 450775, 9780504, 795265022}) {
        ll x = pow(a, d, n);
        if (x == 1 or x == n - 1 or a % n == 0) continue;

        for (int j = 0; j < r - 1; j++) {
            x = mul(x, x, n);
            if (x == n - 1) break;
        }
        if (x != n - 1) return 0;
    }
    return 1;
}

ll rho(ll n) {
    if (n == 1 or prime(n)) return n;
    auto f = [n](ll x) { return mul(x, x, n) + 1; };

    ll x = 0, y = 0, t = 30, prd = 2, x0 = 1, q;
    while (t % 40 != 0 or gcd(prd, n) == 1) {
        if (x == y) x = ++x0, y = f(x);
        q = mul(prd, abs(x - y), n);
        if (q != 0) prd = q;
        x = f(x), y = f(f(y)), t++;
    }
    return gcd(prd, n);
}

vector<ll> fact(ll n) {
    if (n == 1) return {};
    if (prime(n)) return {n};
    ll d = rho(n);
    vector<ll> l = fact(d), r = fact(n / d);
    l.insert(l.end(), r.begin(), r.end());
    return l;
}

vll uniqueFact(ll n) {
	auto f = fact(n);
	auto sf = set<ll>(all(f));
	return vll(all(sf));
}



const ll MAXN = 2e6;
vll list_primes(ll n = MAXN) {
    vll ps;
    bitset<MAXN + 1> sieve;
    sieve.set();
    sieve.reset(1);
    for (ll i = 2; i <= n; ++i) {
        if (sieve[i]) ps.push_back(i);
        for (ll j = i * 2; j <= n; j += i) {
            sieve.reset(j);
        }
    }
    return ps;
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

vll PRIMES;
vector<mint<>> perv(2'000'000);

void run() {
	PRIMES = list_primes();

	int N;
	cin >> N;

	vll XS(N);
	for(auto&xi:XS)
		cin>>xi;

	vector<mint<>> ans(N);
	ans[0] = 1;
	rep(i, 0, N) {
		auto xi = XS[i];
		auto fs = uniqueFact(xi);
		dbg(xi, fs);
		for (int mask = 1; mask < (1<<len(fs));mask++){
			int tot = 0;
			ll v = 1;
			for (int j = 0; j < len(fs); j++) {
				if (mask & (1<<j)) {
					tot++;
					v*=fs[j];
				}
			}
			if (tot&1){
				ans[i]+=perv[v];
			}
			else{
				ans[i]-=perv[v];
			}
		}

		for (int mask = 1; mask < (1<<len(fs));mask++){
			int tot = 0;
			ll v = 1;
			for (int j = 0; j < len(fs); j++) {
				if (mask & (1<<j)) {
					tot++;
					v*=fs[j];
				}
			}
			perv[v]+=ans[i];
		}

	}

	dbg(ans);

	cout << ans.back() << '\n';
}

/*8<
  AC, dynamic programming, combinatorics, number theory
>8*/
