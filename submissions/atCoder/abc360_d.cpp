#include <bits/stdc++.h>
using namespace std;

int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n,t;cin>>n>>t;
  string s;cin>>s;
  vector<pair<int,int>> xs(n);
  for(int i=0;i<n;i++){
    cin>>xs[i].first;
    xs[i].second=i;
  }
  sort(xs.begin(),xs.end());
  deque<int> aux;
  long long ans=0;
  for(int i=n-1;~i;i--){
    auto [xi,idx]=xs[i];
    auto di=s[idx];
    while(aux.size()&&xi+t<aux.back()-t){
      aux.pop_back();
    }
    if(di-'0'){
      ans+=aux.size();
    }
    else aux.push_front(xi);
  }
  cout<<ans<<'\n';
}

// AC, data structures
