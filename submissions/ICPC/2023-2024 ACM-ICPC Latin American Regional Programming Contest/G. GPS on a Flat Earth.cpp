/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define fastio                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
#define all(j) j.begin(), j.end()
#define rall(j) j.rbegin(), j.rend()
#define len(j) (int)j.size()
#define rep(i, a, b) \
  for (common_type_t<decltype(a), decltype(b)> i = (a); i < (b); i++)
#define rrep(i, a, b) \
  for (common_type_t<decltype(a), decltype(b)> i = (a); i > (b); i--)
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) for (auto &xi : ranges::views::reverse(xs))
using ll = long long;
#define inte ll
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define emp emplace
#define ins insert
#define divc(a, b) ((a) + (b)-1ll) / (b)
using str = string;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vc = vector<char>;
using vs = vector<str>;
template <typename T, typename T2>
using umap = unordered_map<T, T2>;
template <typename T>
using pqmn = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using pqmx = priority_queue<T, vector<T>>;
template <typename T, typename U>
inline bool chmax(T &a, U const &b) {
  return (a < b ? a = b, 1 : 0);
}
template <typename T, typename U>
inline bool chmin(T &a, U const &b) {
  return (a > b ? a = b, 1 : 0);
}
/*8<============~ END TEMPLATE ~============}>8*/
void run();

int32_t main() {
#ifndef LOCAL
  fastio;
#endif

  int T = 1;

  // cin >> T;

  rep(t, 0, T) {
    dbg(t);
    run();
  }
}

/**
 * Author: Ulf Lundstrom
 * Date: 2009-02-26
 * License: CC0
 * Source: My head with inspiration from tinyKACTL
 * Description: Class to handle points in the plane.
 * 	T can be e.g. double or long long. (Avoid int.)
 * Status: Works fine, used a lot
 */

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T=ll>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

/**
 * Author: Victor Lecomte, chilli
 * Date: 2019-04-26
 * License: CC0
 * Source: https://vlecomte.github.io/cp-geo.pdf
 * Description: Returns true iff p lies on the line segment from s to e.
 * Use \texttt{(segDist(s,e,p)<=epsilon)} instead when using Point<double>.
 * Status:
 */

template<class P> bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

template<class P> vector<P> segInter(P a, P b, P c, P d) {
	auto oa = c.cross(d, a), ob = c.cross(d, b),
	     oc = a.cross(b, c), od = a.cross(b, d);
	// Checks if intersection is single non-endpoint point.
	if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
		return {(a * ob - b * oa) / (ob - oa)};
	set<P> s;
	if (onSegment(c, d, a)) s.insert(a);
	if (onSegment(c, d, b)) s.insert(b);
	if (onSegment(a, b, c)) s.insert(c);
	if (onSegment(a, b, d)) s.insert(d);
	assert(len(s) <= 2);
	return {all(s)};
}



using Segment = pair<Point<ll>, Point<ll>>;
void run() {
	int N; cin >> N;

	vector<array<Segment,4>> circles; 
	rep(i, 0, N) { 
		ll x, y, r; cin >> x >> y >> r;
		x-=r;
		Point<ll> p1  {x, y};
		Point<ll> p2  {x+r, y-r};
		Point<ll> p3  {x + 2 * r, y};
		Point<ll> p4  {x + r, y + r};
		array<Segment,4> circle = {
			Segment{p1, p2},
			Segment{p2, p3},
			Segment{p3, p4},
			Segment{p4, p1}
		};
		circles.pb(circle);
	}

	vector<Segment> segments;
	vector<Point<ll>> points;
	rep(i,0,4) segments.pb(circles[0][i]);

	rep(i, 1, N) {
		vector<Segment> newSegments;
		vector<Point<ll>> newPoints;

		// segment with segment 
		for(auto &oldSegment : segments) {
			for(auto side : circles[i]) {
				auto inter = segInter(
						oldSegment.first, oldSegment.second,
						side.first, side.second);
				if (len(inter) == 1) {
					newPoints.pb(inter[0]);
				}
				if (len(inter) == 2) {
					oldSegment = {inter[0], inter[1]};
					newSegments.pb({inter[0],inter[1]});
				}
				
			}
		}

		// segment with point
		for (auto oldPoint : points) {
			bool atSome = false;
			for (auto side : circles[i]) {
				atSome |= onSegment(side.first, side.second, oldPoint);
			}
			if (atSome)
				newPoints.pb(oldPoint);
		}

		sort(all(newPoints));
		sort(all(newSegments));
		auto it1=unique(all(newPoints));
		newPoints.erase(it1,end(newPoints));
		auto it2=unique(all(newSegments));
		newSegments.erase(it2,end(newSegments));
		swap(points,newPoints), swap(segments,newSegments);
		//points = newPoints;
		//segments = newSegments;
	}

	dbg(points);
	dbg(segments);

	set<Point<ll>> ans(all(points));
	for (auto &[p1, p2] : segments) {
		if (p1.x > p2.x) swap(p1,p2);
		int dx = 1;
		int dy = p1.y <= p2.y ? 1 : -1;
		for (;;) {
			ans.ins(p1);
			if (p1 == p2) break;
			p1.x += dx;
			p1.y += dy;
		}
	}

	for(auto &[x, y] : ans) {
		cout << x << ' ' << y << endl;
	}
}

/*8<
  Add 4 segments of some 'circle'.
  For each other 'circle' add the intersection of the current segments and the
  new 4 segemtns as the new segments, and if that's only a point, add those
  points.
  For each point result of the intersection keep only those that belongs to
  any of the 4 new segments

  AC, geometry
>8*/

