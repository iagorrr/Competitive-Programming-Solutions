#include <bits/stdc++.h>

#include <numeric>
using namespace std;

unordered_map<int, int> cache;
int ask(int x) {
    if (cache.count(x)) return cache[x];
    cout << "? " << x << endl;

    int res;
    cin >> res;

    cache[x] = res;
    return res;
}

signed main() {
    ios_base::sync_with_stdio(!cin.tie(0));

    int N;
    cin >> N;

    cache[1] = 1;

    int cur = 1;
    int idx = 1;

    vector<int> pathIdx{cur};

    int levelSize = 1;
    int start = 1;
    for (; levelSize < N + 2;) {
        int nextStart = start + levelSize;
        int left = nextStart + idx - 1;
        int right = nextStart + idx - 1 + 1;

        int askLeft = ask(left);
        if (askLeft) {
            cur = left;
        } else {
            idx++;
            cur = right;
        }

        pathIdx.push_back(cur);
        start = start + levelSize;
        levelSize++;
    }

    int ansIdx = -1;
    for (int l = 0, r = (int)pathIdx.size() - 1; l <= r;) {
        int m = midpoint(l, r);

        int v = ask(pathIdx[m]);
        if (v) {
            ansIdx = max(ansIdx, m);
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    assert(~ansIdx);
    cout << "! " << pathIdx[ansIdx] << endl;
}
