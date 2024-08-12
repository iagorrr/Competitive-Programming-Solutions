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

template<typename T>
T maxCheck(T l, T r, auto check) {
        T best = numeric_limits<T>::min();
        while(l <= r){
                T m=midpoint(l,r);
                if(check(m)) {
                        best=max(best,m);
                        l=m+1;
                }
                else r=m-1;
        }
        return best;
}

auto run() {	
        int N, K;
        cin >> N >> K;

        vii XS(N);
        for(auto&[ai,_]:XS)
                cin>>ai;

        for(auto&[_,bi]:XS)
                cin>>bi;

        sort(all(XS));
        
        int ans=0;

        int m1=XS[(N-2)/2].first;
        int m2=XS[N/2].first;
        rep(i,0,N){
                auto&[ai,bi]=XS[i];
                if(bi){
                        if(i<N/2)chmax(ans,ai+K+m2);
                        else chmax(ans,ai+K+m1);
                }
        }

        auto check=[&](int m)->bool{
                int mx=XS.back().first;
                m-=mx;
                if(m<=0)return true;
                int cost=0,done=0;
                rrep(i,N-2,0-1){
                        if(done>=(N+1)/2)break;
                        auto&[ai,bi]=XS[i];
                        if(bi and ai<m){
                                cost+=(m-ai);
                                done++;
                        }
                        done+=(ai>=m);
                }
                return cost<=K&&done>=(N+1)/2;
        };
        chmax(ans,maxCheck((int)1,(int)(2*1e9+1),check));
        cout<<ans<<endl;
}

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

/*{
	k = 0
	A B C D E
          ^     ^
	A B C D
          ^   ^ 
        -> sempre pega o maior elemento
                se for impar vai pegar um
                elemento atrás da mediana

                se for par vai pegar a
                mediana ainda...
                        
        ou seja quado K = 0 sempre pega o maior
        valor e o maior valor da esquerda

        queremos maximizar a soma do mx left
        e mx right

        dividir entre incrementar a mediana ou o maior                
        elemento ??
        8

        2 10
        3 3
        1 1

        vejo se da pra aumentar o valor máximo de alguma forma
        pode ter casos que vale mais apena aumentar a mediana


        3 10
        3 3 3
        0 0 0

        4 4
        2 1 5 1
        0 1 0 1

        5 4
        7 5 2 5 4
        0 0 1 0 1
        
        5 1
        5 15 15 2 11
        1 0 0 1 1

        5 2
        10 11 4 10 15
        1 1 0 1 0

        4 4
        1 1 2 5
        1 1 0 0

        2 1000000000
        1000000000 1000000000
        1 1

                                                                      
        ou vai tudo no maior elemento ou vai tudo na mediana ?
        prova as suas suposições !

        AC, binary search, greedy
        } */
