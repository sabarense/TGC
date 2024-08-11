#include <iostream>
#include <stdexcept>

using namespace std;

struct Node {
    int dado;
    Node *proximo;
};

class Fila {
private:
    Node *inicio;
    Node *fim;

public:
    Fila() : inicio(nullptr), fim(nullptr) {}

    ~Fila() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const {
        return inicio == nullptr;
    }

    void enqueue(int valor) {
        Node *novo = new Node;
        novo->dado = valor;
        novo->proximo = nullptr;
        if (fim != nullptr) {
            fim->proximo = novo;
        }
        fim = novo;
        if (inicio == nullptr) {
            inicio = novo;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            throw runtime_error("Fila vazia!");
        }
        Node *temp = inicio;
        int valor = inicio->dado;
        inicio = inicio->proximo;
        if (inicio == nullptr) {
            fim = nullptr;
        }
        delete temp;
        return valor;
    }

    int peek() const {
        if (isEmpty()) {
            throw runtime_error("Fila vazia!");
        }
        return inicio->dado;
    }

    void imprimir() const {
        Node *p = inicio;
        while (p != nullptr) {
            cout << p->dado << " ";
            p = p->proximo;
        }
        cout << endl;
    }
};

int main() {
    Fila fila;

    fila.enqueue(10);
    fila.enqueue(20);
    fila.enqueue(30);

    cout << "Elementos na fila: ";
    fila.imprimir();

    cout << "Início da fila: " << fila.peek() << endl;

    cout << "Removendo elemento do início: " << fila.dequeue() << endl;

    cout << "Elementos na fila após remoção: ";
    fila.imprimir();

    return 0;
}
