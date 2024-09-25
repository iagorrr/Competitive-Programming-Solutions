#include<bits/stdc++.h>
using namespace std;
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;cin>>n;
	vector<int>ps(n);for(auto&i:ps)cin>>i,i--;
	vector<int>pos(n);
	for(int i=0;i<n;i++){
		pos[ps[i]]=i;
	}
	vector<int>vis(n);
	int mx=0;
	for(int i=0;i<n;i++){
		if(vis[i])continue;
		int cur=1;
		int j=i;
		while(j<n-1&&!vis[j]&&pos[j]<pos[j+1]){
			vis[j]=1;
			j++;
			cur++;
		}
		mx=max(mx,cur);
	}
	cout<<n-mx<<'\n';

}

// AC, greddy
