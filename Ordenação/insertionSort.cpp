#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 6
void inicializar(int a[], int qnt)
{
    srand(time(NULL));

    for(int i = 0; i < qnt; i++)
    {
        a[i] = (rand() % 30);
    }
}

void printArray(int a[], int qnt)
{
    for(int i = 0; i < qnt; i++)
    {
        printf("%3d", a[i]);
    }
    puts("");
}

void insertionSort(int a[], int qnt)
{
    for(int i = 1; i < qnt; i++)
    {
        int key = a[i];
        int j = i - 1;

        while(j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main(void)
{
    int a[SIZE];

    inicializar(a,SIZE);
    printArray(a,SIZE);

    insertionSort(a,SIZE);
    printArray(a,SIZE);

    return 0;
}