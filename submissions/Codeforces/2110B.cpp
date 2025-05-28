#include <bits/stdc++.h>
using namespace std;

void solve() {
        string S;
        cin >> S;

        int it1 = S.find('(');
        int it2 = S.find_last_of(')');
        string S2;
        for (int i = 0; i < (int)S.size(); i++) {
                if (i == it1 or i == it2) continue;

                S2.push_back(S[i]);
        }

        bool ok = true;
        int k = 0;
        for (int i = 0; i < (int)S2.size(); i++) {
                k += S2[i] == '(';
                k -= S2[i] != '(';
                ok &= (k >= 0);
        }
        cout << (ok ? "NO" : "YES") << '\n';
}

int32_t main() {
        ios_base::sync_with_stdio(!cin.tie(0));
        int T;
        cin >> T;

        while (T--) {
                solve();
        }
}

/*
 * strings
 * */
