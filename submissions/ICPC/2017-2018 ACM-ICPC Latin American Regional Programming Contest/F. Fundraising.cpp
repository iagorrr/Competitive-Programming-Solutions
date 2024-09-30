#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using namespace std;

using Node=ll;
inline Node combine(const Node &nl, const Node &nr) {
  return max(nl,nr);
}

struct SegTree {
  int n;
  vector<Node> st;
  SegTree(int _n) : n(_n), st(n << 1) {}

  void assign(int p, const Node &k) {
    for (st[p += n] = k; p >>= 1;)
		 	st[p] = combine(st[p << 1], st[p << 1 | 1]);
  }

  Node query(int l, int r) {
    Node ansl = Node(), ansr = Node();
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ansl = combine(ansl, st[l++]);
      if (r & 1) ansr = combine(st[--r], ansr);
    }
    return combine(ansl, ansr);
  }
};

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;cin>>n;
	using t3=tuple<ll,ll,ll>;
	set<ll> ys;
	vector<t3> xs(n);
	for(auto&[x,y,z]:xs){
		cin>>x>>y>>z;
		ys.emplace(y);
	}
	map<ll,int>compression;
	int t=0;
	for(auto yi:ys)compression[yi]=t++;
	sort(xs.begin(),xs.end());
	{
		vector<t3>aux({xs[0]});
		for(int i=1;i<n;i++){
			auto&[x1,y1,c1]=xs[i];
			auto&[x2,y2,c2]=aux.back();
			if(x1==x2 && y1==y2){
				c2+=c1;
			}
			else aux.push_back(xs[i]);
		}
		xs=aux;
	}
	n = size(xs);
	SegTree seg(t+10);
	ll ans=0;
	for(int i=0;i<n;){
		int curx=get<0>(xs[i]);
		int j=i;
		vector<pair<int,ll>> toupd;
		for(j=i;j<n;j++){
			if(get<0>(xs[j])!=curx)break;
			auto&[x,y,c]=xs[j];
			int yc=compression[y];
			ll best=(yc?seg.query(0,yc-1):0) + c ;
			ll cur=seg.query(yc,yc);
			if(best>cur)
				toupd.emplace_back(yc,best);
			ans=max(ans,best);
		}
		for(auto&[p,v]:toupd){
			seg.assign(p,v);
		}
		i=j;
	}
	cout<<ans<<'\n';
}

// AC, data structures, dp
