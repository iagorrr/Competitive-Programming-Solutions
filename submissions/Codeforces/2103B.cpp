#include<bits/stdc++.h>
using namespace std;
void solve(){
	int N;
	cin>>N;
	string S;cin>>S;
	S = "0" + S;
	vector<int> p1;
	vector<int> p0;
	for(int i=0;i<N;i++){
		if(S[i]=='1'&&S[i+1]=='0')
			p1.emplace_back(i);
		if(S[i]=='0'&&S[i+1]=='1')
			p0.emplace_back(i);
	}
	if(S.back()=='0')
		p0.emplace_back(N);
	else
		p1.emplace_back(N);

	int i_cost = 0;
	for(int i=0;i+1<p1.size();i++){
		if(p1[i+1]!=N)i_cost=min(i_cost,-2);
		else i_cost=min(i_cost,-1);
	}
	for(int i=0;i+1<p0.size();i++){
		if(p0[i+1]!=N)i_cost=min(i_cost,-2);
		else i_cost=min(i_cost,-1);
	}


	int cur=0;
	int c=0;
	for(int i=0;i<=N;i++){
		if(cur!=S[i]-'0'){
			c++;
			cur=!cur;
		}
		c++;
	}
	/*
	cerr<<"c:"<<c<<'\n';
	cerr<<"i_cost:"<<i_cost<<'\n';
	*/
	cout << (c-1)+i_cost << '\n';
}
signed main()  {
	ios_base::sync_with_stdio(!cin.tie(0));
	int t;
	cin>>t;
	while(t--)solve();
}

/*
 * 1...0
 *
 * 0[1...0]0	nada
 * 0[1...0]1	-2
 * 1[1...0]0	+2
 * 1[1...0]1	nada
 *
 * 0[0...1]0	nada
 * 0[0...1]1	+2
 * 1[0...1]0	-2
 * 1[0...1]1	nada
 *
 * tem que rolar essa padrão aí
 *
 * 000 - > 3
 *
 * 111 -> 3
 * 011 -> 4
 *
 * 100 -> 4
 *
 * 10101
 *   lr
 * 10011 ->1234567
 *
 * 10101
 * ok finger começa no 0 da 8 mesmo
 *
 * 101
 * 011
 *
 * 0100
 * p1:=[1]
 * p0:=[0]
 *
 * AC, greedy, math
 * */
