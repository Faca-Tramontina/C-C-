#include <stdio.h>
#define SIZE 3

struct cadastro
{
    int matricula;
    float salario;
};

int imprimirSalario(struct cadastro info)
{
    printf("Matricula: %d\n", info.matricula);
    printf("Salario: R$%.2f\n", info.salario);
    printf("---------------------------\n");
    return info.salario;
}
void cadastrar(struct cadastro a[], int qnt)
{
    for(int i = 0; i < qnt; i++)
    {
        printf("Digite a matricula do funcionario %d: ",i+1);
        scanf("%d", &a[i].matricula);
        printf("Salario do funcionario %d: ", i+1);
        scanf("%f", &a[i].salario);
        printf("-------------------------\n");
    }
}

void menoresMedia(struct cadastro a[], int qnt, float media)
{
    int counter = 0;
    printf("SALARIO ABAIXOS DA MEDIA (R$%.2f)\n\n", media);
    for(int i = 0; i < qnt; i++)
    {
        if(a[i].salario < media)
        {
            printf("Matricula: %d\n", a[i].matricula);
            printf("Salario: R$%.2f\n", a[i].salario);
            printf("---------------------------\n");
            counter++;
        }
    }
}

void insertionSort(struct cadastro a[], int qnt)
{
    for(int i = 1; i < qnt; i++)
    {
        struct cadastro key = a[i];
        int j = i - 1;

        while(j >= 0 && a[j].salario > key.salario)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main(void)
{
    float soma = 0;
    float media;
    struct cadastro a[SIZE];
    cadastrar(a,SIZE);
    insertionSort(a,SIZE);
    for(int i = 0; i < SIZE; i++)
    {
        soma += imprimirSalario(a[i]);
    }
    printf("Somatorio: R$%.2f\n", soma);
    media = soma / SIZE;
    menoresMedia(a,SIZE, media);
    return 0;
}