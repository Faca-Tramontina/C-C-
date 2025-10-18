#include <stdio.h>

int buscaBinaria(int a[], int qnt, int valor)
{
    int p = 0;
    int u = qnt - 1;

    while(p <= u)
    {
        int media = (p + u)/2;

        if(a[media] > valor)
        {
            u = media - 1;
        }
        else if(a[media] < valor)
        {
            p = media + 1;
        }
        else
        {
            return media;
        }
    }
    return -1;
}

int main(void)
{
    int a[5] = {1,2,3,4,5};
    int valor;
    int index;

    printf("Digite um valor a ser encontrado: ");
    scanf("%d", &valor);

    index = buscaBinaria(a, 5, valor);

    if(index != -1)
    {
        printf("A valor %d encontrado na posicao %d\n", a[index], index);
    }
    else
    {
        printf("Valor nao encontrado\n");
    }
    return 0;
}