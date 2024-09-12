#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;cin>>n;
  vector<pair<int,int>> evs;
  while(n--){
    int l,r;cin>>l>>r;
    evs.push_back({l,0});
    evs.push_back({r,1});
  }
  sort(evs.begin(),evs.end());
  long long ans=0;
  int o=0;
  for(auto[p,t]:evs){
    if(t){
      --o;
      ans+=o;
    }
    else o++;
  }
  cout<<ans<<'\n';
}
//  AC, sliding window
