#include <bits/stdc++.h>
using namespace std;

using ld = long double;

template<typename T=ld>
struct Point {
	T x, y;
	bool is_port;
};

template<typename T>
bool operator==(const  Point<T> &a, const Point<T> &b) {
	return a.x == b.x and a.y == b.y;
}

template<typename T=ld>
struct Segment {
	Point<T> p1, p2;
};



template<typename T>
int orientation(Point<T> p, Point<T> q, Point<T> r) {
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
	if (val == 0) return 0; 	// colinear
	else if (val > 0) return 1; 	// clockwise
	else return 2; 		// counterclockwise
}

template<typename T>
bool do_segment_intersect(Segment<T> s1, Segment<T> s2) {
	int o1 = orientation(s1.p1, s1.p2, s2.p1);
	int o2 = orientation(s1.p1, s1.p2, s2.p2);

	int o3 = orientation(s2.p1, s2.p2, s1.p1);
	int o4 = orientation(s2.p1, s2.p2, s1.p2);

	return (o1 != o2 and o3 != o4) or (o1 == 0 and o3 == 0) or (o2 == 0 and o4 == 0);

}

template<typename T>
ld edist(Point<T> p1, Point<T> p2) {
	return hypot(p1.x-p2.x, p1.y-p2.y);
}

int T, M, C;
vector<Point<int>> pts;
vector<Segment<int>> walls;
int xs, ys, xf, yf;

const int maxn = 50 * 2 + 50 + 2 + 12;
vector<pair<int, ld>> adj[maxn];

int n;
void build() {
	n = pts.size();
	//cerr << "n: " << n<< '\n';
	for (int i = 0; i < n; i++) {
		adj[i].clear();
		for (int j = 0; j < n; j++) {
			if (i == j) continue;

			bool ok = true;
			for (int k = 0; k < M; k++) {
				Segment<int> s1({pts[i],pts[j]});

				if (pts[i] == walls[k].p1 or pts[i] == walls[k].p2)
					continue;

				if (pts[j] == walls[k].p1 or pts[j] == walls[k].p2)
					continue;

				if (do_segment_intersect(s1, walls[k])) {
					//cerr << pts[i].x << ' ' << pts[i].y << ' ' << pts[j].x << ' ' << pts[j].y << '\n';
					ok=false;

				}

			}

			if (ok) {
				ld d = (ld)0.000;
				if (!pts[i].is_port or !pts[j].is_port) {
					d = edist(pts[i], pts[j]);
				}
				adj[i].push_back({j, d});
				//cerr << "i: " << i << " j: " << j << " d: " << d << '\n';
			}
			else {
			}
		}
	}
}


ld EPS = 1e-6;
ld dijkstra() {
	vector<vector<ld>> dist(T+1, vector<ld>(n, numeric_limits<ld>::max()));

	using state = tuple<ld, int, int>;
	priority_queue<state, vector<state>, greater<>> pq;

	dist[0][n-2] = 0;
	pq.push({0, 0, n-2});

	while (!pq.empty()) {
		auto [du, tu, u] = pq.top();
		//cerr << u << ' ' << fixed << setprecision(2) << du << '\n';
		pq.pop();

		if (dist[tu][u] < du) continue;

		for (auto [v, w] : adj[u]) {
			int is_port = w < EPS;
			if (is_port and tu + 1 > T)
				continue;
			if (dist[tu+is_port][v] > du + w) {
				dist[tu+is_port][v] = du + w;
				pq.push({du+w, tu+is_port, v});
			}


		}
	}

	ld ans = numeric_limits<ld>::max();
	for (int i = 0; i <= T; i++) {
		ans =min(ans, dist[i][n-1]);
	}
	return ans;
}

void run() {

	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		pts.push_back({x1,y1,false});
		pts.push_back({x2,y2,false});
		walls.push_back({{x1,y1},{x2,y2}});
	}

	for (int i = 0; i < C; i++) {
		int x, y;
		cin >> x >> y;
		pts.push_back({x, y, true});
	}

	cin >> xs >> ys >> xf >> yf;
	pts.push_back({xs, ys, false});
	pts.push_back({xf, yf, false});

	build();

	auto dst = dijkstra();

	cout << fixed << setprecision(1) << dst << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> T >> M >> C) {
		walls.clear();
		pts.clear();

		run();
	}

}

// AC, geometry, graphs, shortest paths
