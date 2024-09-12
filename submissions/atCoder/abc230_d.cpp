#include<bits/stdc++.h>
using namespace std;
int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n,d;cin>>n>>d;
  d--;
  vector<pair<int,int>> segs(n);
  for(auto&[l,r]:segs)cin>>l>>r;
  using pii=pair<int,int>;
  sort(segs.begin(),segs.end(), [&](pii a, pii b){
      return a.second==b.second?a.first<b.first:a.second<b.second;
      });
  int ans=0;
  int ub=-1;
  for(auto&[l,r]:segs){
    if(l<=ub)continue;
    ans++;
    ub=r+d;
  }
  cout<<ans<<'\n';
}
// AC,greedy
