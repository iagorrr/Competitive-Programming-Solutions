/*~=========================BEGIN MACRO=================================~*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define endl '\n'

#define fastio                        \
        ios_base::sync_with_stdio(0); \
        cin.tie(0);

#define int long long

#define all(j) j.begin(), j.end()
#define rall(j) j.rbegin(), j.rend()
#define len(j) (int)j.size()
#define rep(i, a, b) \
        for (common_type_t<decltype(a), decltype(b)> i = a; i < b; i++)
#define rrep(i, a, b) \
        for (common_type_t<decltype(a), decltype(b)> i = a; i > b; i--)
#define pb push_back
#define eb emplace_back

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;
using vs = vector<string>;

/*~==========================END MACRO==================================~*/

struct Seg {
	int n;
	vi st;
	Seg (int _n) : n(_n), st(n<<2) {
		__build(1, 0, n-1);
		dbg(st);
	}

	void __build(int idx, int l, int r) {
		if (l == r) {
			st[idx] = 1;
			return;
		}
		int m = (l+r) >> 1;
		__build(idx<<1, l, m);
		__build(idx<<1|1, m+1, r);
		st[idx] = st[idx<<1] + st[idx<<1|1];
	}

	void assign(int p, int v) {
		dbg(st);
		assign(p, v, 1, 0, n -1);
		dbg(st);
	}

	void assign(int p, int v, int idx , int l, int r) {
		if (l == r) {
			st[idx] = v;
			return;
		}

		int m = (l + r) >> 1;
		if (p <= m) assign(p, v, idx << 1, l, m);
		else assign(p, v, idx << 1 | 1, m+1, r);
		st[idx] = st[idx<<1] + st[idx<<1|1];
	}

	int query(int v) {
		return query(v, 1, 0, n-1);
	}

	int query(int v, int idx, int l, int r) {
		if (l == r) return l;

		int m = (l + r) >> 1;

		if (st[idx<<1] >= v) return query(v, idx<<1, l , m);

		return query(v-st[idx<<1], idx<<1|1, m+1 , r);
	}
};

auto run() {

	int N;
	cin >> N;

	vi QS(N);
	for (int i = 0; i < N; i += 2) {
		cin >> QS[i];
	}
	for (int i = 1; i < N; i += 2) {
		cin >> QS[i];
	}

	vi ans(N);
	Seg st(N);
	for (int i = 0; i < N; i++) {
		dbg(QS[i]);
		ans[i] = st.query(QS[i]);
		st.assign(ans[i], 0);
	}

	for (int i = 0; i < N; i += 2) {
		cout << ans[i] + 1<< " \n"[i+2>=N];
	}

	for (int i = 1; i < N; i += 2) {
		cout << ans[i] + 1 << " \n"[i+2>=N];
	}
}

int32_t main() {
#ifndef LOCAL
        fastio;
#endif

        int T = 1;

        // cin >> T;

        rep(t, 0, T) {
                dbg(t);
                run();
        }
}

/*
 * AC, segment trees
 */
