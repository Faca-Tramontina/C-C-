#include <iostream>
#include <stdio.h>

struct no
{
    int info;
    struct no * prox;
};

typedef struct no * noPtr;

void listar(noPtr top, int qnt)
{
    if(qnt == 0)
    {
        printf("Lista vazia!\n");
    }
    else
    {
        for(int i = 0; i < qnt; i++)
        {
            printf("%3d", top->info);
            top = top->prox;
        }
        puts("");
    }
}


void inserir(noPtr * top, noPtr * bottom, int * qnt)
{
    noPtr p = new no;
    int valor;

    printf("Digite o elemento a ser adicionado a lista: ");
    scanf("%d", &valor);

    p->info = valor;

    if(*qnt == 0)
    {
        *top = p;
        *bottom = p;
        p->prox = *top;

    }
    else
    {
        p->prox = *bottom;
        (*top)->prox = p;
        *bottom = p;
    }

    (*qnt)++;
}

void remover_elemento(noPtr *top, noPtr *bottom, int *qnt)
{
    if(*qnt > 0)
    {
        noPtr p = *top;
        noPtr ant = p;
        int i = 0;
        int elemento;

        printf("Digite o elemento a ser retirado: ");
        scanf("%d", &elemento);

        while(p->info != elemento &&  i < *qnt)
        {
            ant = p;
            p = p->prox;
            i++;
        }

        if(i != *qnt)
        {
            if(p == *top)
            {
                for(int j = 0; j < *qnt - 1; j++)
                {
                    ant = ant->prox;
                }

                ant->prox = *bottom;
                *top = ant;
            }
            else if(p == *bottom)
            {
                *bottom = (*bottom)->prox;
                ant->prox = *bottom;
            }
            else if(*qnt == 1)
            {
                *top = NULL;
                *bottom = NULL;
            }
            else
            {
                ant->prox = p->prox;
            }
            delete(p);
            (*qnt)--;
        }
        else
        {
            printf("Elemento nao encontrado: ");
        }
    }
}

void retirar(noPtr *top, noPtr* bottom, int * qnt)
{
    noPtr p = *bottom;

    if(*qnt > 0)
    {
        if(*qnt == 1)
        {
            *top = NULL;
            *bottom = NULL;
        }
        else
        {
            (*top)->prox = p->prox;
            *bottom = p->prox;
        }
        delete(p);
        (*qnt)--;
    }
    else
    {
        printf("lista vazia: nao tem itens para serem retirados\n");
    }
    
}

int main(void)
{
    int op;
    int continuar = 1;
    noPtr top = NULL;
    noPtr bottom = NULL;
    int qnt = 0;
    
    while(continuar != 0)
    {

        puts("[1] Inserir");
        puts("[2] Retirar");
        puts("[3] Sair");
        puts("-------------------------");
        listar(top, qnt);
        puts("-------------------------");

        printf("-> ");
        scanf("%d", &op);

        switch(op)
        {
            case 1: 
                inserir(&top, &bottom, &qnt);
                break;
            case 2:
                //retirar(&top, &bottom, &qnt);
                remover_elemento(&top, &bottom, &qnt);
                break;
        }
        printf("Continuar?: ");
        scanf("%d", &continuar);
    }
    return 0;
}