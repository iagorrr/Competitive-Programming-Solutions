#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 2'00'000;
ll memo[MAXN][2][2];

const ll MOD = 998244353;

ll sub(ll a, ll b) {
    return (a - b + MOD) % MOD;
}

ll add(ll a, ll b) {
    return (a + b) % MOD;
}

ll mul(ll a, ll b) {
    return (a * b) % MOD;
}

ll fpow(ll a, ll b) {
    ll r = 1;
    for (; b; b >>= 1, a = mul(a, a))
        if (b & 1)
            r = mul(r, a);
    return r;
}

ll vid(ll a, ll b) {
    return mul(a, fpow(b, MOD-2));
}


int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(0));
    memset(memo, -1, sizeof memo);

    const ll TOT_PROB = 1'000'000;
    ll N, P, Q;
    cin >> N >> P >> Q;
    P = vid(P, TOT_PROB);
    Q = vid(Q, TOT_PROB);
    ll R =sub(sub(1, P), Q);

    vector<ll> AS(N);
    for (auto &ai : AS)
        cin >> ai;

    sort(AS.begin(), AS.end());

    function<ll(int, bool, bool)> solve = 
        [&](int i, bool have_prev, bool have_cur) {
            if (i == N) return 0ll;

            auto &ret = memo[i][have_prev][have_cur];
            if (~ret) return ret;

            bool eq_next = (i + 1 < N and AS[i]+1 == AS[i+1]);
            bool eq_prev = (i and AS[i]-1 == AS[i-1]);

            ret = 0;
            // ganhar AS[i]-1
            ret = 
                add(ret, mul(add(eq_prev and !have_prev, solve(i+1, have_cur, false)), P));
            // ganhar AS[i]
            ret =
                add(ret, mul(add(!have_cur, solve(i+1, true, false)), R));
            // ganhar AS[i]+1
            ret =
                add(ret, mul(add(eq_next, solve(i+1, have_cur, eq_next)), Q));
            return ret;
        };

    cout << solve(0, 0, 0) << '\n';
}

// AC, dynamic programming, exptected value
