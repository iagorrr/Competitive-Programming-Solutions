#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
#define rep(i,s,t) for(ll i=s; i<t;i++)
#define rrep(i,s,t) for(ll i=s; i>t;i--)
#define all(x)  x.begin(),x.end() 
#define len(x) (int)x.size()
using pii=pair<int,int>;

/*{=====================~ BEGIN LAZY SEGMENT TREE ~======================*/

using SegT=ll;

struct QueryT {
	SegT v;
	QueryT():v(numeric_limits<SegT>::max()){}
	QueryT(SegT _v):v(_v){}
};

inline QueryT combine(QueryT ln, QueryT rn, pii lr1, pii lr2){
	return QueryT(min(ln.v,rn.v));
}

using LazyT=SegT;

inline QueryT applyLazyInQuery(QueryT q, LazyT l, pii lr){
  if(q.v==QueryT().v)q.v=0;
	q.v+=l;
	return q;
}

inline LazyT applyLazyInLazy(LazyT a,LazyT b){
	return a+b;
}

using UpdateT=SegT;

inline QueryT applyUpdateInQuery(QueryT q,UpdateT u, pii lr){
  if(q.v==QueryT().v)q.v=0;
	q.v+=u;
	return q;
}

inline LazyT applyUpdateInLazy(LazyT l,UpdateT u, pii lr){
	return l+u;
}

template<
	typename Qt=QueryT,
	typename Lt=LazyT,
	typename Ut=UpdateT,
       	auto C=combine,
	auto ALQ=applyLazyInQuery,
	auto ALL=applyLazyInLazy,
	auto AUQ=applyUpdateInQuery,
	auto AUL=applyUpdateInLazy>
struct LazySegmentTree {
	int n,h;
	vector<Qt> ts;
	vector<Lt> ds;
	vector<pii> lrs;

	LazySegmentTree(int _n):
		n(_n),
		h(sizeof(int)*8- __builtin_clz(n)),
		ts(n<<1),
		ds(n),
		lrs(n<<1)
	{
		rep(i,0,n)lrs[i+n]={i,i};
		rrep(i,n-1,0){
			lrs[i]={lrs[i<<1].first,lrs[i<<1|1].second};
		}
	}

	LazySegmentTree(const vector<Qt> &xs):
		LazySegmentTree(len(xs)){
		copy(all(xs),ts.begin()+n);
		rep(i,0,n)lrs[i+n]={i,i};
		rrep(i,n-1,0){
			ts[i]=C(ts[i<<1],ts[i<<1|1],lrs[i<<1],lrs[i<<1|1]);
		}
	}
	
	void set(int p,Qt v){
		ts[p+n]=v;
		build(p);
	}

	void upd(int l,int r,Ut v){
		l+=n,r+=n+1;
	  	int l0=l,r0=r;
	  	for(;l<r;l>>=1,r>>=1){
			if(l&1)apply(l++,v);
			if(r&1)apply(--r,v);
		}
	  	build(l0),build(r0-1);
	}

	Qt qry(int l,int r){
		l+=n,r+=n+1;
		push(l),push(r-1);
	  	Qt resl=Qt(),resr=Qt();
		pii lr1={l,l},lr2={r,r};
	  	for (;l<r;l>>=1,r>>= 1){
			if(l&1)resl=C(resl,ts[l],lr1,lrs[l]),l++;
	    		if(r&1)r--,resr=C(ts[r], resr,lrs[r],lr2);
		}
		return C(resl, resr, lr1, lr2);
	}

	void build(int p){
		while(p>1){
			p>>=1;
			ts[p]=ALQ(C(ts[p<<1],ts[p<<1|1],lrs[p<<1],lrs[p<<1|1]),ds[p], lrs[p]);
		}
	}

	void push(int p){
		rrep(s,h,0){
	    		int i=p>>s;
	    		if(ds[i]!=Lt()) {
				apply(i<<1,ds[i]),apply(i<<1|1,ds[i]);
				ds[i]=Lt();
			}
		  }
	}

	inline void apply(int p,Ut v){
	  	ts[p]=AUQ(ts[p],v,lrs[p]);
	  	if(p<n)ds[p]=AUL(ds[p],v,lrs[p]);
	}
};

/*=======================~ END LAZY SEGMENT TREE ~======================}*/

using vll=vector<ll>;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N,Q;cin>>N>>Q;
  vll BS(N);for(auto&xi:BS)cin>>xi;
  vll CS(N);for(auto&xi:CS)cin>>xi;
  rep(i,0,N){
    CS.push_back(CS[i]);
    BS.push_back(BS[i]);
  }
  vll tmp;
  tmp=BS;
  rep(i,0,N*2)tmp[i]-=CS[i];
  partial_sum(begin(tmp), end(tmp), begin(tmp));
  vector<QueryT> aux; 
  rep(i,0,2*N)aux.push_back(QueryT(tmp[i]));

  LazySegmentTree st(aux);
  rep(q,0,Q){
    int o;cin>>o;
    if(o==1){
      int i;cin>>i;i--;
      ll best=INT_MAX;
      ll dec=i?st.qry(i-1,i-1).v:0;
      for(ll l=i,r=N*2-1;l<=r;){
        int mid=(l+r)/2;
        ll qv=st.qry(i,mid).v-dec;
        if(qv<0){
          best=min(best,mid);
          r=mid-1;
        }
        else{
          l=mid+1;
        }
      }
      if(best==INT_MAX){
        cout<<-1<<'\n';
      }
      else{
        if(best>=N)best-=N;
        best++;
        cout<<best<<endl;
      }
    }
    else if(o==2){
      int i,x;cin>>i>>x;
      i--;
      st.upd(i,2*N-1,x-BS[i]);
      st.upd(i+N,2*N-1,x-BS[i]);
      BS[i] = x;
    }
    else{
      int i,x;cin>>i>>x;
      i--;
      st.upd(i,2*N-1,CS[i]-x);
      st.upd(i+N,2*N-1,CS[i]-x);
      CS[i] = x;
    }
  }
}

// AC, dynamic programming, range queries

