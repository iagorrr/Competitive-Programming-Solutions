#include<bits/stdc++.h>
using namespace std;
int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;cin>>n;
  vector<long long> ans(n+1);
  vector<pair<int,int>> evs;
  while(n--){
    int l,r;cin>>l>>r;
    r+=l;
    evs.push_back({l,0});
    evs.push_back({r,1});
  }
  sort(evs.begin(),evs.end());
  int o=0;
  int pp=0;
  for(auto[p,t]:evs){
    int dp=p-pp;
    if(t){
      ans[o]+=dp;
      o--;
    }
    else{
      ans[o]+=dp;
      o++;
    }
    pp=p;
  }
  for(int i=1;i<=ans.size()-1;i++){
    cout<<ans[i]<<" \n"[i+1==(int)ans.size()];
  }
}

// AC, sweep line
