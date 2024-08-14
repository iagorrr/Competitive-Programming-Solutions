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
#define eb emplace_back

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
using vs = vector<string>;

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

  cin>>T;

  rep(t, 0, T) {
    dbg(t);
    run();
  }
}

/*===============~ END TEMPLATE ~==============}*/

/*{
  dividir no mínimo de segmentos

  tal que pra todo segmento não exista um subset
  daquele segmento tal que o produto de X

  não da pra fazer guloso e manter um
  histograma de primos na fatoração que quando a
  todos os histrogramas dos primos de x
  forem maiores igual as potencias do x
  eu quebro e reseto pra esse número uqe torou 
  tudo ??
  8
  6 4
  2 3 | 6 | 2 | 1 2

  tem que dar exatamente então nao basta dar
  maior, tem que ter um subset do produto
  fechadinho

  se ai não divide x eu nem considero

  olho pro ai que divide X
  se consigo fazer X/ai com os valores
  que já tenho então não posso pegar esse
  ai, vou ter que quebrar

  so precsio manter um vetor de bool
  pros divisores de x

  da fica mais facil de atualizar

  toda vez que entra um ai que é divisor de x
  eu consigo fazer pra todo divisor
  que eu já tinha aquele divisor * ai
  raiz quadradaa em 10^2.5
  da pra atualizar linear toda vez ?
  eh 4 segundos   da né
  tá 10 ^7.5

  acho que é isso

  WA o 2

  acho que tem que escolher otimamente onde
  vai dividir ainda ?
acho que n
  codei errado so

  se ele me der o número eu to trolando
  pq n tem o numero dividido por um e bla..

  AC !

  não tava checando se o ai de fato dividia o num
  ero que ue tava olhadno

  AC, math, number theory, dynamic programming
}*/
const int MAXX=1'00'000;
vll list_divisors(ll x){
  vll ret;
  for(ll d=1;d*d<=x;d++){
    if(!(x%d)){
      ret.eb(d);
      if(x/d!=d)ret.eb(x/d);
    }
  }
  sort(rall(ret));
  return ret;
}
void run() {
  int N,X;cin>>N>>X;
  vll AS(N);for(auto&ai:AS)cin>>ai;
  vll dxs=list_divisors(X);
  vi have(MAXX+1,0);
  have[1]=1;

  int ans=1;
  for(auto&ai:AS){
    dbg(ai,ans);
    if(X%ai)continue;
    if(have[X/ai]){
      ans++;
      for(auto&dxi:dxs)
        have[dxi]=0;
      have[ai]=have[1]=1;
      continue;
    }
    for(auto&dxi:dxs){
      if(!(dxi%ai))
        have[dxi]|=(have[dxi/ai]);
    }
  }
  cout<<ans<<endl;
}
