#include <stdio.h>
#include <windows.h>

void mainmenu(){    //Function untuk menampilkan menu utama
    printf("\n1. Syarat-syarat pada pewarisan harta\n");
    printf("2. Mulai Pengisian\n");
    printf("3. Glosarium\n");
    printf("4. Dasar hukum berdasarkan Al-Quran\n");
    printf("5. Keluar dari Program\n\n");
}

void pilihansatu(){ //Function untuk pilihan pertama
    printf("Berikut ini adalah syarat-syarat dalam menentukan harta warisan :\n");
    printf("1. Jika istri meninggal dan tidak memiliki anak, suami menerima 1/2 dari total harta warisan.\n");
    printf("2. Jika istri meninggal dan memiliki anak, maka suami menerima 1/4 dari total harta warisan.\n");
    printf("3. Jika suami meninggal dan tidak memiliki anak, maka istri menerima 1/4 dari total harta warisan.\n");
    printf("4. Jika suami meninggal dan memiliki anak, maka istri menerima 1/8 dari total harta warisan.\n");
    printf("5. Ayah kandung dari seseorang yang sudah meninggal dan tidak memiliki anak mendapatkan 1/3 dari total harta warisan.\n");
    printf("5. Ayah kandung dari seseorang yang sudah meninggal dan memiliki anak mendapatkan 1/6 dari total harta warisan.\n");
    printf("6. Ibu kandung dari seseorang yang sudah meninggal dan tidak memiliki anak mendapatkan 1/3 dari total harta warisan.\n");
    printf("7. Ibu kandung dari seseorang yang sudah meninggal dan memiliki anak mendapatkan 1/6 dari total harta warisan.\n");
    printf("8. Jika memiliki anak tunggal perempuan, maka mendapat 1/2 bagian dari total harta warisan\n");
    printf("9. Jika memiliki dua atau lebih anak perempuan dan tidak memiliki anak laki-laki, maka seluruh anak perempuan mendapat 2/3 bagian dari total harta warisan dan dibagi rata.\n");
    printf("10. Anak laki-laki mendapatkan bagian ashobah (sisa) dari pembagian Ashabul Furud.\n");
    printf("11. Apabila harta ashobah masih tersisa walaupun sudah dibagi kepada bagian ashobah, harta dikembalikan kepada bagian Ashabul Furud selain suami istri karena mereka mendapatkan waris sebab jalur pernikahan.\n\n");
    fflush(stdin);
    printf("Press Any Key to Go Back to Main Menu : ");
    getchar();
    printf("\n\n");
}

void glosarium(){ //Function untuk glosarium
    printf("- Ashobah (Ashabah) : Bagian sisa/golongan ahli waris yang mendapat bagian sisa\n");
    printf("- Ashabab al-furudh : Golongan ahli waris yang mendapat bagian pasti\n");
    printf("- Faraid : Ilmu yang mempelajari aturan pembagian harta warisan\n");
    printf("- Mauruts : Sesuatu yang diwariskan\n");
    printf("- Mirats : Warisan\n");
    printf("- Siham : Nilai yang dihasilkan dari perkalian bagian fardu ahli waris dengan asal masalah\n");
    printf("- Tirkah : Harta Warisan\n");
    printf("- Warits : Ahli Waris \n\n");
    fflush(stdin);
    printf("Press Any Key to Go Back to Main Menu : ");
    getchar();
    printf("\n\n");
}


void hukum(){//Function untuk dasar hukum berdasarkan Al-Quran
    printf("Q.S. An-Nisa ayat 11 : \n");
    /*
    printf("يُوصِيكُمُ ٱللَّهُ فِىٓ أَوْلَٰدِكُمْ ۖ لِلذَّكَرِ مِثْلُ حَظِّ ٱلْأُنثَيَيْنِ ");
    printf("فَإِن كُنَّ نِسَآءً فَوْقَ ٱثْنَتَيْنِ فَلَهُنَّ ثُلُثَا مَا تَرَكَ ۖ وَإِن كَانَتْ وَٰحِدَةً فَلَهَا ٱلنِّصْفُ ۚ ");
    printf(" ۚ وَلِأَبَوَيْهِ لِكُلِّ وَٰحِدٍ مِّنْهُمَا ٱلسُّدُسُ مِمَّا تَرَكَ إِن كَانَ لَهُۥ وَلَدٌ ۚ ");
    printf(" ۚ فَإِن لَّمْ يَكُن لَّهُۥ وَلَدٌ وَوَرِثَهُۥٓ أَبَوَاهُ فَلِأُمِّهِ ٱلثُّلُثُ  ");
    printf(" ۗ فَإِن كَانَ لَهُۥٓ إِخْوَةٌ فَلِأُمِّهِ ٱلسُّدُسُ ۚ مِنۢ بَعْدِ وَصِيَّةٍ يُوصِى بِهَآ أَوْ دَيْنٍ ");
    printf("ءَابَآؤُكُمْ وَأَبْنَآؤُكُمْ لَا تَدْرُونَ أَيُّهُمْ أَقْرَبُ لَكُمْ نَفْعًا ۚ فَرِيضَةً مِّنَ ٱللَّهِ ۗ إِنَّ ٱللَّهَ كَانَ عَلِيمًا حَكِيمًا \n");
    */
    //Bahasa Arab tidak terdeteksi di DevC++
    printf("Allah mensyari'atkan bagimu tentang (pembagian pusaka untuk) anak-anakmu. Yaitu: bahagian seorang anak lelaki sama dengan bagahian dua orang anak perempuan; ");
    printf("dan jika anak itu semuanya perempuan lebih dari dua, maka bagi mereka dua pertiga dari harta yang ditinggalkan; jika anak perempuan itu seorang saja, maka ia memperoleh separo harta.");
    printf("Dan untuk dua orang ibu-bapa, bagi masing-masingnya seperenam dari harta yang ditinggalkan, jika yang meninggal itu mempunyai anak;");
    printf("jika orang yang meninggal tidak mempunyai anak dan ia diwarisi oleh ibu-bapanya (saja), maka ibunya mendapat sepertiga; jika yang meninggal itu mempunyai beberapa saudara, maka ibunya mendapat seperenam.");
    printf("(Pembagian-pembagian tersebut di atas) sesudah dipenuhi wasiat yang ia buat atau (dan) sesudah dibayar hutangnya.");
    printf("(Tentang) orang tuamu dan anak-anakmu, kamu tidak mengetahui siapa di antara mereka yang lebih dekat (banyak) manfaatnya bagimu.");
    printf("Ini adalah ketetapan dari Allah. Sesungguhnya Allah Maha Mengetahui lagi Maha Bijaksana.\n\n");
    printf("Q.S. An-Nisa ayat 12 : \n");
    printf("Dan bagimu (suami-suami) seperdua dari harta yang ditinggalkan oleh isteri-isterimu, jika mereka tidak mempunyai anak.");
    printf("Jika isteri-isterimu itu mempunyai anak, maka kamu mendapat seperempat dari harta yang ditinggalkannya sesudah dipenuhi wasiat yang mereka buat atau (dan) seduah dibayar hutangnya.");
    printf("Para isteri memperoleh seperempat harta yang kamu tinggalkan jika kamu tidak mempunyai anak. Jika kamu mempunyai anak, maka para isteri memperoleh seperdelapan dari harta yang kamu tinggalkan sesudah dipenuhi wasiat yang kamu buat atau (dan) sesudah dibayar hutang-hutangmu.");
    printf("Jika seseorang mati, baik laki-laki maupun perempuan yang tidak meninggalkan ayah dan tidak meninggalkan anak, tetapi mempunyai seorang saudara laki-laki (seibu saja) atau seorang saudara perempuan (seibu saja), maka bagi masing-masing dari kedua jenis saudara itu seperenam harta.");
    printf("Tetapi jika saudara-saudara seibu itu lebih dari seorang, maka mereka bersekutu dalam yang sepertiga itu, sesudah dipenuhi wasiat yang dibuat olehnya atau sesudah dibayar hutangnya dengan tidak memberi mudharat (kepada ahli waris).");
    printf("(Allah menetapkan yang demikian itu sebagai) syari'at yang benar-benar dari Allah, dan Allah Maha Mengetahui lagi Maha Penyantun. \n\n");
    fflush(stdin);
    printf("Press Any Key to Go Back to Main Menu : ");
    getchar();
     printf("\n\n");
}
