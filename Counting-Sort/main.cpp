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
//#define TAM 5

int d=1;            /// 0 saidas de debug. 1 saida padrao
int arq=1;          /// 0 abrir arquivo. 1 entrada padrao

//variaveis globais
int a[TAM];         // vetor a ser ordenado
int b[TAM];         // vetor ordenado
//int *c;                 // vetor auxiliar de tamanho k que quarda o numero de ocorrencias de elementos i em a
int c[20501231];
int n = TAM;        // quantidade de numeros a serem ordenados
int k = 0;                // maior numero da lista

//funcoes
void lerDatas();
void lerDatasArq();
void countingSort();
void imprimir();

int main()
{
    d ? :printf("size_t: %d\n", sizeof(size_t));
    arq ? lerDatas() : lerDatasArq();
    countingSort();
    imprimir();

    return 0;
}

void lerDatasArq()
{
    d ? :printf("comecou\n");
    char url[]="datas.txt";
    int i=0;
    char palavra[10];

    FILE *arq;
    arq = fopen(url, "r");

    while(!feof(arq) && i < TAM) {
        if(fgets(palavra, 10, arq)>0) {
            a[i] = atoi(palavra);
            if(a[i] > k) {
                k = a[i];
            }
            i++;
        }

    }

    d ? :printf("\n leu todas as datas \n o maior numero e: %d", k);
    k+=8;
    d ? :printf("\nk: %d\n", k);

//    if (NULL == (c = (int *)malloc( (k)*sizeof(int) ) ) ) {
//        printf("malloc failed\n");
//    }

    d ? :printf("\n alocou vetor\n");
    d ? :printf("\n c[0]= %d\n c[1]= %d\n c[k]= %d\nc [k-1]= %d\n", c[0], c[1], c[k], c[k-1]);
    fclose(arq);
}

void lerDatas()
{
    d ? :printf("comecou\n");
    int i;
    for(i=0; i<TAM; i++) {
        scanf("%d", &a[i]);
        if(a[i] > k) {
            k = a[i];
        }
    }
    d ? :printf("\n leu todas as datas \n o maior numero e: %d", k);
    k+=8;
    d ? :printf("\nk: %d\n", k);

    //if (NULL == (c = (int *)malloc( (k)*sizeof(int) ) ) ) {
    //    printf("malloc failed\n");
    //}

    d ? :printf("\n alocou vetor\n");
    d ? :printf("\n c[0]= %d\n c[1]= %d\n c[k]= %d\nc [k-1]= %d\n", c[0], c[1], c[k], c[k-1]);
}

void imprimir()
{
    d ? :printf("\ndatas ordenadas\n");
    int i;
    for(i=0; i<TAM; i++) {
        printf("%d\n", b[i]);
    }
    if (!d) {
        printf("\ndatas originais\n");
        for(i=0; i<TAM; i++) {
            printf("%d\n", a[i]);
        }
    }
}

void countingSort()
{
    int i,j;
    for(i=0; i <= k; i++) {
        c[i] = 0;
    }
    d ? :printf("\nfor1");
    for(j=0; j < n; j++) {
        c[a[j]]++;
    }
    d ? :printf("\nc[k]=%d\nc[k-1]=%d\n", c[k], c[k-1]);
    d ? :printf("\nfor2");

    i=1;
    for(i=1; i <= k; i++) {
        //d ? :printf("\nc[%d]=%d", i, c[i]);
        c[i] += c[i-1];
    }

    d ? :printf("\nfor3");

    for(j=n-1; j>=0; j--) {
        b[c[a[j]]-1] = a[j];
        c[a[j]]--;
    }

    d ? :printf("\nfor4");
    //free(c);
}
