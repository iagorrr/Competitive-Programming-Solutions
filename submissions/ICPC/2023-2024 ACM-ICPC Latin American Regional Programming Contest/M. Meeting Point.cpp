#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using Edge=pair<ll,int>;
using Graph=vector<vector<Edge>>;

const ll oo=1e10;
vector<ll> dists(int s, const Graph&adj, int p){
	int n=size(adj);
	vector<ll> ret(n,oo);
	priority_queue<Edge,vector<Edge>,greater<Edge>> pq;
	ret[s]=0;
	pq.emplace(0,s);
	while(!pq.empty()){
		auto [du,u]=pq.top();
		pq.pop();
		if(du>ret[u])continue;
		for(auto&[w,v]:adj[u]){
			if(v==p)continue;
			if(ret[v]>w+du){
				ret[v]=w+du;
				pq.emplace(w+du,v);
			}
		}
	}
	return ret;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;cin>>n>>m;
	int p,g;cin>>p>>g;
	p--,g--;
	Graph adj(n);
	while(m--){
		int u,v;cin>>u>>v;
		ll w;cin>>w;
		u--,v--;
		adj[u].emplace_back(w,v);
		adj[v].emplace_back(w,u);
	}
	auto dp=dists(p,adj,-1);
	auto dg=dists(g,adj,-1);
	auto dpg=dists(p,adj,g);
	/*
	for(auto ds : {dp,dg,dpg})
		for(int i=0;i<n;i++){
			cerr<<ds[i]<<" \n"[i+1==n];
		}
		*/

	vector<int>ans;
	for(int i=0;i<n;i++){
		if(dp[i] == dp[g] + dg[i] && dpg[i]>dp[i] && dp[g]==dg[i]){
			ans.push_back(i);
		}
	}
	if(!size(ans)){
		cout<<"*\n";
	}
	else{
		for(auto i:ans)cout<<i+1<<' ';
		cout<<'\n';
	}
}

// AC, shortest paths
