// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define len(__x) (ll) __x.size()
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;
#define all(a) a.begin(), a.end()
#define INV(xxxx) \
    for (auto &xxx : xxxx) cin >> xxx;
#define PRINTV(___x) \
    for_each(all(___x), [](ll &____x) { cout << ____x << ' '; }), cout << '\n';
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)
#define rsz(___x, ___n) resize(___x, ___n)

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) {
    cerr << ' ' << h;
    dbg_out(t...);
}
#define dbg(...)                     \
    {                                \
        cerr << #__VA_ARGS__ << ':'; \
        dbg_out(__VA_ARGS__);        \
    }
const ll INF = 1e18;

void run() {
    ll n;
    cin >> n;
    vll xs(n);
    INV(xs);
    ll ans = -1;
    sort(all(xs));
    ll i = n - 1;
    while (i >= 0 and xs[i] == xs[n - 1]) {
        i--;
    }

    if (i == -1) {
        cout << i << '\n';
    } else {
        cout << i + 1 << ' ' << n - i - 1 << '\n';
        for (int j = 0; j <= i; ++j) {
            cout << xs[j] << ' ';
        }
        cout << endl;
        for (int j = i + 1; j < n; ++j) {
            cout << xs[j] << ' ';
        }
        cout << endl;
    }
}

int32_t main(void) {
    fastio;
    int t;
    t = 1;
    cin >> t;
    while (t--) run();
}

// AC, adhoc, math
