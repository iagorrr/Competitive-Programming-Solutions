#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (ll) __x.size()
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

const ll INF = 1e18;

struct state {
  int len, link, cnt, firstpos;
  // this can be optimized using a vector with the alphabet size
  map<char, int> next;
  vi inv_link;
};
struct SuffixAutomaton {
  vector<state> st;
  int sz = 0;
  int last;
  vc cloned;

  SuffixAutomaton(const string &s, int maxlen)
    : st(maxlen * 2), cloned(maxlen * 2) {
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
    for (auto &c : s) add_char(c);

    // precompute for count occurences
    for (int i = 1; i < sz; i++) {
      st[i].cnt = !cloned[i];
    }
    vector<pair<state, int>> aux;
    for (int i = 0; i < sz; i++) {
      aux.push_back({st[i], i});
    }

    sort(all(aux), [](const pair<state, int> &a, const pair<state, int> &b) {
      return a.fst.len > b.fst.len;
    });

    for (auto &[stt, id] : aux) {
      if (stt.link != -1) {
        st[stt.link].cnt += st[id].cnt;
      }
    }

    // for find every occurende position
    for (int v = 1; v < sz; v++) {
      st[st[v].link].inv_link.push_back(v);
    }
  }

  void add_char(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    st[cur].firstpos = st[cur].len - 1;
    int p = last;
    // follow the suffix link until find a transition to c
    while (p != -1 and !st[p].next.count(c)) {
      st[p].next[c] = cur;
      p = st[p].link;
    }
    // there was no transition to c so create and leave
    if (p == -1) {
      st[cur].link = 0;
      last = cur;
      return;
    }

    int q = st[p].next[c];
    if (st[p].len + 1 == st[q].len) {
      st[cur].link = q;
    } else {
      int clone = sz++;
      cloned[clone] = true;
      st[clone].len = st[p].len + 1;
      st[clone].next = st[q].next;
      st[clone].link = st[q].link;
      st[clone].firstpos = st[q].firstpos;
      while (p != -1 and st[p].next[c] == q) {
        st[p].next[c] = clone;
        p = st[p].link;
      }
      st[q].link = st[cur].link = clone;
    }
    last = cur;
  }

  bool checkOccurrence(const string &t) {  // O(len(t))
    int cur = 0;
    for (auto &c : t) {
      if (!st[cur].next.count(c)) return false;
      cur = st[cur].next[c];
    }
    return true;
  }
  ll totalSubstrings() {  // distinct, O(len(s))
    ll tot = 0;
    for (int i = 1; i < sz; i++) {
      tot += st[i].len - st[st[i].link].len;
    }
    return tot;
  }

  // count occurences of a given string t
  ll countOccurences(const string &t) {
    int cur = 0;
    for (auto &c : t) {
      if (!st[cur].next.count(c)) return 0;
      cur = st[cur].next[c];
    }
    return st[cur].cnt;
  }

  // find the first index where t appears a substring O(len(t))
  ll firstOccurence(const string &t) {
    int cur = 0;
    for (auto c : t) {
      if (!st[cur].next.count(c)) return -1;
      cur = st[cur].next[c];
    }
    return st[cur].firstpos - len(t) + 1;
  }

  vi everyOccurence(const string &t) {
    int cur = 0;
    for (auto c : t) {
      if (!st[cur].next.count(c)) return {};
      cur = st[cur].next[c];
    }
    vi ans;
    getEveryOccurence(cur, len(t), ans);
    return ans;
  }

  void getEveryOccurence(int v, int P_length, vi &ans) {
    if (!cloned[v]) ans.pb(st[v].firstpos - P_length + 1);
    for (int u : st[v].inv_link) getEveryOccurence(u, P_length, ans);
  }
};
const int mod = 1e9 + 7;
void run() {
  string s;
  cin >> s;
  SuffixAutomaton sa(s, len(s));
  int k;
  cin >> k;
  vii positions;
  while (k--) {
    string t;
    cin >> t;
    vi endpos = sa.everyOccurence(t);
    for (auto &e : endpos) positions.emplace_back(e, e + len(t) - 1);
  }
  sort(all(positions));

  vi dp(len(s));
  for (auto &[l, r] : positions) {
    if (l == 0) {
      dp[r] = (dp[r] + 1) % mod;
    } else if (dp[l - 1] != 0) {
      dp[r] = (dp[r] + dp[l - 1]) % mod;
    }
  }
  cout << dp[len(s) - 1] << endl;
}
int32_t main(void) {
  // fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, find every substring occurence, dynamic programming
