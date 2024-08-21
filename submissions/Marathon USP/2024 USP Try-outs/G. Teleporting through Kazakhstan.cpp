#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
#define rep(i,s,t) for(ll i=s; i<t;i++)
#define rrep(i,s,t) for(ll i=s; i>t;i--)

using vi=vector<int>;
using vll=vector<ll>;
using vll2d=vector<vll>;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;cin>>N;
  vi AS(N+1);rep(i,1,N+1)cin>>AS[i];
  const ll OO=LLONG_MAX;
  vll2d dp(N+1,vi(N+1,OO));
  auto solve=[&](auto&&self, int i, int j)->ll{
    if(i==N)return 0;
    auto&ret=dp[i][j];
    if(ret!=OO)return ret;
    ll d1=abs(AS[i]-AS[i+1]);
    ret=min(ret,self(self,i+1,j)+d1);
    if(i!=j){
      ll d2=abs(AS[j]-AS[i+1]);
      ret=min(ret,self(self,i+1,i)+d2);
    }
    return ret;
  };
  cout<<solve(solve,0,0)<<'\n';
}

// AC, graphs, shortest paths, dynamic programming
