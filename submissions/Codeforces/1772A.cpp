// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
int main(){ 
    fastio;
    ll n;
    cin >> n;

    while(n--){
        string a;
        cin >> a;

        cout << ((int)a[0]-'0')+((int)a[2]-'0') << '\n';
    }
    return 0;
}
// AC