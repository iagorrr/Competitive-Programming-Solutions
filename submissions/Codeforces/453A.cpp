/*
 * Tem m^n possibilidades
 *
 *  quantas dessas vezes o valor vai ser 1
 *      somente um caso que é quando todos são 1
 *  quantas dessas vezes o valor vai ser 2
 *      2^(n-1) menos todos os casos em que o maior valor é 1
 *      fixa um deles para ser um número 2, e os demais tem 2^(n-1)
 *      possibilidades
 *      ...
 *  quantas dessas vezes o valor vai ser m
 *
 *
 *
 *  essa bomba estora muito fácil
 *      da pra fazer fast pow dividindo tudo ?
 *
 *  melhor uma dpzinha ?
 *
 * para uma tentativa o EV é (1 + 2 + 3 + ... + m) / m
 *
 * m * (m+1)
 *   2
 *
 * (m + 1) /2
 *
 * daria para fazer com o binom aqui ?
 *
 *
 *
 * dp:
 *  dp(1) = (m+1)/2
 *  dp(2) = dp(1) +
 *      ve a probabilidade de ser maior e pega a soma dos maires
 *      ve a probabilidade de ser menor e pega o do anterior ?
 * */
#include <bits/stdc++.h>
using namespace std;

using ld = long double;
using ll = long long;

ll m, n;
ld pw(ld a, ll b) {
  if (b == 0)
    return 1;
  ld a2 = pw(a, b >> 1);

  return a2 * a2 * ((b & 1) ? a : 1);
}

ld p(ld i) { return pw(i / m, n) - pw((i - 1) / m, n); }

signed main() {
  ios_base::sync_with_stdio(!cin.tie(0));
  cin >> m >> n;

  ld s = 0;

  for (ll i = 1; i <= m; i++) {
    s += i * p(i);
  }

  cout << fixed << setprecision(10) << s << endl;
}

// AC, probabilities
