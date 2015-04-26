/// Tomas Abril
/// Helena Arins
/// Andre Badenas

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;
//_________1.000.000
#define TAM 1000000 // Quantas datas ler
//#define TAM 3

//variaveis globais
int a[TAM];         // vetor a ser ordenado
int b[TAM];         // vetor ordenado
int *c;                 // vetor auxiliar de tamanho k que quarda o numero de ocorrencias de elementos i em a
int n = TAM;        // quantidade de numeros a serem ordenados
int k = 0;                // maior numero da lista

//funcoes
void lerDatas();
void countingSort();
void imprimir();

int main()
{
    lerDatas();
    countingSort();
    imprimir();

    return 0;
}

void lerDatas()
{
    printf("comecou\n");
    int i;
    for(i=0; i<TAM; i++) {
        scanf("%d", &a[i]);
        if(a[i] > k) {
            k = a[i];
        }
    }
    printf("\n leu todas as datas \n maior numero e: %d", k);
    c = (int *)malloc(1 + k * sizeof(int));
    printf("\nalocou vetor\n");
}

void imprimir()
{
    printf("\ndatas ordenadas\n");
    int i;
    for(i=0; i<TAM; i++) {
        printf("%d\n", b[i]);
    }
}

void countingSort()
{
    int i,j;
    for(i=0; i <= k; i++) {
        c[i] = 0;
    }
    printf("\nfor1");
    for(j=0; j < n; j++) {
        c[a[j]] ++;
    }
    printf("\nfor2");
    for(i=1; i<=k; i++) {
        c[i] += c[i-1];
    }
    printf("\nfor3");
    for(j=n-1; j>=0; j--) {
        b[c[a[j]]] = a[j];
        c[a[j]] --;
    }
    printf("\nfor4");
}


