#ifndef INCLUDE_INTERFACE_H
#define INCLUDE_INTERFACE_H

typedef enum{
    insertion_sort,
    bubble_sort,
    shell_sort,
    selection_sort,
    merge_sort,
    quick_sort,
    quick_sort_media,
    quick_sort_mediana,
    quick_sort_random,
    heap_sort,
}algoritmos_opcoes;

typedef enum{
    randomico,
    crescente,
    decrescente,
}formatos_opcoes;

int escolha_formato(void); // É uma funcao do tipo inteiro para a escolha do formato que tem como parametro void
int escolha_tamanho(void); // É uma funcao do tipo inteiro para a escolha do tamanho que tem como parametro void
void interface_algoritmo(algoritmos_opcoes algoritmos, formatos_opcoes formatos, int tamanhos); // Uma funcao para mostrar as informaoes do algoritmo selecionado

#endif