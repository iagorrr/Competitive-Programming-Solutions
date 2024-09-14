#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld INF=1e10;
const ld EPS=1e-9;

bool equals(ld a, ld b){
	return abs(a-b) <= EPS;
}


template<typename T>
struct Point{
	typedef Point P;
	T x,y;
	explicit Point(T _x=0,T _y=0): x(_x), y(_y){
	}
	P operator-(P p) const{
		return P {x-p.x,y-p.y};
	}
	P operator*(T d) const{
		return P{x*d,y*d};
	}
	bool operator==(P p){
		return equals(x,p.x) and equals(y,p.y);
	}
	ld dist2() const {
		return x*x+y*y;
	}
	ld dist() const {
		return sqrt((ld)dist2());
	}
	T dot(P p) const {
		return x*p.x + y *p.y;
	}
};

ld segDist(Point<ld> s, Point<ld> e, Point<ld> p){
	if(s==e) return (p-s).dist();
	ld d = (e-s).dist2();
     	auto t=min(
			d,
			max((ld)0,(p-s).dot(e-s))
			);
	return ((p-s)*d-(e-s)*t).dist()/d;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout<<fixed<<setprecision(10);
	cerr<<fixed<<setprecision(10);
	for(int P=1;;P++){
		int N;cin>>N;
		Point<ld> pl;cin>>pl.x>>pl.y;
		if(N==0)break;
		if(P>1)cout<<"\n\n";
		cout<<"Partida #"<<P<<":\n";
		ll pts[2] = {0, 0};
		ld closest[2]={INF,INF};
		for(int t=0;t<2;t++){
			for(int i=0;i<N;i++){
				Point<ld>s,e;
				cin>>s.x>>s.y;
				cin>>e.x>>e.y;
				ld d=segDist(s,e,pl);
				if(equals(d,0.000000000)){
					pts[t]++;
				}
				closest[t]=min(closest[t],d);
			}
			//cerr<<"closest:"<<closest[t]<<endl;
		}
		cout<<"Meninas: "<<pts[0]<<" ponto(s)\n";
		cout<<"Meninos: "<<pts[1]<<" ponto(s)\n";
		if(pts[0]>pts[1]){
			cout<< "As meninas venceram";
		}
		else if (pts[1]>pts[0]){
			cout<< "Os meninos venceram";
		}
		else{
			if(equals(closest[0],closest[1])){
				cout<<"Empate";
			}
			else{
				if(closest[0]<closest[1]){
					cout<< "As meninas venceram";
				}
				else if(closest[0]>closest[1]){
					cout<< "Os meninos venceram";
				}
			}
		}
	}
}


