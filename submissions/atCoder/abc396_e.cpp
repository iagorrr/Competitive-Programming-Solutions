#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2'00'000 + 10;
const int MAXM = 1'00'000 + 10;
const int MAXB = 31;

using vi = vector<int>;

int N, M;
int XS[MAXM];
int YS[MAXM];
int ZS[MAXM];
int AS[MAXN];

/*8<{=============~ BEGIN DSU ~===============>8*/
/*8<
  @Title:

    DSU / UFDS

  @Usage:

    You may discomment the commented parts to
    find online which nodes belong to each
    set, it makes the $union\_set$ method cost
    $O(log^2)$ instead $O(A)$

>8*/

struct DSU {
    vi ps, sz;

    // vector<unordered_set<int>> sts;

    DSU(int N)
        : ps(N + 1),
          sz(N, 1) /*, sts(N) */
    {
        iota(ps.begin(), ps.end(), 0);
        // for (int i = 0; i < N; i++)
        // sts[i].insert(i);
    }
    int find_set(int x) { return ps[x] == x ? x : ps[x] = find_set(ps[x]); }
    int size(int u) { return sz[find_set(u)]; }
    bool same_set(int x, int y) { return find_set(x) == find_set(y); }
    void union_set(int x, int y) {
        if (same_set(x, y)) return;

        int px = find_set(x);
        int py = find_set(y);

        if (sz[px] < sz[py]) swap(px, py);

        ps[py] = px;
        sz[px] += sz[py];
        // sts[px].merge(sts[py]);
    }
};

/*8<===============~ END DSU ~===============}>8*/

vector<int> getMinParititon(vector<vector<int>> &adj, vector<int> &vis, int source, DSU &dsu) {
	vector<vector<int>> byColor(2);
	byColor[0].emplace_back(source);

	vector<int> weight(2);
	weight[0] += dsu.size(source);

	vis[source] = 1;

	queue<int> q;
	q.emplace(source);
	while(q.size()){
		auto u = q.front();
		q.pop();

		for (auto v : adj[u]) {
			if (vis[v] == vis[u]) {
				cout << -1 << '\n';
				exit(0);
			}

			if (vis[v] == 0) {
				vis[v] = 2 + 1 - vis[u];
				q.emplace(v);
				byColor[vis[v]-1].emplace_back(v);
				weight[vis[v]-1] += dsu.size(v);
			}
		}
	}

	return weight[0] < weight[1] ? byColor[0] : byColor[1];
}

vector<int> whichToSet(int b) {
	int p2 = (1<<b);

	DSU dsu(N);
	
	// unir os que tem xor 0
	for (int i = 0; i < M; i++) {
		if (!(ZS[i]&p2)) {
			dsu.union_set(XS[i], YS[i]);
		}
	}

	// montar os grafo "condensado"
	vector<vector<int>> ADJ(N);
	for (int i = 0; i < M; i++) {
		if (ZS[i]&p2) {
			int u =dsu.find_set(XS[i]);
			int v =dsu.find_set(YS[i]);
			if (u == v) {
				cout << -1 << '\n';
				exit(0);
			}
			ADJ[u].emplace_back(v);
			ADJ[v].emplace_back(u);
		}
	}

	// pra cada subgrafo pega o mínimo das bipartições
	// e coloca nos que vão ser 1
	// ja checa se não der bi partido é vapo
	vector<int> vis(N);
	vector<int> setSeted(N);
	for (int i = 0; i < N; i++) {
		int u = dsu.find_set(i);
		if (!vis[u]) {
			auto minParitition = getMinParititon(ADJ, vis, u, dsu);
			for (auto v : minParitition) setSeted[v]=1;
		}
	}
	
	vector<int> ret;
	for (int i = 0; i  < N; i++) {
		if (setSeted[dsu.find_set(i)]) ret.emplace_back(i);
	}

	return ret;
}

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(0));

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> XS[i] >> YS[i] >> ZS[i];
		XS[i]--;
		YS[i]--;
	}

	for (int b = 0; b <= MAXB; b++) {
		auto toSet = whichToSet(b);
		for (auto idx : toSet) {
			AS[idx] |= (1<<b);
		}
	}

	for (int i = 0; i < N; i++) {
		cout << AS[i] << " \n"[i==N-1];
	}
}

/*
tem cara de sat, em cima de cada bit...

X = ...
Y = ...
Z = ...

 * supor que é só de zero e 1 a sequencia e generaliza pra 30 sequencias onde cada uma
 * é um bit
 *
 *
 * Se A[X[i]] ^ B[X[i]]
 *
 * seja i2 = A[i]
 * Z[i2] = X[i2] ^ Y[i2];
 * supondo que
 *
 * 1 = X[A[i]] ^ Y[A[i]]
 *
 * tudo errado:
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * A[X[i]] ^ A[Y[i]] = Z[i];
 *
 * se Z[i] = 1:
 * 	A[X[i]] -> !A[Y[i]]
 * 	!A[X[i]] -> A[Y[i]]
 *
 * se Z[i] = 0:
 * 	A[X[i]] -> A[Y[i]]
 * 	A[X[i]] -> A[Y[i]]
 *
 *
 *
 * dai faz o sat pra cada bit
 *
 * mas tem que minimizar !
 *
 * pega o máximo de zeros possível ??
 *
 * so manipular

3 2
1 3 4
1 2 3

se sei fazer pra um bit é so fazer individual e vapo

se o xor deles é zero eles são iguais
cc tem que ser diferente

vai gerar meio que vários grafinhos DSU !
quem é igual vai pro mesmo dsu

e dai as arestas do grafo vai ser entre os parent's do DSU
tem que dar bipartido pra todo subgrafo


e dai escolhe o menor dos lados pra ser o com o 1

mo treta de codar tá loko

eh um dsu
e um biparitte matching

ent é o N + M
40 vezes

aaaaaa

xabu no caso 3 ?
5 8
4 2 4
2 3 11
3 4 15
4 5 6
3 2 11
3 3 0
3 1 9
3 4 15

4 2 0
2 3 1
3 4 1
4 5 1
3 2 1
3 3 0
3 1 0
3 4 1

4 2 
3 1


* graphs, bitwise
*/
