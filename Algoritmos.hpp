#ifndef ALGORITMOS_H
#define ALGORITMOS_H
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Insertion_Sort(vector<int> vetor)
{                         // Declarando um vector de inteiros chamado Insertion_Sort que tem como parametro o endereço de memoria vetor do vector de inteiros
    int n = vetor.size(); // Essa funcao retorna o tamanho do vetor e armazena em n
    for (int i = 1; i <= n - 1; i++)
    { // Percorre o vetor por completo
        for (int j = i; j > 0 && vetor[j - 1] > vetor[j]; j--)
        {                            // Comeca no indice 1 e testa se esta no indice maior que 0 e se o anterior eh maior, se sim troca
            int aux = vetor[j];      // A variavel aux recebe a posição atual do vetor
            vetor[j] = vetor[j - 1]; // A posição atual do vetor recebe o anterior
            vetor[j - 1] = aux;      // A posição do anterior passa a ser a atual
        }
    }
    return vetor;
}

vector<int> Bubble_Sort(vector<int> vetor)
{
    bool flag = false; // Variável de controle para verificar se o vetor já está ordenado.
    int i, j, aux;
    int n = vetor.size(); // Obtém o tamanho do vetor.
    // Loop externo para percorrer o vetor.
    for (i = 0; i < n - 1; i++)
    {
        // Loop interno para comparar elementos adjacentes e fazer trocas, se necessário.
        for (j = 0; j < n - i - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            { // Testa a posição atual com a adjacente, se for maior faz a troca
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
                flag = true; // Indica que houve uma troca e o vetor ainda não está totalmente ordenado.
            }
        }
        // Se não houver trocas no loop interno, o vetor já está ordenado e podemos sair do loop externo.
        if (flag == false)
        {
            break;
        }
    }

    return vetor; // Retorna o vetor ordenado.
}

vector<int> Shell_Sort(vector<int> vetor)
{                           // Compara se é menor, se sim mantem, se for maior troca
    int tam = vetor.size(); // Obtém o tamanho do vetor.
    // O loop externo que controla o tamanho do intervalo entre os elementos a serem comparados e trocados.
    for (int interval = tam / 2; interval > 0; interval /= 2)
    {
        // O loop interno percorre os elementos do vetor e os compara e troca conforme necessário.
        for (int i = interval; i < tam; i++)
        {
            int temp = vetor[i]; // Armazena o valor atual em uma variável temporária.
            int j;
            // Este loop compara o elemento atual com os elementos do intervalo definido anteriormente e faz as trocas necessárias.
            for (j = i; j >= interval && vetor[j - interval] > temp; j -= interval)
            {
                vetor[j] = vetor[j - interval]; // Move o elemento para a frente no vetor.
            }
            vetor[j] = temp; // Coloca o elemento temporário na posição correta no vetor ordenado.
        }
    }
    return vetor; // Retorna o vetor ordenado.
}

vector<int> Selection_Sort(vector<int> vetor)
{
    int tam = vetor.size(); // Obtém o tamanho do vetor.
    int i, j, i_menor, aux;
    // Loop externo que itera pelo vetor da primeira posição até a penúltima.
    for (i = 0; i < tam - 1; i++)
    {
        i_menor = i; // Assume que o índice do menor elemento é o índice atual (i).
        // Loop interno que itera pelo restante do vetor a partir da posição i+1.
        for (j = i + 1; j < tam; j++)
        {
            if (vetor[j] < vetor[i_menor]) // Compara o elemento na posição j com o menor elemento encontrado até agora.
                i_menor = j;               // Se um elemento menor for encontrado, atualiza i_menor com o índice do novo menor elemento.
        }
        // Troca os elementos na posição i e i_menor para colocar o menor elemento na posição correta.
        aux = vetor[i];
        vetor[i] = vetor[i_menor];
        vetor[i_menor] = aux;
    }
    return vetor; // Retorna o vetor ordenado.
}

// Função responsável por mesclar duas partes ordenadas de um vetor.
void Merge(vector<int> &vetor, int left, int middle, int right)
{
    vector<int> aux(vetor.begin() + left, vetor.begin() + right + 1); // Transfere os elementos entre esquerda e direita para um array auxiliar.

    // Inicializa índices para o array auxiliar (i), segunda metade (j) e vetor original (k).
    int i = 0;
    int j = middle - left + 1;
    int k = left;

    // Mescla os elementos até que um dos subarrays (aux[i..meio] ou aux[meio+1..direita]) seja totalmente processado.
    while (i <= middle - left && j <= right - left)
    {

        // Compara os elementos atuais dos dois subarrays e coloca o menor no vetor original.
        if (aux[i] <= aux[j])
        {
            vetor[k] = aux[i];
            i++;
        }
        else
        {
            vetor[k] = aux[j];
            j++;
        }
        k++;
    }
    while (i <= middle - left)
    { // Copia os elementos restantes do subarray da primeira metade, se houver.
        vetor[k] = aux[i];
        i++;
        k++;
    }
    while (j <= right - left)
    { // Copia os elementos restantes do subarray da segunda metade, se houver.
        vetor[k] = aux[j];
        j++;
        k++;
    }
    // Neste ponto, os elementos entre esquerda e direita estão mesclados e ordenados no vetor original.
}

void Merge_Sort(vector<int> &vetor, int left, int right)
{
    // Verifica se o subvetor possui 0 ou 1 elemento (caso base)
    if (left >= right)
        return;
    else
    {
        int middle = (left + right) / 2;      // Calcula o índice do meio do subvetor
        Merge_Sort(vetor, left, middle);      // Chama recursivamente a função Merge_Sort para ordenar o subvetor da esquerda
        Merge_Sort(vetor, middle + 1, right); // Chama recursivamente a função Merge_Sort para ordenar o subvetor da direita
        Merge(vetor, left, middle, right);    // Chama a função Merge para combinar os subvetores ordenados
    }
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int left = low + 1;
    int right = high;

    while (true) {
        while (left <= right && arr[left] < pivot) {
            left++;
        }

        while (left <= right && arr[right] > pivot) {
            right--;
        }

        if (left <= right) {
            std::swap(arr[left], arr[right]);
        } else {
            break;
        }
    }

    std::swap(arr[low], arr[right]);
    return right;
}

void Quick_Sort_1(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        Quick_Sort_1(arr, low, pivotIndex - 1);
        Quick_Sort_1(arr, pivotIndex + 1, high);
    }
}

int particao(vector<int> &values, int left, int right)
{
    // Calcula a média entre os elementos nos índices left e right.
    int pivotIndex = (left + right) / 2;
    int pivot = values[pivotIndex];

    // Troca o pivô com o último elemento do intervalo.
    swap(values[pivotIndex], values[right]);

    // Inicializa o índice 'i' para o início da partição.
    int i = left;

    // Itera sobre os elementos da sublista da direita do pivô.
    for (int j = left; j < right; j++)
    {
        // Compara o elemento atual com o pivô.
        if (values[j] <= pivot)
        {
            // Troca os elementos em 'i' e 'j'.
            swap(values[i], values[j]);
            // Incrementa o índice 'i'.
            i += 1;
        }
    }

    // Troca o pivô de volta para a posição correta.
    swap(values[i], values[right]);

    return i; // Retorna o novo índice do pivô após a partição.
}

void Quick_Sort_2(vector<int> &values, int left, int right)
{
    // Verifica se o índice 'left' é menor que o índice 'right'.
    if (left < right)
    {
        int index_pivot = particao(values, left, right); // Chama a função 'partition' para obter o índice do pivô
        Quick_Sort_2(values, left, index_pivot - 1);     // Chama recursivamente o quickSort para a partição à esquerda do pivô.
        Quick_Sort_2(values, index_pivot + 1, right);    // Chama recursivamente o quickSort para a partição à direita do pivô.
    }
}

// Função para trocar dois elementos no vetor.
void swap(vector<int>& values, int i, int j) {
    int temp = values[i];
    values[i] = values[j];
    values[j] = temp;
}

// Função para encontrar a mediana de três elementos. MEDIANA
int medianOfThree(vector<int>& values, int left, int right) {
    int mid = left + (right - left) / 2;

    // Ordena left, mid e right.
    if (values[left] > values[mid]) {
        swap(values, left, mid);
    }
    if (values[left] > values[right]) {
        swap(values, left, right);
    }
    if (values[mid] > values[right]) {
        swap(values, mid, right);
    }

    // Coloca o pivô (mediana) na posição correta (right-1).
    swap(values, mid, right - 1);

    // Retorna o valor da mediana.
    return values[right - 1];
}

// Função de partição para o algoritmo quicksort.
int partition_1(vector<int>& values, int left, int right) {
    // Escolhe o pivô como a mediana de três.
    int pivot = medianOfThree(values, left, right);

    // Inicializa os índices 'i' e 'j'.
    int i = left - 1;
    int j = right;

    while (true) {
        // Encontra o elemento maior que o pivô na sublista esquerda.
        do {
            i++;
        } while (values[i] < pivot);

        // Encontra o elemento menor que o pivô na sublista direita.
        do {
            j--;
        } while (values[j] > pivot);

        // Se 'i' e 'j' se cruzarem, a partição está completa.
        if (i >= j) {
            break;
        }

        // Troca os elementos em 'i' e 'j'.
        swap(values, i, j);
    }

    // Coloca o pivô no lugar certo.
    swap(values, i, right - 1);

    // Retorna o índice do pivô após a partição.
    return i;
}

// Função principal do algoritmo quicksort.
void Quick_Sort_3(vector<int>& values, int left, int right) {
    if (left < right) {
        // Particiona o vetor e obtém o índice do pivô.
        int pivotIndex = partition_1(values, left, right);

        // Chama recursivamente o quicksort para as sublistas à esquerda e à direita do pivô.
        Quick_Sort_3(values, left, pivotIndex - 1);
        Quick_Sort_3(values, pivotIndex + 1, right);
    }
}

// Função para particionar o vetor
int partition_2(vector<int>& arr, int low, int high) {
    int pivot = arr[low + rand() % (high - low + 1)]; // Escolha randômica do pivô
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j) {
            return j;
        }

        // Troca arr[i] e arr[j]
        swap(arr[i], arr[j]);
    }
}

// Função recursiva para ordenar o vetor usando o QuickSort
void Quick_Sort_4(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Particiona o vetor e obtém o índice do pivô
        int partitionIndex = partition_2(arr, low, high);

        // Chama recursivamente a função em ambos os lados do pivô
        Quick_Sort_4(arr, low, partitionIndex);
        Quick_Sort_4(arr, partitionIndex + 1, high);
    }
}

void minHeapify(vector<int> &heap, int i, int heap_size){
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    if (left < heap_size && heap[left] < heap[smallest])
        smallest = left;
    if (right < heap_size && heap[right] < heap[smallest])
        smallest = right;
    if (smallest != i)
    {
        std::swap(heap[i], heap[smallest]);
        minHeapify(heap, smallest, heap_size);
    }
}

void buildMinHeap(vector<int> &heap){
    int heap_size = heap.size();
    for (int i = (heap_size / 2) - 1; i >= 0; --i)
    {
        minHeapify(heap, i, heap_size);
    }
}

void Heap_Sort(vector<int> &arr){
    int heap_size = arr.size();
    buildMinHeap(arr);
    for (int i = heap_size - 1; i > 0; --i)
    {
        std::swap(arr[0], arr[i]);
        minHeapify(arr, 0, i);
    }
}

int Heap_Minimum(std::vector<int> &heap){
    return heap[0];
}

int Heap_Extract_Min(vector<int> &heap){
    int min = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    minHeapify(heap, 0, heap.size());
    return min;
}

void Heap_Increase_Key(vector<int> &heap, int value, int position){
    heap[position] = value;
    while (position > 0 && heap[(position - 1) / 2] > heap[position])
    {
        std::swap(heap[position], heap[(position - 1) / 2]);
        position = (position - 1) / 2;
    }
}

void Heap_Insert(vector<int> &heap, int value){
    minHeapify(heap, 0, heap.size());
    heap.push_back(value);
    Heap_Increase_Key(heap, value, heap.size()-1);
}

#endif