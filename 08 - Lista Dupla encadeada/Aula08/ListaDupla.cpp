#include <iostream>
#include <cstdlib>
#include "ListaDupla.h"

using namespace std;

ListaDupla::ListaDupla()
{
    cout << "Criando uma ListaDupla" << endl;
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaDupla::~ListaDupla()
{
    cout<< endl<< endl << "Destruindo ListaDupla" << endl;
    NoDuplo *p = primeiro;
    while(p != NULL)
    {
        NoDuplo *t = p->getProx();
        delete p;
        p = t;
    }
}

bool ListaDupla::busca(int val)
{
    NoDuplo *p;
    for(p = primeiro; p != NULL; p = p->getProx())
        if(p->getInfo() == val)
            return true;
    return false;
}

int ListaDupla::get(int k)
{
    NoDuplo *p = primeiro;
    for(int i = 0; i < k; i++)
    {
        if(p == NULL)
            break;
        p = p->getProx();
    }
    if(p == NULL)
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
    else
        return p->getInfo();
}

void ListaDupla::set(int k, int val)
{
    NoDuplo *p = primeiro;
    for(int i = 0; i < k; i++)
    {
        if(p == NULL)
            break;
        p = p->getProx();
    }
    if(p == NULL)
        cout << "ERRO: Indice invalido!" << endl;
    else
        p->setInfo(val);
}

void ListaDupla::insereInicio(int val)
{
	NoDuplo *p = new NoDuplo();
	p->setInfo(val);
	p->setProx(primeiro);
	p->setAnt(NULL);

	if(n == 0) ultimo = p;
	else primeiro->setAnt(p);

	primeiro = p;
	n = n + 1;
}

void ListaDupla::removeInicio()
{
	NoDuplo *p;
	if(primeiro != NULL)
	{
		p = primeiro;
		primeiro = p->getProx();
		delete p;
		n = n - 1;

		if(n == 0) 	ultimo = NULL;
		else primeiro->setAnt(NULL);
	}
	else
        cout << "ERRO: lista vazia" << endl;
}

void ListaDupla::insereFinal(int val)
{
    NoDuplo *p= new NoDuplo();
    // settagem
    p->setInfo(val);
    p->setProx(NULL);
    p->setAnt(ultimo);

    if(n==0)
    {
        primeiro =p;
    }
    else
        ultimo->setProx(p);


    ultimo = p;
    n++;
}

void ListaDupla::removeFinal()
{

    NoDuplo *p;

    if(primeiro != NULL)
    {
        p = ultimo;
        ultimo= p->getAnt();
        delete p;
        n--;

        if(n ==0) // se apos remover a lista ficar vazia
            primeiro == NULL; // o primeiro tbm vai ser nulo
        else // se a lista n tiver vazia
            ultimo ->setProx(NULL);
    }
    else
        cout << "ERRO: lista vazia";

}

void ListaDupla::imprime()
{
    NoDuplo *p;
    cout << "lista :";
    for(p= primeiro; p != NULL; p=p->getProx())
    {
        cout << p->getInfo()<< ", ";
    }
    cout << endl;
}

void ListaDupla::imprimeReverso()
{
    NoDuplo *p;
    cout << "lista Reversa: ";
    for(p= ultimo; p != NULL; p=p->getAnt())
    {
        cout << p->getInfo()<< ", ";
    }
    cout << endl;
}

ListaDupla* ListaDupla::concatena(ListaDupla *l2)
{


}

ListaDupla* ListaDupla::partir(int x)
{


}

void ListaDupla::removeOcorrencias(int val)
{
    NoDuplo *p;
    NoDuplo *aux;

    NoDuplo *ant;

    for(p= primeiro; p != NULL; p=p->getProx())
    {

        if(p->getInfo() == val)
        {
            if( p == primeiro) // a ocorrencia for a primeira
            {
                primeiro = p->getProx();
                primeiro = p;
                delete p;
            }


        }
        ant->getInfo();
    }
}

ListaDupla* ListaDupla::criaListaMenorMaior()
{
    ListaDupla *lista = new ListaDupla();
    NoDuplo *menor = primeiro;
    NoDuplo *maior = primeiro;


    for(NoDuplo *p = primeiro; p!= NULL; p=p->getProx())
    {
        if(p->getInfo() < menor->getInfo() )
            menor=p;
        if(p->getInfo() > maior->getInfo() )
            maior=p;
    }// achando os valores maior e menor

    removeOcorrencias(menor->getInfo() );
    removeOcorrencias(maior->getInfo() );



 /* !percorrer lista
    !salvar o maior e menor valor
    remover no
    !colocar no na nova lista
    !retornar lista

    */


    // adicionando na nova lista
    lista->insereInicio( menor->getInfo() );
    lista->insereFinal(maior->getInfo() );

    return lista;
}

void ListaDupla::removeDepoisMaior()
{
    // no apos o Maior valor
    NoDuplo *p;
    NoDuplo *maior;
    NoDuplo *aux;

    maior = primeiro;
    for(p=primeiro; p!= NULL; p=p->getProx())
    {
        if(p->getInfo() > maior->getInfo() )
            maior =p;
    } // achar o maior

    p = maior->getProx(); // usando P de auxiliar

    // maior == ao maior valor
    // p == ao proximo do MAIOR


    maior->setProx(p->getProx());
    aux =p->getProx();
    aux->setAnt(maior);

    delete p;
}

























