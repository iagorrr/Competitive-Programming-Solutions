/*
- acho que nunca vale a pena fazer mais de uma op em um número
- vale sim:
    - um cara muito caro e outro muito barato
    a gente tora o barato até ele ter gcd != 1

- fzd a op em um só cara seria de boas...
    - vero quao distante está de um dos primos dos demais valores...

- se quiser fazer a op em dois caras vai ser sempre dois impares ?
    - 1 em cada, ambos pares vapo

- tem sempre o caso de ser zero mesmo...

- seg + bb pra saber o quanto preciso incrementar pra chegar em
um valor que é multiplo dos demais primos
mt complexo, mt corner case...
- daria pra tacar tudo em um set e fazer um lower bound tbm...
melhor
- tem que garantir que o valor achado já não era achado por mim...
- se processar em ordem e ver o i-ésimo, quando a gente estiver inserindo a
gente ve para os que já foram os mais pertos...
    - mas aí o custo impacta o mais perto pode ser mais caro...




1. É zero, tem alguém com um primo em comum
    - ok

2. É Bi, onde Ai é impar, e existe pelo menos um par
    - Ok, menor custo de um impar

2. É Bi + Bj, onde Ai e Aj é impar
    - ok, dois impares com menor custo

3. É Bi * Ki
    - Não da pra brutar todos os primos n ?
    ver pra cada valor o custo de ele ter tal primo na
    fatorcao dele desde que ele já n tenha...
        - posso ter 10^4 primos, vai ficar quadrático
        consigo fazer 10 casos desses, fica em 10 segundos...
    - da pra voltar com a idéia do histograma + set pra pegar o mais próximo
    - tle se todos os casos tiverm o 2 por exemplo..

4. caso onde precise fazer 2 em 1, e 1 no outro, acho q tem
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxn = 2'00'000 + 2;
int hist[maxn + 1];
vector<int> facts[maxn + 1];

void solve() {
    int n;
    cin >> n;

    vector<pair<ll, ll>> xs(n);
    for (auto &[bi, ai] : xs) cin >> ai;
    for (auto &[bi, ai] : xs) cin >> bi;
    sort(xs.begin(), xs.end());

    ll ans = LLONG_MAX;

    unordered_map<int, int> mp;
    // ans = 0
    {
        for (auto &[bi, ai] : xs) {
            for (auto pi : facts[ai]) {
                mp[pi]++;
            }
        }
        for (auto &[bi, ai] : xs) {
            for (auto pi : facts[ai]) {
                mp[pi]--;
            }

            for (auto pi : facts[ai]) {
                if (mp[pi]) {
                    ans = 0;
                }
            }

            for (auto pi : facts[ai]) {
                mp[pi]++;
            }
        }
    }

    // ans = bi
    {
        for (auto &[bi, ai] : xs) {
            for (auto pi : facts[ai + 1]) {
                if (mp[pi]) {
                    ans = min(ans, bi);
                }
            }
        }
    }

    // the two odds
    ans = min(ans, xs[0].first + xs[1].first);

    // more than one in a single one
    {
        for (auto pi : facts[xs[0].second]) mp[pi]--;

        ll ai = xs.front().second;
        for (auto [p, q] : mp) {
            if (q == 0) continue;
            ll k = p - (ai % p);
            if (k == p) k = 0;
            ans = min(ans, k * xs.front().first);
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(!cin.tie(0));

    for (int i = 2; i <= maxn; i++) {
        if (facts[i].size()) continue;
        for (int j = i; j <= maxn; j += i) {
            facts[j].push_back(i);
        }
    }

    int t;
    cin >> t;
    while (t--) solve();
}
