#include<bits/stdc++.h>
using namespace std;
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;cin>>n;
	vector<pair<int,int>>ans;
	vector<vector<int>> adj(n,vector<int>(n,1));
	for(int i=0;i<n;i++)adj[i][i]=0;
	int x=0,y=n-1;
	if(n&1)y--;
	while(~y){
		adj[x][y]=0;
		x++,y--;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(adj[i][j])ans.emplace_back(i+1,j+1);
		}
	}
	cout<<ans.size()<<'\n';
	for(auto[u,v]:ans)cout<<u<<' '<<v<<'\n';
}
// AC, graphs
