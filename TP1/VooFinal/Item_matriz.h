typedef struct{
    int hora, minuto, segundo;
}Tempo;                                                                                                                 //define esse tipo para facilitar a declaracao do UltimaHr no ItemMatriz

typedef struct{
    TLista ListaV;
    int NumeroVoos;
    Tempo UltimaHr;
}ItemMatriz;


void IMInicializa(ItemMatriz* pMatriz);

void IMInsere(ItemMatriz* pMatriz, int hdec_min,int hdec_hora,int hpouso_min,int hpouso_hora,char aeroportodec[4],char aeroportopouso[4],int pistadec);

void TempoAtual(ItemMatriz* pMatriz);                                                                                   // funcao para pegar o tempo atual do sistema e inserir em UltimaHr

void IMRemove(ItemMatriz* pMatriz, int id);