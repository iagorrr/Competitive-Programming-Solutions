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
	int N;
	cin>>N;
	vll XS(N);
	for(auto&xi:XS)
		cin>>xi;


	string S;
	cin>>S;

	vi pl, pr;
	rep(i,0,N){
		if(S[i]=='L')pl.eb(i);
		else pr.eb(i);
	}

	vll psum(N);
	psum[0]=XS[0];
	rep(i,1,N){
		psum[i]=XS[i]+psum[i-1];
	}

	reverse(all(pl));
	ll ans=0;
	
	while(len(pl)&&len(pr)){
		int l=pl.back();
		int r=pr.back();
		if(r<l)break;
		ans+=(psum[r]-(l?psum[l-1]:0));
		pl.pop_back(),pr.pop_back();
	}
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
  AC, greddy, prefix sum
  }*/


