#include <bits/stdc++.h>
using namespace std;

#define int long long
using ll = long long;

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N,M,C;cin>>N>>M>>C;
	int c1,c2;c1=c2=0;
	vector<priority_queue<int>> st(M);
	for(int i=0;i<N;i++){
		int a,b;cin>>a>>b;
		a--,b--;
		if(st[a].size()<C){
			st[a].emplace(i);
			c1++;
			continue;
		}
		if(st[b].size()<C){
			st[b].emplace(i);
			c2++;
			continue;
		}
	}
	cout<<c1<<' '<<c2<<'\n';
}

// AC, ad-hoc 
