#include <iostream>
#include <stdio.h>
#define LIMITE 3
struct conteiner
{
    int codigo;
    struct conteiner * prox;
};

typedef struct conteiner * conteinerPtr;

conteinerPtr topo = NULL;

int conteiners = 0;

void adicionar()
{
    if(conteiners < LIMITE)
    {
        conteinerPtr p = new conteiner;
        int cod;

        printf("Insira o codigo do conteiner: ");
        scanf("%d", &cod);

        p->codigo = cod;

        p->prox = topo;
        topo = p;
        conteiners++;
    }
    else
    {
        printf("Limite maximo atingido\n");
    }

}

void remover()
{
    conteinerPtr p = topo;

    if(topo != NULL)
    {
        printf("Conteiner Retirado: %d\n", p->codigo);
        topo = p->prox;
        delete(p);
    }
    else
    {
        printf("Não há conteiners para retirar.\n");
    }
}

void listar()
{
    if(topo != NULL)
    {
        conteinerPtr p = topo;

        while(p != NULL)
        {
            printf("%3d\n", p->codigo);
            p = p->prox;
        }
    }
    else
    {
        printf("Lista vazia!\n");
    }
}



int main(void)
{
    char continuar = 'y';
    int op;
    while(continuar != 'n')
    {
        printf("----------------\n");
        printf("[1] adicionar\n");
        printf("[2] remover\n");
        printf("[3] sair\n");
        printf("----------------\n");
        listar();
        printf("----------------\n");
        printf("-> ");
        scanf("%d", &op);
        switch(op)
        {
            case 1:
                adicionar();
                break;
            case 2:
                remover();
                break;
            case 3:
                continuar = 'n';
        }
    }

    return 0;
}