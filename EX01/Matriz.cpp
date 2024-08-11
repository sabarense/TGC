#include <iostream>
#include <vector>

using namespace std;

class Matriz {
private:
    vector<vector<int>> dados;
    int linhas;
    int colunas;

public:
    Matriz(int l, int c) : linhas(l), colunas(c) {
        dados.resize(linhas, vector<int>(colunas, 0));
    }

    void setValor(int l, int c, int valor) {
        if (l >= 0 && l < linhas && c >= 0 && c < colunas) {
            dados[l][c] = valor;
        } else {
            cout << "Índice fora dos limites!" << endl;
        }
    }

    int getValor(int l, int c) const {
        if (l >= 0 && l < linhas && c >= 0 && c < colunas) {
            return dados[l][c];
        } else {
            cout << "Índice fora dos limites!" << endl;
            return -1;
        }
    }

    void removerValor(int l, int c) {
        if (l >= 0 && l < linhas && c >= 0 && c < colunas) {
            dados[l][c] = 0; // Define o valor padrão como 0
        } else {
            cout << "Índice fora dos limites!" << endl;
        }
    }

    void imprimir() const {
        for (int i = 0; i < linhas; ++i) {
            for (int j = 0; j < colunas; ++j) {
                cout << dados[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matriz matriz(3, 3);

    matriz.setValor(0, 0, 1);
    matriz.setValor(0, 1, 2);
    matriz.setValor(0, 2, 3);
    matriz.setValor(1, 0, 4);
    matriz.setValor(1, 1, 5);
    matriz.setValor(1, 2, 6);
    matriz.setValor(2, 0, 7);
    matriz.setValor(2, 1, 8);
    matriz.setValor(2, 2, 9);

    cout << "Matriz antes de remover:" << endl;
    matriz.imprimir();

    matriz.removerValor(1, 1);

    cout << "Matriz depois de remover o valor na posição (1, 1):" << endl;
    matriz.imprimir();

    return 0;
}
