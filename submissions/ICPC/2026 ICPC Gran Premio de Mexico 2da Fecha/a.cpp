#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
using ll = long long;

const ll mod = 998244353;

using _edge = tuple<int, int, int>;
vector<vector<_edge>> preffixAutomaton(const vector<int> &z) {
    int n = z.size();

    vector<vector<_edge>> adj(2);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        r = max(r, z[i] + i);
        if (i < r) continue;

        int nxt = adj.size();
        adj.back().push_back({nxt, l + 1, r});
        adj.push_back({});
        l = i;
    }
    for (auto &x : adj) x.push_back({1, 0, 0});

    return adj;
}
ll solve(vector<vector<_edge>> &g, int k) {
    int n = g.size();

    vector<vector<ll>> memo(n, vector<ll>(k + 1, -1));

    function<ll(ll, ll)> dp = [&](ll i, ll j) {
        if (j == 0) return 1ll;

        auto &ret = memo[i][j];

        if (~ret) {
            return ret;
        }

        ret = 0;
        for (auto [v, l, r] : g[i]) {
            auto c = r - l + 1;
            if (c <= j) {
                ret = (ret + dp(v, j - c)) % mod;
            }
        }
        return ret;
    };

    return dp(0, k);
}

vector<int> zf(const string &s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    auto padasDataStructure = preffixAutomaton(zf(s));
    cout << solve(padasDataStructure, k) << '\n';
}

int main() {
    ios_base::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;

    while (t--) solve();
}

// mais de uma aresta igual
