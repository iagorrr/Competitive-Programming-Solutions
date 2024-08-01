#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

#define MAX 501
bool vis[MAX][MAX][2];
bool vis2[MAX][MAX];

vector<ii> dir4 = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n;
	cin >> n;

	vector<ii> dance[2];
	for(int i = 0; i < 2; i++)
	{
		ll x, y;
		cin >> x >> y;
		
		dance[i].emplace_back(x, y);
		dance[i].emplace_back(y, x);
	}


	vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));
	
	int ans = 1;
	queue<tuple<int, int, int>> q;

	vis[1][1][0]= vis[1][1][1] = vis2[1][1]  = true;
	q.emplace(1, 1, 0);
	q.emplace(1, 1, 1);

	while(q.size())
	{
		auto [x, y, p] = q.front();
		q.pop();

		for(auto [dx, dy] : dance[p]) 
		{
			for(auto [ddx, ddy] : dir4)
			{
				auto nx = x + (dx * ddx), ny = y + (dy * ddy);

				if(nx <= 0 or ny <= 0 or nx > n or ny > n)
					continue;

				if(not vis[nx][ny][!p])
				{
					if(not vis2[nx][ny])
						++ans;

					vis2[nx][ny] = true;
					vis[nx][ny][!p] = true;
					q.emplace(nx, ny, !p);
				}
			}
		}
	}


	cout << ans << "\n";
}

// AC, graphs, bfs
