#include <bits/stdc++.h>
using namespace std;

#define int long long
using ll = long long;

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll a;cin>>a;
	int m;cin>>m;
	multiset<ll> st;
	vector<ll>xs(m);for(auto&xi:xs){
		cin>>xi;
		st.emplace(xi);
	}

	for(auto xi:xs){
		if(a%xi)continue;
		if(st.find(a/xi)==st.end())
			continue;
		int a1=xi;
		int a2=a/xi;
		if(a1>a2)swap(a1,a2);
		cout<<a1<<' '<<a2<<'\n';
		return 0;
	}

}
 
// AC, math
