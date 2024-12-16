#include<bits/stdc++.h>
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(0));
    int n, k;
    cin >> n >> k;
    string s,f;
    cin >> s;
    cin >> f;
    int min_inc = 1e9, max_inc = 0, current_bt = -1, best_table = -1, inc= 0;
    for(int i= 1; i <= 2*n; i++) {
        int table_i = (i > n ? i-n : i);
        max_inc = 0;
        for(int j = 1; j <= 2*n; j++){
            int table_j = (j > n ? j-n : j);
            char b =  j > n ? f[table_j-1] : s[table_j-1];
            if(b != '1') continue;
            if((i <= n and j <= n) or (i > n and j > n)) inc = abs(table_i - table_j);
            else inc = table_i+k+table_j;
            max_inc = max(inc, max_inc);
       }
       if(min_inc > max_inc) best_table = i, min_inc = min(min_inc, max_inc);
    }
    cout << min_inc << "\n";
    cout << (best_table > n ? 1 : 2)<< " ";
    cout << (best_table  > n ? best_table-n : best_table)<< "\n";
}

// AC, brute force
