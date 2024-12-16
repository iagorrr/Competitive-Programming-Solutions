#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(0));

    int N;
    cin >> N;

    string S, T;
    cin >> S >> T;

    {
        int qa, qb;
        qa = qb = 0;
        for (auto c : S)
            qa += c == 'a', qb += c == 'b';

        for (auto c : T)
            qa += c == 'a', qb += c == 'b';

        if ((qa & 1) or (qb & 1)) {
            cout << -1 << '\n';
            return 0;
        }
    }

    vector<int> t1, t2;;
    for (int i = 0; i < N; i++) {
        if (S[i] != T[i]) {
            if (S[i] == 'a')
                t1.emplace_back(i);
            else t2.emplace_back(i);
        }
    }

    cerr << size(t1) << ' ' << size(t2) << '\n';
    vector<pair<int,int>> ans;
    while (size(t1) >= 2) {
        ans.emplace_back(t1.back(), end(t1)[-2]);
        t1.pop_back(), t1.pop_back();
    }

    while (size(t2) >= 2) {
        ans.emplace_back(t2.back(), end(t2)[-2]);
        t2.pop_back(), t2.pop_back();
    }

    if (size(t2) + size(t1) == 1) {
        cout << -1 << '\n';
        return 0;
    }

    if (size(t2) + size(t1) == 2) {
        ans.emplace_back(t1.back(), t1.back());
        ans.emplace_back(t1.back(), t2.back());
    }

    cout << size(ans) << '\n';
    for (auto &[a, b] : ans) {
        cout << a + 1 << ' ' << b + 1<< '\n';
    }
}

// AC, strings
