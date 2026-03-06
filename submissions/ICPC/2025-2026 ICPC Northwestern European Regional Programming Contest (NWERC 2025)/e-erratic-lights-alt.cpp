#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAX = 101;
double logfact[MAX];

void calc() {
    logfact[0] = 0;
    for (int i = 1; i < MAX; i++) logfact[i] = logfact[i - 1] + log(i);
}

double binom(int n, int k, double p) {
    return exp(logfact[n] - logfact[k] - logfact[n - k] + k * log(p) +
               (n - k) * log(1 - p));
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));
    calc();

    int n;
    cin >> n;

    string s;
    cin >> s;

    int r = count(s.begin(), s.end(), 'r');
    int g = count(s.begin(), s.end(), 'g');
    int b = count(s.begin(), s.end(), 'b');

    vector<int> counts = {r, g, b};
    sort(counts.begin(), counts.end());

    int x = counts[0], y = counts[1], z = counts[2];

    if (x == 0 && y == 0) {
        cout << fixed << setprecision(10) << 0.0 << endl;
        return 0;
    }

    if (x == 0) {
        cout << fixed << setprecision(10) << (long double)y * 3.0 << endl;
        return 0;
    }

    long double ans = x * 1.5;

    long double extra_expected = 0;
    for (int i = 0; i <= x; i++) {
        long double prob = binom(x, i, (double)1 / 2);

        int final_y = y + i;
        int final_z = z + (x - i);

        extra_expected += prob * (min(final_y, final_z) * 3.0);
    }

    cout << fixed << setprecision(10) << ans + extra_expected << endl;
    return 0;
}
