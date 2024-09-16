#include<bits/stdc++.h>
using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N,K;cin>>N>>K;
	const int mod=1'000'000'000+7;
	vector memo(N,vector<int>(K,-1));
	function<int(int,int)>solve=[&](int i, int j){
		if(j==K)return (int)0;
		if(i==N)return (int)1;
		auto&ret=memo[i][j];
		if(~ret)return ret;
		return ret=(solve(i+1,j+1)+solve(i+1,0))%mod;
	};
	cout<<solve(0,0)<<'\n';
}
// AC, dynamic programming
