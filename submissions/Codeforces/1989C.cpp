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
using vpii = vector<pii>;
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

#define INV(XS) for(auto&xi:XS)cin>>xi;
auto run() {
	int N;
	cin>>N;

	vpii XS(N);	
	for(auto&[a,_]:XS)cin>>a;
	for(auto&[_,b]:XS)cin>>b;
	sort(rall(XS));

	int cnt1=0;
	for(auto&[ai,bi]:XS)
		cnt1+=((ai==bi)&&(abs(ai)==1));

	function<bool(int)>check=[&](int m)->bool{
		int a=0,b=0;
		for(auto&[x,y]:XS){
			if(x==0&&y==-1)
				continue;
			if(x<1)b+=y;
			else a+=x;
		}

		for(auto&[x,y]:XS){
			if(a>=m&&b>=m)break;
			if(x<1)break;
		}

		if(a<m)return false;
		int r=min(a-m,cnt1);
		return b+r>=m;
	};

	const int oo=1'000'000'000ll;
	auto ans=maxCheck(-oo,oo,check);
	ans=(ans==numeric_limits<int>::min()?-1:ans);
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
	give all to a single movie
	then just try to increase the
       	answer by tranfering a few votes

	AC, binary search, greddy
  }*/
