#include <iostream>
#include <stdio.h>
#include <stdlib.h>
struct peca
{
    int num;
    struct peca * prox;
};

typedef struct peca * pecaPtr;

pecaPtr top = NULL;
pecaPtr bottom = NULL;

void desmontar()
{
    pecaPtr p = new peca;
    int numero;

    printf("Digite o numero da peca: ");
    scanf("%d", &numero);

    p->num = numero;

    if(top == NULL)
    {
        p->prox = top;
        top = p;
        bottom = p;
    }
    else
    {
        p->prox = bottom->prox;
        bottom->prox = p;
        bottom = p;
    }
}

void montar()
{
    if(top == NULL)
    {
        printf("Nao ha pecas para montar\n");
    }
    else
    {
        pecaPtr p = top;
        top = p->prox;
        delete(p);
    }
}

void listar()
{
    if(top != NULL)
    {
        pecaPtr p = top;

        while(p != NULL)
        {
            printf("%3d", p->num);
            p = p->prox;
        }
        puts("");
    }
    else
    {
        printf("Lista Vazia!\n");
    }
}


int main(void)
{

    for(int i = 0; i < 1; i++)
    {
        listar();
        desmontar();
    }

    listar();
    montar();
    montar();
    listar();

    return 0;
}