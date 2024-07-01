#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vi2d = vector<vector<int>>;

#define len(x) (int)x.size()

struct trie {
  vi2d to;
  vi end, pref;
  int sigma;
  char norm;

  trie(int sigma_ = 26, char norm_ = 'a')
    : sigma(sigma_), norm(norm_) {
    to = {vector<int>(sigma)};
    end = {0}, pref = {0};
  }

  int next(int node, char key) {
    return to[node][key - norm];
  }

  void insert(const string &s) {
    int x = 0;
    for (auto c : s) {
      int &nxt = to[x][c - norm];
      if (!nxt) {
        nxt = len(to);
        to.push_back(vi(sigma));
        end.emplace_back(0), pref.emplace_back(0);
      }
      x = nxt, pref[x]++;
    }
    end[x]++, pref[0]++;
  }
  void erase(const string &s) {
    int x = 0;
    for (char c : s) {
      int &nxt = to[x][c - norm];
      x = nxt, pref[x]--;
      if (!pref[x]) nxt = 0;
    }
    end[x]--, pref[0]--;
  }
  int find(const string &s) {
    int x = 0;
    for (auto c : s) {
      x = to[x][c - norm];
      if (!x) return 0;
    }
    return x;
  }
};

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	trie st;
	while(n--) {
		string s;
		cin >> s;
		st.insert(s);
	}

	auto ps = st.pref;

	using ll = long long;

	ll ans = 0;
	for (auto i : ps) {
		ans = ans + ((ll)(i)*(i-1))/2ll;
	}
	ans = ans - ((ll)(ps.front())*(ps.front()-1))/2ll;

	cout << ans << '\n';
}
// AC, strings, trie
