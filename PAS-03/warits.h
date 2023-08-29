
#include "tools.h"
#define ISTRI 0
#define SUAMI 1
#define IBU 2
#define BAPAK 3
#define ANAK_LAKI 4
#define ANAK_PEREMPUAN 5


typedef struct{
    int id;
    float bagian;
    int min;
    int max;
    int jumlah;
    float hartaTotal;
    float hartaIndividual;
} Warits;

/*
    id:
    istri = 0
    suami = 1
    ayah kandung = 2
    ibu kandung = 3
    anak laki-laki = 4
    anak perempuan = 5
*/

// Pass by reference, 0
void modifyWarits(Warits *pWarits, int pId, int pJumlah){
    pWarits->id = pId;
    pWarits->bagian = 0;
    pWarits->min = 0;

    switch(pId){
    case ISTRI:
        pWarits->max = 4;
        break;
    case ANAK_LAKI ... ANAK_PEREMPUAN:
        pWarits->max = -1;
        break;
    default:
        pWarits->max = 1;
        break;
    }
    
    pWarits->jumlah = clampInt(pJumlah, pWarits->min, pWarits->max);
    pWarits->hartaIndividual = 0;
    pWarits->hartaTotal = 0;
}


const char *idParser(int id){
    switch(id){
        case ISTRI:
            return "Istri";
        case SUAMI:
            return "Suami";
        case ANAK_PEREMPUAN:
            return "Anak perempuan";
        case ANAK_LAKI:
            return "Anak laki-laki";
        case IBU:
            return "Ibu kandung";
        case BAPAK:
            return "Ayah kandung";
        default:
            return "Invalid";
    }
}

void printWarits(Warits pWarits){
    printf("\nNama Warits: %s", idParser(pWarits.id));
    printf("\nBagian: %.3f", pWarits.bagian);
    printf("\nJumlah: %d", pWarits.jumlah);
    printf("\nHarta Total: Rp%.3f", pWarits.hartaTotal);
    printf("\nHarta Individual: Rp%.3f", pWarits.hartaIndividual);
    printf("\n");
}

// 0
int isPresent(Warits *warits, int pJumlahWarits, int pId){  //Untuk suami dan istri
    for(int i = 0; i < pJumlahWarits; i++){
        if(warits[i].id == pId){
            return 1;
        }
    }
    return 0; // 0 = gaada, 1 = ada
}

// 0
int getCount(Warits *warits, int pJumlahWarits, int pId){
    for(int i = 0; i < pJumlahWarits; i++){
        if(warits[i].id == pId){
            return warits[i].jumlah; 
        }
    }
    return 0;
}

// i
void hitungBagian(Warits *pWarits, float pBagian, float *pAshobah){
    pWarits->bagian = pBagian;
    if (pAshobah != NULL){
        float a = *pAshobah; //Kalau ada Ashobah, maka dimasukkan ke perhitungan
        a -= pBagian;
        *pAshobah = a;
    }
}

// i
void hitungHarta(Warits *pWarits, float pHarta){
    pWarits->hartaTotal = pHarta * pWarits->bagian;
    pWarits->hartaIndividual = pWarits->hartaTotal / pWarits->jumlah;
}

// ptrWarits[0]
float hitungAshobah(Warits *pWarits, int pJumlahWarits, float pAshobah, int pMode){
    int jumlahLaki = getCount(pWarits, pJumlahWarits, ANAK_LAKI); // misal 2
    int jumlahPerempuan = getCount(pWarits, pJumlahWarits, ANAK_PEREMPUAN); // 1

    int jumlahTotal = 2 * jumlahLaki + jumlahPerempuan; //5
    float jumlahIndividual = pAshobah / (float)jumlahTotal;  // 10 : 5 = 2
    
    float ashobahPerempuan = (float)jumlahPerempuan * jumlahIndividual;  // 1 * 2 = 2
    float ashobahLaki = 2.0 * (float)jumlahLaki * jumlahIndividual;  // 2 * 2 * 2 = 8
    /*
    Untuk Debug
    printf("\nHasil hitung ashobah laki = %.3f", ashobahLaki);
    printf("\nHasil hitung ashobah perempuan = %.3f", ashobahPerempuan);
    */

    float retValue;
    if(pMode == ANAK_LAKI){
        retValue = ashobahLaki;
    }else if(pMode == ANAK_PEREMPUAN){
        retValue = ashobahPerempuan;
    }
    return retValue;
    
}

void createTable(Warits *pWarits, int pJumlahWarits){
    /*
        Tabel Pembagian Waris
        ----------------------------------------------------------------------------
        | pewaris        | bagian | jumlah |   harta total    |  harta individual  |
        |----------------+--------+--------+---------------------------------------|
        | anak laki-laki |  0.333 |   129  |  Rp122812334.123 |  Rp122812334.123   |
        |---------------------------------------------------------------------------
    */
    printf("\tTabel Pembagian Waris\n");
    int i;
    printf("\t");
    for(i = 0; i < (16 + 8 + 8 + 20 + 20) * 2; i++){
        printf("=");
    }   
    printf("\n");

    printf("\t%16s\t\t%8s\t\t%8s\t\tRp%20s\t\tRp%20s\n\n",
    "Pewaris","Bagian", "Jumlah", "Harta Total", "Harta Individual");

    printf("\t");
    for(i = 0; i < (16 + 8 + 8 + 20 + 20) * 2; i++){
        printf("=");
    }
    printf("\n");

    for(i = 0; i < pJumlahWarits; i++){
        printf("\t%16s\t\t%8.3f\t\t%8d\t\tRp%20.3f\t\tRp%20.3f\n\n", 
        idParser(pWarits[i].id), pWarits[i].bagian, pWarits[i].jumlah, pWarits[i].hartaTotal, pWarits[i].hartaIndividual);
    }
}