// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(xxxx) for(auto &xxx : xxxx) cin >> xxx;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

string change(string s) {
  for(auto &c : s) {
    if(c == 'l') c = '1';
    if(c == 'o') c = '0';
  }
  return s;
}

void run(){
  int n; cin >> n;
  string s, t;
  cin >> s >> t; 

  s= change(s); 
  t= change(t);

  cout << (t == s ? "Yes" : "No") << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// AC, ad-hoc
