#include<bits/stdc++.h>
using namespace std;
#define all(x) begin(x),end(x)
const string vow { "aeiou"};
string s;
vector<int>ps;
int solve(int l, int r){
	if(l==r){
		return 1;
	}
	bool cl=vow.find(s[l])!=string::npos;
	bool cr=vow.find(s[r])!=string::npos;
	int li=l<r?1:-1;
	int ri=l<r?-1:1;
	int ans=0;
	int v=0;
	{
		int l2=min(l,r);
		int r2=max(l,r);
		v=ps[r2]-(l2?ps[l2-1]:0);
		//cerr<<"l2:"<<l2<<' '<<" r2:"<<r2<<" v:"<<v<<'\n';
	}
	if(!cl&&v)return 0;
	if(!cl&&!cr){
		ans+=solve(l,r+ri);
	}
	else if(!cl&&cr){
		return 0;
	}
	else if(cl&&!cr){
		ans+=solve(l,r+ri);
		//ans+=solve(r,l+li);
		ans+=(v==1);
	}
	else if(cl&&cr){
		ans+=solve(r,l+li);
	}
	return ans;
}
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	ps.resize(size(s));
	ps[0]=vow.find(s[0])!=string::npos;
	for(int i=1;i<size(s);i++){
		ps[i]=ps[i-1]+(vow.find(s[i])!=string::npos);
	}
	cout<<solve(0,size(s)-1)<<endl;
}


// AC, strings, brute force
