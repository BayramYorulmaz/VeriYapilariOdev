#include <stdio.h>
#include <stdlib.h>

struct yapilar {
    int YapiVerisi;
    struct yapilar *gosterdigi;
};

struct yapilar *start = NULL;
struct yapilar *temp = NULL;

void basaEkle(int veri) {
    struct yapilar *eleman;
    eleman = (struct yapilar *) malloc(sizeof(struct yapilar));
    eleman->YapiVerisi = veri;
    eleman->gosterdigi = start;
    start = eleman;
}

void sonaEkle(int veri) {
    struct yapilar *eleman;
    eleman = (struct yapilar *) malloc(sizeof(struct yapilar));
    eleman->YapiVerisi = veri;
    eleman->gosterdigi = NULL;

    if (start == NULL) {
        start = eleman;
    } else {
        temp = start;
        while (temp->gosterdigi != NULL) {
            temp = temp->gosterdigi;
        }
        temp->gosterdigi = eleman;
    }
}

void arayaEkle(int n, int veri) {
    struct yapilar *eleman;
    eleman = (struct yapilar *) malloc(sizeof(struct yapilar));
    eleman->YapiVerisi = veri;

    temp = start;

    
    if (temp == NULL) {
        printf("Liste bo?, araya eleman eklenemez.\n");
        return;
    }

   
    while (temp != NULL && temp->YapiVerisi != n) {
        temp = temp->gosterdigi;
    }

    
    if (temp == NULL) {
        printf("Eleman listede bulunamad?.\n");
        free(eleman); 
        return;
    }

   
    eleman->gosterdigi = temp->gosterdigi;
    temp->gosterdigi = eleman;
}

void bastanSil()
{
	if(start!=NULL)
	{
	
	temp=start->gosterdigi;
	free(start ) ;
	start= temp;
    } 
    else 
    free(start) ;

}

void sondanSil()
{
	if(start->gosterdigi!= NULL )
	{
		temp= start;
		while (temp->gosterdigi->gosterdigi!=NULL )
		{
			temp= temp->gosterdigi;
		}
		free(temp->gosterdigi ) ;
		temp->gosterdigi= NULL;
		
	}
	else
	bastanSil();
	
}

void aradanSil(int veri)
{
	

	temp= start;
	if( temp->YapiVerisi==veri )
	{
		bastanSil();
	}
	else
	{
		struct yapilar * temp2;
		temp2= (struct yapilar *) malloc (sizeof(struct yapilar  )) ;
		
		while(temp->gosterdigi->YapiVerisi!= veri)
		{
			temp= temp->gosterdigi;
			
		}
		if(temp->gosterdigi->gosterdigi == NULL )
		{
			sondanSil();
		}
		
		else
		{
			temp2= temp->gosterdigi->gosterdigi;
	     	free(temp->gosterdigi);
		    temp->gosterdigi= temp2;
		}
		
	}

	
	
	
}

void tersCevir()
{
	struct yapilar * temp2= NULL;
	struct yapilar *prev= NULL;
	
	temp= start;
	 while(temp!= NULL )
	{
		temp2= temp->gosterdigi;
		temp->gosterdigi= prev;
		prev= temp;
		temp= temp2;
	}
	start = prev;
}




void yazdir() 
{
	system("cls") ;
	if(start!= NULL  )
	{
    temp = start;
    while (temp->gosterdigi!= NULL) 
    
	
	{
        printf("%d ", temp->YapiVerisi );
        temp = temp->gosterdigi;
    } 
	printf("%d ", temp->YapiVerisi );
   
    }
    else
    printf("Eleman yok ! !") ;
}

int main() {
    int sayi, adet = 0, secim, n;

    while (adet != 6) {
        printf("\nBasa eleman eklemek icin 1\n");
        printf("Sona eleman eklemek icin 2\n");
        printf("Araya eleman eklemek icin 3\n");
        printf("Bastan eleman silmek icin 4\n");
        printf("Sondan eleman silmek icin 5\n");
        printf("Aradan eleman silmek icin 6\n");
        printf("Elamanlari ters cevirmek icin 7\n");
        printf("Seciminizi yapiniz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("\nBasa eklenecek elemanin degeri: ");
                scanf("%d", &sayi);
                basaEkle(sayi);
                yazdir();
                break;

            case 2:
                printf("\nSona eklenecek elemanin degeri: ");
                scanf("%d", &sayi);
                sonaEkle(sayi);
                yazdir();
                break;

            case 3:
                printf("Hangi sayidan once araya eklemek istersiniz: ");
                scanf("%d", &n);
                printf("\nAraya eklenecek elemanin degeri: ");
                scanf("%d", &sayi);
                arayaEkle(n, sayi);
                yazdir();
                break;
                
            case 4:
                bastanSil();
                yazdir();
                break;

            case 5:
                sondanSil();
                yazdir();
                break;
                
            case 6: printf("Aradan silinecek elemanin degeri : ") ;
                scanf("%d" , &sayi) ;
                aradanSil(sayi ) ;
                yazdir() ;
                break;
                
            case 7: printf("Elamanlar ters cevriliyor.... : \n") ;
                tersCevir() ;
                yazdir() ;
                break;
                
                
            default:
                printf("Gecersiz secim!\n");
                break;
        }
        adet++;
    }

    return 0;
}
