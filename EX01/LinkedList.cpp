#include <iostream>
#include <string>

using namespace std;

struct Aluno {
    int matricula;
    string nome;
    Aluno *proximo;
};

void adicionarAluno(Aluno *&inicio, int matricula, const string &nome) {
    Aluno *novo = new Aluno;
    novo->matricula = matricula;
    novo->nome = nome;
    novo->proximo = nullptr;

    if (inicio == nullptr) {
        inicio = novo;
    } else {
        Aluno *p = inicio;
        while (p->proximo != nullptr) {
            p = p->proximo;
        }
        p->proximo = novo;
    }
}

bool encontrarAluno(Aluno *inicio, int matricula) {
    Aluno *p = inicio;
    while (p != nullptr) {
        if (p->matricula == matricula) {
            return true;
        }
        p = p->proximo;
    }
    return false;
}


bool removerAluno(Aluno *&inicio, int matricula) {
    if (inicio == nullptr) return false;

    if (inicio->matricula == matricula) {
        Aluno *temp = inicio;
        inicio = inicio->proximo;
        delete temp;
        return true;
    } 

    Aluno *p = inicio;
    while (p->proximo != nullptr && p->proximo->matricula != matricula) {
        p = p->proximo;
    }

    if (p->proximo == nullptr) return false;

    Aluno *temp = p->proximo;
    p->proximo = p->proximo->proximo;
    delete temp;
    return true;
}


void imprimirLista(Aluno *inicio) {
    Aluno *p = inicio;
    while (p != nullptr) {
        cout << p->matricula << " / " << p->nome << endl;
        p = p->proximo;
    }
}

int main() {
    Aluno *inicio = nullptr;

    adicionarAluno(inicio, 100, "Yan");
    adicionarAluno(inicio, 101, "Ana");
    adicionarAluno(inicio, 102, "Lucas");
    adicionarAluno(inicio, 103, "João");
    adicionarAluno(inicio, 104, "Maria");

    cout << "Lista de alunos:" << endl;
    imprimirLista(inicio);

    int matriculaBusca = 104;
    if (encontrarAluno(inicio, matriculaBusca)) {
        cout << "Aluno com matricula " << matriculaBusca << " encontrado." << endl;
    } else {
        cout << "Aluno com matricula " << matriculaBusca << " nao encontrado." << endl;
    }

    int matriculaRemover = 104;
    if (removerAluno(inicio, matriculaRemover)) {
        cout << "Aluno com matricula " << matriculaRemover << " removido." << endl;
    } else {
        cout << "Aluno com matricula " << matriculaRemover << " nao encontrado para remocao." << endl;
    }

    cout << "Lista de alunos apos remocao:" << endl;
    imprimirLista(inicio);

    return 0;
}
