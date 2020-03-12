#include <stdio.h>
#include <stdlib.h>
#include "TADVoo.h"
#include <time.h>
#include "TADLista.h"
#include "Item_matriz.h"
#include "Matriz_Voos.h"
#include <string.h>


int main() {
    int n,count2=0,id=0,vetorID[256], quantidade = 0;                                                                    //vetorID salva todas os VIDs para ser mais facil saber se eles existem ou não, quantidade marca quantos VIDs temos
    char esc;
    srand(time(NULL));
    while (n != 2) {
        printf("Digite '0' caso as insercoes sejam feitas manualmente, ou '1' para inserir atravez de um arquivo:\n");
        scanf("%d", &n);
        MatrizVoos teste;
        if (n == 0 && count2==0) {                                                                                       // cria a matriz e faz todas suas posições receberem uma celula cabeça
            InicializaMatriz(&teste);
            count2++;
        }
        if (n==0) {               // caso de inserção manual
            printf("Operacoes disponiveis:\nb) Inserir voo\nc) Remover voo\nd)Procurar voo\ne) Imprimir voos de acordo com horario de decolagem e pouso\nf)Imprimir voos de acordo com hora de decolagem\ng) Imprimir voos de acordo com hora de pouso\nh) Imprimir toda a matriz\ni) Encontrar faixa de horario de decolagem e previsao de pouso com maior numero de voos cadastrados\nj)  Encontrar faixa de horario de decolagem e previsao de pouso com menor numero de voos cadastrados\nk) Encontrar lista de voos mais recentemente alterada\nl) Encontrar lista de voos menos recentemente alterada\nm) Verificar se matriz é esparça\n");

            while(esc != 'z') {                                                                                         //dentro desse while é identificado qual operação o usuario deseja e a partir disso chamará a função apropriada
                scanf("%c", &esc);

                if (esc == 'b'){                                                                                        //inserir
                    int hdec_min,hdec_hora,hpouso_min,hpouso_hora,pistadec;
                    char aeroportodec[4],aeroportopouso[4];
                    printf("Digite os dados do voo:\n");
                    scanf("%d:%d %d:%d %s%s %d",&hdec_hora ,&hdec_min,&hpouso_hora,&hpouso_min ,aeroportodec,aeroportopouso,&pistadec);
                    if (pistadec<10)                                                                                    //10 é o numero de pistas de decolagem
                        MVInserir(&teste,hdec_min,hdec_hora,hpouso_min,hpouso_hora,aeroportodec,aeroportopouso,pistadec);
                    else {                                                                                              //se o numero da pista inserido for maior que 10 o usuario tem que inserir novamente os dados
                        printf("\nNumero de pista nao encontrado!\n");
                    }
                    vetorID[quantidade]=teste.Matriz[hdec_hora][hpouso_hora].ListaV.pUltimo->Item.VID;                  // salva o ID inserido no vetorID
                    quantidade++;
               }

                else if(esc == 'c') {                                                                                   //remover
                    int i, count=0;                                                                                     // count para saber se o ID foi encontrado pelo menos uma vez
                    printf("Digite o id do voo a remover: ");
                    scanf("%d", &id);
                    for (i = 0; i < quantidade; i++) {
                        if (id == vetorID[i]) {                                                                         // verifica se o ID pedido ja foi inserido em algum momento ou não
                            MVRemover(&teste, id);
                            quantidade--;
                            count++;
                            vetorID[i]=0;                                                                               //retira o ID do vetor armazenador de IDs
                            break;
                        }
                    }
                    if (count == 0)
                        printf("\nVOO NAO ENCONTRADO\n");
                }


                else if(esc == 'd'){                                                                                    //procurar por ID
                    int i, count=0;                                                                                     // count para saber se o ID foi digitado alguma vez ou não
                    printf("Digite o id do voo a procurar: ");
                    scanf("%d",&id);
                    for(i = 0; i < quantidade; i++){
                        if(id == vetorID[i]){                                                                           //verifica se o ID ja foi digitado anteriormente
                            MVProcurar(&teste,id);
                            count++;
                            vetorID[i]=0;                                                                               //retira o ID do vetor armazenador de IDs
                            break;
                        }
                    }
                    if(count==0)
                        printf("\nVOO NAO ENCONTRADO\n");
                }

                else if(esc == 'e'){                                                                                    // imprime por horario de decolagem e pouso
                    int hdec_hora,hdec_min,hpouso_min,hpouso_hora;
                    printf("Digite a hora de decolagem e pouso do voo: ");
                    scanf("%d:%d %d:%d",&hdec_hora,&hdec_min,&hpouso_hora,&hpouso_min);
                    MVImprimir1(&teste,hdec_hora,hpouso_hora);                                                          //passamos hdec_hora e hpouso_hora como parametro para poder utiliza-los como indices da matriz
                }

                else if(esc == 'f'){                                                                                    // imprime todos os voos que decolam no horario
                    int hdec_hora,hdec_min;
                    printf("Digite a hora de decolagem do voo: ");
                    scanf("%d:%d",&hdec_hora,&hdec_min);
                    MVImprimir2(&teste,hdec_hora);                                                                      //passamos hdec_hora como parametro para poder utilizar como indice [i] da matriz
                }

                else if(esc == 'g'){                                                                                    //imprime todos os voos que pousam no horario
                    int hpouso_hora,hpouso_min;
                    printf("Digite a hora de pouso do voo: ");
                    scanf("%d:%d",&hpouso_hora,&hpouso_min);
                    MVImprimir3(&teste,hpouso_hora);                                                                    //passamos hpouso_hora como parametro para poder utilizar como indice [j] da matriz
                }

                else if(esc == 'h')                                                                                     //imprime toda matriz
                    MVImprimir4(&teste);

                else if(esc == 'i')                                                                                     //imprime posição com maior numero de voos
                    MVEncontrar1(&teste);

                else if(esc == 'j')                                                                                     //imprime posição com menor numero de voos
                    MVEncontrar2(&teste);

                else if(esc == 'k')                                                                                     //imprime posição que foi alterada mais recentemente
                    MVEncontrar3(&teste);

                else if(esc == 'l')                                                                                     //imprime posição que foi alterada menos recentemente
                    MVEncontrar4(&teste);

                else if(esc == 'm')                                                                                     //verifica se é esparça
                    MVVerificar(&teste);

                else if(esc == 'z')                                                                                     // encerra a inserção manual
                    printf("Programa encerrado!");
            }





            //Para o caso de arquivo, sempre que encontrarmos "- 48" estaremos realizando a conversão através da tabela ASCII


        } else if (n == 1) {                                                                                            //caso de inserção por arquivo
            FILE *Arquivo = NULL;
            char nFile[50], linha[24], option;                                                                          //option lê a primeira letra de cada linha para saber qual opção escolhida pelo usuario
            char a_pous[4] = {'\0'}, a_dec[4] = {'\0'}, VID[3];
            int i = 0,i2=0, k = 0, count, j, ih_dec = 0, ih_pous = 0, im_dec = 0, im_pous = 0, hdez_dec = 0, huni_dec = 0, mdez_dec = 0, muni_dec = 0, hdez_pous = 0, huni_pous = 0, mdez_pous = 0, muni_pous = 0, pista = 0;
            scanf("%s", nFile);
            Arquivo = fopen(nFile, "r");
            while (!feof(Arquivo)) {
                printf("\n------------------------------------------------------------------------------\n");
                fgets(linha, 24, Arquivo);
                printf("LINHA ATUAL: %s\n", linha);
                option = linha[0];
                printf("FIRST CHAR: %c\n", option);
                if (option == 'a' && count2==0) {                                                                       //cria a matriz para o caso de arquivo e faz todas as suas posições receberem uma celula cabeça
                    fInicializaMatriz(&teste);
                    count2++;
                    printf("a\n");
                } else if (option == 'b') {
                    printf("\n--------------------\n");
                    hdez_dec = ((int) linha[2] - 48) * 10;
                    huni_dec = ((int) linha[3] - 48);
                    mdez_dec = ((int) linha[5] - 48) * 10;
                    muni_dec = ((int) linha[6] - 48);
                    hdez_pous = ((int) linha[8] - 48) * 10;
                    huni_pous = ((int) linha[9] - 48);
                    mdez_pous = ((int) linha[11] - 48) * 10;
                    muni_pous = ((int) linha[12] - 48);
                    pista = (int) linha[22] - 48;
                    ih_dec = hdez_dec + huni_dec;
                    im_dec = mdez_dec + muni_dec;
                    ih_pous = hdez_pous + huni_pous;
                    im_pous = mdez_pous + muni_pous;
                    i = 0;
                    for (j = 14; j < 17; j++) {
                        a_dec[i] = linha[j];
                        i++;
                    }
                    i2=0;
                    for (k = 18; k < 21; k++) {
                        a_pous[i2]= linha[k];
                        i2++;
                    }
                    IMInsere(&teste.Matriz[ih_dec][ih_pous],im_dec,ih_dec,im_pous,ih_pous,a_dec,a_pous,pista);
                    vetorID[quantidade] = teste.Matriz[ih_dec][ih_pous].ListaV.pUltimo->Item.VID;
                    quantidade++;
                    printf("VOO INSERIDO\n");
                } else if (option == 'c') {
                    count = 0;
                    int azul;
                    for (i = 2; i < 4; i++) {
                        VID[count] = linha[i];
                        count++;
                    }
                    int iVID = ((int) VID - 48);
                    for( azul = 0; azul < quantidade; azul++){
                        if(iVID == vetorID[azul]){
                            MVRemover(&teste, iVID);
                            break;
                        }
                        else if(azul == quantidade - 1 && iVID != vetorID[quantidade - 1]){
                            printf("\nVOO NAO ENCONTRADO\n");
                        }
                    }
                    ;
                } else if (option == 'd') {
                    count = 0;
                    int azul;
                    for (i = 2; i < 4; i++) {                                                                           //quantidade de caracteres da ID se for maior favor alterar aqui;
                        VID[count] = linha[i];
                        count++;
                    }
                    int iVID = ((int) VID - 48);
                    for( azul = 0; azul < quantidade; azul++){
                        if(iVID == vetorID[azul]){
                            MVProcurar(&teste, iVID);
                            break;
                        }
                        else if(azul == quantidade - 1 && iVID != vetorID[quantidade - 1]){
                            printf("\nVOO NAO ENCONTRADO\n");
                        }
                    }
                } else if (option == 'e') {
                    hdez_dec = ((int) linha[2] - 48) * 10;
                    huni_dec = ((int) linha[3] - 48);
                    mdez_dec = ((int) linha[5] - 48) * 10;
                    muni_dec = ((int) linha[6] - 48);
                    hdez_pous = ((int) linha[8] - 48) * 10;
                    huni_pous = ((int) linha[9] - 48);
                    mdez_pous = ((int) linha[11] - 48) * 10;
                    muni_pous = ((int) linha[12] - 48);
                    ih_dec = hdez_dec + huni_dec;
                    im_dec = mdez_dec + muni_dec;
                    ih_pous = hdez_pous + huni_pous;
                    im_pous = mdez_pous + muni_pous;
                    MVImprimir1(&teste, ih_dec, ih_pous);
                } else if (option == 'f') {
                    hdez_dec = ((int) linha[2] - 48) * 10;
                    huni_dec = ((int) linha[3] - 48);
                    mdez_dec = ((int) linha[5] - 48) * 10;
                    muni_dec = ((int) linha[6] - 48);
                    ih_dec = hdez_dec + huni_dec;
                    im_dec = mdez_dec + muni_dec;
                    MVImprimir2(&teste, ih_dec);
                } else if (option == 'g') {
                    hdez_pous = ((int) linha[2] - 48) * 10;
                    huni_pous = ((int) linha[3] - 48);
                    mdez_pous = ((int) linha[5] - 48) * 10;
                    muni_pous = ((int) linha[6] - 48);
                    ih_pous = hdez_pous + huni_pous;
                    im_pous = mdez_pous + muni_pous;
                    MVImprimir3(&teste, ih_pous);
                } else if (option == 'h') {
                    MVImprimir4(&teste);
                } else if (option == 'i') {
                    MVEncontrar1(&teste);
                } else if (option == 'j') {
                    MVEncontrar2(&teste);
                } else if (option == 'k') {
                    MVEncontrar3(&teste);
                } else if (option == 'l') {
                    MVEncontrar4(&teste);
                } else if (option == 'm') {
                    MVVerificar(&teste);
                }
                printf("\n------------------------------------------------------------------------------\n");
            }

            fclose(Arquivo);
        }

    }
    return 0;
}