#define N_WARITS 6
#include <stdio.h>
#include <stdlib.h>
#include "warits.h"
#include "userInterface.h"

/*
                 Mengikuti tabel Ahli Waris dan Bagian Waris
       Hukum Waris Islam Indonesia Menurut KHI (Kompilasi Hukum Islam)
         oleh Nasichun Amin, M.Ag (Penghulu Muda di KUA Kec. Gresik)
*/

int main(){

  Warits *ptrWarits;
  int pilihan = 1, opt;
  
  
  printf("\n------Program Penghitung Waris------");
  printf("\n\nSilakan pilih menu yang ingin dituju");
  while(1){
    mainmenu();
    printf("Pilih Salah Satu Menu : ");
    scanf("%d", &opt);
    printf("\n");
    if(opt == 1){
      pilihansatu();
    }
    else if(opt == 2){
      int i = 0;
      int jumlahWarits = 0;
      int adaAshobah = 0;
      float ashobah = 1.0;  //untuk bagian sisa setelah bagian ashabul furud dikeluarkan
      float harta = 0;   //Jumlah harta awal
      ptrWarits = malloc(jumlahWarits * sizeof(Warits));

      printf("\nJumlah harta yang ditinggalkan :");
      scanf("%f", &harta);

      // Dynamic Struct
      for(i = 0; i < N_WARITS; i++){
        int temp = 0;
        printf("\nJumlah %s: ", idParser(i));
        scanf("%d", &temp);
        if(temp < 0 || temp > 0){
          ptrWarits = realloc(ptrWarits, sizeof(Warits) * (jumlahWarits + 1));
          if(ptrWarits == NULL){
            perror("\nAlokasi memori gagal");
            exit(1);
          }
        modifyWarits(&ptrWarits[jumlahWarits], i, temp);
          printf("Jumlah %s (disesuaikan): %d\n", idParser(ptrWarits[jumlahWarits].id), ptrWarits[jumlahWarits].jumlah);
          if(i == 0 && ptrWarits[jumlahWarits].jumlah > 0){
            i++;
          }
          jumlahWarits++;
        }
      }

      for(i = 0; i < jumlahWarits; i++) // i merupakan posisi elemen dari ptrWarits
      {
        ///////// ISTRI ///////
        if(ptrWarits[i].id == ISTRI){
          if(isPresent(&ptrWarits[0], jumlahWarits, ANAK_PEREMPUAN) || isPresent(&ptrWarits[0], jumlahWarits, ANAK_LAKI)){
            hitungBagian(&ptrWarits[i], 1/8.0, &ashobah);
          }else{
            hitungBagian(&ptrWarits[i], 1/4.0, &ashobah);
          }
          hitungHarta(&ptrWarits[i], harta);
        } 
        
        ///////// SUAMI ///////
        else if(ptrWarits[i].id == SUAMI){
          if(isPresent(&ptrWarits[0], jumlahWarits, ANAK_PEREMPUAN) || isPresent(&ptrWarits[0], jumlahWarits, ANAK_LAKI)){
            hitungBagian(&ptrWarits[i], 1/4.0, &ashobah);
          }else{
            hitungBagian(&ptrWarits[i], 1/2.0, &ashobah);
          }
          hitungHarta(&ptrWarits[i], harta); 
        }

        ///////// BAPAK /////////
        else if(ptrWarits[i].id == BAPAK){
          if(isPresent(&ptrWarits[0], jumlahWarits, ANAK_PEREMPUAN) || isPresent(&ptrWarits[0], jumlahWarits, ANAK_LAKI)){
            hitungBagian(&ptrWarits[i], 1/6.0, &ashobah);  //Ada anak
          }else if((!isPresent(&ptrWarits[0], jumlahWarits, ANAK_PEREMPUAN) && !isPresent(&ptrWarits[0], jumlahWarits, ANAK_LAKI) && isPresent(&ptrWarits[0], jumlahWarits, IBU) && isPresent(&ptrWarits[0], jumlahWarits, ISTRI))){
            hitungBagian(&ptrWarits[i], 1/2.0, &ashobah);
          }else{
            hitungBagian(&ptrWarits[i], 2/3.0, &ashobah); //Tidak ada anak
          }
          hitungHarta(&ptrWarits[i], harta);
        } 
        
        ///////// IBU /////////
        else if(ptrWarits[i].id == IBU){
          if(isPresent(&ptrWarits[0], jumlahWarits, ANAK_PEREMPUAN) || isPresent(&ptrWarits[0], jumlahWarits, ANAK_LAKI)){
            hitungBagian(&ptrWarits[i], 1/6.0, &ashobah); //Ada anak
          }else if((!isPresent(&ptrWarits[0], jumlahWarits, ANAK_PEREMPUAN) && !isPresent(&ptrWarits[0], jumlahWarits, ANAK_LAKI) && isPresent(&ptrWarits[0], jumlahWarits, BAPAK) && isPresent(&ptrWarits[0], jumlahWarits, ISTRI))){
            hitungBagian(&ptrWarits[i], 1/4.0, &ashobah);
          }
          else{
            hitungBagian(&ptrWarits[i], 1/3.0, &ashobah);//Tidak ada anak;
          }
          hitungHarta(&ptrWarits[i], harta);
        } 

        ///////// ANAK PEREMPUAN /////////
        else if(ptrWarits[i].id == ANAK_PEREMPUAN){
          if(isPresent(&ptrWarits[0], jumlahWarits, ANAK_LAKI)){  //Menjadikan Anak Perempuan bagian dari Ashobah
            adaAshobah = 1;
            hitungBagian(&ptrWarits[i], hitungAshobah(&ptrWarits[0], jumlahWarits, ashobah, ANAK_PEREMPUAN), NULL); 
          }else if(getCount(&ptrWarits[0], jumlahWarits, ANAK_PEREMPUAN) == 1){
            hitungBagian(&ptrWarits[i], 1/2.0, &ashobah);
          }else{
            hitungBagian(&ptrWarits[i], 2/3.0, &ashobah);
          }
          if(adaAshobah){
            ptrWarits[i].bagian = hitungAshobah(&ptrWarits[0], jumlahWarits, ashobah, ANAK_PEREMPUAN);
          }
          hitungHarta(&ptrWarits[i], harta);
        }
        
        ///////// ANAK LAKI-LAKI /////////
        else if(ptrWarits[i].id == ANAK_LAKI){
          adaAshobah = 1;
          hitungBagian(&ptrWarits[i], hitungAshobah(&ptrWarits[0], jumlahWarits, ashobah, ANAK_LAKI), NULL);
          ptrWarits[i].bagian = hitungAshobah(&ptrWarits[0], jumlahWarits, ashobah, ANAK_LAKI);
          hitungHarta(&ptrWarits[i], harta);
        }
      }

      createTable(&ptrWarits[0], jumlahWarits);
      free(ptrWarits);
      }
  else if(opt == 3){
    glosarium();
  }
  else if(opt == 4){
    hukum();
  }
  else if(opt == 5){
    break;
  }
  else{
    printf("\n\nPilihan menu tidak Valid\n\n");
  }
  }
  return 0;
}  



