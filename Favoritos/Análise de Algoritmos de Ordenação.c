#include <stdio.h>
#include <stdlib.h>
#define SIZE 6
void printArray(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(i != 5)
            printf("%d\t", a[i]);
        else
            printf("%d |", a[i]);
    }
}

void show(int a[],int n,int flag, int typeSort)
{
    printArray(a, n);
    switch (typeSort)
    {
        case 1:
            if(flag)
            {
                printf(" Sim, troca");
            }
            else
            {
                printf(" Nao, mantem");
            }
            printf("\n");
            break;
        default:
            break;
    }
}
void bubble_sort(int a[], int n, int *c, int *t)
{
    int flag = 1;
    int limite = n - 1;
    while(flag)
    {
        flag = 0;
        for(int i = 0; i < limite; i++)
        {
            if(a[i] > a[i+1])
            {
                flag = 1;
                int aux = a[i];
                a[i] = a[i+1];
                a[i+1] = aux;
                (*t)++;
            }
     
            (*c)++;
            show(a,n,flag, 1);
        }
        limite--;
    }
}

void selection_sort(int a[], int n, int *c, int *t)
{
    for(int i = 0; i < n-1; i++)
    {
        int min = i;
        int j = i + 1;
        for(j; j < n; j++)
        {
            if(a[j] < a[min])
            {
                min = j;
            }
            (*c)++;
        }
        if(min != i)
        {
            int aux = a[min];
            a[min] = a[i];
            a[i] = aux;
            (*t)++;
        }
        show(a, n, 0, 0);
        printf(" Valor menor = %d\n", a[i]);
    }
}

void insertion_sort(int a[], int n, int *c, int *t)
{
    int flag = 0;

    for(int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        (*c)++;

    
        while(j >= 0 && a[j] > key)
        {
            (*c)++;
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = key;
        (*t)++;

        show(a, n, flag, 0);
        printf(" Key: %d\n", key);
    }
}

void copiar(int a[], int b[],int n)
{
    for(int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}

void resultados(int a[], int comparacoes, int trocas)
{
    printf("------------------------------------------\n");
    printf("Total de comparacoes: %d\n", comparacoes);
    printf("Total de trocas: %d\n", trocas);
    printf("------------------------------------------\n");
}
int main(void)
{
    char fim = 's';
    while(fim != 'n')
    {
        int array[SIZE] = {89,10,15,5,32,26};
        int array1[SIZE];
        int array2[SIZE];

        copiar(array1,array,SIZE);
        copiar(array2,array,SIZE);


        int comparacoes = 0, trocas = 0;
        printf("O array antes de passar pela ordenacao:\n");
        printArray(array, 5);
        printf("\n");
        printf("------------------------------------------\n");

        printf("-------------- Bubble  Sort --------------\n");
        bubble_sort(array, SIZE, &comparacoes, &trocas);
        resultados(array, comparacoes, trocas);
        
        comparacoes = 0; 
        trocas = 0;

        printf("------------- Selection Sort -------------\n");
        selection_sort(array1, SIZE, &comparacoes, &trocas); 
        resultados(array1, comparacoes, trocas);

        comparacoes = 0; 
        trocas = 0;

        printf("------------- Insertion Sort -------------\n");
        insertion_sort(array2,SIZE,&comparacoes,&trocas);
        resultados(array1, comparacoes, trocas);
        printf("Pressione 'n' para finalizar o programa: ");
        scanf(" %c", &fim);
    }

    return 0;
}
