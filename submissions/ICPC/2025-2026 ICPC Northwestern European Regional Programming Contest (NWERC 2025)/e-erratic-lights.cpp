#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int max_tries = 500;
const int max_success_tries = 500;
long double mem[max_tries + 1][max_success_tries + 1];

void precompute(long double success_probability) {
    long double fail_probability = 1 - success_probability;

    for (int i = 1; i <= max_tries; i++) mem[0][i] = 0;
    mem[0][0] = 1.0;

    for (int i = 1; i <= max_tries; i++) {
        mem[i][0] = mem[i - 1][0] * fail_probability;

        for (int j = 1; j <= min(i, max_success_tries); j++) {
            long double from_prev_success =
                mem[i - 1][j - 1] * success_probability;
            long double from_prev_failure =
                (j < i) ? mem[i - 1][j] * fail_probability : 0.0;

            mem[i][j] = from_prev_success + from_prev_failure;
        }
    }
}

long double pmf(int n, int k) {
    if (k < 0 || k > n) return 0.0;
    return mem[n][k];
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    precompute((long double)1 / 2);

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
        long double prob = pmf(x, i);

        int final_y = y + i;
        int final_z = z + (x - i);

        extra_expected += prob * (min(final_y, final_z) * 3.0);
    }

    cout << fixed << setprecision(10) << ans + extra_expected << endl;
    return 0;
}
