#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1'000'000'007;
const int INV2 = 500000004;
void solve(){
	int N;
	cin>>N;
	string S;
	cin>>S;
	reverse(begin(S),end(S));
	vector<vector<int>>memo(N,vector<int>(2,-1));
	S.push_back('0');
	function<int(int,int)> solve=[&](int u, bool o){
		if(u>=N-1)return 0ll;
		auto&ret=memo[u][o];
		if(~ret)return ret;
		ret= 0;
		if(o){
			//  floor
			auto c1 = (1+solve(u+1, S[u+1]=='1'))%MOD;
			// ceil
			int nu=u+1;
			for (int j = u+1; j <= N; j++){
				if (S[j] == '0') {
					nu = j;
					break;
				}
			}
			auto c2 = (nu-u+solve(nu, true))%MOD;
			ret = (c1+c2)%MOD;
			ret = (ret*INV2)%MOD;
		}
		else{
			auto c1 = solve(u+1, S[u+1]=='1');
			ret = (c1+1)%MOD;
		}
		return ret;
	};
	cout<<solve(0,S.front()=='1')<<'\n';
}
signed main() {
	ios_base::sync_with_stdio(!cin.tie(0));
	int t;
	cin>>t;
	while(t--) solve();
}

// AC, math, probabilites, expected value, bitwise
