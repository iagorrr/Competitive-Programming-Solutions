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
	ld r;cin>>r;
	ld area=r*r*PI;
	cout<<fixed<<setprecision(10)<<sqrt(area)<<'\n';
}
 
