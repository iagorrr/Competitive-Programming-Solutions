#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(0));
    int n; cin >> n;
    vector<int> a(n);
    for (auto &xi : a)
        cin >> xi;

    int odd_neg = 0, even_neg = 0;
    int ans_neg, ans_pos, ans_zero;
    ans_neg = ans_pos = ans_zero = 0;
    
    int cur_neg = 0;
    even_neg = 1;
    for (int i =0 ; i < n; i++) {
        int ai = a[i];
        if (ai == 0) {
            odd_neg = even_neg = cur_neg = 0;
            even_neg = 1;
        }
        else {
            cur_neg += (ai < 0);
            odd_neg += (cur_neg & 1);
            even_neg += !(cur_neg & 1);

            if (cur_neg & 1) {
                ans_neg += even_neg;
                ans_pos += (odd_neg-1);
            }
            else {
                ans_neg += odd_neg;
                ans_pos += (even_neg-1);
            }
        }
    }

    int close_zero = n;
    for (int i = n -1; ~i; i--) {
        if (a[i] == 0)
            close_zero = i;

        ans_zero += (n-close_zero);
    }


    cout << ans_neg << ' ' << ans_zero << ' ' << ans_pos << '\n';
}

// AC, prefix sums
