/*{=======================~ BEGIN MACRO ~================================*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define endl '\n'

#define fastio                        \
        ios_base::sync_with_stdio(0); \
        cin.tie(0);

//#define int long long

#define all(j) j.begin(), j.end()
#define rall(j) j.rbegin(), j.rend()
#define len(j) (int)j.size()
#define rep(i, a, b) \
        for (common_type_t<decltype(a), decltype(b)> i = a; i < b; i++)
#define rrep(i, a, b) \
        for (common_type_t<decltype(a), decltype(b)> i = a; i > b; i--)
#define pb push_back
#define pf push_front
#define eb emplace_back

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;
using vs = vector<string>;

template<typename T, typename U> inline bool chmax(T &a, U const& b) {
       	return (a < b ? a = b, 1 : 0); }
template<typename T, typename U> inline bool chmin(T &a, U const& b) {
       	return (a > b ? a = b, 1 : 0); }

/*=========================~ END MACRO ~================================}*/

auto run() {
	int N, Q;
	cin >> N >> Q;

	{
		int x;
		rep(i, 1, N)
			cin >> x;
	}

	vi PS(N+1);
	rep(i, 1, N+1)
		cin >> PS[i];

	vi subsz;
	function<int(int)>dfs=[&](int u){
		if(u>N)return 0;
		subsz.eb(dfs(u<<1)+dfs(u<<1|1)+1);
		return subsz.back();
	};
	dfs(1);
	subsz.eb(-1);
	reverse(all(subsz));
	dbg(subsz);

	vi fs(1,-1);
	function<void(int)>dfs2=[&](int u){
		if(u>N)return;
		if((u<<1)<=N)fs.eb(1);
		else fs.eb(0);
		dfs2(u<<1);
		dfs2(u<<1|1);
	};
	dfs2(1);
	dbg(fs);

	vi ps(1,-1);
	function<void(int,int)>dfs3=[&](int u,int p){
		ps.eb(p);
		int c=len(ps)-1;
		if((u<<1|1)<=N) {
			dfs3(u<<1,c);
			dfs3(u<<1|1,c);
		}
	};
	dfs3(1,-1);
	dbg(ps);

	vi ws(N+1);
	int totw=0;

	function<void(int)> update=[&](int i){
		if(i==-1)return;
		auto pi=PS[i];
		totw-=ws[pi];
		ws[pi]=0;

		int sl=(pi<<1);
		int sr=(pi<<1|1);

		int s1=-1;
		int s2=-1;
		if(fs[i]){
			s1=PS[i+1];
			s2=PS[i+subsz[i]/2+1];
		}

		if(sl<=N) {
			ws[pi]+=(s1!=sl and s1!=sr);
			ws[pi]+=(s2!=sl and s2!=sr);
		}

		totw+=ws[pi];
		update(ps[i]);
	};

	rep(i,1,N+1)
		update(i);

	dbg(ws);
	dbg(totw);

	rep(i,0,Q){
		int x,y;
		cin>>x>>y;

		swap(PS[x],PS[y]);
		update(x);
		update(y);

		cout<<(totw?"NO":"YES")<<endl;
	}
}

int32_t main() {
#ifndef LOCAL
        fastio;
#endif

        int T = 1;

        cin >> T;

        rep(t, 0, T) {
                dbg(t);
                run();
        }
}

/*
   AC, dfs and similar
 */

