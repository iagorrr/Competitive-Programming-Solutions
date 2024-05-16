#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...) 42
#endif
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int)__x.size()
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
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)
int lg2(ll x) {
  return __builtin_clzll(1) - __builtin_clzll(x);
}

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D",
// "LD", "L"}); int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}; int
// dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll oo = 1e18;
int T(1);
const int MAXN(1'000'000);

auto run() {
  int n;
  cin >> n;
  vll xs(n);
  for (auto &xi : xs) cin >> xi;

  vector<char> toright(n);
  toright[0] = 1;
  toright[n - 1] = false;
  for (int i = 1; i < n - 1; i++) {
    ll dr = abs(xs[i] - xs[i + 1]),
       dl = abs(xs[i - 1] - xs[i]);
    toright[i] = dr < dl;
  }

  vll acr(n);
  for (int i = 1; i < n; i++) {
    acr[i] = acr[i - 1];
    if (toright[i - 1])
      acr[i]++;
    else
      acr[i] += xs[i] - xs[i - 1];
  }

  vll acl(n);
  acl.back() = 0;
  for (int i = n - 2; i >= 0; i--) {
    acl[i] = acl[i + 1];
    if (!toright[i + 1])
      acl[i]++;
    else
      acl[i] += xs[i + 1] - xs[i];
  }

  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (a < b) {
      cout << acr[b] - acr[a] << '\n';
    } else {
      cout << acl[b] - acl[a] << '\n';
    }
  }
}
int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  cin >> T;

  for (int i = 1; i <= T; i++) {
    run();
  }
}

/*
 * Greddy
 * Prefix sum
 * https://codeforces.com/contest/1922/submission/242288985
 * */
