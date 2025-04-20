#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(0));
	int N, M;
	cin >> N >> M;
	vector<pair<int,int>> pts(M);
	for(auto&[a,b]:pts)
		cin>>a>>b, a--,b--;
	map<pair<int,int>, int> g;
	for(auto&[a,b]:pts){
		b =(b + a)%N;
		a = 0;
		g[{a,b}]++;
	}
	int tot = 0;
	for(auto&[p,v]:g)tot+=v;
	int ans = 0;
	for(auto&[p,v]:g){
		ans += v * (tot-v);
	}
	cout<<ans/2ll<<'\n';
}


// AC, geometry
