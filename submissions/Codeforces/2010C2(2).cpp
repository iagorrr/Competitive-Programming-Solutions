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
#define rep(i, a, b)                           \
  for (common_type_t<decltype(a), decltype(b)> \
           i = (a);                            \
       i < (b); i++)
#define rrep(i, a, b)                          \
  for (common_type_t<decltype(a), decltype(b)> \
           i = (a);                            \
       i > (b); i--)
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) \
  for (auto &xi : ranges::views::reverse(xs))
using ll = long long;
#define int ll
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
using pqmn =
    priority_queue<T, vector<T>, greater<T>>;
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
  @Title: Z-function get occurence positions
  @Time: $O(len(s) + len(p))$
>8*/
vi getOccPos(string& s, string& p) {
  // Z-function
  char delim = '#';
  string t{p + delim + s};
  vi zs(len(t));

  int l = 0, r = 0;
  for (int i = 1; i < len(t); i++) {
    if (i <= r) zs[i] = min(zs[i - l], r - i + 1);
    while (zs[i] + i < len(t) and
           t[zs[i]] == t[i + zs[i]])
      zs[i]++;
    if (r < i + zs[i] - 1)
      l = i, r = i + zs[i] - 1;
  }

  // Iterate over the results of Z-function to get
  // ranges
  vi ans;
  int start = len(p) + 1 + 1 - 1;
  for (int i = start; i < len(zs); i++) {
    if (zs[i] == len(p)) {
      int l = i - start;
      ans.emplace_back(l);
    }
  }
  return ans;
}

template <class T>
std::vector<int> z_algorithm(
    const std::vector<T>& s) {
  int n = int(s.size());
  if (n == 0) return {};
  std::vector<int> z(n);
  z[0] = 0;
  for (int i = 1, j = 0; i < n; i++) {
    int& k = z[i];
    k = (j + z[j] <= i)
            ? 0
            : std::min(j + z[j] - i, z[i - j]);
    while (i + k < n && s[k] == s[i + k]) k++;
    if (j + z[j] < i + z[i]) j = i;
  }
  z[0] = n;
  return z;
}

std::vector<int> z_algorithm(
    const std::string& s) {
  int n = int(s.size());
  std::vector<int> s2(n);
  for (int i = 0; i < n; i++) {
    s2[i] = s[i];
  }
  return z_algorithm(s2);
}

void run() {
  str S;cin>>S;
  auto zs=z_algorithm(S);
  rep(i,1,len(zs)){
    if(zs[i]>=i&&i<len(S)-i){
      cout<<"YES"<<endl;
      cout<<S.substr(0,len(S)-i)<<endl;
      return;
    }
  }
  cout<<"NO"<<endl;
}

/*8<
  AC, strings, Z-function
>8*/
