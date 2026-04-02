/*

12345678910111213141516171819




021
*/

/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define fastio                                                                 \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#define all(j) j.begin(), j.end()
#define rall(j) j.rbegin(), j.rend()
#define len(j) (int)j.size()
#define rep(i, a, b)                                                           \
  for (common_type_t<decltype(a), decltype(b)> i = (a); i < (b); i++)
#define rrep(i, a, b)                                                          \
  for (common_type_t<decltype(a), decltype(b)> i = (a); i > (b); i--)
#define repn(i, b) for (auto i = 0; i < (b); i++)
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) for (auto &xi : ranges::views::reverse(xs))
#define loop while (1)
using ll = long long;
#define endl '\n'
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define ef emplace_back
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

#define TT template <typename T>
#define TTU template <typename T, typename U>

TTU using umap = unordered_map<T, U>;
TT using pqmn = priority_queue<T, vector<T>, greater<T>>;
TT using pqmx = priority_queue<T, vector<T>>;

TTU inline bool chmax(T &a, U const &b) { return (a < b ? a = b, 1 : 0); }
TTU inline bool chmin(T &a, U const &b) { return (a > b ? a = b, 1 : 0); }

// read vector
// TODO: abstract this to any container.
TT std::istream &operator>>(std::istream &is, std::vector<T> &vec) {
  for (auto &element : vec) {
    is >> element;
  }
  return is;
}

// print vector
// TODO: abstract this to any container.
TT ostream &operator<<(ostream &os, vector<T> &xs) {
  rep(i, os.iword(0), xs.size()) os << xs[i] << (i == xs.size() ? "" : " ");
  os.iword(0) = 0;
  return os;
}

// print multiset
// TODO: abstract this to any container.
TT ostream &operator<<(ostream &os, multiset<T> &xs) {
  for (auto it = xs.begin(); it != xs.end(); it++)
    os << *it << (next(it) == end(xs) ? "" : " ");
  return os;
}

// sum a vector, using the default constructor as initial value
// TODO: abstract this to any container.
TT T sumList(vector<T> &xs) { return accumulate(all(xs), T()); }

/*
 * verify if a `predicate` is valid for
 * values in range [l, r]
 *
 * TODO: put a type in predicate ??
 * */
// bool all_of_in_range(T l, T r, auto predicate) {
//     return ranges::all_of(views::iota(l, r + 1),
//                           [&](T v) { return predicate(v); });
// }

// checks if a  value v is the interval [l, r]
TT bool inline between(T v, T l, T r) { return clamp(v, l, r) == v; }

/*8<============~ END TEMPLATE ~============}>8*/
void __init();
void __run();
void __pre_run();

int32_t main() {
#ifndef LOCAL
  fastio;
#endif
  __init();

  int T = 1;

  cin >> T;

  rep(t, 0, T) {
    dbg(t);
    __pre_run();
    __run();
  }
}

/*
 *
 *
 *
 *
 *
 * */

const ll maxd = 20;
vll totalSumByLenAcc(maxd);

vll totCharsByLen(maxd);
vll totCharsByLenAcc(maxd);

vll totValuesByLen(maxd);
vll totValuesByLenAcc(maxd);
vll p10s(1, 1);
void __init() {

  totValuesByLen[1] = 9;
  rep(i, 2, maxd) totValuesByLen[i] = totValuesByLen[i - 1] * 10;
  partial_sum(all(totValuesByLen), begin(totValuesByLenAcc));

  totalSumByLenAcc[1] = 45;
  ll p10 = 10;
  rep(i, 2ll, maxd) {
    totalSumByLenAcc[i] = totalSumByLenAcc[i - 1];
    p10s.eb(p10);

    rep(d, 1, 9 + 1) {
      totalSumByLenAcc[i] += d * p10;
      totalSumByLenAcc[i] += totalSumByLenAcc[i - 1];
    }

    p10 *= 10ll;
  }

  totCharsByLen[1] = 9;
  p10 = 1;
  rep(i, 2, maxd) { totCharsByLen[i] = totValuesByLen[i] * i; }
  partial_sum(all(totCharsByLen), begin(totCharsByLenAcc));

  // dbg(totCharsByLen);
  // dbg(totCharsByLenAcc);
  //
  // dbg(totValuesByLen);
  // dbg(totValuesByLenAcc);
  //
  // dbg(totalSumByLenAcc);
}

void __pre_run() {}

vll getDigits(ll v) {
  vll ret;

  while (v) {
    ret.eb(v % 10);
    v /= 10ll;
  }
  reverse(all(ret));
  return ret;
}

ll getValue(vll &xs, int i) {
  if (len(xs) <= i)
    return 1;
  ll ret = 0;

  for (; i < len(xs); i++) {
    ret *= 10ll;
    ret += xs[i];
  }

  return ret;
}

void __run() {
  ll K;
  cin >> K;

  ll curK = 0;
  ll curLen = 0;
  ll ans = 0;
  for (int l = 1; l < maxd; l++) {
    if (totCharsByLenAcc[l] <= K) {
      ans = totalSumByLenAcc[l];
      curK = totCharsByLenAcc[l];
      curLen = l;
    } else
      break;
  }
  dbg(ans, curLen, curK);

  // how many whole integers i still have ?
  curLen++;
  ll totalDigitsLeft = K - curK;
  ll totalCompleteIntegersLeft = totalDigitsLeft / curLen;
  ll lastCompleteNumber = p10s[curLen - 1] + totalCompleteIntegersLeft - 1;

  dbg(totalCompleteIntegersLeft);

  ans += [&] {
    if (!totalCompleteIntegersLeft)
      return 0ll;

    ll ret = 0;
    vll digits = getDigits(lastCompleteNumber);
    ll pref_sum = 0;

    repn(i, len(digits)) {
      ll di = digits[i];
      ll digitsLeft = len(digits) - 1 - i;

      rep(j, i == 0, di) {
        ret += (pref_sum + j) * p10s[digitsLeft];

        if (digitsLeft > 0) {
          ret += 45ll * digitsLeft * p10s[digitsLeft - 1];
        }
      }

      pref_sum += di;
    }

    ret += pref_sum;

    return ret;
  }();

  ans += [&] {
    return 0ll;
    if (!totalCompleteIntegersLeft)
      return 0ll;
    ll ret = 0;
    vll digits = getDigits(lastCompleteNumber);
    repn(i, len(digits)) {
      ll di = digits[i];
      ll digitsLeft = len(digits) - 1 - i;

      // o ultimo digito é desconsiderado
      rep(j, 1, di) {
        ret += j * p10s[digitsLeft] + totalSumByLenAcc[len(digits) - i - 1];
      }

      // quantos que o ultimo digito vai ter na verdade
      ll aaaaa = i + 1 == len(digits) ? 1 : getValue(digits, i + 1) + 1;
      ret += (di * aaaaa);
    }
    return ret;
  }();

  // integer that will have only a prefix of it !
  ans += [&] {
    if ((K - curK) % curLen == 0)
      return 0ll;

    ll ret = 0;

    ll x = lastCompleteNumber + 1;
    vll digits = getDigits(x);
    repn(i, (K - curK) % curLen) { ret += digits[i]; }

    return ret;
  }();

  cout << ans << endl;
}

/*8<
>8*/
