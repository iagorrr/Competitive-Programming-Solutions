#include<bits/stdc++.h>
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(0));
    int a, b, k1, k2, n;
    cin >>a>> b>> k1>> k2>> n;

    int mx = -1;
    {
        priority_queue<int> pq;
        for (int i = 0; i < a; i++)
            pq.emplace(k1);

        for (int i = 0; i < b; i++)
            pq.emplace(k2);

        for (int i = 0; i < n and !pq.empty(); i++) {
            int u = pq.top();
            pq.pop();
            if (u > 1) pq.emplace(u - 1);
        }

        mx = a + b - pq.size();
    }

    int mn = -1;
    {
            priority_queue<int, vector<int>, greater<>> pq;
            for (int i = 0; i < a; i++)
                pq.emplace(k1);

            for (int i = 0; i < b; i++)
                pq.emplace(k2);

            for (int i = 0; i < n and !pq.empty(); i++) {
                int u = pq.top();
                pq.pop();
                if (u > 1) pq.emplace(u - 1);
            }

            mn = a + b - pq.size();
    }

    cout << mx << ' ' << mn << '\n';
}


// AC, implementation
