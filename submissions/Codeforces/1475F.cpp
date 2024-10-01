/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define endl '\n'
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
using Graph = vector<vector<pair<ll, int>>>;
/*8<============~ END TEMPLATE ~============}>8*/
/*8<
  @Description:

    Calculates a valid assignment to boolean
    variables a, b, c,... to a 2-SAT
    problem, so that an expression of the type
    $(a||b)\&\&(!a||c)\&\&(d||!b)\&\&...$ becomes
    true, or reports that it is unsatisfiable.

  @Usage:

    Negated variables are represented by
    bit-inversions (\texttt{$\tilde{}x$}).

    Returns true iff it is solvable
    ts.values[0..N-1] holds the assigned values
    to the vars.

  @Time:

    $O(N+E)$, where N is the number of boolean
    variables, and E is the number of clauses.

>8*/

struct TwoSat {
  int N;
  vector<vi> gr;
  vi values;  // 0 = false, 1 = true

  TwoSat(int n = 0) : N(n), gr(2 * n) {}

  int addVar() {  // (optional)
    gr.eb();
    gr.eb();
    return N++;
  }

  void implies(int f, int j){
	  either(~f,j);
  }

  void either(int f, int j) {
    f = max(2 * f, -1 - 2 * f);
    j = max(2 * j, -1 - 2 * j);
    gr[f].pb(j ^ 1);
    gr[j].pb(f ^ 1);
  }
  void setValue(int x) { either(x, x); }

  void atMostOne(const vi &li) {  // (optional)
    if (len(li) <= 1) return;
    int cur = ~li[0];
    rep(i, 2, len(li)) {
      int next = addVar();
      either(cur, ~li[i]);
      either(cur, next);
      either(~li[i], next);
      cur = ~next;
    }
    either(cur, ~li[1]);
  }

  vi val, comp, z;
  int time = 0;
  int dfs(int i) {
    int low = val[i] = ++time, x;
    z.pb(i);
    for (int e : gr[i])
      if (!comp[e]) low = min(low, val[e] ?: dfs(e));
    if (low == val[i]) do {
        x = z.back();
        z.pop_back();
        comp[x] = low;
        if (values[x >> 1] == -1) values[x >> 1] = x & 1;
      } while (x != i);
    return val[i] = low;
  }

  bool solve() {
    values.assign(N, -1);
    val.assign(2 * N, 0);
    comp = val;
    rep(i, 0, 2 * N) if (!comp[i]) dfs(i);
    rep(i, 0, N) if (comp[2 * i] == comp[2 * i + 1]) return 0;
    return 1;
  }
};

void run(){
	int n;cin>>n;
	vector<string>a(n),b(n);
	for(auto&ai:a)cin>>ai;
	for(auto&bi:b)cin>>bi;
	TwoSat sat(2*n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int u=i,v=n+j;
			if(a[i][j]!=b[i][j]){
				sat.implies(~u,v);
				sat.implies(u,~v);
				sat.implies(~v,u);
				sat.implies(v,~u);
			}
			else{
				sat.implies(u,v);
				sat.implies(~u,~v);
			}
		}
	}
	cout<<(sat.solve()?"YES":"NO")<<'\n';
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;cin>>t;
	while(t--){
		run();
	}
}

// AC, two sat

