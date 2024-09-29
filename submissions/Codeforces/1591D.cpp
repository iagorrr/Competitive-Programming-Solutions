/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
using namespace std;
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
//#define inte ll
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

int min_swaps(vector<int>&ps){
	int ans=0;
	for(int i=0;i<len(ps);i++){
		while(ps[i]!=i){
			swap(ps[i],ps[ps[i]]);
			ans++;
		}
	}
	return ans;
}

void run() {
	int n;cin>>n;
	vector<int>xs(n);
	trav(xi,xs)cin>>xi,xi--;
	if(set<int>(all(xs)).size()<n){
		cout<<"YES\n";
		return;
	}
	int ms=min_swaps(xs);
	cout<<((ms&1)?"NO":"YES")<<endl;
}

/*8<
  se o size for <= 2 não tiver ordenado fudeo
  ja sorted eh vapo

  AC, math, permutations
>8*/
