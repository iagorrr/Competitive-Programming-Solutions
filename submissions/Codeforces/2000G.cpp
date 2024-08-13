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
/*{=========================~ BEGIN MAX CHECK ~==========================*/

/*
	Returns the maximum value in range [l, r] that satisfies the
	lambda function check, if there is no such value the minimal 
	possible value for that type will be returned.
 */

template<typename T>
T maxCheck(T l, T r, function<bool(T)> check) {
        T best = numeric_limits<T>::min();
        while(l<=r){
                T m=midpoint(l,r);
                if(check(m))chmax(best,m),l=m+1;
                else r=m-1;
        }
        return best;
}

/*===========================~ END MAX CHECK ~==========================}*/

using edge=tuple<int,ll,ll>;
auto run() {
	int N, M;
	cin>>N>>M;
	vector<vector<edge>> adj(N);
	int T0,T1,T2;
	cin>>T0>>T1>>T2;
	rep(i,0,M){
		int u,v;
		ll w1,w2;
		cin>>u>>v>>w1>>w2;
		u--,v--;
		adj[u].eb(v,w1,w2);
		adj[v].eb(u,w1,w2);
	}

	const ll OO=numeric_limits<ll>::max();
	function<bool(int)>check=[&](int s){
		vll ds(N,OO);
		ds[0]=s;
		priority_queue<pair<ll,int>,
			vector<pair<ll,int>>,
			greater<>> pq;
		pq.emplace(s,0);

		while(len(pq)){
			auto[du,u]=pq.top();
			pq.pop();
			if(du>ds[u])continue;

			for(auto&[v,w1,w2]:adj[u]){
				if(du<=T1&&du+w1>T1){
					ll ndv=min(T2+w1,du+w2);
					if(chmin(ds[v],ndv))
						pq.emplace(ds[v],v);
				}
				else if(T1<du&&du<T2){
					ll ndv=min(T2+w1,du+w2);
					if(chmin(ds[v],ndv))
						pq.emplace(ds[v],v);
				}
				else{
					if(chmin(ds[v],du+w1))
						pq.emplace(ds[v],v);
				}
			}
		}

		return ds[N-1]<=T0;
	};

	auto ans=maxCheck(0ll, 1'000'000'000ll,check);
	if(ans==numeric_limits<int>::min())ans=-1;
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
  grafo simples e conexo

  ponderado com minutso dos buses
  posso andar tbm, que SEMPRE demora mais que o ônibus

  to em 1 no tempo 0
  quero chegar no N até o tempo t0

  tenho uma call de t1->t2, nesse tempo não posso andar de bus
  posso sair imediatamente em t1 e voltar imediatamente em t2

  busca binária n resopsta ?

  AC, graphs, shortest paths, binary search
  }*/


