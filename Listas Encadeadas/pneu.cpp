#include <stdio.h>
#include <iostream>

struct pneu
{
    int num;
    struct pneu * prox;
};

typedef struct pneu * pnPtr;

pnPtr topo = NULL;

void inserir()
{
    pnPtr p = new pneu;
    int valor;

    printf("Numero do pneu: ");
    scanf("%d", &valor);

    p->num = valor;
    p->prox = topo;
    topo = p;
}

void remover()
{
    
    pnPtr p;
    while(topo != NULL)
    {
        p = topo;
        topo = p->prox;
        delete (p);
    }
}

void listar()
{
    if(topo != NULL)
    {
        pnPtr p = topo;

        while(p != NULL)
        {
            printf("%3d\n", p->num);
            p = p->prox;
        }
    }
    else
    {
        printf("Lista vazia!\n");
    }
}


int main()
{
    for(int i = 0; i < 3; i++)
    {
        inserir();
    }
    listar();
    remover();
    listar();
    return 0;
}

