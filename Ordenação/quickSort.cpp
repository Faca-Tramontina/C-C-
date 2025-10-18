#include <stdio.h>
#define SIZE 8
int particiona(int v[], int inicio, int fim)
{
    int pivo = (v[inicio] + v[fim] + v[(inicio + fim)/2])/ 3;
    while(inicio < fim)
    {
        while(inicio < fim && v[inicio] <= pivo)
        {
            inicio++;
        }
        while(inicio < fim && v[fim] > pivo)
        {
            fim = fim-1;
        }
        int aux = v[inicio];
        v[inicio] = v[fim];
        v[fim] = aux;
    }
    return inicio;
}

void quickSort(int a[], int inicio, int fim)
{
    if(inicio < fim)
    {
        int meio = particiona(a,inicio, fim);
        quickSort(a,inicio,meio-1);
        quickSort(a,meio, fim);
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
    quickSort(a,inicio,fim);
    printArray(a);

    return 0;
}