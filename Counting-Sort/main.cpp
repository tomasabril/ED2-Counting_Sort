/// Tomas Abril
/// Helena Arins
/// Andre Badenas

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

//variaveis globais
int datas[1000000];

//funcoes
void lerDatas();
void countingSort();
void imprimir();

int main()
{
    lerDatas();


    return 0;
}

void lerDatas()
{
    int i;
    for(i=0; i<1000000; i++) {
        scanf("%d", &datas[i]);
    }
}

void imprimir()
{
    int i;
    for(i=0; i<1000000; i++) {
        printf("%d\n", datas[i]);
    }
}


