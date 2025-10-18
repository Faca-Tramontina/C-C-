#include <stdio.h>
void bubbleSort(int a[], int qnt)
{
    for(int i = 0; i < qnt - 1; i++)
    {
        for(int j = 0; j < qnt - 1 - i; j++)
        {
            if(a[j] > a[j+1])
            {
                int aux = a[j];
                a[j] = a[j+1];
                a[j+1] = aux;
            }
        }
    }
}