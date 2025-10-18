#include <stdio.h>
#include <iostream>
#include <string.h>

struct contato
{
    int numero;
    char nome[100];
    struct contato * prox;

};

typedef struct contato * ctPtr;

ctPtr top = NULL;
ctPtr bottom = NULL;

void adicionar()
{
    ctPtr p = new contato;
    int numero;
    char nome[100];

    printf("Numero do contato: ");
    scanf("%d", &numero);

    printf("Nome do contato: ");
    scanf(" %s", nome);

    p->numero = numero;
    strcpy(p->nome, nome);

    if(top == NULL)
    {
        p->prox = top;
        top = p;
        bottom = p;
    }
    else
    {
        ctPtr i = top;

        while(i != NULL && i->numero != numero)
        {
            i = i->prox;
        }

        if(i != NULL)
        {
            printf("Este contato ja existe");
        }
        else
        {

            ctPtr aux = top;
            ctPtr ant;

            while(aux != NULL && strcmp(p->nome, aux->nome) > 0)
            {
                ant = aux;
                aux = aux->prox;
            }

            if(aux == top)
            {
                p->prox = top->prox;
                top = p;
            }
            else if(aux == NULL)
            {
                p->prox = ant->prox;
                ant->prox = p;
            }
            else
            {
                p->prox = aux;
                ant->prox = p;
            }
        }
    }
}

void listar()
{
    if(top == NULL)
    {
        printf("Lista vazia!\n");
    }
    else
    {
        ctPtr p = top;
        int i = 0;
        while(p != NULL)
        {
            printf("Contato: %d\n", i);
            printf("Nome: %s\n", p->nome);
            printf("Numero: %d\n", p->numero);
            puts("-----------------------");
            i++;
            p = p->prox;
        }
    }
}

int main(void)
{
    int continuar = 1;

    while(continuar != 0)
    {
        adicionar();
        puts("");
        listar();
        puts("");
        printf("yes or no?: ");
        scanf("%d", &continuar);
    }

    return 0;
}