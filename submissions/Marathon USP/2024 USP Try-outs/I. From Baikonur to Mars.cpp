#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
#define rep(i,s,t) for(ll i=s; i<t;i++)
#define rrep(i,s,t) for(ll i=s; i>t;i--)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define len(x) (int)x.size()

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin>>N;
  vector<int>XS(N);
  for(auto&xi:XS)cin>>xi;
  sort(rall(XS));
  while(len(XS)&&XS.back()==0)XS.pop_back();

  if(!XS.empty()&&XS.back()==XS.front()&&XS.back()==1){
    cout<<1<<endl;
    return 0;
  }

  int ans=0;
  bool odd=0,even=0;
  for(auto&xi:XS){
    odd|=(xi&1);
    even|=((xi!=0)&&!(xi&1));
  }

  if(odd)ans=2;
  else if(even)ans=1;

  cout<<ans<<endl;
}
// AC, greedy
