#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
#define rep(i,s,t) for(ll i=s; i<t;i++)
#define rrep(i,s,t) for(ll i=s; i>t;i--)

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N; cin>>N;

  vector<int> A(N); for(int i=0; i<N; i++) cin>>A[i];
  
  sort(A.begin(), A.end());
  ll ans = 0;
  int B;
  for(int i=0; i<N; i++) {
    if(ans < 1ll*A[i]*(N-i)) {
      ans = 1ll*A[i]*(N-i);
      B = A[i];
    }
  }
  cout<<B<<" "<<ans<<"\n";

  return 0;
}

// AC, ad-hoc
