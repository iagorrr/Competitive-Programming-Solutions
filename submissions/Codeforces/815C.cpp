#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e3 + 1;
int ds[maxn], cs[maxn], ps[maxn], sz[maxn];
vector<int> mem[maxn][2];
vector<int> tree[maxn];
vector<int> dag[maxn];

int n, b;

const int oo = 1e9 + 2;

void calc(int u) {
    if (sz[u] != 0) return;
    sz[u] = 1;

    for (int v : dag[u]) {
        calc(v);
        sz[u] += sz[v];
    }
}

void dp(int u, int boa) {
    if (mem[u][boa].size()) return;
    auto& uDp = mem[u][boa];
    uDp = {boa ? oo : 0, cs[u] - boa * ds[u]};

    for (int v : tree[u]) {
        vector<int> newDp;
        for (int padas = 0; padas <= boa; padas++) {
            dp(v, padas);
            vector<int>& vDp = mem[v][padas];
            int newSz = uDp.size() + vDp.size() - 1;
            newDp.resize(newSz, oo);

            for (int wU = 0; wU < (int)uDp.size(); wU++) {
                if (uDp[wU] >= oo) continue;
                for (int wV = 0; wV < (int)vDp.size(); wV++) {
                    if (vDp[wV] >= oo) continue;

                    newDp[wU + wV] = min(newDp[wU + wV], uDp[wU] + vDp[wV]);
                }
            }
        }

        uDp = move(newDp);
    }
}

signed main() {
    ios_base::sync_with_stdio(!cin.tie(0));
    cin >> n >> b;

    for (int i = 0; i < n; i++) {
        cin >> cs[i] >> ds[i];
        if (i) {
            int pi;
            cin >> pi;
            pi--;
            dag[i].emplace_back(pi);
            tree[pi].emplace_back(i);
        }
    }

    for (int i = 0; i < n; i++) calc(i);

    int carlos = 0;

    for (int boa = 0; boa < 2; boa++) {
        dp(0, boa);
        auto& porFavorMeAceiteSendoVerdeCarlos = mem[0][boa];
        for (int ans = (int)porFavorMeAceiteSendoVerdeCarlos.size() - 1;
             ans >= 0; ans--) {
            if (porFavorMeAceiteSendoVerdeCarlos[ans] <= b) {
                carlos = max(carlos, ans);
                break;
            }
        }
    }

    cout << carlos << endl;
}
