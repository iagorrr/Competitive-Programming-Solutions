#include<bits/stdc++.h>
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(0));
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> AS(M);
    for (auto &ai : AS)
        cin >> ai;

    priority_queue<pair<int,int>> pq;
    for (int i = 0; i < M; i++) {
        pq.emplace(AS[i], i);
    }

    int same = 0, idx = 0;
    vector<int> assingnment(N, -1);
    while(idx < N and !pq.empty()) {
        auto [q, u] = pq.top();
        pq.pop();

        if (idx and assingnment[idx - 1] == u and same == K) {
            if (pq.empty()) {
                cout << -1 << '\n';
                return 0;
            }

            auto [q2, u2] = pq.top();
            pq.pop();


            assingnment[idx] = u2;

            if (q2 != 1) pq.emplace(q2-1,u2);

            pq.emplace(q, u);
            same = 1;
            idx++;

            continue;
        }

        assingnment[idx] = u;
        if (idx and assingnment[idx-1] == u)
            same++;
        else same = 1;

        if (q!=1) pq.emplace(q-1, u);
        idx++;
    }

    int mn = *min_element(assingnment.begin(), assingnment.end());
    if (mn == -1) {
        cout << -1 << '\n';
        return 0;
    }

    for (auto ai : assingnment) {
        cout << ai + 1 << ' ';
    }

    cout << '\n';
}

// AC, greedy
