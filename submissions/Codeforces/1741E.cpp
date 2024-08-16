/*{=============~ BEGIN TEMPLATE ~==============*/
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
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound

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

template <typename T, typename U>
inline bool chmax(T &a, U const &b) {
  return (a < b ? a = b, 1 : 0);
}
template <typename T, typename U>
inline bool chmin(T &a, U const &b) {
  return (a > b ? a = b, 1 : 0);
}

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

/*===============~ END TEMPLATE ~==============}*/

/*{
  Acho que da pra modelar uma
  dpzinha dp(i,j) se a posição i é :
    j:1=pertence a um segmento e só

    j:2=é o tamanho do segmento a esquerda

    j:3=é o tamanho do segmento a direita
    esse é torador

  
    dp(i,j)
    até a posição i

  j:
    1. é borda esquerda
    2. é borda direita
    3. é  nomeio
    4. 1 e 2 e 3 (elemento solo)

  o último segmento é meio definido né

  o tamanho dele é definido a esquerda

  acho que dá certo mas o caso de testar
  meu tamanho temrinando na posição I
  eu só testo se na posição i - ai 

  consegue ser uma borda do da direita

  uma dp pra saber se a posição posição
  i consegue ser uma borda do da frente

  se ele consegue ter o tamanho do da esquerda
  ou se continuando ele consegue achar alguem
  a direita
  mas como saber de onde começou né
  doidera
  

  dp (i, j)
    
    se da pra fazer o solve com o lemento i sendo:
      borda da direita
      borda da esquerda

  o caso do back é de boa pq é só ir resolvendo
  pra trás

  f1(i) só diz se da pra fixar o tamanho
  da sequencia a esquerda de I pra ser ai

  AC, dynamic programming
}*/

void run() {
  int N;cin>>N;
  vi BS(N);for(auto&bi:BS)cin>>bi;
  vi2d atR(N);
  rep(i,0,N){
    auto bi=BS[i];
    if(i-bi>=0)atR[i-bi].eb(i);
  }

  // [ ... ] L R [ ... ]
  //   ...   R [ ... ] R [ ... ]
  // [ ... ] L [ ... ] L
  //   ...   R [ ... ] [ ... ] L

  /*
     dp(i,j)
     se da pra resolver sabendo que o
     cara i é protege o:
       j=1 da esquerda
       j=0 da direita
   */

  const int LEFT=1,RIGHT=0;
  vi2d dp(N, vi(2,-1));
  auto solve=[&](auto&&self,int i,int dir)->int{
    if(i==N)return 1;
    if(i>N)return 0;
    auto&ret=dp[i][dir];
    if(~ret)return ret;
    ret=0;
    if(dir==LEFT){
      if(i+1<N){
        for(auto r:atR[i+1]){
          ret|=self(self,r,LEFT);
        }
      }
      ret|=self(self,i+1,RIGHT);
    }
    else{
      ret|=self(self,i+BS[i]+1,RIGHT);
      if(i+BS[i]+1<N){
        for(auto r:atR[i+BS[i]+1]){
          ret|=self(self,r,LEFT);
        }
      }
    }
    return ret;
  };
  
  dbg(atR);
  bool ans=0;
  for(auto r:atR[0]){
    ans|=solve(solve,r,LEFT);
  }
  ans|=solve(solve,0,RIGHT);
  cout<<(ans?"YES":"NO")<<endl;

}

