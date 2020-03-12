#include <stdio.h>
#include <stdlib.h>
#include "TADVoo.h"
#include <time.h>
#include "TADLista.h"
#include "Item_matriz.h"
#include "Matriz_Voos.h"
#include <string.h>

void InicializaMatrizDinamica(MatrizVoos *mv){                                                                              //aloca o espaco no heap para a matriz
    int i;
    mv -> Matriz = (ItemMatriz **)malloc(576*sizeof(ItemMatriz));
    for(i=0; i<24; i++){
        mv -> Matriz[i] = (ItemMatriz *)malloc(24*sizeof(ItemMatriz));
    }
}

void fInicializaMatriz(MatrizVoos *mv) {
    int i, j;
    InicializaMatrizDinamica(mv);
    for (i = 0; i < 24; i++) {
        for (j = 0; j < 24; j++) {
            IMInicializa(&(mv->Matriz[i][j]));
        }
    }
}

void InicializaMatriz(MatrizVoos *mv){
    int i, j;
    InicializaMatrizDinamica(mv);
    for(i=0; i<24; i++){
        for(j=0; j<24; j++){
            IMInicializa(&(mv -> Matriz[i][j]));
        }
    }

}

void MVInserir(MatrizVoos *mv,int hdec_min,int hdec_hora,int hpouso_min,int hpouso_hora,char aeroportodec[4],char aeroportopouso[4],int pistadec){   //operação b
        IMInsere(&mv->Matriz[hdec_hora][hpouso_hora],hdec_min,hdec_hora,hpouso_min,hpouso_hora,aeroportodec,aeroportopouso,pistadec);
}

void MVRemover(MatrizVoos *mv,int id){                                                                                  //operação c
    int i,j;
    for(i = 0; i < 24; i++){
        for(j = 0; j < 24; j++) {
            if(mv->Matriz[i][j].ListaV.pPrimeiro->pProx!=NULL)
                IMRemove(&(mv->Matriz[i][j]),id);
        }
    }
    printf("\nVOO REMOVIDO\n\n");
}

void MVProcurar(MatrizVoos *mv,int id){                                                                                 //operação d
    int i,j;
    for(i = 0; i < 24; i++) {
        for (j = 0; j < 24; j++) {
            if (mv->Matriz[i][j].ListaV.pPrimeiro->pProx != NULL)
                LProcura(&(mv->Matriz[i][j].ListaV), id);
        }
    }
}

void MVImprimir1(MatrizVoos *mv,int hdec_hora,int hpouso_hora){                                                         //operação e
    Apontador paux;
    int count=0;
    paux=mv->Matriz[hdec_hora][hpouso_hora].ListaV.pPrimeiro->pProx;                                                    //como a matriz esta organizada por horario, definimos a posição diretamente pelo horario que foi
    while(paux!=NULL){                                                                                                  // fornecido pelo usuario
        GetVID(&(paux->Item));
        count++;                                                                                                        //usa-se o count para saber se existe ou nao um voo no horario pedido
        paux=paux->pProx;
    }
    if(count==0)
        printf("\nNenhum voo encontrado!\n");
}

void MVImprimir2(MatrizVoos *mv,int hdec_hora){                                                                         //operação f
    int j,count=0;
    Apontador paux;
    for(j = 0; j < 24; j++){
        paux = mv-> Matriz[hdec_hora][j].ListaV . pPrimeiro ->pProx;                                                    //aqui colocamos apenas o horario de decolagem diretamente no indice linha, pois podemos ter qualquer
        while(paux != NULL){                                                                                            //horario de pouso, entao percorremos toda as colunas dessa linha verificando se existe ou nao
            GetVID(&(paux -> Item));                                                                                    //algum voo nelas.
            count++;
            paux = paux -> pProx;                                                                                       // novamente count utilizado para saber se existe algum voo no horario pedido
        }
    }
    if(count==0)
        printf("\nNenhum voo encontrado!\n");
}

void MVImprimir3(MatrizVoos *mv,int hpouso_hora){                                                                       //operação g
    int i,count=0;
    Apontador paux;
    for(i = 0; i < 24; i++){
        paux = mv->Matriz[i][hpouso_hora].ListaV . pPrimeiro -> pProx;                                                  //mesmo caso do MVImprimir2, porem agora colocamos apenas o horario de decolagem no indice coluna
        while(paux != NULL){                                                                                            // count utilizado do mesmo modo de MVImprimir2 também
            GetVID(&(paux->Item));
            count++;
            paux = paux -> pProx;
        }
    }
    if(count==0)
        printf("\nNenhum voo encontrado!\n");
}

void MVImprimir4(MatrizVoos *mv) {                                                                                      //operação h
    Apontador paux;
    int i, j,count=0;                                                                                                   //utilizamos o count para saber se a matriz nao possui nenhuma posicao preenchida, ou seja, é vazia
    for (i = 0; i < 24; i++) {
        for (j = 0; j < 24; j++) {
            paux = mv->Matriz[i][j].ListaV.pPrimeiro->pProx;
            while (paux != NULL) {
                GetVID(&(paux->Item));
                count++;
                paux = paux->pProx;
            }
        }
    }
    if (count==0)
        printf("\nMatriz vazia!\n");
}

void MVEncontrar1(MatrizVoos *mv){                                                                                      // operação i
    int i,j,iM = 0,jM = 0,count = 0,comp = 0;                                                                           //iM guarda o indice i com maior numero de voos, jM guarda o indice j com maior numero de voos
    for(i = 0; i< 24; i++){                                                                                             // count recebe a quantidade de voos de todas as posicoes, enquanto comp recebe apenas o valor daquelas que tiverem mais voos
        for(j = 0; j < 24; j++){                                                                                        // que a antiga
            count=mv->Matriz[i][j].NumeroVoos;
            if(count > comp){
                comp = count;
                iM = i;
                jM = j;
            }
            else{
                continue;
            }
        }
    }
    printf("A maior quantidade de voos em uma faixa de horario e %d, e eles estao nos indices\n i: %d\n j: %d \n", comp, iM, jM);
}

void MVEncontrar2(MatrizVoos *mv){      //operação j                                                                    funciona basicamente como a MVEncontra1
    int i,j,iMenor = 0,jMenor = 0,count = 0,comp;
    for(i = 0; i< 24; i++){
        for(j = 0; j<24; j++){
            count=mv->Matriz[i][j].NumeroVoos;
            if(i==0 && j==0)                                                                                            //unica diferenca para o MVEncontrar1, precisa desse if pois caso a posicao [0][0] tenha pelo menos 1 voo é preciso que o valor de comp
                comp=count;                                                                                             // seja alterado, ou iMenor e jMenor nunca irão mudar
            if(count < comp){
                comp = count;
                iMenor=i;
                jMenor=j;
            }
            else{
                continue;
            }
            count = 0;
        }
    }
    printf("A menor quantidade de voos em uma faixa de horario e %d, e eles estao nos indices \n i: %d\n j: %d\n", comp, iMenor, jMenor);
}

void MVEncontrar3(MatrizVoos *mv){                                                                                      //operação k
    int i,j, salvai, salvaj;
    Tempo maior;
    maior.hora=0;
    maior.minuto=0;
    maior.segundo=0;
    salvai=0;
    salvaj=0;
    for (i=0; i<24;i++) {
        for (j = 0; j < 24; j++) {
            if(i==0 && j==0){
                maior.hora = mv->Matriz[i][j].UltimaHr.hora;
                maior.minuto = mv->Matriz[i][j].UltimaHr.minuto;
                maior.segundo = mv->Matriz[i][j].UltimaHr.segundo;
                salvai = i;
                salvaj = j;
            }
            else if (mv->Matriz[i][j].UltimaHr.hora > maior.hora || (mv->Matriz[i][j].UltimaHr.hora == maior.hora && mv->Matriz[i][j].UltimaHr.minuto >= maior.minuto && mv->Matriz[i][j].UltimaHr.segundo >= maior.segundo)) {
                maior.hora = mv->Matriz[i][j].UltimaHr.hora;
                maior.minuto = mv->Matriz[i][j].UltimaHr.minuto;
                maior.segundo = mv->Matriz[i][j].UltimaHr.segundo;
                salvai = i;
                salvaj = j;
            }
        }
    }
    printf("Posicao[i]= %d\nPosicao[j]= %d\nHorario= %02d:%02d:%02d\n", salvai, salvaj, maior.hora, maior.minuto, maior.segundo);

}

void MVEncontrar4(MatrizVoos *mv){                                                                                      //operação l
    int i,j, salvai, salvaj;
    Tempo menor;
    for (i=0; i<24;i++){
        for(j=0; j<24;j++){
            if(i==0 && j==0){
                menor.hora=mv->Matriz[i][j].UltimaHr.hora;
                menor.minuto=mv->Matriz[i][j].UltimaHr.minuto;
                menor.segundo=mv->Matriz[i][j].UltimaHr.segundo;
                salvai=i;
                salvaj=j;
            }
            else if(mv->Matriz[i][j].UltimaHr.hora<menor.hora || (mv->Matriz[i][j].UltimaHr.hora==menor.hora && mv->Matriz[i][j].UltimaHr.minuto<=menor.minuto && mv->Matriz[i][j].UltimaHr.segundo<=menor.segundo)){
                menor.hora=mv->Matriz[i][j].UltimaHr.hora;
                menor.minuto=mv->Matriz[i][j].UltimaHr.minuto;
                menor.segundo=mv->Matriz[i][j].UltimaHr.segundo;
                salvai=i;
                salvaj=j;
            }
        }
    }
    printf("Posicao[i]= %d\nPosicao[j]= %d\nHorario= %02d:%02d:%02d\n", salvai, salvaj, menor.hora, menor.minuto, menor.segundo);

}

void MVVerificar(MatrizVoos *mv){                                                                                       //operação m
    int count0=0, count1=0, i, j;                                                                                       //count0 conta quantas posicoes estão vazias e count1 conta quantas posicoes possuem pelo menos 1 voo
    for(i=0; i<24; i++){
        for(j=0; j<24;j++){
            if (mv->Matriz[i][j].ListaV.pPrimeiro->pProx==NULL)
                count0++;
            else if (mv->Matriz[i][j].ListaV.pPrimeiro->pProx!=NULL)
                count1++;
        }
    }
    if (count0>=(2*count1))
        printf("E esparca");
    else
        printf("Nao e esparca");
}
