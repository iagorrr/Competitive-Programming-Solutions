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

template <typename T>  // print vector
ostream &operator<<(ostream &os, vector<T> &xs) {
    rep(i, os.iword(0), xs.size()) os << xs[i] << (i == xs.size() ? "" : " ");
    os.iword(0) = 0;
    return os;
}

/*8<============~ END TEMPLATE ~============}>8*/


template <typename T = ll,
          auto cmp = [](T &src1, T &src2, T &dst) { dst = max(src1, src2); }>
class SparseTable {
   private:
    int sz;
    vi logs;
    vector<vector<T>> st;

   public:
    SparseTable(const vector<T> v) : sz(len(v)), logs(sz + 1) {
        rep(i, 2, sz + 1) logs[i] = logs[i >> 1] + 1;
        st.resize(logs[sz] + 1, vector<T>(sz));
        rep(i, 0, sz) st[0][i] = v[i];
        for (int k = 1; (1 << k) <= sz; k++) {
            for (int i = 0; i + (1 << k) <= sz; i++) {
                cmp(st[k - 1][i], st[k - 1][i + (1 << (k - 1))], st[k][i]);
            }
        }
    }
    T query(int l, int r) {
        r++;
        const int k = logs[r - l];
        T ret;
        cmp(st[k][l], st[k][r - (1 << k)], ret);
        return ret;
    }
};

bool solve(const vector<int> &AS, int K) {
	int N = AS.size();

	vector<int> psum(N);
	psum[0] = (AS[0] <= K ? 1 : -1);
	for (int i = 1; i < N; i++) {
		psum[i] = psum[i-1] + (AS[i] <= K ? 1 : -1);
	}

	vector<int> psumReverse(N);
	psumReverse[N-1] = (AS[N-1] <= K ? 1 : -1);
	for (int i = N-2; i>=0; i--) {
		psumReverse[i] = psumReverse[i+1] + (AS[i] <= K ? 1 : -1);
	}

	SparseTable st(psum);
	SparseTable stReverse(psumReverse);

	for (int p = 0; p < N-2; p++) {
		if (psum[p] < 0) continue;

		
		// podemos ter o  meio <= K
		auto greaterMid = st.query(p+1,N-2) - psum[p];

		// ou o fim <= K
		
		auto greaterRight = stReverse.query(p+2,N-1);


		if (greaterMid >= 0 or greaterRight >= 0)
			return true;
	}

	return false;
}

void solve(){

	int N, K;
	cin >>N>>K;
	vector<int>AS(N);
	for(auto&ai:AS)cin>>ai;

	bool ans = solve(AS,K);
	reverse(AS.begin(), AS.end());
	ans |= solve(AS, K);
	cout << (ans ? "YES" : "NO") << '\n';

}

signed main()  {
	ios_base::sync_with_stdio(!cin.tie(0));
	int t;
	cin>>t;
	while(t--)solve();
}

/*
 * Nlog passa
 *
 * N tbm né
 *
 * 3 2 1
 *
 * a gente pode pre computar a mediana
 * de todos os prefixos e todos os sufixos...
 *
 * psum pra saber se um segmento tem medina menor ou igual a K
 *
 * brute force, range queries, data structures
 * */
