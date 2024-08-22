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
#define int long long
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
#define trav(a, x) for (auto &a : x)
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define emp emplace
#define ins insert
#define divc(a, b) ((a) + (b)-1ll) / (b)
using str = string;
using ll = long long;
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
template<typename T, typename T2>
using umap=unordered_map<T,T2>;
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
  tenho que ter atingido um dx=x, dy=y
  partindo do ponto 0

  
  se visitava dps do r ou antes do l tá de boa
  vai continuar passando por la
  caso contrário precisa ver neh

  se aconteceu até de [0, l] ou de [r,n-1]
  eh mec

  da pra lançar aquele mo safado nao ?
  pra saber quais variações ocorream ali
  dai sei o dx e o dy que ele entra

  so preciso saber se entrou a variação
  que da match com a cordenada que ele quer
  map de map
  vapo vapo
  acho que sai
>8*/
pii d(char c){
  static const pii dirs[]={
    {0,1},{0,-1},{-1,0},{1,0}
  };
  static const str s="UDLR";
  rep(i,0,4){
    if(s[i]==c)return dirs[i];
  }
  return {-666,-666};
}

void run() {
  int N,Q;cin>>N>>Q;
  str S;cin>>S;
  vpii cord1,cord2;
  umap<int,umap<int,vi>> appears, appears2;
  {
    int x,y;x=y=0;
    rep(i,0,N){
      auto c=S[i];
      auto ds=d(c);
      x+=ds.first;
      y+=ds.second;
      cord1.eb(x,y);
      appears[x][y].eb(i);
    }
  }
  {
    reverse(all(S));
    int x,y;x=y=0;
    rep(i,0,N){
      auto c=S[i];
      auto ds=d(c);
      x+=ds.first;
      y+=ds.second;
      cord2.eb(x,y);
      appears2[x][y].eb(i);
    }
  }
  rep(q,0,Q){
    int x,y,l,r;cin>>x>>y>>l>>r;
    l--,r--;
    if(x==0&&y==0){
      cout<<"YES"<<endl;
      continue;
    }
    if(len(appears[x][y])&&
        (appears[x][y].back()>=r
         ||appears[x][y].front()<l)){
        cout<<"YES\n";
        continue;
        }
    // tem que ta no meio
    int li=(N-1-r),ri=(N-1-l);
    auto [cx,cy]=l?cord1[l-1]:(pii){0,0};
    auto [px,py]=li?cord2[li-1]:(pii){0,0};
    int nx=x-cx,ny=y-cy;;
    dbg(cx,cy);
    dbg(li,ri);
    dbg(px,py);
    nx+=px;
    ny+=py;
    dbg(nx,ny);
    auto it=lower_bound(all(appears2[nx][ny]),li);
    if(it!=end(appears2[nx][ny])&&*it<=ri){
      cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
  }
}

/*
  AC, data structures, binary search,
  implementation
 */
