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
	int N,M,K;
	cin>>N>>M>>K;
	int W;
	cin>>W;
	vll AS(W);
	for(auto&ai:AS)
		cin>>ai;

	vll per;
	rep(i,1,N+1){
		rep(j,1,M+1){
			ll l=max(K-(M-j),1ll);
			ll r=min(j,K);
			ll u=max(K-(N-i),1ll);
			ll d=min(i,K);
			ll h=d-u+1,v=r-l+1;
			per.eb(h*v);
		}
	}

	sort(rall(per));
	sort(rall(AS));
	ll ans=0;
	rep(i,0,W){
		ans=ans+AS[i]*per[i];
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
  }*/


