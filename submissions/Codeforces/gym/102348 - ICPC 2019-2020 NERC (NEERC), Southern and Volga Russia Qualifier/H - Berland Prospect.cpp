#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

const int MAXN = 3'000;
int memo[MAXN+1][MAXN+1];

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(0));
    memset(memo, -1, sizeof memo);

    int N;
    cin >> N;
    
    vector<ll> XS(N);
    for (auto &xi : XS)
        cin >> xi;

    int ans = 0;
    function<int(int,int)> solve =
        [&](int i, int j) {
            if (i >= N) return 0;

            auto &ret = memo[i][j];
            if (~ret) return ret;

            ret = 1;

            if (j == N) {
                for (int k = i + 1; k < N; k++) {
                    ret = max(ret, 1 + solve(k, i));
                }
            }
            else {
                ll d = XS[i] - XS[j];
                auto it = lower_bound(XS.begin() + j, XS.end(), XS[i] + d);
                if (it != end(XS) and *it == XS[i] + d)
                    ret = max(ret, 1 + solve(it - begin(XS), i));
            }

            return ret;
        };

    for (int i = 0; i < N; i++) {
        ans = max(ans, solve(i, N));
    }

    cout << ans << '\n';
}

// AC, dynamic programming
