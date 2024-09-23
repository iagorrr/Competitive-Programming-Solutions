#include<bits/stdc++.h>
using namespace std;
int hist[4'00'000];
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;cin>>n;
	for(int i=0;i<3*n;i++){
		int x;cin>>x;
		x+=1'00'000;
		hist[x]++;
	}
	bool ans=0;
	for(int i=0;i<4'00'000;i++){
		ans|=((hist[i]%3)!=0);
	}
	cout<<(ans?"Y":"N")<<'\n';
}

// AC,ad-hoc,games
