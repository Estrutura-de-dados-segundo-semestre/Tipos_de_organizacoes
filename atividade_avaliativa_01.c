#include <stdio.h>
#include <stdlib.h> // Para usar a funcao exit

// Funcao para trocar dois elementos
void swap(int *a, int *b) {
    int temp = *a; // Armazena o valor de a em uma variavel temporaria
    *a = *b;       // Coloca o valor de b em a
    *b = temp;     // Coloca o valor temporario (original de a) em b
}

// Funcao de ordenacao Selection Sort
void selectionSort(int arr[], int n) {
    // Percorre todo o array, exceto o ultimo elemento
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Define o indice do menor elemento como o indice atual
        // Busca o menor elemento nos elementos restantes
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) { // Verifica se encontrou um valor menor
                minIndex = j; // Atualiza o indice do menor elemento
            }
        }
        // Troca o menor elemento encontrado com o primeiro elemento nao ordenado
        if (minIndex != i) {
            swap(&arr[minIndex], &arr[i]);
        }
    }
}

// Funcao de ordenacao Insertion Sort
void insertionSort(int arr[], int n) {
    // Percorre o array a partir do segundo elemento
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Armazena o valor atual em key
        int j = i - 1;    // Define j como o indice anterior ao atual
        
        // Move os elementos do array que sao maiores que key uma posicao a frente
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Move o elemento maior para a posicao a frente
            j--;                 // Decrementa j para continuar verificando elementos anteriores
        }
        arr[j + 1] = key; // Insere key na posicao correta
    }
}

// Funcao para imprimir o array
void printArray(int arr[], int n) {
    // Percorre o array e imprime cada elemento
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Imprime o elemento atual seguido de um espaco
    }
    printf("\n"); // Quebra de linha apos imprimir todos os elementos
}

// Funcao principal com menu
int main() {
    int n, choice; // Declara variaveis para o tamanho do array e a escolha do menu
    
    // Solicita o tamanho do array ao usuario
    printf("Digite o numero de elementos no array: ");
    scanf("%d", &n); // Le o valor do usuario e armazena em n

    int arr[n];  // Declara um array com o tamanho especificado pelo usuario

    // Solicita os valores do array ao usuario
    printf("Digite os elementos do array:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1); // Indica o numero do elemento
        scanf("%d", &arr[i]); // Le o valor e armazena na posicao i do array
    }

    do {
        // Exibe o menu para o usuario escolher o metodo de ordenacao ou sair
        printf("\nEscolha o metodo de ordenacao:\n");
        printf("1. Selection Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Sair\n");
        printf("Digite sua escolha (1, 2 ou 3): ");
        scanf("%d", &choice); // Le a escolha do usuario e armazena em choice

        switch (choice) { // Verifica a escolha do usuario
            case 1:
                selectionSort(arr, n); // Chama a funcao de Selection Sort
                printf("Array ordenado usando Selection Sort:\n");
                printArray(arr, n); // Imprime o array ordenado
                break;
            case 2:
                insertionSort(arr, n); // Chama a funcao de Insertion Sort
                printf("Array ordenado usando Insertion Sort:\n");
                printArray(arr, n); // Imprime o array ordenado
                break;
            case 3:
                printf("Saindo do programa...\n");
                exit(0); // Encerra o programa
            default:
                printf("Escolha invalida. Tente novamente.\n"); // Mensagem para escolha invalida
        }
    } while (choice != 3); // Repete o menu ate que a escolha seja 3 (sair)

    return 0;
}