#include <iostream>
#include <vector>

using namespace std;


void gerarSubgrafos(int numeroVertices) {
    int totalVertices = numeroVertices;
    int totalArestas = (numeroVertices * (numeroVertices - 1)) / 2;

    // total de subgrafos = 2^(número de vértices + número de arestas)
    int totalSubgrafos = 1 << (totalVertices + totalArestas);

    cout << "Total de subgrafos: " << totalSubgrafos << endl;

    for (int subgrafoAtual = 0; subgrafoAtual < totalSubgrafos; ++subgrafoAtual) {
        cout << "Subgrafo " << subgrafoAtual + 1 << ": { ";
        
        // subgrafo com os vértices e arestas correspondentes ao número binário
        for (int posicaoAtual = 0; posicaoAtual < totalVertices + totalArestas; ++posicaoAtual) {
            if (subgrafoAtual & (1 << posicaoAtual)) {
                if (posicaoAtual < totalVertices) {
                    // posicaoAtual faz parte do subgrafo
                    cout << "v" << posicaoAtual + 1 << " ";
                } else {
                    // aresta correspondente faz parte do subgrafo
                    int indiceAresta = posicaoAtual - totalVertices;
                    int verticeOrigem = indiceAresta / (numeroVertices - 1) + 1;
                    int verticeDestino = indiceAresta % (numeroVertices - 1) + 2;
                    if (verticeDestino <= numeroVertices && verticeOrigem < verticeDestino) {
                        cout << "(v" << verticeOrigem << ", v" << verticeDestino << ") ";
                    }
                }
            }
        }
        cout << "}" << endl;
    }
}

int main() {
    int numeroVertices;
    
    cout << "Informe o número de vértices: ";
    cin >> numeroVertices;

    gerarSubgrafos(numeroVertices);

    return 0;
}
