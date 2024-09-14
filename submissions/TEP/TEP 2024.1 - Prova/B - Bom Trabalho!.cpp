#include<bits/stdc++.h>
using namespace std;

template<typename t>
using Point = pair<t,t>;
#define x first
#define y second

using ll = long long;

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Point<ll> p,q;
	cin>>p.x>>p.y;
	cin>>q.x>>q.y;

	ll a = p.y-q.y;
	ll b =  q.x-p.x;
	ll c = p.x*q.y-p.y*q.x;
	ll ans=0;
	ll r,n;cin>>r>>n;
	while(n--){
		ll x,y;cin>>x>>y;
		if(a*x+b*y+c!=0){
			ans+=r;
		}
	}
	if(ans==0){
		cout<<"Bom trabalho!"<<'\n';
	}
	else
		cout<<ans<<'\n';
}


