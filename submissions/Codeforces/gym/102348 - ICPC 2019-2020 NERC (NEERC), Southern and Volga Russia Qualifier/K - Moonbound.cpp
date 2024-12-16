#include<bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(0));

    int N;
    cin >> N;

    using a4 = array<int, 4>;
    vector<a4> ans;

    int k = ans.size();
    int mx = (N * N * 3ll) / 4;

    for (int j = 1; j <= N; j += 2) {
        for (int i = N - 1; i >= 1; i -= 2) {
            ans.push_back(a4{ 1, i, j, 1});
            ans.push_back(a4{ 1, i+1, j+1, 1});
            ans.push_back(a4{ 2, i, j , 2});
        }
    }

    //cerr << "K: " << k << " mx: " << mx << '\n';
    assert(k <= mx);

    cout << ans.size() << '\n';

    for (auto xs : ans) {
        for (auto xi : xs)
            cout << xi << ' ';
        cout <<'\n';
    }
}

// AC, greedy
