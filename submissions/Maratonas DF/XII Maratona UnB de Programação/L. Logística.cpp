#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 998244353;

ll fpow(ll a, ll b) {
  ll r = 1;
  while (b) {
    if (b & 1) r = (r * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return r;
}

/*8<==========================================>8*/
/*8<
  @Title:

    Prefix Sum 2D

  @Description:

    Given an 2D array with $N$ lines and $M$
    columns, find the sum of the subarray that
    have the left upper corner at $(x1, y1)$ and
    right bottom corner at $(x2, y2)$.

  @Time:

    Build $O(N \cdot M)$, Query $O(1)$.

>8*/

const int N = 1001;
ll matrix[N][N];
ll s[N][N];
ll psum[N][N];

void buildpsum(int n, int m) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      s[i][j] =
          s[i][j - 1] + matrix[i - 1][j - 1];
      psum[i][j] = psum[i - 1][j] + s[i][j];
    }
}

ll squery(int x1, int y1, int x2, int y2) {
  ll ans = psum[x2 + 1][y2 + 1] + psum[x1][y1];
  ans -= psum[x2 + 1][y1] + psum[x1][y2 + 1];
  return ans;
}

ll M[1001][1001][10][10];
ll op(ll a, ll b) { return gcd(a, b); }

void SparseMatrix(int n, int m) {
  int i, j, x, y;
  for (i = 0; (1 << i) <= n; i++) {
    for (j = 0; (1 << j) <= m; j++) {
      for (x = 0; (x + (1 << i) - 1) < n; x++) {
        for (y = 0; (y + (1 << j) - 1) < m; y++) {
          if (i == 0 && j == 0)
            M[x][y][i][j] = matrix[x][y];
          else if (i == 0)
            M[x][y][i][j] =
                op(M[x][y][i][j - 1],
                   M[x][y + (1 << (j - 1))][i]
                    [j - 1]);
          else if (j == 0)
            M[x][y][i][j] =
                op(M[x][y][i - 1][j],
                   M[x + (1 << (i - 1))][y][i - 1]
                    [j]);
          else {
            int tempa =
                op(M[x + (1 << (i - 1))][y][i - 1]
                    [j - 1],
                   M[x][y + (1 << (j - 1))][i - 1]
                    [j - 1]);
            int tempb = op(M[x][y][i - 1][j - 1],
                           M[x + (1 << (i - 1))]
                            [y + (1 << (j - 1))]
                            [i - 1][j - 1]);
            M[x][y][i][j] = op(tempa, tempb);
          }
        }
      }
    }
  }
  return;
}

int lg2(int x) {
  return sizeof(int) * 8 - __builtin_clz(x) - 1;
}

ll query2d(int x, int y, int x1, int y1) {
  int k = lg2(x1 - x + 1);
  int l = lg2(y1 - y + 1);

  int tempa = op(M[x][y][k][l],
                 M[x1 - (1 << k) + 1][y][k][l]);
  int tempb = op(M[x][y1 - (1 << l) + 1][k][l],
                 M[x1 - (1 << k) + 1]
                  [y1 - (1 << l) + 1][k][l]);
  return op(tempa, tempb);
}

int32_t main() {
  ios_base::sync_with_stdio(!cin.tie(0));

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> matrix[i][j];
    }
  }

  buildpsum(n, m);
  SparseMatrix(n, m);

  int xlen;
  cin >> xlen;
  vector<int> XS(xlen);
  for (auto &xi : XS) cin >> xi, xi--;
  ;

  int ylen;
  cin >> ylen;
  vector<int> YS(ylen);
  for (auto &yi : YS) cin >> yi, yi--;

  ll sum = 0;
  ll tot = 0;
  for (int i = 0; i < xlen; i++) {
    for (int j = i; j < xlen; j++) {
      for (int k = 0; k < ylen; k++) {
        for (int l = k; l < ylen; l++) {
          auto s =
              squery(XS[i], YS[k], XS[j], YS[l]);
          auto d =
              query2d(XS[i], YS[k], XS[j], YS[l]);
          assert(s % d == 0);
          sum = (sum + s / d) % MOD;
          tot++;
        }
      }
    }
  }

  ll ans = (sum * fpow(tot, MOD - 2)) % MOD;
  cout << ans << endl;
}
