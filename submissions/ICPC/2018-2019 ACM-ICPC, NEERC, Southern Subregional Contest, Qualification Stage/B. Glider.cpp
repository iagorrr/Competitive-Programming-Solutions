#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define f first
#define s second
#define all(x) x.begin(), x.end()
#define nl "\n"
int32_t main() {
        ios_base::sync_with_stdio(!cin.tie(0));

        int N, H;
        cin >> N >> H;

        vector<pair<int, int>> P(N);
        for (int i = 0; i < N; i++) {
                cin >> P[i].first >> P[i].second;
        }

        vector<int> fall;
        fall.push_back(H);
        for (int i = N - 2; i >= 0; i--) {
                fall.push_back(P[i + 1].f - P[i].s);
        }
        reverse(all(fall));

        vector<ll> pre(N + 1);
        for (int i = 0; i < N; i++) {
                pre[i + 1] = pre[i] + fall[i];
        }

        vector<ll> pre2(N + 1);
        for (int i = 0; i < N; i++) {
                pre2[i + 1] = pre2[i] + P[i].s - P[i].f;
        }

        ll ans = 0;
        for (int i = 0; i < N; i++) {
                ll cur = pre[i];
                auto pos = lower_bound(all(pre), cur + H) - pre.begin();
                // cout<<pos<<" "<<pre2[i]<<nl;
                ans = max(ans, H + pre2[pos] - pre2[i]);
        }
        cout << ans << nl;
}
