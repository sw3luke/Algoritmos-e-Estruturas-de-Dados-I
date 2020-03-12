#include <stdio.h>
#include <stdlib.h>
#include "TADVoo.h"
#include <time.h>
#include "TADLista.h"
#include "Item_matriz.h"
#include "Matriz_Voos.h"

void IMInicializa(ItemMatriz* pMatriz){                                                                                 //cria uma celula cabeca pra cada posicao da matriz
    pMatriz->NumeroVoos=0;
    LInicializa(&(pMatriz->ListaV));
    TempoAtual(pMatriz);
}

void IMInsere(ItemMatriz* pMatriz, int hdec_min,int hdec_hora,int hpouso_min,int hpouso_hora,char aeroportodec[4],char aeroportopouso[4],int pistadec){
    pMatriz->NumeroVoos++;
    LInsere(&(pMatriz->ListaV),hdec_min,hdec_hora,hpouso_min,hpouso_hora,aeroportodec,aeroportopouso,pistadec);
    TempoAtual(pMatriz);
}

void TempoAtual(ItemMatriz* pMatriz){
    time_t now;                                                                                                         //função da biblioteca <time.h>
    time(&now);                                                                                                         //função da bibliotece <time.h>
    struct tm *local=localtime(&now);
    pMatriz->UltimaHr.hora= local->tm_hour;
    pMatriz->UltimaHr.minuto=local->tm_min;
    pMatriz->UltimaHr.segundo=local->tm_sec;
}

void IMRemove(ItemMatriz *pMatriz, int id){
    pMatriz->NumeroVoos--;
    LRemove(&(pMatriz->ListaV),id);
    TempoAtual(pMatriz);
}
