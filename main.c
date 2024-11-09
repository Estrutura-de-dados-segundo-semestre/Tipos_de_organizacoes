#include <stdio.h>
#include <stdlib.h> // Para usar a função exit
#include <time.h>   //biblioteca para calcular o tempo de execução

// função para trocar dois elementos
void swap(int *a, int *b)
{
    int temp = *a; // Armazena o valor de a em uma variável temporária
    *a = *b;       // Coloca o valor de b em a
    *b = temp;     // Coloca o valor temporário (original de a) em b
}

// função de ordenação Selection Sort
void selectionSort(int arr[], int n)
{
    // Percorre todo o array, exceto o último elemento
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i; // Define o índice do menor elemento como o índice atual
        // Busca o menor elemento nos elementos restantes
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {                 // Verifica se encontrou um valor menor
                minIndex = j; // Atualiza o índice do menor elemento
            }
        }
        // Troca o menor elemento encontrado com o primeiro elemento não ordenado
        if (minIndex != i)
        {
            swap(&arr[minIndex], &arr[i]);
        }
    }
}

// função de ordenação Insertion Sort
void insertionSort(int arr[], int n)
{
    // Percorre o array a partir do segundo elemento
    for (int i = 1; i < n; i++)
    {
        int key = arr[i]; // Armazena o valor atual em key
        int j = i - 1;    // Define j como o índice anterior ao atual

        // Move os elementos do array que são maiores que key uma posição á frente
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; // Move o elemento maior para a posição á frente
            j--;                 // Decrementa j para continuar verificando elementos anteriores
        }
        arr[j + 1] = key; // Insere key na posição correta
    }
}

// função de ordenação bubble
void bubble(int *v)
{
    int i, j, n; // declara as variáveis 'i' e 'j' para o loop e 'n' para o tamanho do vetor
    int aux;     // declara uma variável auxiliar para ajudar na troca dos elementos

    for (i = 0; i < n - 1; i++)     // laço externo que percorre até o penúltimo elemento do vetor
        for (j = 1; j < n - i; j++) // laço interno que percorre até o último elemento não ordenado
            if (v[j] < v[j - 1])
            {                    // verifica se o elemento atual é menor que o anterior
                aux = v[j];      // guarda o valor de v[j] em 'aux' para poder trocar
                v[j] = v[j - 1]; // move o elemento maior para a posição do j
                v[j - 1] = aux;  // coloca o valor armazenado do auxiliar na posição anterior ao do j
            }
}

// função de ordenação merge sort
void merge(int vetor[], int inicio, int meio, int fim)
{                                   // combina duas metades de um array que já foram ordenadas
    int tamanho = fim - inicio + 1; // números de elementos que entre inicio e fim que vão ser ordenadas
    int i, j, k, posicao;
    int temp[tamanho]; // array temporário para guardar os elementos de vetor antes de trocá-los

    // Copia os elementos para o array temporário
    for (i = inicio, k = 0; i <= fim; i++, k++)
    {
        temp[k] = vetor[i];
    }

    // Configura índices para esquerda e direita usando o array temp
    i = 0;                 // começa no primeiro elemento da metade da esquerda
    j = meio - inicio + 1; // começa no primeiro elemento da metade da direita
    posicao = inicio;      // índice atual do vetor que coloca o próximo elemento ordenado

    while (i <= meio - inicio && j <= fim - inicio)
    {
        if (temp[i] <= temp[j])
        {                                 // compara os elementos das duas metades
            vetor[posicao++] = temp[i++]; // o menor é inserido no vetor e a posição aumenta para o próximo lugar disponível do vetor
        }
        else
        {
            vetor[posicao++] = temp[j++]; // i e j aumentam conforme os elementos da direita ou esquerda avançam
        }
    }

    // while garante que os elementos que sobraram sejam copiados para o vetor
    while (i <= meio - inicio)
    {
        vetor[posicao++] = temp[i++];
    }

    while (j <= fim - inicio)
    {
        vetor[posicao++] = temp[j++];
    }
}

// função recursiva que divide o array até que cada metade tenha apenas um elemento
void mergeSort(int arr[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2; // calcula o meio do array

        mergeSort(arr, inicio, meio);  // ordena a metade esquerda
        mergeSort(arr, meio + 1, fim); // ordena a metade direita

        merge(arr, inicio, meio, fim); // combina as duas metades
    }
}

// função para imprimir o array
void printArray(int arr[], int n)
{
    // Percorre o array e imprime cada elemento
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]); // Imprime o elemento atual seguido de um espaço
    }
    printf("\n"); // Quebra de linha após imprimir todos os elementos
}

void trocar(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

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

int particionar(int lista[], int inicio, int fim)
{
    int pivo = lista[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++)
    {
        if (lista[j] < pivo)
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
        int indicePivo = particionar(lista, inicio, fim);
        quicksort(lista, inicio, indicePivo - 1);
        quicksort(lista, indicePivo + 1, fim);
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
// função principal com menu
int main()
{
    int arr[100];                         // declaração do array e do seu tamanho
    int n = sizeof(arr) / sizeof(arr[0]); // é calculado pelo número de elementos no array
    int choice;                           // declaração da variável que irá armazenar a escolha do método feita pelo usuário

    clock_t inicio, fim; // declaração das variáveis para o tempo inicial e final
    double tempo_cpu;    // variável para armazenar o tempo total da execução

    do
    {
        // Exibe o menu para o usuário escolher o método de ordenação ou sair
        printf("\nEscolha o método de ordenação:\n");
        printf("1. Selection Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Bubble Sort\n");
        printf("4. Merge Sort\n");
        printf("5. Quick Sort\n");
        printf("6. Heap Sort\n");
        printf("7. Sair\n");
        printf("Digite sua escolha (de 1 a 7): \n");
        scanf("%d", &choice); // Lê a escolha do usuário e armazena em choice

        switch (choice)
        { // Verifica a escolha do usuário
        case 1:
            srand(time(NULL));
            for (int i = 0; i < n; i++)
            { // sorteia os números aleatórios para o array
                arr[i] = rand();
            }
            printf("Array antes:\n");
            printArray(arr, n);
            inicio = clock();      // armazena o tempo de início dos clocks do processador
            selectionSort(arr, n); // Chama a função de Selection Sort
            fim = clock();         // armazena o tempo de fim dos clocks do processador
            printf("\nArray ordenado usando Selection Sort:\n");
            printArray(arr, n); // Imprime o array ordenado
            tempo_cpu = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
            printf("\nTempo de execução: %f segundos\n", tempo_cpu);
            break;
        case 2:
            srand(time(NULL));
            for (int i = 0; i < n; i++)
            { // sorteia os números aleatórios para o array
                arr[i] = rand();
            }
            printf("Array antes:\n");
            printArray(arr, n);
            inicio = clock();      // armazena o tempo de início dos clocks do processador
            insertionSort(arr, n); // Chama a função de Insertion Sort
            fim = clock();         // armazena o tempo de fim dos clocks do processador
            printf("\nArray ordenado usando Insertion Sort:\n");
            printArray(arr, n); // Imprime o array ordenado
            tempo_cpu = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
            printf("\nTempo de execução: %f segundos\n", tempo_cpu);
            break;
        case 3:
            srand(time(NULL));
            for (int i = 0; i < n; i++)
            { // sorteia os números aleatórios para o array
                arr[i] = rand();
            }
            printf("Array antes:\n");
            printArray(arr, n);
            inicio = clock(); // armazena o tempo de início dos clocks do processador
            bubble(arr);      // Chama a função Bubble
            fim = clock();    // armazena o tempo de fim dos clocks do processador
            printf("\nArray ordenado usando Bubble:\n");
            printArray(arr, n); // Imprime o array ordenado
            tempo_cpu = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
            printf("\nTempo de execução: %f segundos\n", tempo_cpu);
            break;
        case 4:
            srand(time(NULL));
            for (int i = 0; i < n; i++)
            { // sorteia os números aleatórios para o array
                arr[i] = rand();
            }
            printf("Array antes:\n");
            printArray(arr, n);
            inicio = clock();         // armazena o tempo de início dos clocks do processador
            mergeSort(arr, 0, n - 1); // Chama a função Merge Sort
            fim = clock();            // armazena o tempo de fim dos clocks do processador
            printf("\nArray ordenado usando Merge Sort:\n");
            printArray(arr, n); // Imprime o array ordenado
            tempo_cpu = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
            printf("\nTempo de execução: %f segundos\n", tempo_cpu);
            break;
        case 5:
            srand(time(NULL));
            for (int i = 0; i < n; i++)
            { // sorteia os números aleatórios para o array
                arr[i] = rand();
            }
            printf("Array antes:\n");
            printArray(arr, n);
            inicio = clock();         // armazena o tempo de início dos clocks do processador
            quicksort(arr, 0, n - 1); // Chama a função Quick Sort
            fim = clock();            // armazena o tempo de fim dos clocks do processador
            printf("\nArray ordenado usando Quick Sort:\n");
            printArray(arr, n); // Imprime o array ordenado
            tempo_cpu = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
            printf("\nTempo de execução: %f segundos\n", tempo_cpu);
            break;
        case 6:
            srand(time(NULL));
            for (int i = 0; i < n; i++)
            { // sorteia os números aleatórios para o array
                arr[i] = rand();
            }
            printf("Array antes:\n");
            printArray(arr, n);
            inicio = clock(); // armazena o tempo de início dos clocks do processador
            heapSort(arr, n); // Chama a função de Heap Sort
            fim = clock();    // armazena o tempo de fim dos clocks do processador
            printf("\nArray ordenado usando Heap Sort:\n");
            printArray(arr, n); // Imprime o array ordenado
            tempo_cpu = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
            printf("\nTempo de execução: %f segundos\n", tempo_cpu);
            break;
        case 7:
            printf("Saindo do programa...\n");
            exit(0); // Encerra o programa
        default:
            printf("Escolha inválida. Tente novamente.\n"); // Mensagem para escolha inválida
        }
    } while (choice != 7); // Repete o menu até que a escolha seja 7 (sair)

    return 0;
}