typedef struct {
    int VID;
    int hdec_hora;
    int hdec_min;
    int hpouso_hora;
    int hpouso_min;
    char aeroportodec[4];
    char aeroportopouso[4];
    int pistadec;
} TADVoo;

void CriaVID(TADVoo *Item);

void Inicializa(TADVoo* Item, int hdec_min,int hdec_hora,int hpouso_min,int hpouso_hora,char aeroportodec[4],char aeroportopouso[4],int pistadec);

void GetVID(TADVoo *voo);

