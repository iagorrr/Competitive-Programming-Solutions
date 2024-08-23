#include <bits/stdc++.h>
using namespace std;

#define int long long
using ll = long long;

const int BLK = 1000;

const int MAX = 1e6+6, N = 1e5+5;
int vis[MAX];

vector<int> primos;

void crivo(){
	primos.push_back(2);
	for(int i =4; i < MAX; i+= 2) vis[i] = 1;
	for(int i =3; i < MAX; i+= 2){
		if(!vis[i]){
			primos.push_back(i);
			for(int j = i*i; j < MAX; j+= 2*i){
				vis[j] = 1; 
			}
		}
	}
}

vector<vector<int>> caras;

vector<int> fat(int x){
	vector<int> ans;
	for(auto p : primos){
		while(x%p == 0){
			x /= p;
			ans.push_back(p);
		}
		if(p*p > x){
			break;
		}
	}
	if(x > 1){
		ans.push_back(x);
	}
	return ans;
}

struct Query{
	int l,r,idx;

	Query(int l, int r, int idx): l(l), r(r), idx(idx){}
	bool operator <(Query other) const{
		if(l/BLK != other.l/BLK) return l/BLK < other.l/BLK;
		return (l/BLK & 1) ? r < other.r : r > other.r;
	}
};

int qtd[MAX], num[N];

inline void add(int i){
	for(auto x : caras[i]){
		qtd[x]++;
	}
}

inline void remove(int i){
	for(auto x : caras[i]){
		qtd[x]--;
	}
}

bool check(int i){
	vector<int> temp = fat(num[i]);
	for(int i =0; i < (int)temp.size(); i++){
		if(qtd[temp[i]] <= 0){
			for(int j= 0; j < i; j++){
				qtd[temp[j]]++;
			}
			return false;
		}
		qtd[temp[i]]--;
	}
	for(int i =0; i < (int) temp.size(); i++){
		qtd[temp[i]]++;
	}
	return true;
}

vector<int> mo(vector<Query> & queries){
	vector<int> res(queries.size());
	sort(queries.begin(),queries.end());

	int l = 0, r = -1;
	for(Query q : queries){
		while(l > q.l) add(--l);
		while(r < q.r) add(++r);
		while(l < q.l) remove(l++);
		while(r > q.r) remove(r--);
		res[q.idx] = check(q.idx);
	}
	return res;
}

int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	crivo();
	int n; cin >> n;
	for(int i =0; i < n ; i++){
		int x; cin >> x;
		caras.push_back(fat(x));
	}
	int q; cin >> q;
	vector<Query> que;
	for(int i =0; i < q; i++){
		int l, r,x; cin >> l >> r >> x;
		l--; r--;
		num[i] = x;
		que.push_back(Query(l,r,i));
	}
	vector<int> res = mo(que);

	for(int i = 0; i<q; i++){
		if(res[i]){
			cout << "Yes" << '\n';
		}
		else{
			cout << "No" << '\n';
		}
	}
}

// AC, math, number theory, range queries, Mo's 
