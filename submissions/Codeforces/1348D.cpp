#include<bits/stdc++.h>
using namespace std;

void run(){
	int n;
	cin>>n;
	auto check=[&](int d)->bool{
		int s=1;
		int prev=1;
		for(int i=1;i<=d;i++){
			int mx=min(prev*2,(n-s)/(d-i+1));
			s+=mx;
			prev=mx;
		}
		return s==n;
	};
	int best=INT_MAX;
	for(int l=1,r=min(100,n-1);l<=r;){
		int m=midpoint(l,r);
		auto cur=check(m);
		if(cur){
			best=min(best,m);
			r=m-1;
		}
		else l=m+1;
	}
	if(best==INT_MAX){
		cout<<-1<<'\n';
		return;
	}
	vector<int>ans;	ans.reserve(best);
	int s=1;
	int prev=1;
	for(int i=1;i<=best;i++){
		int mx=min(prev*2,(n-s)/(best-i+1));
		ans.push_back(mx-prev);
		s+=mx;
		prev=mx;
	}
	cout<<size(ans)<<'\n';
	for(auto&ai:ans){
		cout<<ai<<' ';
	}
	cout<<'\n';

}
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;cin>>t;
	while(t--){
		run();
	}
}

// AC, greedy, binary search
