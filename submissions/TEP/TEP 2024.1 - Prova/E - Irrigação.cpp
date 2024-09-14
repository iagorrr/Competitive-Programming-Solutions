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
	Point<ll> c;
	ll m;
	cin>>c.x>>c.y;
	cin>>m;m*=m;
	ll mx=-1;
	int n;cin>>n;
	while(n--){
		Point<ll> p;
		cin>>p.x>>p.y;
		ll dx=p.x-c.x;
		ll dy=p.y-c.y;
		mx=max(mx,dx*dx+dy*dy);
	}
	if(mx>m){
		cout<<-1<<'\n';
	}
	else{
		m/=m;
		ll ans=sqrt(mx);
		if(ans*ans<mx)ans++;
		cout<<ans<<'\n';
	}

}


