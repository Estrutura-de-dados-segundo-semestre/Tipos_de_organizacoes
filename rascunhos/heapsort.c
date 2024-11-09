#include <stdio.h>
#include <stdlib.h>

void heapify(int lista[], int tamanho, int i)
{
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < tamanho && lista[esquerda] > lista[maior])
        maior = esquerda;

    if (direita < tamanho && lista[direita] > lista[maior])
        maior = direita;

    if (maior != i)
    {
        trocar(&lista[i], &lista[maior]);
        heapify(lista, tamanho, maior);
    }
}

void heapSort(int lista[], int tamanho)
{
    for (int i = tamanho / 2 - 1; i >= 0; i--)
        heapify(lista, tamanho, i);

    for (int i = tamanho - 1; i > 0; i--)
    {
        trocar(&lista[0], &lista[i]);
        heapify(lista, i, 0);
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

    heapSort(lista, tamanho);

    printf("Lista organizada: ");
    exibirLista(lista, tamanho);

    free(lista);
    return 0;
}
