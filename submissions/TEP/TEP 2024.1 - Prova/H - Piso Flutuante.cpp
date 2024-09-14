#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD=1'000'000'007;
const int MAXW=2'000'000;
ll dp[MAXW+1];

ll w,h;
ll solve(ll p){
	if(p==0||p==-1)return 1;
	if(p<0)return 0;
	auto&ret=dp[p];
	if(~ret)return ret;
	if(h==1){
	return ret=(solve(p-1))%MOD;
	}
	return ret=(solve(p-h)+solve(p-1))%MOD;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(dp,-1,sizeof dp);
	cin>>w>>h;
	cout<<solve(w-1)<<endl;

}


