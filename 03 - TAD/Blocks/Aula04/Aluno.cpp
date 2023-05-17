#include "Aluno.h"

Aluno::Aluno(string n, string m)
{
    cout << "Criando aluno" << endl;
    nome = n;
    matricula = m;
}

Aluno::~Aluno()
{
    cout << "Destruindo objeto aluno" << endl;
}

// ----------------------------------------------------------------------------
// Exercicio 1
// ----------------------------------------------------------------------------

void Aluno::leNotas()
{
    // Implemente sua solucao aqui
}

double Aluno::calculaMedia()
{
    // Implemente sua solucao aqui
    return 0;
}

// ----------------------------------------------------------------------------

void Aluno::setNome(string novo)
{
    nome = novo;
}

string Aluno::getNome()
{
    return nome;
}

// ----------------------------------------------------------------------------
// Exercicio 2
// ----------------------------------------------------------------------------

// Implemente aqui a sua solucao


// ----------------------------------------------------------------------------
// Exercicio 3
// ----------------------------------------------------------------------------

// Implemente aqui sua solucao

