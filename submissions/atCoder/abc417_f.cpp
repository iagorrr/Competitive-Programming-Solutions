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

using ll = long long;

const ll mod = 998244353;

inline ll sum(const ll a, const ll b) { return (a + b) % mod; }

ll sub(const ll a, const ll b) { return (a - b + mod) % mod; }

ll mul(const ll a, const ll b) { return (a * b) % mod; }

int fpow(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1) r = mul(r, a);
		a = mul(a, a);
		b>>=1;
	}

	return r;
}
int divm(int a, int b) { return mul(a, fpow(b,mod-2));}

struct SqrtDecomposition {
    struct t_sqrt {
        int l, r;

	ll s, v, ts;
t_sqrt() {
            l = numeric_limits<int>::max();
            r = numeric_limits<int>::min();
	    s = 0;
	    ts = -1;
        };
    };

    int sqrtLen;
    vector<t_sqrt> blocks;
    vector<ll> as;
    vector<int> as_ts;
    int ts;
    SqrtDecomposition(const vector<ll> &as_) {
        int n = as_.size();
        sqrtLen = (int)sqrt(n + .0) + 1; // make this const
        blocks.resize(sqrtLen + 6.66);
        as = as_;
	ts = 0;
	as_ts = vector<int>(n, -1);

	// Initialize each block, and increment based in the 
	// given vector
        for (int i = 0; i < n; i++) {
            auto& bi = blocks[i / sqrtLen];
            bi.l = min(bi.l, i), bi.r = max(bi.r, i);
	    bi.s = sum(bi.s, as[i]);
        }
    }


    void update(int l, int r, ll v) {
	    ts++;
        auto apply1 = [&](int idx, ll v) -> void {
            auto& bi = blocks[idx / sqrtLen];
	    auto& ai = as[idx];
	    auto& ai_ts= as_ts[idx];

	    ll prev = 	bi.ts == -1 or (bi.ts <= ai_ts)
		     	? ai : bi.v;

	    bi.s = sub(bi.s, prev), bi.s = sum(bi.s, v);

	    as[idx] = v, as_ts[idx] = ts;
        };

        auto apply2 = [&](int idx, ll v) -> void {
	    auto &bi = blocks[idx];
	    int sz =  bi.r-bi.l+1;
	    bi.s = mul(sz, v);
	    bi.ts = ts;
	    bi.v = v;

        };

        int cl = l / sqrtLen, cr = r / sqrtLen;

        if (cl == cr) { // Apply to a single element
            for (int i = l; i <= r; i++) {
                apply1(i, v);
            }
        } else {
		// Apply for single elments in the prerix
            for (int i = l; i <= (cl + 1) * sqrtLen - 1; i++) {
                apply1(i,v);
            }

	    // Apply for the blocks in the between
            for (int i = cl + 1; i <= cr - 1; i++) {
                apply2(i,v);
            }

	    // Apply for single elements in the suffix
            for (int i = cr * sqrtLen; i <= r; i++) {
                apply1(i, v );
            }
        }
    }

    // sum of a[i]*b[i] in range [l  r]
    ll query(int l, int r) {
        auto eval1 = [&](int idx) -> ll {
	    auto bi = blocks[idx/sqrtLen];
	    ll  v = bi.ts == -1 or as_ts[idx]  >= bi.ts ? 
		    as[idx] : bi.v;
	    return v;
        };

        auto eval2 = [&](int idx) -> ll {
            auto &b = blocks[idx];
	    return b.s;
        };

        ll ret = 0;
        int cl = l / sqrtLen, cr = r / sqrtLen;
        if (cl == cr) {
            for (int i = l; i <= r; i++) {
                ret = sum(ret, eval1(i));
            }
        } else {
            for (int i = l; i <= (cl + 1) * sqrtLen - 1; i++) {
                ret = sum(eval1(i), ret);
            }

            for (int i = cl + 1; i <= cr - 1; i++) {
                ret = sum(ret, eval2(i));
            }

            for (int i = cr * sqrtLen; i <= r; i++) {
                ret = sum(ret, eval1(i));
            }
        }

        return ret;
    }
};



signed main() {
	ios_base::sync_with_stdio(!cin.tie(0));
	int n, m;
	cin >> n >> m;

	vector<ll> as(n);
	for (auto &ai : as) cin >> ai;

	SqrtDecomposition ds(as);

	while (m--) {
		dbg(ds.as);
		int l , r;
		cin >> l >> r;
		l--, r--;

		ll s = ds.query(l, r);
		ll e = divm(s, r-l+1);
		dbg(s, l, r, r-l+1, e);
		ds.update(l, r, e);
	}

	for (int i = 0; i < n; i++) {
		cout << ds.query(i, i) << ' ';
	}

	cout << endl;
}

/*
 *
 * uma vez que escolhe um l e um r
 * seja z = r - l + 1, s = sum(l, r);
 *
 * todo mundo tem valor esperado de s / z
 * pedras
 *
 * faz esse update aí, a cada step
 *
 * e vapo ?
 *
 * ver se quadrático da pelo menos tle
 *
 * o que a gente precisa é de uma estrutura
 * com range set e range query e vapo
 *
 * a soma faz como sempre, pega o mínimo 
 * de nós pra representar o que a gente quer
 *
 * e pra dar update tbm pega o mínimo de nós
 * o valor daquele nó vira sz * v
 *
 * e nos filhos a gente marca que precisa atualizar 
 * com o valor v
 *
 * minha seg comporta isso ?
 *
 * não da pra fazer com sqrt não ???
 *
 * acho que dava pra fazer esse offset 
 * com a difere
 * d
 * 
 *
 * dava nao kk
 *
 * deu certin mane
 *
 *
 * AC, range query, expected value
 * */

