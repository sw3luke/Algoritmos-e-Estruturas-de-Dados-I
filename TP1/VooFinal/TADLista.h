typedef struct Celula* Apontador;

typedef struct Celula {
    TADVoo Item;
    struct Celula* pProx;
} TCelula;

typedef struct {
    Apontador pPrimeiro;
    Apontador pUltimo;
} TLista;

void LInicializa(TLista* pLista);

void LInsere(TLista* pLista,int hdec_min,int hdec_hora,int hpouso_min,int hpouso_hora,char aeroportodec[4],char aeroportopouso[4],int pistadec);

void LRemove(TLista* pLista,int id);

void LProcura(TLista* pLista, int id);