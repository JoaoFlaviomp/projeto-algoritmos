#include <stdio.h> 
#include <ctime>
#include "Interface.h"
#include "Interface.cpp"

std::vector<int> testArr = {7, 8, 9, 2, 1, 5, 10, 3, 6, 4};

void printVector(std::vector<int> &arr){
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main(void){
    int opcao_selecionada, valor_formato, valor_tamanho, heapMin;
    clock_t inicio, final;
    double tempo_total;
	
    do{
    printf("Escolha uma opcao: \n");
    printf("[1] - Insertion Sort\n");
    printf("[2] - Bubble Sort\n");
    printf("[3] - Shell Sort\n");
    printf("[4] - Selection Sort\n");
    printf("[5] - Merge Sort\n");
    printf("[6] - Quick Sort\n");
    printf("[7] - Quick Sort media\n");
    printf("[8] - Quick Sort mediana\n");
    printf("[9] - Quick Sort random\n");
    printf("[10] - Heap Sort(MIN)\n");
    printf("[11] - Heap Minimo\n");
    printf("[12] - Heap Extract Min\n");
    printf("[13] - Heap Increase Key\n");
    printf("[14] - Heap Insert\n");
    printf("[0] - Sair\n");

    printf("Escolha sua opcao: ");
    scanf("%d", &opcao_selecionada);
    
    switch(opcao_selecionada){
        case 0: // encerrar programa
        break;
        
        case 1: // insertion sort
        valor_formato = escolha_formato();
        valor_tamanho = escolha_tamanho();
        inicio = clock();
        interface_algoritmo((algoritmos_opcoes)(opcao_selecionada - 1), (formatos_opcoes)valor_formato, valor_tamanho);
        final = clock();
        tempo_total = (final - inicio)/(double) CLOCKS_PER_SEC;
        salvar_tempo((formatos_opcoes)valor_formato, valor_tamanho, tempo_total, (algoritmos_opcoes)(opcao_selecionada - 1));
        break;
        
        case 2: // bubble sort
        valor_formato = escolha_formato();
        valor_tamanho = escolha_tamanho();
        inicio = clock();
        interface_algoritmo((algoritmos_opcoes)(opcao_selecionada - 1), (formatos_opcoes)valor_formato, valor_tamanho);
        final = clock();
        tempo_total = (final - inicio)/(double) CLOCKS_PER_SEC;
        salvar_tempo((formatos_opcoes)valor_formato, valor_tamanho, tempo_total, (algoritmos_opcoes)(opcao_selecionada - 1));
        break;

        case 3: // shell sort
        valor_formato = escolha_formato();
        valor_tamanho = escolha_tamanho();
        inicio = clock();
        interface_algoritmo((algoritmos_opcoes)(opcao_selecionada - 1), (formatos_opcoes)valor_formato, valor_tamanho);
        final = clock();
        tempo_total = (final - inicio)/(double) CLOCKS_PER_SEC;
        salvar_tempo((formatos_opcoes)valor_formato, valor_tamanho, tempo_total, (algoritmos_opcoes)(opcao_selecionada - 1));
        break;

        case 4: // selection sort
        valor_formato = escolha_formato();
        valor_tamanho = escolha_tamanho();
        inicio = clock();
        interface_algoritmo((algoritmos_opcoes)(opcao_selecionada - 1), (formatos_opcoes)valor_formato, valor_tamanho);
        final = clock();
        tempo_total = (final - inicio)/(double) CLOCKS_PER_SEC;
        salvar_tempo((formatos_opcoes)valor_formato, valor_tamanho, tempo_total, (algoritmos_opcoes)(opcao_selecionada - 1));
        break;

        case 5: // merge sort
        valor_formato = escolha_formato();
        valor_tamanho = escolha_tamanho();
        inicio = clock();
        interface_algoritmo((algoritmos_opcoes)(opcao_selecionada - 1), (formatos_opcoes)valor_formato, valor_tamanho);
        final = clock();
        tempo_total = (final - inicio)/(double) CLOCKS_PER_SEC;
        salvar_tempo((formatos_opcoes)valor_formato, valor_tamanho, tempo_total, (algoritmos_opcoes)(opcao_selecionada - 1));
        break;

        case 6: // quick sort
        valor_formato = escolha_formato();
        valor_tamanho = escolha_tamanho();
        inicio = clock();
        interface_algoritmo((algoritmos_opcoes)(opcao_selecionada - 1), (formatos_opcoes)valor_formato, valor_tamanho);
        final = clock();
        tempo_total = (final - inicio)/(double) CLOCKS_PER_SEC;
        salvar_tempo((formatos_opcoes)valor_formato, valor_tamanho, tempo_total, (algoritmos_opcoes)(opcao_selecionada - 1));
        break;

        case 7: // quick sort media
        valor_formato = escolha_formato();
        valor_tamanho = escolha_tamanho();
        inicio = clock();
        interface_algoritmo((algoritmos_opcoes)(opcao_selecionada - 1), (formatos_opcoes)valor_formato, valor_tamanho);
        final = clock();
        tempo_total = (final - inicio)/(double) CLOCKS_PER_SEC;
        salvar_tempo((formatos_opcoes)valor_formato, valor_tamanho, tempo_total, (algoritmos_opcoes)(opcao_selecionada - 1));
        break;

        case 8: // quick sort mediana
        valor_formato = escolha_formato();
        valor_tamanho = escolha_tamanho();
        inicio = clock();
        interface_algoritmo((algoritmos_opcoes)(opcao_selecionada - 1), (formatos_opcoes)valor_formato, valor_tamanho);
        final = clock();
        tempo_total = (final - inicio)/(double) CLOCKS_PER_SEC;
        salvar_tempo((formatos_opcoes)valor_formato, valor_tamanho, tempo_total, (algoritmos_opcoes)(opcao_selecionada - 1));
        break;

        case 9: // quick sort random
        valor_formato = escolha_formato();
        valor_tamanho = escolha_tamanho();
        inicio = clock();
        interface_algoritmo((algoritmos_opcoes)(opcao_selecionada - 1), (formatos_opcoes)valor_formato, valor_tamanho);
        final = clock();
        tempo_total = (final - inicio)/(double) CLOCKS_PER_SEC;
        salvar_tempo((formatos_opcoes)valor_formato, valor_tamanho, tempo_total, (algoritmos_opcoes)(opcao_selecionada - 1));
        break;

        case 10: // heap sort
        valor_formato = escolha_formato();
        valor_tamanho = escolha_tamanho();
        inicio = clock();
        interface_algoritmo((algoritmos_opcoes)(opcao_selecionada - 1), (formatos_opcoes)valor_formato, valor_tamanho);
        final = clock();
        tempo_total = (final - inicio)/(double) CLOCKS_PER_SEC;
        salvar_tempo((formatos_opcoes)valor_formato, valor_tamanho, tempo_total, (algoritmos_opcoes)(opcao_selecionada - 1));
        break;

        case 11: // Heap minimum
                std::cout << "+-------------------------------+" << std::endl
                          << "|     Heap antes da ordenacao   |" << std::endl
                          << "+-------------------------------+" << std::endl;
                printVector(testArr);
                Heap_Sort(testArr);
                heapMin = Heap_Minimum(testArr);
                std::cout << "+-------------------------------+" << std::endl
                          << "|     Heap depois da ordenacao  |" << std::endl
                          << "+-------------------------------+" << std::endl;
                printVector(testArr);
                std::cout << "+-------------------------------+" << std::endl
                          << "|         Elemento minimo       |" << std::endl
                          << "+-------------------------------+" << std::endl
                          << heapMin << std::endl;
                break;

        case 12: // Heap extract min
                std::cout << "+-------------------------------+" << std::endl
                          << "|     Heap antes da extracao   |" << std::endl
                          << "+-------------------------------+" << std::endl;
                printVector(testArr);
                Heap_Sort(testArr);
                heapMin = Heap_Extract_Min(testArr);
                std::cout << "+-------------------------------+" << std::endl
                          << "|     Heap depois da extracao  |" << std::endl
                          << "+-------------------------------+" << std::endl;
                Heap_Sort(testArr);
                printVector(testArr);
                std::cout << "+-------------------------------+" << std::endl
                          << "|         Elemento minimo       |" << std::endl
                          << "+-------------------------------+" << std::endl
                          << heapMin << std::endl;
                break;

        case 13: // Heap increase key
                std::cout << "+-------------------------------+" << std::endl
                          << "|     Heap antes da ordenacao   |" << std::endl
                          << "+-------------------------------+" << std::endl;
                printVector(testArr);

                int positionToIncrease;
                std::cout << "Digite a posicao desejada (entre 0 e 9): ";
                std::cin >> positionToIncrease;

                if (positionToIncrease < 0 || positionToIncrease >= testArr.size()) {
                    std::cout << "Posição inválida. Por favor, escolha uma posição entre 0 e 9." << std::endl;
            break;
                }
                Heap_Increase_Key(testArr, 1000, positionToIncrease);
                Heap_Sort(testArr);
            std::cout << "+-------------------------------+" << std::endl
              << "|     Heap depois da ordenacao  |" << std::endl
              << "+-------------------------------+" << std::endl;
              printVector(testArr);
            break;

        case 14: // Heap insert
                std::cout << "+-------------------------------+" << std::endl
                          << "|     Heap antes da ordenacao   |" << std::endl
                          << "+-------------------------------+" << std::endl;
                printVector(testArr);
                Heap_Insert(testArr, 1000);
                Heap_Sort(testArr);
                std::cout << "+-------------------------------+" << std::endl
                          << "|     Heap depois da ordenacao  |" << std::endl
                          << "+-------------------------------+" << std::endl;
                printVector(testArr);
                break;
    }

    }while(opcao_selecionada != 0);
    
 return 0;
}