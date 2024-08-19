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
           i = a;                              \
       i < b; i++)
#define rrep(i, a, b)                          \
  for (common_type_t<decltype(a), decltype(b)> \
           i = a;                              \
       i > b; i--)
#define trav(a,x) for (auto& a : x)
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define emp emplace
#define ins insert
#define divc(a,b) (a+b-1ll)/b

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

template <typename T>
using min_heap =
    priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T, vector<T>>;

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
  quero sempre perder o mńimio possível
   
  se tem um cara que perde puco mas precisa
  de mt pra fazer vou nele enquanto der, dai
  quando n rolar mais eu pego o pŕoximo que
  perde menos ?

  5 3
  9 6 7 5 5
  8 4 5 1 2
  1 2 2 4 3

  10 4 7
  9 4 7     + 2
  8 4 7     + 2
  6 4 7     + 2
  4 4 7     + 2
  4 4 5     + 2
  4 4 2     + 2

  resposta sempre par
  faço com o que perde menos e que pra começar
  precisa menor igual a min
  quanto gasto pra resolver pra cada material
  individualmente ?
  deve ser caro

  ordena a quantidade de cada material
  o ai e o bi é 1e6
  da pra mante uma parada de 1e6
  que diz:
    quanto tenho I o mńimo que consigo perder
    é parada[i]

    dae mantenho um histograma de quantos
    eu tenho em cada parada

    e vou movendo eles linearmente

    passo do 1e6 até 1

    a cada movimento incremeenta a respsta

    todo mundo e é maior que 1e6 eu faço os movimentos que precias pra ficar <= 1e65
    
    vpao vapo ?
>8*/
const int MAXAI=1'000'000;
int jmp[MAXAI+1];
int qtd[MAXAI+1];
void run() {
  memset(jmp,-1,sizeof(jmp));
  int N,M;cin>>N>>M;
  using T=tuple<int,int,int>;
  vector<T> XS(N);
  for(auto&[di,ai,bi]:XS)
    cin>>ai;
  for(auto&[di,ai,bi]:XS){
    cin>>bi;di=ai-bi;
  }
  vi CS(M);trav(ci,CS)cin>>ci;
  sort(all(XS));
  int idx=MAXAI;
  for(auto&[di,ai,bi]:XS){
    while(idx>=ai)jmp[idx--]=di;
  }
  ll ans=0;
  trav(ci,CS){
    if(ci>MAXAI){
      ll d=ci-MAXAI;
      ll dec=jmp[MAXAI];
      ll o=divc(d,dec);
      ans+=(o*2ll);
      ci=ci-o*dec;
    }
    qtd[ci]++;
  }
  rrep(i,MAXAI,0){
    if(jmp[i]<0)break;
    ans+=(qtd[i]*2ll);
    qtd[i-jmp[i]]+=qtd[i];
  }
  cout<<ans<<endl;
}
// AC,sortings,greedy
