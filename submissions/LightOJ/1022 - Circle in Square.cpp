#include <bits/stdc++.h>
using namespace std;

using ld = long double;
const ld pi=2*acos(0.0);

void run() {
  ld r;
  cin>>r;
  cout<<2*r*2*r-r*r*pi<<endl;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout<<fixed<<setprecision(2);

  int t;
  cin>>t;
  for(int i=1;i<=t;i++){
    cout<<"Case "<<i<<": ";
    run();
  }
}

// AC, geometry
