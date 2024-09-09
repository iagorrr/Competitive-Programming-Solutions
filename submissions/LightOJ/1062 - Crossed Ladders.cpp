#include<bits/stdc++.h>
using namespace std;
using ld=long double;
void run(){
  ld x,y,c;cin>>x>>y>>c;
  ld mnw=0,mxw=1e8;
  for(;;){
    ld w=(mnw+mxw)/2.0;
    ld alpha=acos(w/y);
    ld beta=acos(w/x);
    ld tan_alpha=tan(alpha);
    ld tan_beta=tan(beta);
    ld w1=c/tan_alpha;
    ld w2=w-w1;
    ld h=w2*tan_beta;
    if(abs(h-c)<=1e-9){
      cout<<fixed<<setprecision(10)<<w<<endl;
      return;
    }
    
    if(h>c)
       mnw=w;
    else
      mxw=w;
  }
}
int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;cin>>t;
  for(int i=1;i<=t;i++){
    cout<<"Case "<<i<<": ";
    run();
  }
}

// AC, geometry, binary search
