typedef struct{
    ItemMatriz **Matriz;
    char data[10];
    int NumeroTotalV;
    char UltimaHr2[5];
}MatrizVoos;

void MVInserir(MatrizVoos *mv,int hdec_min,int hdec_hora,int hpouso_min,int hpouso_hora,char aeroportodec[4],char aeroportopouso[4],int pistadec);

void MVRemover(MatrizVoos *mv,int id);

void MVProcurar(MatrizVoos *mv,int id);

void MVImprimir1(MatrizVoos *mv,int hdec_hora,int hpouso_hora);

void MVImprimir2(MatrizVoos *mv,int hdec_hora);

void MVImprimir3(MatrizVoos *mv,int hpouso_hora);

void MVImprimir4(MatrizVoos *mv);

void MVEncontrar1(MatrizVoos *mv);

void MVEncontrar2(MatrizVoos *mv);

void MVEncontrar3(MatrizVoos *mv);

void InicializaMatrizDinamica(MatrizVoos *mv);

void MVEncontrar4(MatrizVoos *mv);

void MVVerificar(MatrizVoos *mv);

void InicializaMatriz(MatrizVoos *mv);

void fInicializaMatriz(MatrizVoos *mv);