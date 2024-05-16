#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int) __x.size()
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

void run() {
	array<int, 3> l;
	for (int i = 0; i < 3; i++) cin >> l[i];
	sort(l.rbegin(), l.rend());
	
	bool ans = false;
	ans |= l[0]-l[1] == l[2];
	ans |= l[0] == l[1] and !(l[2]&1);
	ans |= l[1] == l[2] and !(l[0]&1);
	if(ans) cout << "YES\n";
	else cout << "NO\n";
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  cin >> t;
  while (t--) run();
}
// AC, geometry
