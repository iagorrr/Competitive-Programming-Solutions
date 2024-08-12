/*{=======================~ BEGIN MACRO ~================================*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define endl '\n'

#define fastio                        \
        ios_base::sync_with_stdio(0); \
        cin.tie(0);

#define int long long

#define all(j) j.begin(), j.end()
#define rall(j) j.rbegin(), j.rend()
#define len(j) (int)j.size()
#define rep(i, a, b) \
        for (common_type_t<decltype(a), decltype(b)> i = a; i < b; i++)
#define rrep(i, a, b) \
        for (common_type_t<decltype(a), decltype(b)> i = a; i > b; i--)
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
using vii = vector<pii>;
using vc = vector<char>;
using vs = vector<string>;

template<typename T, typename U> inline bool chmax(T &a, U const& b) {
       	return (a < b ? a = b, 1 : 0); }
template<typename T, typename U> inline bool chmin(T &a, U const& b) {
       	return (a > b ? a = b, 1 : 0); }


/*=========================~ END MACRO ~================================}*/

auto run() {
        int N,D;
        cin>>N>>D;

        const int MAXC=1'000'000;
        vi XS(N),YS(N);
        rep(i,0,N){
                cin>>XS[i]>>YS[i];
                XS[i]+=2*MAXC;
                YS[i]+=2*MAXC;
        }

        sort(all(XS)),sort(all(YS));

        vll fx(MAXC*4+1),fy(MAXC*4+1);

        int px=0,leq=0,gre=N;
        ll sdx=accumulate(all(XS),0ll);
        rep(x,0,MAXC*4+1){
                fx[x]=sdx;
                while(px<N&&XS[px]==x)
                        leq++,gre--,px++;
                sdx-=gre;
                sdx+=leq;
        }

        int py=0;leq=0,gre=N;
        ll sdy=accumulate(all(YS),0ll);
        rep(y,0,MAXC*4+1){
                fy[y]=sdy;
                while(py<N&&YS[py]==y)
                        leq++,gre--,py++;
                sdy-=gre;
                sdy+=leq;
        }


        ll ans=0;
        sort(rall(fx)),sort(all(fy));
        int p=-1;
        rep(x,0,MAXC*4+1){
                while(p+1<len(fy)&&fx[x]+fy[p+1]<=D)
                        p++;
                 
                ans+=(p+1);
        }


        cout<<ans<<endl;
}

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



/*{
        Muito provavelmente vai linear em uma das dimensões
        e faz um lower bound e upper bound pra saber o l e r
        que da pra ir na outra dimensão

        se estou num X fixo o mais longe dele é sempre o menor
        xi ou o maior xi

        esse mais distatne é meu limitante ?

        quando to testando o y pra um dado x é só pegar o menor x e o menor
        y tbm kkk

        tem que ver pro cara que tá o mais longe possível do x atual
        qual é o menor/maior y que ele permite

        mas se o ponto dele for muito baixo ele vai torar todo mundo

        AC, math, geometry, sliding window
  }*/
