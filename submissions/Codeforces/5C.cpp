#include<bits/stdc++.h>
using namespace std;
#define len(x) (int)x.size()
#define eb emplace_back

int32_t main() {
	ios_base::sync_with_stdio(!cin.tie(0));
	string S;
	cin >> S;

	int szAns = 0, qAns = 1;
	vector<pair<char, int>> stk;


	for (auto c : S) {
		int asz = 0;
		if (len(stk) and stk.back().first == '*') {
			asz = stk.back().second;
			stk.pop_back();
		}
		if (c == ')') {
			if (!len(stk) or stk.back().first != '(') {
				stk.clear();
			}
			else {
				int sz = asz + 2;
				stk.pop_back();

				if (sz == szAns) qAns++;
				else if (sz > szAns) szAns = sz, qAns = 1;

				if (len(stk) and stk.back().first == '*') {
					stk.back().second += sz;
					sz = stk.back().second;

					if (sz == szAns) qAns++;
					else if (sz > szAns) szAns = sz, qAns = 1;
				}
				else
					stk.eb('*', sz);
			}
		}
		else {
			if (asz) stk.eb('*', asz);
			stk.eb('(', 1);
		}
	}
	cout << szAns << ' ' << qAns << endl;
}


/*
   AC, ad-hoc
 */
