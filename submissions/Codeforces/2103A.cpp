#include<bits/stdc++.h>
using namespace std;
void solve(){
	int N;
	cin >> N;
	vector<int>AS(N);
	for(auto&ai:AS)cin>>ai;
	int ans=0;
	vector<int> have(N+1);
	for(auto&ai:AS)
		have[ai]=1;
	cout<<count(have.begin(),have.end(),1)<<'\n';
}
signed main()  {
	ios_base::sync_with_stdio(!cin.tie(0));
	int t;
	cin>>t;
	while(t--)solve();
}
// AC,greedy,math
