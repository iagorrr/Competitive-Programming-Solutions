#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
#define len(x) (int)x.size()

struct pt {
    ll x, y, c;

    pt(ll _x, ll _y) : x(_x), y(_y) {
        if (y == 0) {
            c = x >= 0 ? 2 : 4;
        } else {
            c = y >= 0 ? 3 : 1;
        }
    }

    bool operator<(const pt& o) const {
        if (o.c == c) {
            return y * o.x < x * o.y;
        } else {
            return c < o.c;
        }
    }
};
struct p {
    vector<pt> pts;
    vector<ll> psumX, psumY;

    p(const vector<pt>& xs, ll sx, ll sy)
        : pts(xs), psumX(len(xs)), psumY(len(xs)) {
        for (auto& pi : pts) pi = pt(pi.x * sx, pi.y * sy);
        sort(pts.begin(), pts.end());

        psumX[0] = pts[0].x;
        for (int i = 1; i < len(psumX); i++) psumX[i] = psumX[i - 1] + pts[i].x;

        psumY[0] = pts[0].y;
        for (int i = 1; i < len(psumY); i++) psumY[i] = psumY[i - 1] + pts[i].y;
    }

    ll solve(ll L, ll K) {
        ll ans = 0;

        pt mn = pt(K, -L);
        pt mx = pt(-K, L);

        // todos após
        auto itL = upper_bound(pts.begin(), pts.end(), mn);
        auto itR = lower_bound(pts.begin(), pts.end(), mx);
        if (itR != pts.begin() and itL != pts.end()) {
            int r = prev(itR) - pts.begin();
            int l = itL - pts.begin();
            ans += abs(psumX[r] - (l ? psumX[l - 1] : 0)) * L;
            ans += abs(psumY[r] - (l ? psumY[l - 1] : 0)) * K;
        }

        return ans;
    }
};

signed main() {
    ios_base::sync_with_stdio(!cin.tie(0));
    ll n, q;
    cin >> n >> q;

    vector<pt> pts;
    for (ll i = 0; i < n; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        pts.push_back(pt(a - b, c - d));
    }

    vector<p> ps;
    ps.push_back(p(pts, 1, 1));
    ps.push_back(p(pts, -1, 1));
    ps.push_back(p(pts, 1, -1));
    ps.push_back(p(pts, -1, -1));

    while (q--) {
        ll k, l;
        cin >> l >> k;
        ll ans = 0;
        for (auto& pi : ps) ans = max(ans, pi.solve(l, k));
        cout << ans << endl;
    }
}
