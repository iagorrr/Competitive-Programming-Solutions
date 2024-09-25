#include<bits/stdc++.h>
using namespace std;
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int>have(3);
	for(auto&i:have)cin>>i;

	vector<int>want(3);
	for(auto&i:want)cin>>i;
	int ans=0;
	for(int i=0;i<3;i++){
		ans+=max(0,-have[i]+want[i]);
	}
	cout<<ans<<'\n';

}

// AC, ad-hoc
