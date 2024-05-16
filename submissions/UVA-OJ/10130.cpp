#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int) __x.size()
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
#define all(a) a.begin(), a.end()
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

vector<string> dir({"LU", "U", "RU", "R", "RD", "D", "LD", "L"});
int dx[] =           {-1,  -1,   -1,   0,    1,   1,    1,   0};
int dy[] =           {-1,   0,    1,   1,    1,   0,   -1,  -1};
const ll oo = 1e18;

ll knapSack(int u, ll w, vll &VS, vll &WS, vll2d &memo) {
	if (u < 0 or w <= 0) return 0;
	if (memo[u][w] != -1) return memo[u][w];

	ll a = 0, b = 0;
	a = knapSack(u-1, w, VS, WS, memo);
	if (WS[u] <= w)
		b = knapSack(u-1, w - WS[u], VS, WS, memo) + VS[u];
	return memo[u][w] = max(a, b);
}

void solve() {
	int N;
	cin >> N;

	vll VS(N);
	vll WS(N);
	for (int i = 0; i < N; i++) {
		cin >> VS[i] >> WS[i];
	}

	int G;
	cin >> G;
	ll ans = 0;
	for (int i = 0; i < G; i++) {
		ll WI;
		cin >> WI;

		vll2d memo(N, vll(WI+1,-1));
		ans += knapSack(N-1, WI, VS, WS, memo);
	}
	cout << ans << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  cin >> t;
  while (t--) solve();
}

// AC, binary knapsack
