#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define nl "\n"
int32_t main() {
        ios_base::sync_with_stdio(!cin.tie(0));

        int N, M, D;
        cin >> N >> M >> D;

        vector<int> A(N);
        for (int i = 0; i < N; i++) {
                cin >> A[i];
        }

        set<int> st;
        for (int i = 0; i < N; i++) {
                st.insert(A[i]);
        }

        map<int, int> pos;
        int ans = 0;
        for (int i = 1; i <= N; i++) {
                int cur = *st.begin();
                while (st.lower_bound(cur) != st.end()) {
                        cur = *st.lower_bound(cur);
                        // cout<<cur<<nl;
                        pos[cur] = i;
                        st.erase(cur);
                        cur += D + 1;
                }
                if (size(st) == 0) {
                        ans = i;
                        break;
                }
        }

        cout << ans << nl;
        for (int i = 0; i < N; i++) {
                cout << pos[A[i]] << " ";
        }
        cout << "\n";
}
