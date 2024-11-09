#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int lista[], int inicio, int fim)
{
    int pivô = lista[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++)
    {
        if (lista[j] < pivô)
        {
            i++;
            trocar(&lista[i], &lista[j]);
        }
    }
    trocar(&lista[i + 1], &lista[fim]);
    return i + 1;
}

void quicksort(int lista[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int índicePivô = particionar(lista, inicio, fim);
        quicksort(lista, inicio, índicePivô - 1);
        quicksort(lista, índicePivô + 1, fim);
    }
}

void exibirLista(int lista[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main()
{
    int tamanho;
    printf("Digite o tamanho da lista: ");
    scanf("%d", &tamanho);

    int *lista = (int *)malloc(tamanho * sizeof(int));
    if (lista == NULL)
    {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    printf("Digite os elementos da lista:\n");
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &lista[i]);
    }

    quicksort(lista, 0, tamanho - 1);

    exibirLista(lista, tamanho);

    free(lista);
    return 0;
}
