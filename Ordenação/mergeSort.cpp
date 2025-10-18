#include <stdio.h>
#define SIZE 8

void merge(int a[], int inicio, int fim, int meio)
{
    int i, aux[SIZE];
    int poslivre = inicio;
    int inicioA1 = inicio;
    int inicioA2 = meio + 1;

    while(inicioA1 <= meio && inicioA2 <= fim)
    {
        if(a[inicioA1] > a[inicioA2])
        {
            aux[poslivre] = a[inicioA2];
            inicioA2++;
        }
        else
        {
            aux[poslivre] = a[inicioA1];
            inicioA1++;
        }
        poslivre++;
    }
    
    for(i = inicioA1; i <= meio; i++)
    {
        aux[poslivre] = a[i];
        poslivre++;
    }
    
    for(i = inicioA2; i <= fim; i++)
    {
        aux[poslivre] = a[i];
        poslivre++;
    }

    for(i = inicio; i <= fim; i++)
    {
        a[i] = aux[i];
    }
}

void mergeSort(int a[], int inicio, int fim)
{
    if(inicio < fim)
    {
        int meio = (inicio + fim) / 2;
        mergeSort(a, inicio, meio);
        mergeSort(a, meio+1, fim);
        merge(a,inicio,fim,meio);
    }
}

void printArray(int a[])
{
    for(int i = 0; i < SIZE; i++)
    {
        printf("%3d", a[i]);
    }
    puts("");
}

int main(void)
{
    int a[SIZE] = {1, 4, 3, 5, 7, 2, 6, 10};
    int inicio = 0;
    int fim = SIZE - 1;

    printArray(a);
    mergeSort(a,inicio,fim);
    printArray(a);

    return 0;
}