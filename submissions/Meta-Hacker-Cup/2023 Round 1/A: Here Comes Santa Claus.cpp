#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
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

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D", "LD", "L"});
// int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
// int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll oo = 1e18;

auto solve() {
  ll N;
  cin >> N;
  vll XS(N);
  for (auto &xi : XS) cin >> xi;
  sort(all(XS));
  // cout << "li " << N << endl;

  ld a = 0, b = 0;
  for (int i = 0; i < 2; i++) a += XS[i];

  for (int i = N - 1; i >= N - 2; i--) b += XS[i];

  ld ans = 0;

  ld pa = a / 2.00;
  ld pb = b / 2.00;
  ans = pb - pa;

  if (N == 5) {
    a = XS[0] + XS[2];
    b = XS[N - 1] + XS[N - 2];

    pa = a / 2.00;
    pb = b / 2.00;
    ans = pb - pa;

    a = XS[0] + XS[1];
    b = XS[N - 1] + XS[N - 3];

    pa = a / 2.00;
    pb = b / 2.00;
    ans = max(ans, pb - pa);
  }
  cout << fixed << setprecision(10) << ans;
}
int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  int t;
  t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
    cout << endl;
  }
}

// AC, math
