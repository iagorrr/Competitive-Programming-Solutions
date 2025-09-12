#include<bits/stdc++.h>
using namespace std;

using ll = long long;
void solve(){
        int n;
        cin >> n;

        vector<ll> xs(n);
        for (auto &xi :xs)
                cin >> xi;

        ll s = 0;
        {
                ll sig = 1;
                for (auto xi : xs) {
                        s += xi * sig;
                        sig*=-1;
                }
        }

        ll oo = 1e10;
        ll ans = s + (n-1) - !(n&1);
        {
                vector<ll> increase(n, -oo);
                for (int i = 1; i < n; i += 2) {
                        increase[i] = i + 2 * xs[i];
                }
                vector<ll> mx(n, -oo);
                mx[n-1]=increase[n-1];
                for(int i=n-2; i >= 0; i--) {
                        mx[i] = max(mx[i+1], increase[i]);
                }

                for (int i =0,d=0; i + 1 < n; i += 2, d+=2) {
                        ans = max(ans, s - 2 * xs[i] - d + mx[i+1]);
                }
        }

        {
                vector<ll> increase(n, -oo);
                for (int i = 2; i < n; i += 2) {
                        increase[i] = i - 1 - 2 * xs[i];
                }
                vector<ll> mx(n, -oo);
                mx[n-1]=increase[n-1];
                for(int i=n-2; i >= 0; i--) {
                        mx[i] = max(mx[i+1], increase[i]);
                }

                for (int i =1,d=0; i + 1< n; i += 2, d+=2) {
                        ans = max(ans, s + 2 * xs[i] - d + mx[i+1]);
                }
        }


        cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(!cin.tie(0));
	int t;cin>>t;while(t--)solve();
}
