#include <stdio.h>
#include <iostream>
struct _no
{
    int info;
    struct _no * prox;
};
typedef struct _no * noPtr;

noPtr topo = NULL; 

void imprimirMenu()
{
    printf("[1] push\n");
    printf("[2] pop\n");
}

int listaVazia()
{
    if(topo == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void listar()
{
    noPtr p = topo;

    puts("-------------------------------");
    if(!listaVazia())
    {
        while(p != NULL)
        {
            
            printf("%3d", p->info);

            p = p->prox;
        }
        puts("");

    }
    else
    {
        printf("A lista esta vazia\n");
    }
    puts("-------------------------------");
}

void push()
{
    noPtr p;
    int valor;

    p = new _no;

    printf("Digite o valor do elemento: ");
    scanf("%d", &valor);

    p->info = valor;
    p-> prox = topo;

    topo = p;
}

void pop()
{
    noPtr p = topo;

    if(!listaVazia())
    {
        topo = topo->prox;
        delete(p);
        printf("O elemento foi removido da lista\n");
    }
    else
    {
        printf("Lista vazia!\n");
    }
}

int main(void)
{
    int op;

    imprimirMenu();
    listar();
    printf("Digite sua escolha: ");
    scanf("%d", &op);

    while(op != 0)
    {
        switch(op)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
        }
        listar();
        imprimirMenu();
        printf("Digite sua escolha: ");
        scanf("%d", &op);
    }

    return 0;
}