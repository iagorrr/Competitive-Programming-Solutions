#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll q, n, t;
	cin >> q >> n >> t;

	vector<pll> qts(q);
	for (auto &[a, b] : qts) cin >> a >> b;
	sort(qts.rbegin(), qts.rend());

	vector<pll> alunos(n);
	for (int i = 0; i < n; i++) {
		cin >> alunos[i].first;
		alunos[i].second = i;
	}

	sort(alunos.begin(), alunos.end());

	multiset<ll> mst;
	ll s = 0;

	vector<int> ans(n);
	for (auto &[inte, idx] : alunos) {
		while (!qts.empty()) {
			auto [i, ti] = qts.back();
			if (i > inte) break;
			qts.pop_back();

			if (s + ti <= t) {
				s += ti;
				mst.emplace(ti);
			}
			else {
				if (!mst.empty() and *mst.rbegin() > ti) {
					s -= *mst.rbegin();
					s+=ti;

					mst.erase(prev(mst.end()));
					mst.emplace(ti);
				}
			}
		}

		ans[idx] = (int)mst.size();
	}
	
	for (int i = 0; i < n; i++) {
		cout << ans[i] << '\n';
	}

}

// AC, greddy, data structures
