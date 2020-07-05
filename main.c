#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Eleman_Sayisi;
    int sayi,i,j,secim=0;

    printf("Eleman sayisii giriniz:");
    scanf("%d",&Eleman_Sayisi);
    int *dizi=(int*) malloc(Eleman_Sayisi*sizeof(int));
    int *Pointer_dizisi=(int*) malloc((Eleman_Sayisi+1)*sizeof(int));

            printf("Header degerini giriniz:");
            scanf("%d",&sayi);
            while(sayi>Eleman_Sayisi || sayi<=-2){
                printf("Header degerini eleman sayisindan buyuk ve -2 dem kucuk bir deger olamaz yeniden giriniz:");
                scanf("%d",&sayi);
            }
            *Pointer_dizisi=sayi;
            Pointer_dizisi++;

    printf("Ana diziyi ve Pointer dizisini giriniz:\n");
    for(i=0;i<Eleman_Sayisi;i++){
        printf("dizinin %d elemanini giriniz:",i+1);
        scanf("%d",&sayi);
        *dizi=sayi;
        dizi++;

        printf("%d elemanýn point ettigi eleman:",i+1);
        scanf("%d",&sayi);
            while(sayi>Eleman_Sayisi || sayi<=-2){
                printf("Pointer degeri eleman sayisindan buyuk ve -2 den kucuk bir deger olamaz yeniden giriniz:");
                scanf("%d",&sayi);
            }
                *Pointer_dizisi=sayi;
                Pointer_dizisi++;


   }

   dizi=dizi-Eleman_Sayisi;
   printf("Girilen dizi  :| ");

    for(i=0;i<Eleman_Sayisi;i++){
        printf("|%d",*dizi);
        dizi++;
   }
   printf("|\n");


   Pointer_dizisi=Pointer_dizisi-Eleman_Sayisi-1;
   printf("Pointer dizisi:");

    for(i=0;i<=Eleman_Sayisi;i++){
        printf("|%d ",*Pointer_dizisi);
        Pointer_dizisi++;
   }
   printf("|");


Pointer_dizisi=Pointer_dizisi-Eleman_Sayisi-1;
dizi=dizi-Eleman_Sayisi;


printf("\nislem seciniz \n1-)Diziyi Siralama \n2-)Diziye Eleman Ekleme \n3-)Diziden Eleman Silme \nCikis icin 9'a basiniz...");
scanf("%d",&secim);


while(secim>0){
        if(secim==1){
            printf("\n\n Dizi siralandi==>");
            j=*Pointer_dizisi;
            while(j>0){
                printf("|%d",dizi[j-1]);
                j=Pointer_dizisi[j];
            }
        }
        else if(secim==2){
                Eleman_Sayisi++;
                dizi = realloc(dizi,sizeof(int)*Eleman_Sayisi);
                Pointer_dizisi=realloc(Pointer_dizisi,sizeof(int)*(Eleman_Sayisi+1));

                printf("dizinin %d elemanini giriniz:",Eleman_Sayisi);
                scanf("%d",&sayi);
                dizi[Eleman_Sayisi-1]=sayi;

                j=*Pointer_dizisi;
                int t=0,k=0;
                while(dizi[j-1]<sayi){
                        k=j;
                        j=Pointer_dizisi[j];
                        t++;
                }

                printf("%d elemanýn point ettigi eleman:%d oldu",i,j);
                Pointer_dizisi[Eleman_Sayisi]=j;
                Pointer_dizisi[k]=Eleman_Sayisi;


                printf("eleman eklendi...");

                printf("\n Girilen dizi  :| ");
                for(i=0;i<Eleman_Sayisi;i++){
                   printf("|%d",dizi[i]);
                }

                printf("\n Pointer dizisi:");
                for(i=0;i<Eleman_Sayisi+1;i++){
                   printf("|%d ",Pointer_dizisi[i]);
                }
        }
        else if(secim==3){
                printf("\n\nSilmek istediðiniz elemani giriniz :");
                scanf("%d",&sayi);
                j=*Pointer_dizisi;
                int k=0;
                while(dizi[j-1]!=sayi){
                        k=j;
                        j=Pointer_dizisi[j];
                }



                Pointer_dizisi[k]=Pointer_dizisi[j];
                Pointer_dizisi[j]=-9;

                printf("eleman silindi...");

                 printf("\n Girilen dizi  :| ");
                for(i=0;i<Eleman_Sayisi;i++){
                   printf("|%d",dizi[i]);
                }

                printf("\n Pointer dizisi:");
                for(i=0;i<Eleman_Sayisi+1;i++){
                   printf("|%d ",Pointer_dizisi[i]);
                }


        }
        else if(secim==9){
            exit(0);
        }

        printf("\nislem seciniz \n1-)Diziyi Siralama \n2-)Diziye Eleman Ekleme \n3-)Diziden Eleman Silme \nCikis icin 9'a basiniz...");
        scanf("%d",&secim);
}

    return 0;
}
