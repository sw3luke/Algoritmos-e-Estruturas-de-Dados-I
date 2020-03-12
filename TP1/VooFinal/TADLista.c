#include <stdio.h>
#include <stdlib.h>
#include "TADVoo.h"
#include <time.h>
#include "TADLista.h"
#include "Item_matriz.h"
#include "Matriz_Voos.h"
#include <string.h>

void LInicializa(TLista* pLista){                                                                                       //cria celula cabeca
    pLista->pPrimeiro=(Apontador)malloc(sizeof(TCelula));
    pLista->pUltimo=pLista->pPrimeiro;
    pLista->pPrimeiro->pProx=NULL;
}

void LInsere(TLista* pLista,int hdec_min,int hdec_hora,int hpouso_min,int hpouso_hora,char aeroportodec[4],char aeroportopouso[4],int pistadec){  //insere nova celula na lista
    pLista->pUltimo->pProx=(Apontador)malloc(sizeof(TCelula));
    pLista->pUltimo=pLista->pUltimo->pProx;
    pLista->pUltimo->pProx=NULL;
    Inicializa(&(pLista->pUltimo->Item),hdec_min,hdec_hora,hpouso_min,hpouso_hora,aeroportodec,aeroportopouso,pistadec); //chama funcao para preencher o campo item
}

void LRemove(TLista* pLista,int id){
    Apontador pAux,pAux2;
    pAux=pLista->pPrimeiro->pProx;                                                                                      //o que vai ser removido
    pAux2=pLista->pPrimeiro;                                                                                            //o anterior ao que vai ser removido
    while(id!=pAux->Item.VID){                                                                                          //procura o voo que tem o id desejado
        pAux=pAux->pProx;
        pAux2=pAux2->pProx;
        if (pAux==NULL)
            return;
    }
    if (pAux->pProx==NULL){
        pAux2->pProx=NULL;
        pLista->pUltimo=pAux2;
    }
    else{
        pAux2->pProx=pAux->pProx;
    }
    free(pAux);
}

void LProcura(TLista* pLista,int id){
    Apontador pAux;
    pAux=pLista->pPrimeiro->pProx;
    while(id != pAux->Item.VID){
        pAux=pAux->pProx;
        if (pAux==NULL)
            return;
    }
        GetVID(&(pAux->Item));                                                                                          // chama funcao que imprime as informacoes do voo
}