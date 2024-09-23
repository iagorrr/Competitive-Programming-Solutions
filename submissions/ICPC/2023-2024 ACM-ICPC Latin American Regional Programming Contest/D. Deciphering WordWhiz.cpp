#include<bits/stdc++.h>
using namespace std;
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;cin>>n;
	vector<string>words(n);for(auto&wi:words)cin>>wi;
	int m;cin>>m;
	vector<string>guess(m);for(auto&gi:guess)cin>>gi;
	vector<int> have('z'-'a'+10);
	for(auto&c:words[0])
		have[c-'a']=1;
	for(int i=0;i<m;i++){
		int ans=0;
		for(auto&w:words){
			string cur;
			for(int j=0;j<5;j++){
				if(w[j]==words[0][j]){
					cur.push_back('*');
				}
				else if(have[w[j]-'a']){
					cur.push_back('!');
				}
				else cur.push_back('X');
			}
			ans+=(cur==guess[i]);
		}
		cout<<ans<<'\n';
	}
}

// AC, ad-hoc
