#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) x.begin(), x.end()
#define nl "\n"
int32_t main() {
        ios_base::sync_with_stdio(!cin.tie(0));

        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
                cin >> A[i];
        }

        vector<int> B = A;
        for (int i = 0; i < N; i++) {
                while (B[i] % 2 == 0) B[i] /= 2;
        }
        sort(all(B));
        if (B[0] != B[N - 1]) {
                cout << -1 << nl;
                return 0;
        }

        map<ll, int> cnt;
        multiset<ll> cur;
        for (int i = 0; i < N; i++) {
                cnt[A[i]]++;
                cur.insert(A[i]);
        }

        int ans = 0;
        while (cur.size() > 1) {
                auto val = *cur.begin();
                if (cnt[val] > 1) {
                        cur.erase(cur.begin());
                        cur.erase(cur.begin());
                        cnt[val * 2]++;
                        cnt[val] -= 2;
                        cur.insert(val * 2);
                } else {
                        cur.erase(cur.begin());
                        cur.insert(val * 2);
                        cnt[val * 2]++;
                        cnt[val]--;
                        ans++;
                }
        }
        cout << ans << nl;
}
