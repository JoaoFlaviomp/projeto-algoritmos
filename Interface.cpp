#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include "Interface.h"
#include "io.hpp"
#include "Algoritmos.hpp"

using namespace std;

int escolha_formato(void){
    printf("Escolha uma opcao em que as instancias serao geradas: \n");
    printf("[1] - Numeros randomicos\n");
    printf("[2] - Numeros crescentes\n");
    printf("[3] - Numeros decrescentes\n");

    int opcao_selecionada;
    printf("Escolha sua opcao: ");
    scanf("%d", &opcao_selecionada);

    return opcao_selecionada - 1; // opcao_selecionada entra como 2, 2 - 1 = 1, 1 em formatos_opcoes eh crescente

}

int escolha_tamanho(void){
    printf("Digite o tamanho da entrada (10,100,1000,10000,100000,1000000)\n");

    int tamanho;
    scanf("%d", &tamanho);

    return tamanho;
}

void interface_algoritmo(algoritmos_opcoes algoritmos, formatos_opcoes formatos, int tamanhos){
    string endereco_arquivo; // Variavel do tipo string chamada endereco_arquivo
    vector <int> vetor; //Declarando um vector de inteiros chamado vetor

    switch (algoritmos){
    case insertion_sort:
        endereco_arquivo = gerar_arquivo(formatos, tamanhos, algoritmos); // Vai gerar um arquivo com um determinado formato e tamanho e vai ser salvo em endereco_arquivo
        vetor = carregar_arquivo(endereco_arquivo); // Vai carregar o endereco que esta nesse arquivo e mandar para o vetor
        vetor = Insertion_Sort(vetor); // Ordenar o vetor e retornar o vetor
        salvar_arquivo(vetor, formatos, tamanhos, algoritmos); // salvando a saida
        break;
    case bubble_sort:
        endereco_arquivo = gerar_arquivo(formatos, tamanhos, algoritmos); // Vai gerar um arquivo com um determinado formato e tamanho e vai ser salvo em endereco_arquivo
        vetor = carregar_arquivo(endereco_arquivo); // Vai carregar o endereco que esta nesse arquivo e mandar para o vetor
        vetor = Bubble_Sort(vetor); // Ordenar o vetor e retornar o vetor
        salvar_arquivo(vetor, formatos, tamanhos, algoritmos); // salvando a saida
        break;
    case shell_sort:
        endereco_arquivo = gerar_arquivo(formatos, tamanhos, algoritmos); // Vai gerar um arquivo com um determinado formato e tamanho e vai ser salvo em endereco_arquivo
        vetor = carregar_arquivo(endereco_arquivo); // Vai carregar o endereco que esta nesse arquivo e mandar para o vetor
        vetor = Shell_Sort(vetor); // Ordenar o vetor e retornar o vetor
        salvar_arquivo(vetor, formatos, tamanhos, algoritmos); // salvando a saida
        break;
    case selection_sort:
        endereco_arquivo = gerar_arquivo(formatos, tamanhos, algoritmos); // Vai gerar um arquivo com um determinado formato e tamanho e vai ser salvo em endereco_arquivo
        vetor = carregar_arquivo(endereco_arquivo); // Vai carregar o endereco que esta nesse arquivo e mandar para o vetor
        vetor = Selection_Sort(vetor); // Ordenar o vetor e retornar o vetor
        salvar_arquivo(vetor, formatos, tamanhos, algoritmos); // salvando a saida
        break;
    case merge_sort:
        endereco_arquivo = gerar_arquivo(formatos, tamanhos, algoritmos); // Vai gerar um arquivo com um determinado formato e tamanho e vai ser salvo em endereco_arquivo
        vetor = carregar_arquivo(endereco_arquivo); // Vai carregar o endereco que está nesse arquivo e mandar para o vetor
        Merge_Sort(vetor, 0, vetor.size() - 1); // Correção: ajuste do índice de fim
        salvar_arquivo(vetor, formatos, tamanhos, algoritmos); // salvando a saída
        break;
    case quick_sort:
        endereco_arquivo = gerar_arquivo(formatos, tamanhos, algoritmos); // Vai gerar um arquivo com um determinado formato e tamanho e vai ser salvo em endereco_arquivo
        vetor = carregar_arquivo(endereco_arquivo); // Vai carregar o endereco que está nesse arquivo e mandar para o vetor
        Quick_Sort_1(vetor, 0, vetor.size() - 1); // Correção: ajuste do índice de fim
        salvar_arquivo(vetor, formatos, tamanhos, algoritmos); // salvando a saída
        break;
    case quick_sort_media:
        endereco_arquivo = gerar_arquivo(formatos, tamanhos, algoritmos); // Vai gerar um arquivo com um determinado formato e tamanho e vai ser salvo em endereco_arquivo
        vetor = carregar_arquivo(endereco_arquivo); // Vai carregar o endereco que está nesse arquivo e mandar para o vetor
        Quick_Sort_2(vetor, 0, vetor.size() - 1); // Correção: ajuste do índice de fim
        salvar_arquivo(vetor, formatos, tamanhos, algoritmos); // salvando a saída
        break;
    case quick_sort_mediana:
        endereco_arquivo = gerar_arquivo(formatos, tamanhos, algoritmos); // Vai gerar um arquivo com um determinado formato e tamanho e vai ser salvo em endereco_arquivo
        vetor = carregar_arquivo(endereco_arquivo); // Vai carregar o endereco que está nesse arquivo e mandar para o vetor
        Quick_Sort_3(vetor, 0, vetor.size() - 1); // Correção: ajuste do índice de fim
        salvar_arquivo(vetor, formatos, tamanhos, algoritmos); // salvando a saída
        break;
    case quick_sort_random:
        endereco_arquivo = gerar_arquivo(formatos, tamanhos, algoritmos); // Vai gerar um arquivo com um determinado formato e tamanho e vai ser salvo em endereco_arquivo
        vetor = carregar_arquivo(endereco_arquivo); // Vai carregar o endereco que está nesse arquivo e mandar para o vetor
        Quick_Sort_4(vetor, 0, vetor.size() - 1); // Correção: ajuste do índice de fim
        salvar_arquivo(vetor, formatos, tamanhos, algoritmos); // salvando a saída
        break;
    case heap_sort:
        endereco_arquivo = gerar_arquivo(formatos, tamanhos, algoritmos); // Vai gerar um arquivo com um determinado formato e tamanho e vai ser salvo em endereco_arquivo
        vetor = carregar_arquivo(endereco_arquivo); // Vai carregar o endereco que está nesse arquivo e mandar para o vetor
        Heap_Sort(vetor); // Correção: ajuste do índice de fim
        salvar_arquivo(vetor, formatos, tamanhos, algoritmos); // salvando a saída
    }
}

