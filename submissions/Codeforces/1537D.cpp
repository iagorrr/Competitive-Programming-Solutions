#include <bits/stdc++.h>
using namespace std;


bool solve(int x) {
    if (x & 1) return false;
    return __builtin_popcount(x) != 1 or (__builtin_ffs(x)&1);
}

void run() {
    int N;
    cin >> N;
    cout << (solve(N) ? "Alice" : "Bob") << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(!cin.tie(0));

    int T;
    cin >> T;
    for (;T--;) {
        run();
    }
}

// AC, math, games
