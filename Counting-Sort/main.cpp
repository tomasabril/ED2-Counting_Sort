/// Tomas Abril
/// Helena Arins
/// Andre Badenas

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

//#define TAM 1000000 // Quantas datas ler
#define TAM 10

//variaveis globais
int a[TAM+1];         // vetor a ser ordenado
int b[TAM+1];         // vetor ordenado
int *c;                 // vetor auxiliar de tamanho k que quarda o numero de ocorrencias de elementos i em a
int n = TAM;        // quantidade de numeros a serem ordenados
int k=0;                // maior numero da lista

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
    int i;
    for(i=1; i<TAM+1; i++) {
        scanf("%d", &a[i]);
        if(a[i] > k) {
            k = a[i];
        }
    }
    c = (int *)malloc(1 + k * sizeof(int));
}

void imprimir()
{
    printf("\n");
    int i;
    for(i=1; i<TAM+1; i++) {
        printf("%d\n", b[i]);
    }
}

void countingSort()
{
    int i,j;
    for(i=1; i <= k; i++) {
        c[i] = 0;
    }
    for(j=1; j < n+1; j++) {
        c[a[j]] = c[a[j]] + 1;
    }
    for(i=2; i<=k; i++) {
        c[i] = c[i] + c[i-1];
    }
    for(j=n; j>=1; j--) {
        b[c[a[j]]] = a[j];
        c[a[j]] = c[a[j]] - 1;
    }
}


