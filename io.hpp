#ifndef IO_H
#define IO_H
#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <random>
#include <algorithm>
#include "Interface.h"
#include <windows.h>

using namespace std;

bool existe_diretorio(const char* path){
    DWORD fileAttributes = GetFileAttributesA(path);
    return (fileAttributes != INVALID_FILE_ATTRIBUTES) && (fileAttributes & FILE_ATTRIBUTE_DIRECTORY);
}

void criar_pasta(const char* path){
    if (existe_diretorio(path)) {
        //std::cout << "O diretorio existe." << std::endl; //se necessario avisar, só ligar
    } else {
        char command[100]; // Ajuste o tamanho conforme necessário
        snprintf(command, sizeof(command), "mkdir \"%s\"", path);
        system(command); // Executa o comando usando system()
    }
}

// Funcao para criar um arquivo
string gerar_arquivo(formatos_opcoes ordem, int tamanho, algoritmos_opcoes algoritmo)
{
    ofstream arquivo; // Pega as informacoes do codigo e leva para o arquivo
    string endereco;  // variavel do tipo string chamada endereco
    string caminho;
    string nome_algoritmo;
    switch (algoritmo)
    {
    case insertion_sort:
        nome_algoritmo = "insertion_sort";
        break;
    case bubble_sort:
        nome_algoritmo = "bubble_sort";
        break;
    case shell_sort:
        nome_algoritmo = "shell_sort";
        break;
    case selection_sort:
        nome_algoritmo = "selection_sort";
        break;
    case merge_sort:
        nome_algoritmo = "merge_sort";
        break;
    case quick_sort:
        nome_algoritmo = "quick_sort";
        break;
    case quick_sort_media:
        nome_algoritmo = "quick_sort_media";
        break;
    case quick_sort_mediana:
        nome_algoritmo = "quick_sort_mediana";
        break;
    case quick_sort_random:
        nome_algoritmo = "quick_sort_random";
        break;
    case heap_sort:
        nome_algoritmo = "heap_sort";
        break;
    //case
    }
    switch (ordem)
    {
    case randomico:
        caminho = nome_algoritmo +"/arquivodeentrada/random";
        endereco = caminho +"/entradarandom" + to_string(tamanho) + ".txt";
        break;
    case crescente:
        caminho = nome_algoritmo +"/arquivodeentrada/crescente";
        endereco = caminho +"/entradacrescente" + to_string(tamanho) + ".txt";
        break;
    case decrescente:
        caminho = nome_algoritmo +"/arquivodeentrada/decrescente";
        endereco = caminho +"/entradadecrescente" + to_string(tamanho) + ".txt";
        break;
    }
    
    criar_pasta(caminho.c_str());
    arquivo.open(endereco); // abrir o arquivo com o endereco escolhido no switch
    
    vector<int> vetor; // Criando um vetor para salvar os numeros
    
    // Gerador pseudoaleatorio
    std::random_device rd;
    std::mt19937 gerador(rd());
    std::uniform_int_distribution<int> range(1, 1000000); // Escopo dos numeros

    arquivo << tamanho << endl; // Anotando o tamanho na primeira linha do txt
    
    // A partir desse switch que é gerado os números crescentes, decrescentes e aleatórios
    switch (ordem)
    {
    case randomico: // Medio caso
        for (int i = 0; i < tamanho; i++)
        {
            vetor.push_back(range(gerador)); // gerando e colocando os numeros no final do vetor
        }
        break;
    case crescente: // Melhor caso
        for (int i = 0; i < tamanho; i++)
        {
            vetor.push_back(range(gerador)); // gerando e colocando os numeros no final do vetor
        }
        sort(vetor.begin(), vetor.end()); // Vai ordenar o vetor em ordem crescente
        break;
    case decrescente: // Pior caso
        for (int i = 0; i < tamanho; i++)
        {
            vetor.push_back(range(gerador)); // gerando e colocando os numeros no final do vetor
        }
        sort(vetor.begin(), vetor.end(), greater<int>()); // Vai ordenar o vetor em ordem decrescente
        break;
    }

    for (int num : vetor)
    { 
        arquivo << num << endl; // para todo numero no vetor vai ser escrito no arquivo
    }
    arquivo.close(); // fecha o arquivo
    return endereco; // retorna o endereco que o arquivo esta
}

// Funcao para carregar o arquivo no vetor
vector<int> carregar_arquivo(string endereco)
{
    ifstream arquivo(endereco); // Pega as informacoes do arquivo e tras para o codigo
    vector<int> numeros; // Declarando uma variavel do tipo vector de inteiros
    int tamanho, aux;
    arquivo >> tamanho; // Le a primeira linha e salva em tamanho

    for (int i = 0; i < tamanho; i++) // Cada interacao do for aux vai receber o numero do arquivo e vai salvar no vetor
    {                           
        arquivo >> aux; // Arquivo passa os numeros para aux
        numeros.push_back(aux); // Pega o valor de aux e salva no vetor numeros
    }
    arquivo.close(); // fecha o arquivo
    return numeros;  // retorna o vetor
}

// Funcao de salvar o vetor ordenado no arquivo de saida
void salvar_arquivo(vector<int> vetor, formatos_opcoes ordem, int tamanho,algoritmos_opcoes algoritmo)
{
    ofstream arquivo; // Pega as informacoes do codigo e leva para o arquivo
    string endereco; // Variavel do tipo string chamada endereco
    string caminho;
    string nome_algoritmo;
    switch (algoritmo)
    {
    case insertion_sort:
        nome_algoritmo = "insertion_sort";
        break;
    case bubble_sort:
        nome_algoritmo = "bubble_sort";
        break;
    case shell_sort:
        nome_algoritmo = "shell_sort";
        break;
    case selection_sort:
        nome_algoritmo = "selection_sort";
        break;
    case merge_sort:
        nome_algoritmo = "merge_sort";
        break;
    case quick_sort:
        nome_algoritmo = "quick_sort";
        break;
    case quick_sort_media:
        nome_algoritmo = "quick_sort_media";
        break;
    case quick_sort_mediana:
        nome_algoritmo = "quick_sort_mediana";
        break;
    case quick_sort_random:
        nome_algoritmo = "quick_sort_random";
        break;
    case heap_sort:
        nome_algoritmo = "heap_sort";
        break;
    //case
    } 
    switch (ordem)
    {
    case randomico:
        caminho = nome_algoritmo +"/arquivodesaida/random";
        endereco = caminho +"/saidarandom" + to_string(tamanho) + ".txt";
        break;
    case crescente:
        caminho = nome_algoritmo +"/arquivodesaida/crescente";
        endereco = caminho +"/saidacrescente" + to_string(tamanho) + ".txt";
        break;
    case decrescente:
        caminho = nome_algoritmo +"/arquivodesaida/decrescente";
        endereco = caminho +"/saidadecrescente" + to_string(tamanho) + ".txt";
        break;
    }
    
    criar_pasta(caminho.c_str());
    arquivo.open(endereco); // abrir o arquivo com o endereco escolhido no switch
    
    if (!arquivo.is_open()) // Verificando se o arquivo nao foi aberto com sucesso
    {                                                   
        printf("Erro ao abrir o arquivo para escrita"); // Mensagem de erro
        return;
    }
    
    arquivo << tamanho << endl; // Anotando o tamanho na primeira linha do txt

    for (int num : vetor)
    {
        arquivo << num << endl; // salva o vetor no arquivo
    }
    arquivo.close(); // Fecha o arquivo

    cout << "Arquivo salvo no " << endereco << " com sucesso!" << endl;
}

// Funcao para salvar o tempo gasto pelo respectivo algoritmo
void salvar_tempo(formatos_opcoes ordem, int tamanho, double segundos, algoritmos_opcoes algoritmo)
{
    ofstream arquivo; // Pega as informacoes do codigo e leva para o arquivo
    string endereco;
    string caminho;
    string nome_algoritmo; // Variavel do tipo string chamada endereco
    switch (algoritmo)
    {
    case insertion_sort:
        nome_algoritmo = "insertion_sort";
        break;
    case bubble_sort:
        nome_algoritmo = "bubble_sort";
        break;
    case shell_sort:
        nome_algoritmo = "shell_sort";
        break;
    case selection_sort:
        nome_algoritmo = "selection_sort";
        break;
    case merge_sort:
        nome_algoritmo = "merge_sort";
        break;
    case quick_sort:
        nome_algoritmo = "quick_sort";
        break;
    case quick_sort_media:
        nome_algoritmo = "quick_sort_media";
        break;
    case quick_sort_mediana:
        nome_algoritmo = "quick_sort_mediana";
        break;
    case quick_sort_random:
        nome_algoritmo = "quick_sort_random";
        break;
    case heap_sort:
        nome_algoritmo = "heap_sort";
        break;
    //case
    }
    switch (ordem)
    {
    case randomico:
        caminho = nome_algoritmo +"/arquivodetempo/random";
        endereco = caminho +"/temporandom" + to_string(tamanho) + ".txt";
        break;
    case crescente:
        caminho = nome_algoritmo +"/arquivodetempo/crescente";
        endereco = caminho +"/tempocrescente" + to_string(tamanho) + ".txt";
        break;
    case decrescente:
        caminho = nome_algoritmo +"/arquivodetempo/decrescente";
        endereco = caminho +"/tempodecrescente" + to_string(tamanho) + ".txt";
        break;
    }
    
    criar_pasta(caminho.c_str());
    arquivo.open(endereco); // Abrindo o arquivo
    arquivo << "Tempo gasto: " << segundos << " em segundos" << endl; // Escrevendo dentro do arquivo o tempo gasto
    arquivo.close(); // Fecha o arquivo
    
}

#endif