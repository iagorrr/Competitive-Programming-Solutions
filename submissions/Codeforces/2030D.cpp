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

void run() {
	int N,Q;
	cin>>N>>Q;

	vi PS(N), pos(N);
	rep(i, 0, N) {
		cin >> PS[i]; PS[i]--;
		pos[PS[i]] = i;
	}

	string S; cin >> S;

	set<int> badOn;

	vi isBad(N), covered(N);
	set<int> toClose;
	rep(i, 0, N - 1) {
		isBad[i] = (S[i] == 'L' and S[i+1] == 'R');
		toClose.emp(max(i,pos[i]));

		while (len(toClose) and *toClose.begin() <= i) {
			toClose.erase(toClose.begin());
		}


		covered[i] = len(toClose) != 0;

		if(isBad[i] and covered[i])
			badOn.emp(i);
	}


	rep(i, 0 , Q) {
		int q; cin >> q; q--;

		badOn.erase(q - 1);
		badOn.erase(q);

		S[q] = 'R' + 'L' - S[q];

		isBad[q] = q + 1 <  N and S[q] == 'L' and S[q+1] == 'R';

		if (q and S[q-1] == 'L' and S[q] == 'R')
			isBad[q-1] = true;
		else isBad[q-1] = false;

		if (q and S[q-1] == 'L' and S[q] == 'R' and isBad[q-1] and covered[q-1])
			badOn.emp(q-1);

		if (q + 1 < N and S[q] == 'L' and S[q+1] == 'R' and isBad[q] and covered[q])
			badOn.emp(q);

		dbg(badOn);

		cout << (len(badOn) ? "NO" : "YES") << '\n';
	}
}


/*8<
  divide em segmentos tal que não tem nenhum LR pq meio que fecha quem pode swapar com quem

  o menor valor de cada segmento tem ser igual ao menor indice do segmento

  se todos estiverem ok ent dá certo

  mas ta uma porra de codar isso ai

  AC, data-structures, implementation
>8*/
