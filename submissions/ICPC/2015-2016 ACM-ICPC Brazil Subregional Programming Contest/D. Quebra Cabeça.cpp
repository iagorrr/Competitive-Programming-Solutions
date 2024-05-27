#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int L, C;

const int maxd = 105;
string GRID[maxd][maxd];
map<string, set<int>> PLINE, PCOL;
set<string> SLINE[maxd], SCOL[maxd];
map<string,int> HLINE[maxd], HCOL[maxd];
ll VLINE[maxd], VCOL[maxd];
map<string, ll> ans;

void read() {
	cin >> L >> C;

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < C; j++) {
			cin >> GRID[i][j];

			PLINE[GRID[i][j]].emplace(i);
			PCOL[GRID[i][j]].emplace(j);

			SLINE[i].emplace(GRID[i][j]);
			SCOL[j].emplace(GRID[i][j]);

			HLINE[i][GRID[i][j]]++;
			HCOL[j][GRID[i][j]]++;
		}

		cin >> VLINE[i];
	}

	for (int i = 0; i < C; i++)
		cin >> VCOL[i];

}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	read();

	// qtd, isline, idx
	using state = tuple<int, bool, int>;
	set<state> pq;

	for (int i = 0; i < L; i++){
		if (SLINE[i].size() == 1)
			pq.emplace(SLINE[i].size(), 1, i);
	}

	for (int i = 0; i < C; i++){
		if (SCOL[i].size() == 1)
			pq.emplace(SCOL[i].size(), 0, i);
	}

	while (!pq.empty()) {
		auto [qtd, isline, idx] = *pq.begin();
		pq.erase(pq.begin());

		if (isline) {
			if(SLINE[idx].empty()) continue;
			auto curs = *SLINE[idx].begin();
			SLINE[idx].erase(curs);
			int qtd_curs = HLINE[idx][curs];
			ll curv = VLINE[idx] /qtd_curs;
			ans[curs] = curv;

			for (auto l : PLINE[curs]){
				int ql = HLINE[l][curs];
				VLINE[l] -= curv*ql;
				SLINE[l].erase(curs);
				if(SLINE[l].size() == 1) {
					pq.emplace(1, 1, l);
				}
			}


			for (auto c : PCOL[curs]) {
				int qc = HCOL[c][curs];
				VCOL[c] -= curv*qc;
				SCOL[c].erase(curs);
				if(SCOL[c].size() == 1) {
					pq.emplace(1, 0, c);
				}

			}
		}
		else { 
			if(SCOL[idx].empty()) continue;
			auto curs = *SCOL[idx].begin();
			SCOL[idx].erase(curs);
			int qtd_curs = HCOL[idx][curs];
			ll curv = VCOL[idx] /qtd_curs;
			ans[curs] = curv;

			for (auto l : PLINE[curs]){
			       	int ql = HLINE[l][curs];
				VLINE[l] -= curv*ql;
				SLINE[l].erase(curs);
				if(SLINE[l].size() == 1) {
					pq.emplace(1, 1, l);
				}
			}


			for (auto c : PCOL[curs]) {
				int qc = HCOL[c][curs];
				VCOL[c] -= curv*qc;
				SCOL[c].erase(curs);
				if(SCOL[c].size() == 1) {
					pq.emplace(1, 0, c);
				}

			}
		}
	}

	for (auto [s, v] : ans) {
		cout << s << ' ' << v << '\n';
	}
}

// AC, implementation
