#include <stdio.h>
#include <stdlib.h>
#include "TADVoo.h"
#include <time.h>
#include "TADLista.h"
#include "Item_matriz.h"
#include "Matriz_Voos.h"
#include <string.h>

void Inicializa(TADVoo* Item, int hdec_min,int hdec_hora,int hpouso_min,int hpouso_hora,char aeroportodec[4],char aeroportopouso[4],int pistadec) {
    CriaVID(Item);                                                                                                      //como o VID deve ser gerado aleatoriamente, chamamos a funcao que faz isso
    Item->hdec_hora = hdec_hora;
    Item->hdec_min = hdec_min;
    Item->hpouso_hora = hpouso_hora;
    Item->hpouso_min = hpouso_min;
    strcpy(Item->aeroportodec, aeroportodec);
    strcpy(Item->aeroportopouso, aeroportopouso);
    Item->pistadec = pistadec;
    printf("\n\nO id do voo e: %d\n\n", Item->VID);
}


void CriaVID(TADVoo* Item){                                                                                             //funcao para criar um VID aleatorio
    int id;
    id=(rand() %99)+100;
    Item->VID=id;
}

void GetVID(TADVoo *voo){
    printf("Id: %d\nHorario de decolagem: %02d:%02d\nHorario de pouso: %02d:%02d\nAeroporto de decolagem: %s\nAeroporto de pouso: %s\nPista de decolagem: %d\n\n", voo->VID, voo->hdec_hora, voo-> hdec_min, voo-> hpouso_hora, voo-> hpouso_min, voo-> aeroportodec, voo-> aeroportopouso,voo -> pistadec);
}