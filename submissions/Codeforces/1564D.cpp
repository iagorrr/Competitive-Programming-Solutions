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

  cin >> T;

  rep(t, 0, T) {
    dbg(t);
    run();
  }
}
/*8<
  @Title: Binomial MOD
  @Description: find $\binom{n}{k} \pmod{MOD}$
  @Time:
    \begin{compactitem}
      \item precompute: on first call it takes
      $O(MAXNBIN)$ to precompute the factorials
      \item query: $O(1)$.
    \end{compactitem}
  @Memory: $O(MAXNBIN)$
  @Warning: Remember to set $MAXNBIN$ properly !
>8*/
const ll MOD = 998244353;
inline ll binom(ll n, ll k) {
  static const int BINMAX = 2'000'000;
  static vll FAC(BINMAX + 1), FINV(BINMAX + 1);
  static bool done = false;
  if (!done) {
    vll INV(BINMAX + 1);
    FAC[0] = FAC[1] = INV[1] = FINV[0] = FINV[1] = 1;
    for (int i = 2; i <= BINMAX; i++) {
      FAC[i] = FAC[i - 1] * i % MOD;
      INV[i] = MOD - MOD / i * INV[MOD % i] % MOD;
      FINV[i] = FINV[i - 1] * INV[i] % MOD;
    }
    done = true;
  }

  if (n < k || n < 0 || k < 0) return 0;
  return FAC[n] * FINV[k] % MOD * FINV[n - k] % MOD;
}

void run() {
	int _;cin>>_;
	string s;
	cin>>s;
	int n=0;
	int k=0;
	for(int i=0;i<len(s);i++){
		if(i+1<len(s)&&s[i]==s[i+1]&&(s[i]=='1')){
			n++;
			i++;
		}
		else {
			k+=(s[i]!='1');
		}
	}
	k++;
	dbg(n,k);
	cout<<binom(n+k-1,n)<<'\n';

}

/*8<
  even only reach even
  odd only reach odd

  is like we're moving pairs of numbers one 

  011011
  110011
  110110

  111100<- can become this

  every case can be converted to it ?

  if i have two numbers one adjacent

  i can aways put them to the first positions

  10001111110110111000
  10011011110110111000
  ...
  11100011110110111000
  11100110110110111000

  if i have:
  0000000000111000000000000
  can only move the midle 1
  and one of the 1 will be
	alone :(

  0000000001111000000000000
  this one can become a 'regular' string
  because is even ?

  5 1's:
  00000000011111000000000000
  00000000011101100000000000
  00000000110101100000000000
  00000000110111000000000000
  
  okay if is odd one of them stay behind

  same quantity of one's probably same total ways...

  if i can move two by two
  if i have a block with odd lenght it will remain odd
  lenght alwyas...

  if it's even it's easy, just every way such that there
  is no continuos segment of one's with odd quantitty

  count how many maks of size n with k numbers as 1
  such that i have x contingous 1's with odd lenght

  quantitiy of 1 segments with odd lenght will always
  be the same as the initial

  we want to take N

  split it in a few groups

  such that X of them will have odd lenght

  essentialy we can remove X of N, build 
  only even segments

  and them choose X of the segments and make them
  with odd lenght

  so ways to divice (N-X) in AT LEAST X groups

	them we still need to choose X of these groups
	to sum 1

	and still a way to put the zeroes


	n = 20
	11101111011000100010
	3      4  2   1   1
	tot1=11

	we have 3 segments with odd lenght

	so we want a way to split 11-3 in

	the problem now is :
		how many maks exists such that:
		- N bits
		- M bits are one
		- there is exaclty K segments of 1's
		that have odd lenght

		let's brute force !

	10001111110110111000
	1000A A A 0A 0A 1000

	AC, combinatorics
>8*/
