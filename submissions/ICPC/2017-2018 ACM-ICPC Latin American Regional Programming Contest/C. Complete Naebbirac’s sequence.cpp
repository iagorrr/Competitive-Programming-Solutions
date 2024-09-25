#include<bits/stdc++.h>
using namespace std;
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k,n;cin>>k>>n;
	vector<int>hist(k);
	vector<int>xs(n);for(auto&xi:xs)cin>>xi,hist[xi-1]++;
	for(int i=0;i<k;i++){
		hist[i]++;
		if(count(hist.begin(),hist.end(),hist[i])==k){
			cout<<"+"<<i+1<<'\n';
			return 0;
		}
		hist[i]--;
	}
	for(int i=0;i<k;i++){
		hist[i]--;
		if(count(hist.begin(),hist.end(),hist[i])==k){
			cout<<"-"<<i+1<<'\n';
			return 0;
		}
		hist[i]++;
	}
	for(int i=0;i<k;i++){
		hist[i]--;
		for(int j=0;j<k;j++){
			if(i==j)continue;
			hist[j]++;
			if(count(hist.begin(),hist.end(),hist[i])==k){
				cout<<"-"<<i+1<<" +"<<j+1<<'\n';
				return 0;
			}
			hist[j]--;
		}
		hist[i]++;
	}
	cout<<"*\n";
}

// brute-force
