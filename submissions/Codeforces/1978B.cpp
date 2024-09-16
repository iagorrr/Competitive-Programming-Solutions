#include<bits/stdc++.h>
using namespace std;

using ld=long double;
using ll=long long;

template<auto cmp=greater<ll>()>
ll ternarySearch(ll l, ll r, auto f){
	const ll eps=3;
	while(r-l>=eps){
		ll m1=l+(r-l)/3;
		ll m2=r-(r-l)/3;
		if(cmp(f(m1),f(m2)))r=m2;
		else l=m1;
	}
	for(ll i=l;i<=r;i++)
		if(cmp(f(i),f(l)))l=i;
	return l;
}


using ll = long long;
void run(){
	ll n,a,b;
	cin>>n>>a>>b;
	auto f=[&](ll k){
		ll reg=(n-k)*a;
		ll other=k*b+k-(k*(k+1))/2;
		return reg+other;
	};
	auto mxx=ternarySearch(0ll,min(n,b),f);
	cout<<f(mxx)<<'\n';
}
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;cin>>t;
	while(t--){
		run();
	}
}

// AC, ternary search
