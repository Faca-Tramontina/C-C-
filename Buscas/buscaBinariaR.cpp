#include <stdio.h>
#define SIZE 6
int buscaBinaria(int a[],int inicio, int fim, int valor)
{

    if(inicio <= fim)
    {
        int meio = (inicio + fim) / 2;

        if(a[meio] > valor)
        {
            return buscaBinaria(a,inicio, meio - 1, valor);
        }
        else if(a[meio] < valor)
        {
            return buscaBinaria(a,meio+1, fim, valor);
        }
        else
        {
            return meio;
        }
    }
    return -1;

}

int binaria(int A[], int x, int ini, int fim)
{
    int meio;
    meio = (ini + fim)/2;
    if(ini > fim)
    return -1;
    if(x == A[meio])
    return meio;
    else{
        if(x < A[meio])
        binaria(A, x, ini, meio - 1);
        else
        binaria(A, x, meio + 1, fim);
    }
}

int main(void)
{
    int a[SIZE] = {1,2,3,4,5,6};
    int valor;
    int resultado;

    printf("Digite um valor para ser encontrado: ");
    scanf("%d", &valor);

    resultado = binaria(a,valor,0,SIZE-1);

    if(resultado != -1)
    {
        printf("Valor %d encontrado na posicao %d\n", a[resultado], resultado);
    }
    else
    {
        printf("Valor nao encontrado!\n");
    }
    printf("RESULTADO: %d", resultado);
    return 0;
}