#include<bits/stdc++.h>
using namespace std;

template<typename T>
using Point = pair<T,T>;
#define x first
#define y second

using ld = long double;

const ld PI=acos(-1);
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ld B,b,h,alpha;
	cin>>B>>b>>h>>alpha;
	alpha *= ((ld)PI/180);

	ld w1=h/tan(alpha);
	ld l1=sqrt(w1*w1+h*h);
	ld w2=B-b-w1;
	ld l2=sqrt(w2*w2+h*h);
	cout<<fixed<<setprecision(10);
	cout<<B+b+l1+l2<<'\n';
}



