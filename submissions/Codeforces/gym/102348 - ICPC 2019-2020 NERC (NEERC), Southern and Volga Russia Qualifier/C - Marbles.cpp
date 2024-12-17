#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXC = 20;
const ll OO = 1e18;
ll memo[1<<MAXC];

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(0));
    memset(memo, -1, sizeof memo);

    int N;
    cin >> N;

    vector<int> XS(N);
    for (auto &xi : XS)
        cin >> xi, xi--;

    vector<vector<int>> qtd(MAXC, vector<int>(N));
    qtd[XS.front()][0] = 1;
    for (int i = 1; i < N; i++) {
        for (int q = 0; q < 20; q++) {
            qtd[q][i] = qtd[q][i-1] + (XS[i] == q);
        }
    }

    vector<vector<int>> rqtd(MAXC, vector<int>(N));
    rqtd[XS.back()][N-1] = 1;
    for (int i = N - 2; ~i; i--) {
        for (int q = 0; q < 20; q++) {
            rqtd[q][i] = rqtd[q][i+1] + (XS[i] == q);
        }
    }

    /*
        dec[i][j] quando 'removo' a cor i quanto que 
        barateia pra por a cor j no 'início'
    */
    vector<vector<ll>> dec(MAXC, vector<ll>(MAXC));

    for (int i = 0; i < N; i++) {
        for (int c = 0; c < MAXC; c++) {
            dec[XS[i]][c] += (rqtd[c][i]);
        }
    }

    vector<ll> cost(MAXC);
    for (int i = 0; i < N; i++) {
        auto ci = XS[i];
        cost[ci] += (i - (i?qtd[ci][i-1]:0));
    }

    int full_mask = 0;
    for (auto xi : XS) {
        full_mask |= (1ll << xi);
    }

    function<ll(int)> solve = 
        [&](int mask) {
            if (mask == full_mask)
                return 0ll;

            auto &ret = memo[mask];
            if (~ret) return ret;

            ret = OO;
            for (int i = 0; i < MAXC; i++) {
                if ((full_mask & (1<<i)) and !(mask & (1<<i))) {
                    for (int j = 0; j < MAXC; j++) {
                        if (j != i)
                            cost[j] -= dec[i][j];
                    }

                    ret = min(ret, cost[i] + solve(mask | (1<<i)));

                    for (int j = 0; j < MAXC; j++) {
                        if (j != i)
                            cost[j] += dec[i][j];
                    }
                }
            }

            return ret;
        };

    cout << solve(0) << '\n';
}

// AC, dynamic programming, sortings, constructive algorithms
