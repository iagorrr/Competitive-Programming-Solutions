#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> getEulerianCycleEdges(
    const vector<vector<pair<int, int>>>& adj) {
    const int n = adj.size();

    vector<char> edgeProcessed(n, 0);
    vector<tuple<int, int, int>> edgesDirection;
    vector<int> adjIdx(n, 0);

    for (int start_node = 0; start_node < n; start_node++) {
        if (adjIdx[start_node] == adj[start_node].size()) continue;

        vector<int> stack;
        stack.push_back(start_node);

        while (!stack.empty()) {
            int u = stack.back();

            if (adjIdx[u] < adj[u].size()) {
                auto [v, edgeIdx] = adj[u][adjIdx[u]];
                adjIdx[u]++;

                if (!edgeProcessed[edgeIdx]) {
                    edgeProcessed[edgeIdx] = 1;
                    edgesDirection.emplace_back(edgeIdx, u, v);

                    stack.push_back(v);
                }
            } else {
                stack.pop_back();
            }
        }
    }

    return edgesDirection;
}

void solve() {
    int n;
    cin >> n;
    vector<int> as(n);
    for (auto& ai : as) cin >> ai, ai--;
    vector<int> bs(n);
    for (auto& bi : bs) cin >> bi, bi--;

    {
        vector<int> hist(n);
        for (auto& ai : as) hist[ai]++;
        for (auto& bi : bs) hist[bi]++;
        for (auto& hi : hist) {
            if (hi & 1) {
                cout << -1 << '\n';
                return;
            }
        }
    }

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n; i++) {
        adj[as[i]].emplace_back(bs[i], i), adj[bs[i]].emplace_back(as[i], i);
    }

    auto edgesDirection = getEulerianCycleEdges(adj);

    vector<int> ans;
    for (auto& [idx, u, v] : edgesDirection) {
        if (as[idx] != u) ans.push_back(idx);
    }

    cout << ans.size() << '\n';
    for (auto& i : ans) cout << i + 1 << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(!cin.tie(0));
    int t;
    cin >> t;
    while (t--) solve();
}

/*
- Tem que ter todos os elementos de B e vice versa
- Sempre que pego um elemento estou dando um elemento tbm
- Dá pra transformar isso em two sat ?
- Tem cara de fluxo n ?
- O negócio vai até 1e6
- supondo que eu fiz op(i), lá na frente eu tenho que ter o ai no próprio
a ou o no bi pra gente conseguir pegar ele...
- se fosse um de cada era two sat fácil
- se fosse um fluxo safado cada posição i teria que ser um "célula" da
network, só pode entrar e sair 1 e dai dentro da célula eu escolho
se vou pegar o de cima ou o debaixo, isso resolve o role de uma op
- mas tenho que garantir que a quantidade de um certo valor que peguei
pra cima é igual ao que eu peguei em baixo
- da pra fazer só um bipartite n ?
- cada posicao é um nó e ela liga nas demais posicoes que tem o mesmo valor
- isso impoem que pra cada posicao eu tenho que ter ligar em outra pra impor que
eu sempre tenho a mesma quantidade de cada ladao
- mas acho que isso n impoem ter a mesma quantidade de cada lado
- é 5 segundos
- só liga i -> j, se a[i] = a[j] ?, daí pra cada um que eu tenho em a que é
copia vou ter que flipar um deles mas é falso pq posso deixar os dois e ser
resolver lá na frente e n fazer esse flip
- se eu garantir que para todo valor que eu pego em A eu pego um outro em B
- se eu tenho como fazer um set de operações pra atender as contraints
da pra fazer o complemento dela tbm.
- então tanto faz como vou fazer a primeira operação, no pior dos casos
é o complemento de uma outra resposta
- a resposta não é única
 *
 *
 *
 *


1. pra cada número eu tenho que ter qtd dele igual em cima
e em baixo

- o que dá pra fazer é se eu pego um número pra ir pra cima ele já escolhe
somente os outros nós que colocam uma cópia dele para baixo
- cada célula dessa tem as duas escolhas possíveis de cada índice
- tenho que garantir que vai os dois pra mesma célula ainda
- acho que fluxo tá muito torado de modelar aqui
- props:
        - se tenho duas célula iguais é meio whatever, uma oposto da outra e
foda-se



- se eles forem iguais continua sendo um rearranjo tbm ???

4
1 2 2 4
3 1 4 3


- se tenho um (Ai/Bj) eu só posso ligar em (Ai/X) ou (X/Ai)
no fim eu vou estar deixando de fazer o Bj, até um certo
momento ou eu ligo e vou, ou já inponho a outra areasta lá
- mas aí é mt caro tem que ter um jeito de ter poucas soluções
- é um grafo denso né ? se eu tiver todas as células meio que
iguais...
- restriction: se a quantidade de um valor quando bota tudo
pra cima for ímpar  fudeo ?
        - nem tanto se tiver um que tem os dois lados iguais tá safe
        - é meio que um dominó né
        - só tenho que decompor em ciclos fechadinhos
        - esse que é o mesmo em ai e bi é só descartar
        - no fim taca todo mundo pra cima, essa quantidade tem que ser par
        - ou da só pra somar tudo por que esses que são iguais não muda a
paridade
- é literalmente um dominó em que eu tenho que usar todas as pessas
e cada trilha precisa começar e terminar no mesmo valor
- e cada nó usa sempre duas arestas nem mais nem menos
-



- é só um apontar para o de baixo po
- se chega pelo 2 tem que sair pelo 1..., e ele aponta para todos os demais
índices que tem 1...
- e o que me impede de mandar tudo pro sink ?
por que tecnicamente o maxflow vai meio que tentar fazer o ma'ximo de ciclos
precisa meio que fazer sair por onde entrou... e somente
e se sai por onde entrou ele vai só entrar e sair foda-se
- tem que ter um nó representando o "to sink" desse nó de entrada e só sai por
ele aí é safe


- e o que impede de sair por um "out" qualquer ?

é só modelar po


lol é ciclo halmitonianolol

se era sempre um Ai -> Bi ou o Bi -> Ai quando a gente reverte

o grau de entrada de V significa a quantidade que ele aparece somada
de cima e de baixo, já vimos que isso tem que ser par


Se u -> v então u tá em cima e v tá em baixo
pra ter a mesma quantidade em tudo o grau de entrada do de cima tem que ser
igual ao grau de entrada do debaixo


todos os valores aparecem em quantidade pares
logo o grau de entrada dele é par tbm né
e o de sáida tbm ?

*/
