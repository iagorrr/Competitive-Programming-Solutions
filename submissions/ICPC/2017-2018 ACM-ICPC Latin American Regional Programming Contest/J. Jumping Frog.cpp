#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int hist[MAXN];
int done[MAXN];
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;cin>>s;
	cerr<<s<<'\n';
	int n=size(s);
	int ans=0;
	if(count(begin(s),end(s),'R')==n){
		cout<<n-1<<'\n';
		return 0;
	}
	vector<int>ds;
	for(int j=2;j*j<=n;j++){
		if((n%j)==0){
			ds.emplace_back(j);
			if(j!=n/j)ds.emplace_back(n/j);
		}
	}
	auto check=[&](int d)->bool{
		if(done[d])return false;
		memset(hist,0,sizeof hist);
		for(int i=0;i<n;i++){
			if(s[i]=='R'){
				hist[i%d]++;
			}
		}
		bool ok=false;
		for(int i=0;i<d;i++){
			if(hist[i]==n/d)
				ok|=1;
		}
		if(ok)cerr<<d<<'\n';
		ans+=ok;
		done[d]=1;
		return ok;
	};
	for(auto d:ds){
		if(check(d)){
			for(int i=d*2;i<n;i+=d)
				check(i);
		}

	}
	cout<<ans<<'\n';
}
// AC, math, number theory
