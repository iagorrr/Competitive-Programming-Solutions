/*~=========================BEGIN MACRO=================================~*/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif

#define endl '\n'

#define fastio                        \
        ios_base::sync_with_stdio(0); \
        cin.tie(0);

#define int long long

#define all(j) j.begin(), j.end()
#define rall(j) j.rbegin(), j.rend()
#define len(j) (int)j.size()
#define rep(i, a, b) \
        for (common_type_t<decltype(a), decltype(b)> i = a; i < b; i++)
#define rrep(i, a, b) \
        for (common_type_t<decltype(a), decltype(b)> i = a; i > b; i--)
#define pb push_back
#define eb emplace_back

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;
using vs = vector<string>;

/*~==========================END MACRO==================================~*/

/*~================BEGIN LONGEST INCREASING SUBSEQUENCE=================~*/
#define len(j) (int)j.size()
#define all(j) j.begin(), j.end()
#define rall(j) j.rbegin(), j.rend()
#define rep(i, a, b) \
        for (common_type_t<decltype(a), decltype(b)> i = a; i < b; i++)

using vi = vector<int>;

template <typename T>
pair<int, vi> lis(const vector<T>& xs, int n) {
        vector<T> dp(n + 1, numeric_limits<T>::max());
        dp[0] = numeric_limits<T>::min();

        int sz = 0;
        vi psx(n);

        rep(i, 0, n) {
                int pos = lower_bound(all(dp), xs[i]) - dp.begin();

                sz = max(sz, pos);

                dp[pos] = xs[i];

                psx[i] = pos;
        }

        return {sz, psx};
}

template <typename T>
vi get_idx(vector<T> xs) {
        int n = xs.size();

        auto [sz1, psx1] = lis(xs, n);

        // reverse(all(xs));
        transform(rall(xs), xs.begin(), [](T x) { return -x; });
        // for (auto& xi : xs) xi = -xi;

        auto [sz2, psx2] = lis(xs, n);

        vi ans;
        rep(i, 0, n) {
                int l = psx1[i];
                int r = psx2[n - i - 1];
                if (l + r - 1 == sz1) ans.eb(i);
        }

        return ans;
}
/*~=================END LONGEST INCREASING SUBSEQUENCE==================~*/

auto run() {
        auto pos_naipe = [](char c) {
                switch (c) {
                        case 'S':
                                return 0;
                                break;

                        case 'W':
                                return 1;
                                break;

                        case 'E':
                                return 2;
                                break;

                        case 'R':
                                return 3;
                                break;

                        case 'C':
                                return 4;
                                break;
                }
        };

        int N;
        cin >> N;

        vector<pair<int, string>> SS(N);
        for (auto& [num, si] : SS) {
                cin >> si;
                num = stoi(si.substr(1));
        }

        int ans = INT_MAX;
        const int DT = 1e6;
        vi permv;
        rep(i, 0, 5) { permv.eb(DT * i); }
        do {
                vi order;
                for (auto& [num, si] : SS) {
                        order.eb(num + permv[pos_naipe(si[0])]);
                }

                int cur = N - lis(order, len(order)).first;
                ans = min(ans, cur);

        } while (next_permutation(permv.begin(), permv.begin() + 4));

        cout << ans << endl;
}

int32_t main() {
#ifndef LOCAL
        fastio;
#endif

        int T = 1;

        // cin >> T;

        rep(t, 0, T) {
                dbg(t);
                run();
        }
}

/*
        tem que saber quando vale a pena passar pra posição
   certa e quando vale apena puxar de longe pra posição
   certa


        AC, dynamic programming
 */
