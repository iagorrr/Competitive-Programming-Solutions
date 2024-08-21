#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
#define rep(i,s,t) for(ll i=s; i<t;i++)
#define rrep(i,s,t) for(ll i=s; i>t;i--)

const int MX = 1e5+10;
vector<array<ll, 3>> G[MX];

ll INF = 1e18;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, M, T; cin>>N>>M>>T;

  for(int i=0; i<M; i++) {
    int a, b, x, y;
    cin>>a>>b>>x>>y;
    a--, b--;
    G[a].push_back({b, x, y});
    G[b].push_back({a, x, y});
  }

  using tup = tuple<ll,int>;
  priority_queue<tup, vector<tup>, greater<tup>> q;
  vector<ll> D(N, INF);
  D[0] = T;
  q.push({T, 0});
  while(!q.empty()) {
    auto [time, u] = q.top();
    q.pop();

    for(auto v:G[u]) {
      ll x = time%(v[1]+v[2]);

      ll nxt = time;
      if(x >=v[1]) nxt += (v[1]+v[2])-x;
      //cout<<time<<" "<<nxt<<"\n";
      if(nxt < D[v[0]]){
        D[v[0]] = nxt;
        q.push({nxt, v[0]});
      }
    }
  }
  cout<<D[N-1]<<"\n";
  return 0;
}

// AC, graphs, shortest paths
