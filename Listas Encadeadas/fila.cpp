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
    printf("[1] enqueue\n");
    printf("[2] dequeue\n");
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

void enqueue()
{
    noPtr aux, p = new _no;

    printf("Digite o valor do elemento: ");
    scanf("%d", &p->info);

    p->prox = NULL;

    if(listaVazia())
    {
        topo = p;
    }
    else
    {
        aux = topo;
        
        while(aux->prox != NULL)
        {
            aux = aux -> prox;
        }

        aux->prox = p;
    }
}

void dequeue()
{
    noPtr p;

    if(listaVazia())
    {
        printf("Fila vazia\n");
    }
    else
    {
        p = topo;

        topo = p->prox;
        delete p;
        printf("O elemento foi retirado da fila\n");
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
                enqueue();
                break;
            case 2:
                dequeue();
                break;
        }
        listar();
        imprimirMenu();
        printf("Digite sua escolha: ");
        scanf("%d", &op);
    }

    return 0;
}