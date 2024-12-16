#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(0));
    const vector<string> WINNER {"Monocarp", "Bicarp"};

    int N;
    cin >> N;

    string S;
    cin >> S;

    int s1, q1;
    s1 = q1 = 0;
    for (int i = 0; i < N / 2; i++) {
        s1 += (S[i] != '?') * (S[i] - '0');
        q1 += (S[i] == '?');
    }

    int s2, q2;
    s2 = q2 = 0;
    for (int i = N / 2; i < N; i++) {
        s2 += (S[i] != '?') * (S[i] - '0');
        q2 += (S[i] == '?');
    }

    int mn = min(q2, q1);
    q2 -= mn;
    q1 -= mn;


    if (q2 == q1 and q1 == 0) {
        cout << WINNER[s1 == s2] << '\n';
        return 0;
    }


    if ((q1 == 0 and s1 <= s2) or (q2 == 0 and s2 <= s1)){
        cout << WINNER[0] << '\n';
        return 0;
    }

    int s = q2 ? s2 : s1;
    int d = abs(s1 - s2);
    int q = max(q2, q1);
    bool only_zero = (q+1)/2 * 9 >= d;
    int left = d - (q/2)*9;
    bool only_nine = 0 <= left and left <= (q+1)/2 * 9;
    if (only_zero and only_nine) {
        cout << WINNER[1] << '\n';
        return 0;
    }
    else
        cout << WINNER[0] << '\n';
}
