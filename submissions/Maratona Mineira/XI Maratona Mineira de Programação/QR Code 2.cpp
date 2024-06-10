#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()

void rotate(vector<string> &grid, int M) {
  vector<string> tmp = grid;
  for(int i=0; i<M; i++) {
    for(int j=0; j<M; j++) {
      grid[i][j] = tmp[M-j-1][i];
    }
  }
}

void printGrid(vector<string> grid) {
  for(auto s:grid) {
    cout<<s<<"\n";
  }
  cout<<"\n";
}

// 101
// 000
// 111
//
// 00 -> 02
// 01 -> 11

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N; cin>>N;
  vector<string> grid(N);
  for(int i=0; i<N; i++) {
    cin>>grid[i];
  }

  int ans = 0;
  for(int k=0; k<4; k++) {
    int lo = 0, hi=N/2;
    while(lo<hi) {
      int t = (hi+lo+1)/2;
      vector<string> grid1(t, string(t, '.'));
      vector<string> grid2(t, string(t, '.'));
      vector<string> grid3(t, string(t, '.'));

      for(int i=0; i<t; i++) {
        for(int j=0; j<t; j++) {
          grid1[i][j] = grid[i][j];
        }
      }
      for(int i=0; i<t; i++) {
        for(int j=0; j<t; j++) {
          grid2[i][j] = grid[i][j+N-t];
        }
      }
      for(int i=0; i<t; i++) {
        for(int j=0; j<t; j++) {
          grid3[i][j] = grid[i+N-t][j+N-t];
        }
      }
      rotate(grid2, t);
      rotate(grid2, t);
      rotate(grid2, t);
      rotate(grid3, t);
      rotate(grid3, t);
      if(grid1 == grid2 && grid1 == grid3) {
        lo = t;
      } else {
        hi = t-1;
      }
    }
    ans = max(ans, lo);
    rotate(grid, N);
  }
  cout<<ans<<"\n";
  return 0;
}

// AC, binary search
