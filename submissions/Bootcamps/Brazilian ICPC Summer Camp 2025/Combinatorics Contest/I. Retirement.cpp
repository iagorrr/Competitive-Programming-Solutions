/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define fastio                        \
        ios_base::sync_with_stdio(0); \
        cin.tie(0);
#define all(j) j.begin(), j.end()
#define rall(j) j.rbegin(), j.rend()
#define len(j) (int)j.size()
#define rep(i, a, b) \
        for (common_type_t<decltype(a), decltype(b)> i = (a); i < (b); i++)
#define rrep(i, a, b) \
        for (common_type_t<decltype(a), decltype(b)> i = (a); i > (b); i--)
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) for (auto &xi : ranges::views::reverse(xs))
using ll = long long;
#define endl '\n'
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define emp emplace
#define ins insert
#define divc(a, b) ((a) + (b) - 1ll) / (b)
using str = string;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vc = vector<char>;
using vs = vector<str>;
template <typename T, typename T2>
using umap = unordered_map<T, T2>;
template <typename T>
using pqmn = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using pqmx = priority_queue<T, vector<T>>;
template <typename T, typename U>
inline bool chmax(T &a, U const &b) {
        return (a < b ? a = b, 1 : 0);
}
template <typename T, typename U>
inline bool chmin(T &a, U const &b) {
        return (a > b ? a = b, 1 : 0);
}
/*8<============~ END TEMPLATE ~============}>8*/
void run();

int32_t main() {
#ifndef LOCAL
        fastio;
#endif

        int T = 1;

        rep(t, 0, T) {
                dbg(t);
                run();
        }
}

template <ll m>
struct mod_int {
        ll x;

        mod_int(ll v = 0) {
                x = v % m;
                if (x < 0) v += m;
        }

        mod_int &operator+=(mod_int const &b) {
                x += b.x;
                if (x >= m) x -= m;
                return *this;
        }

        mod_int &operator-=(mod_int const &b) {
                x -= b.x;
                if (x < 0) x += m;
                return *this;
        }
        mod_int &operator*=(mod_int const &b) {
                x = (ll)x * b.x % m;
                return *this;
        }

        friend mod_int mpow(mod_int a, ll e) {
                mod_int res = 1;
                while (e) {
                        if (e & 1) res *= a;
                        a *= a;
                        e >>= 1;
                }
                return res;
        }
        friend mod_int inverse(mod_int a) { return mpow(a, m - 2); }

        mod_int &operator/=(mod_int const &b) { return *this *= inverse(b); }
        friend mod_int operator+(mod_int a, mod_int const b) { return a += b; }
        mod_int operator++(int) { return this->x = (this->x + 1) % m; }
        mod_int operator++() { return this->x = (this->x + 1) % m; }
        friend mod_int operator-(mod_int a, mod_int const b) { return a -= b; }
        friend mod_int operator-(mod_int const a) { return 0 - a; }
        mod_int operator--(int) { return this->x = (this->x - 1 + m) % m; }

        mod_int operator--() { return this->x = (this->x - 1 + m) % m; }
        friend mod_int operator*(mod_int a, mod_int const b) { return a *= b; }
        friend mod_int operator/(mod_int a, mod_int const b) { return a /= b; }
        friend ostream &operator<<(ostream &os, mod_int const &a) {
                return os << a.x;
        }
        friend bool operator==(mod_int const &a, mod_int const &b) {
                return a.x == b.x;
        }
        friend bool operator!=(mod_int const &a, mod_int const &b) {
                return a.x != b.x;
        }
};

using mint = mod_int<1'000'000'000 + 7>;

template <typename T>
struct Matrix {
        int n, m;
        valarray<valarray<T>> v;

        Matrix(int _n, int _m, int id = 0)
                : n(_n), m(_m), v(valarray<T>(m), n) {
                if (id) {
                        rep(i, 0, n) v[i][i] = 1;
                }
        }

        valarray<T> &operator[](int x) { return v[x]; }

        Matrix transpose() {
                Matrix newv(m, n);

                rep(i, 0, n) rep(j, 0, m) newv[j][i] = (*this)[i][j];

                return newv;
        }

        Matrix operator+(Matrix &b) {
                Matrix ret(*this);
                return ret.v += b.v;
        }

        Matrix &operator+=(Matrix &b) { return v += b.v; }

        Matrix operator*(Matrix b) {
                Matrix ret(n, b.m);

                rep(i, 0, n) rep(j, 0, m) rep(k, 0, b.m)
                        ret[i][k] += v[i][j] * b.v[j][k];

                return ret;
        }

        Matrix &operator*=(Matrix b) { return *this = *this * b; }

        Matrix power(ll exp) {
                Matrix in = *this;
                Matrix ret(n, n, 1);

                while (exp) {
                        if (exp & 1) ret *= in;
                        in *= in;
                        exp >>= 1;
                }
                return ret;
        }

        /*
         * Alters current matrix.
         * Does gaussian elimination and puts matrix in
         * upper echelon form (possibly reduced).
         * Returns the determinant of the square matrix
         * with side equal to the number of rows of the
         * original matrix.
         */
        T gaussjordanize(int reduced = 0) {
                T det = T(1);

                int line = 0;
                rep(col, 0, m) {
                        int pivot = line;
                        while (pivot < n && v[pivot][col] == T(0)) pivot++;

                        if (pivot >= n) continue;

                        swap(v[line], v[pivot]);

                        if (line != pivot) det *= T(-1);

                        det *= v[line][line];

                        v[line] /= T(v[line][col]);

                        if (reduced) rep(i, 0, line) {
                                        v[i] -= T(v[i][col]) * v[line];
                                }

                        rep(i, line + 1, n) { v[i] -= T(v[i][col]) * v[line]; }

                        line++;
                }

                return det * (line == n);
        }

        /*
         * Needs to be called in a square matrix that
         * represents a system of linear equations. Returns {possible solution,
         * number of solutions (2 if infinite solutions)}
         */
        pair<vector<T>, int> solve_system(vector<T> results) {
                Matrix aux(n, m + 1);

                rep(i, 0, n) {
                        rep(j, 0, m) aux[i][j] = v[i][j];
                        aux[i][m] = results[i];
                }

                T det = aux.gaussjordanize(1);
                int ret = 1 + (det == T(0));

                int n = results.size();

                rrep(i, n - 1, 0 - 1) {
                        int pivot = 0;
                        while (pivot < n && aux[i][pivot] == T(0)) pivot++;

                        if (pivot == n) {
                                if (aux[i][m] != T(0)) ret = 0;
                        } else
                                swap(aux[i], aux[pivot]);
                }

                rrep(i, n - 1, 0 - 1) rep(j, i + 1, n)
                        aux[i][m] -= aux[i][j] * aux[j][m];

                rep(i, 0, n) results[i] = aux[i][m];

                rep(i, 0, n) rep(j, 0, m) v[i][j] = aux[i][j];

                return {results, ret};
        }

        /* Does not alter current matrix. Returns {inverse matrix, is curent
         * matrix invertable} */
        pair<Matrix<T>, bool> find_inverse() {
                int n = v.size();
                Matrix<T> aug(n, 2 * n);

                rep(i, 0, n) rep(j, 0, n) aug[i][j] = v[i][j];

                rep(i, 0, n) aug[i][n + i] = 1;

                T det = aug.gaussjordanize(1);

                Matrix<T> ret(n, n);
                rep(i, 0, n) ret[i] = valarray<T>(aug[i][slice(n, n, 1)]);

                return {ret, det != T(0)};
        }

        /* Returns rank of matrix. does not alter it. */
        int get_rank() const {
                if (m == 0) return 0;

                Matrix<T> aux(*this);

                aux.gaussjordanize();

                int resp = 0;

                rep(i, 0, n) resp += (aux[i] != valarray<T>(m)).sum();

                return resp;
        }
};

void run() {
        ll R, A, B;
        cin >> R >> A >> B;

        dbg(A, B);
        auto f = [&](ll x) {
                if (x >= R) return R;

                ll nx2 = x - (x * A) / B - ((x * A) % B != 0);

                assert(nx2 <= R);

                return nx2;
        };

        Matrix<mint> matrix_a(R + 1, R + 1);

        auto inv_r = inverse(mint(R));

        rep(i, 0, R) {
                rep(j, 1, R + 1) { matrix_a[i][f(i + j)] -= inv_r; }
                matrix_a[i][i] += 1;
        }

        vector<mint> matrix_b(R + 1, 1);
        matrix_b[R] = 0;

        auto [sol, qtd] = matrix_a.solve_system(matrix_b);

        cout << sol[0].x << endl;
}

/*8<
 * Combinatorics, linear algebra
>8*/
