#include <iostream>
#include <stdexcept>

using namespace std;

struct Node {
    int dado;
    Node *proximo;
};

class Pilha {
private:
    Node *topo;

public:
    Pilha() : topo(nullptr) {}

    ~Pilha() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() const {
        return topo == nullptr;
    }

    void push(int valor) {
        Node *novo = new Node;
        novo->dado = valor;
        novo->proximo = topo;
        topo = novo;
    }

    int pop() {
        if (isEmpty()) {
            throw runtime_error("Pilha vazia!");
        }
        Node *temp = topo;
        int valor = topo->dado;
        topo = topo->proximo;
        delete temp;
        return valor;
    }

    int peek() const {
        if (isEmpty()) {
            throw runtime_error("Pilha vazia!");
        }
        return topo->dado;
    }

    void imprimir() const {
        Node *p = topo;
        while (p != nullptr) {
            cout << p->dado << " ";
            p = p->proximo;
        }
        cout << endl;
    }
};

int main() {
    Pilha pilha;

    pilha.push(10);
    pilha.push(20);
    pilha.push(30);

    cout << "Elementos na pilha: ";
    pilha.imprimir();

    cout << "Topo da pilha: " << pilha.peek() << endl;

    cout << "Removendo elemento do topo: " << pilha.pop() << endl;

    cout << "Elementos na pilha após remoção: ";
    pilha.imprimir();

    return 0;
}
