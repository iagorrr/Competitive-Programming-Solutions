#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int)__x.size()
using ll = long long;
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

const ll INF = 1e18;

// impossível :
// adicionei, fiz query e tava ordenado, dai tirei e ficou desordenado
// deixei só um elemento e estava desordenado
// vazio e estar desordenado

// possível:
// partir de um ordenado ou vazio e a query ser ordenado
bool run() {
  string s;
  cin >> s;

  int desordenados = 0;
  vector<pair<char, int>> cur;
  char numsei = '?';
  char ordem = '1';
  char desordem = '0';
  int i = 0;
  int sz = 0;
  for (auto &c : s) {
    if (c == ordem or c == desordem) {
      if (c == desordem) {
        if (sz <= 1) return false;
        if (cur.back().fst == ordem) return false;
        if (cur.back().fst == numsei) {
          if (cur.back().snd == 1)
            cur.back().fst = desordem;
          else {
            cur.back().snd--;
            cur.emplace_back(desordem, 1);
          }

          desordenados++;
          continue;
        }
      }
      if (c == ordem) {
        if (sz <= 1) continue;
        if (desordenados >= 1) {
          return false;
        }
        if (cur.back().fst == desordem) {
          return false;
        }
        if (cur.back().fst == numsei) {
          cur = vector<pair<char, int>>();
          cur.emplace_back(numsei, 1);
          if (sz > 1) cur.emplace_back(ordem, sz - 1);
          continue;
        }
      }
    } else {
      if (c == '+') {
        if (sz >= 1 and cur.back().fst == numsei) cur.back().snd++;
        else cur.emplace_back(numsei, 1);
        sz++;
      } else {
        if (sz >= 1 and cur.back().fst == desordem) desordenados--;
        if(sz >= 1 and cur.back().snd == 1)
          cur.pop_back();
        else
          cur.back().snd--;
        sz--;
      }
    }
    i++;
  }
  return true;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    if (run())
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}

// AC, data structures, implementation
