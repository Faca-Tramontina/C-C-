#include <stdio.h>

void selectionSort(int a[], int qnt)
{
    for(int i = 0; i < qnt - 1; i++)
    {
        int menor = i;

        for(int j = i+1; j < qnt; j++)
        {
            if(a[j] < a[menor])
            {
                menor = j;
            }
        }
        int aux = a[i];
        a[i] = a[menor];
        a[menor] = aux;
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

int main(void)
{
    int a[5] = {4,3,5,2,1};

    printArray(a,5);
    selectionSort(a,5);
    printArray(a,5);


}