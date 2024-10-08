#include<bits/stdc++.h>
using namespace std;

void run() {
	int N,M,K;cin>>N>>M>>K;

	vector<int> verticalX(N);
	for(auto&xi:verticalX)cin>>xi;

	vector<int> horizontalY(M);
	for(auto&yi:horizontalY)cin>>yi;

	vector<pair<int,int>> pts(K);
	for(auto&[x,y]:pts)cin>>x>>y;
	
	long long ans = 0;
	{
		sort(pts.begin(),pts.end());

		int pl=0;
		for(int i=0;i+1<N;i++){
			int left=verticalX[i];
			int right=verticalX[i+1];

			while(pl<K and pts[pl].first <= left)pl++;
			if(pl >= K) continue;
			if(pl < 0) continue;
			if(pts[pl].first >= right)continue;
			
			int pr = pl;
			while (pr + 1 < K and pts[pr+1].first < right)
				pr++;

			map<long long, long long> perRow;
			long long tot = 0;
			for (int j=pl; j <= pr; j++) {
				ans += (tot-perRow[pts[j].second]);
				perRow[pts[j].second]++;
				tot++;
			}
		}
	}
	{
		sort(pts.begin(),pts.end(),[&](pair<int,int>&a, pair<int,int>&b){
				return a.second == b.second ? a.first < b.first : a.second < b.second;
				});

		int pl=0;
		for(int i=0;i+1<M;i++){
			int lower = horizontalY[i];
			int upper = horizontalY[i+1];

			while(pl<K and pts[pl].second <= lower)pl++;
			if(pl >= K) continue;
			if(pl < 0) continue;
			if(pts[pl].second >= upper)continue;
			
			int pr = pl;
			while (pr + 1 < K and pts[pr+1].second < upper)
				pr++;

			map<long long, long long> perColumn;
			long long tot = 0;
			for (int j=pl; j <= pr; j++) {
				ans += (tot-perColumn[pts[j].first]);
				perColumn[pts[j].first]++;
				tot++;
			}
		}
	}


	cout << ans << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(!cin.tie(0));
	int t;cin>>t;
	while(t--){
		run();
	}
}


// AC, two pointers, sortings
