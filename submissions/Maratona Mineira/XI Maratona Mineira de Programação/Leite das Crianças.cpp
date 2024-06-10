#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()

int main() {
  int N, L;
  cin>>N>>L;
  vector<int> A(N);
  for(int i=0; i<N; i++) {
    cin>>A[i];
    A[i] = 100-A[i];
  }

  sort(all(A));

  int ans =0;
  for(int i=0; i<N; i++) {
    if(A[i] > L) break;
    L -= A[i];
    ans++;
  }
  cout<<ans<<"\n";
  return 0;
}

// AC, greddy, sortings
