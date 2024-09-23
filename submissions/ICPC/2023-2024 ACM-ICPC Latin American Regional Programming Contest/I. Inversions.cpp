#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=1'000'000'000+7;
/*8<
  @Title: Fast Pow
  @Description: Computes $a^b \pmod{m}$
  @Time: $O(\log{B})$.
>8*/
ll fpow(ll a, ll b, ll m) {
  ll ret = 1;
  while (b) {
    if (b & 1) ret = (ret * a) % m;
    b >>= 1;
    a = (a * a) % m;
  }
  return ret;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;cin>>s;
	ll n;cin>>n;
	n=n%mod;
	ll ans=0;
	vector<ll>hist('z'-'a'+10);
	for(auto c:s){
		hist[c-'a']++;
	}
	ll sm=0;
	ll nf=((n-1)*(n))%mod;
	nf=(nf*fpow(2,mod-2,mod))%mod;
	for(char c='a';c<='z';c++){
		int i=c-'a';
		ll q=hist[i];
		ll cur=(sm*q)%mod;
		cur=(cur*nf)%mod;
		ans+=cur;
		sm+=q;
	}
	fill(hist.begin(),hist.end(),0);
	ll per=0;
	for(auto c:s){
		ll inc=0;
		for(int i='z'-'a';i>c-'a';i--)
			inc+=hist[i];
		hist[c-'a']++;
		per=(per+inc)%mod;
	}
	per=(per*n)%mod;
	ans=(ans+per)%mod;
	cout<<ans<<'\n';
}
// AC, math
