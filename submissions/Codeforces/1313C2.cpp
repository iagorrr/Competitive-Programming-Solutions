/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define fastio                  \
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
#define inte ll
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

  // cin >> T;

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
template <typename T = ll,
          auto cmp = [](T &src1, T &src2, T &dst) { dst = min(src1, src2); }>
class SparseTable {
 private:
  int sz;
  vi logs;
  vector<vector<T>> st;

 public:
  SparseTable(const vector<T> &v) : sz(len(v)), logs(sz + 1) {
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

void run() {
	int N;
	cin >> N;
	vll MS(N);
	for (auto &xi : MS)
		cin >> xi;

	SparseTable st(MS);
	vll prefixSum(N);
	prefixSum[0] = MS[0];
	rep(i, 1, N) {
		// da pra fazer sem BB ?
		auto firstLessEqual = maxCheck(0, i-1, [&](int p) {
				ll v = st.query(p, i-1);
				return v <= MS[i];
				});
		dbg(i, firstLessEqual.has_value(), *firstLessEqual);
		if (firstLessEqual) {
			prefixSum[i] = prefixSum[*firstLessEqual] + ((i - *firstLessEqual) * MS[i]);
		}
		else {
			prefixSum[i] = (i+1ll) * MS[i];
		}
	}

	vll suffixSum(N);
	suffixSum.back() = MS.back();
	rrep(i, N-2, 0-1) {
		auto firstLessEqual = minCheck(i + 1, N-1, [&](int p) {
				return st.query(i+1, p) <= MS[i];
				});

		if (firstLessEqual) {
			suffixSum[i] = suffixSum[*firstLessEqual] + ((*firstLessEqual - i) * MS[i]);
		}
		else {
			suffixSum[i] = (N-i) * MS[i];
		}
	}

	dbg(prefixSum);
	dbg(suffixSum);

	ll ans = max(suffixSum.front(), prefixSum.back());
	int pos = suffixSum.front() > prefixSum.back() ? -1 : N-1;
	rep(i, 0, N-1) {
		ll cur = prefixSum[i]  + suffixSum[i+1];
		if (cur > ans) {
			pos = i;
			ans = cur;
		}
	}

	dbg(ans);
	dbg(pos);

	vll arrayAns;
	rrep(i, pos, -1) {
		if (arrayAns.empty()) {
			arrayAns.eb(MS[i]);
		}
		else {
			arrayAns.eb(min(MS[i], arrayAns.back()));
		}
	}
	reverse(all(arrayAns));

	if(pos+1 < N)
		arrayAns.eb(MS[pos+1]);
	rep(i, pos + 2, N) {
			arrayAns.eb(min(MS[i], arrayAns.back()));
	}


	for(auto a : arrayAns)
		cout << a << ' ';
	cout << endl;
}

/*8<
  AC, brute force, binary search, range queries
>8*/
