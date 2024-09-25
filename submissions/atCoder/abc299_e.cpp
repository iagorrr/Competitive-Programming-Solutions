#include<bits/stdc++.h>
using namespace std;
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;cin>>n>>m;
	vector<vector<int>> g(n);
	for(int i=0;i<m;i++){
		int u,v;cin>>u>>v;
		u--,v--;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	int k;cin>>k;
	vector<int>black(n,1);
	vector<pair<int,int>> query;
	for(int i=0;i<k;i++){
		int pi,di;cin>>pi>>di;
		pi--;
		query.emplace_back(pi,di);
		if(!di)continue;
		vector<int>vis(n,2*n);
		vis[pi]=0;
		queue<int>q;
		q.emplace(pi);
		while(size(q)){
			auto u=q.front();q.pop();
			if(vis[u]<di)
				black[u]=false;
			for(auto v:g[u]){
				if(vis[v]>vis[u]+1){
					vis[v]=vis[u]+1;
					q.emplace(v);
				}
			}
		}
	}

	bool ans=true;
	for(auto&[pi,di]:query){
		vector<int>vis(n,2*n);
		vis[pi]=0;
		queue<int>q;
		q.emplace(pi);
		bool ok=false;
		while(size(q)){
			auto u=q.front();q.pop();
			if(vis[u]==di&&black[u]){
				ok=true;
				break;
			}
			for(auto v:g[u]){
				if(vis[v]>vis[u]+1){
					vis[v]=vis[u]+1;
					q.emplace(v);
				}
			}
		}
		ans&=ok;
	}
	ans&=(count(black.begin(),black.end(),1)>0);
	if(ans){
		cout<<"Yes\n";
		for(auto i:black){
			cout<<i;
		}
		cout<<'\n';
	}
	else{
		cout<<"No\n";
	}
}
// AC, graphs, shortest paths
