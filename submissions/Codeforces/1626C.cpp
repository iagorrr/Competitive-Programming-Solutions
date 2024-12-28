#include <bits/stdc++.h>
using namespace std;

void run() {
    int N;
    cin >> N;

    vector<int> KS(N);
    for (auto &ki : KS)
        cin >> ki;

    vector<int> HS(N);
    for (auto &hi : HS)
        cin >> hi;

    vector<pair<int,int>> lrs(N);
    for (int i = 0; i < N; i++) {
        int hi = HS[i], ki = KS[i];
        lrs[i] = {ki - hi + 1, ki};
    }

    sort(begin(lrs), end(lrs), [&](const pair<int,int>&a, const pair<int,int>&b){
            return a.first == b.first ? a.second > b.second : a.first < b.first;
            });

    vector<pair<int,int>> lrs2 { lrs[0] };
    for (int i = 1; i < N; i++) {
        auto &[pl, pr] = lrs2.back();
        auto &[l, r] = lrs[i];

        if (l <= pr) pr = max(pr, r);
        else lrs2.push_back(lrs[i]);
    }

    long long ans = 0;

    for (auto &[l, r] : lrs2) {
        long long x = (r - l + 1);
        ans += (x*(x+1))/2;
    }

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(0));

    int T;
    cin >> T;
    for(;T--;) 
        run();


}

// AC, sortings, greedy
