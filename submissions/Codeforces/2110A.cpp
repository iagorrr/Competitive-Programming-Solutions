#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& a) {
        int N = a.size();

        int ans = N;
        for (int i = 0; i < N; i++) {
                if ((a[i] + a.back()) % 2 == 0) ans = min(ans, i);
        }

        for (int i = N - 1; i >= 0; i--) {
                if ((a[i] + a.front()) % 2 == 0) ans = min(ans, N - i - 1);
        }

        if ((a.back() + a.front()) % 2 == 0) ans = 0;

        return ans;
}

int32_t main() {
        ios_base::sync_with_stdio(!cin.tie(0));
        int T;
        cin >> T;

        while (T--) {
                int N;
                cin >> N;

                vector<int> XS(N);
                for (auto& xi : XS) cin >> xi;

                sort(XS.begin(), XS.end());

                cout << solve(XS) << '\n';
        }
}

/*
 * AC, implementation, sorrings
 * */
