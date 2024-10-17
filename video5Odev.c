#include <stdio.h>
#include <stdlib.h>

struct yapilar
{
	int YapiVerisi;
	struct yapilar * gosterdigi;

};

struct yapilar * Yapi0 = NULL;
struct yapilar * Yapi1 = NULL;

void SonaEkleme(int sayi)
{
	struct yapilar * ekleme;
	ekleme = (struct yapilar * ) malloc (sizeof (struct yapilar) );
	ekleme->YapiVerisi = sayi;
	ekleme->gosterdigi = NULL;
	
	if(Yapi1 == NULL )
	{
		Yapi1 = ekleme;
	}
	else
	{
		Yapi0 = Yapi1 ;
		while (Yapi0->gosterdigi != NULL)
		{
			Yapi0= Yapi0-> gosterdigi;
		}
		Yapi0->gosterdigi = ekleme;		
	}
}


void BasaEkleme(int sayi)
{
	struct yapilar * ekleme;
	ekleme = (struct yapilar * ) malloc (sizeof (struct yapilar) );
	ekleme->YapiVerisi = sayi;
	ekleme->gosterdigi = Yapi1;
	Yapi1 = ekleme;
	

}

void Yazdirma ()
{
	Yapi0 = Yapi1;
	while(Yapi0->gosterdigi != NULL )
	{
		printf (" %d ",Yapi0->YapiVerisi);
		Yapi0 = Yapi0 -> gosterdigi;
	}
	printf (" %d ",Yapi0->YapiVerisi);
}

void main()
{
	int sayi, x = 0 , secim = 0 ;
	
	
	while(x < 5)
	{
	secim = 0 ;

		printf("\n basa eklemek icin 1e  basin :: \n sona eklemek icin 2ye basin ::");
		scanf("%d", & secim );
		
		if(secim == 1)
		{
	  		printf("\n lutfen bir sayi girin ::");
			scanf("%d", & sayi );
			BasaEkleme(sayi);
			x++;
			Yazdirma();
		}
		else if(secim == 2 )
		{
			printf("\n lutfen bir sayi girin ::");
			scanf("%d", & sayi );
			SonaEkleme(sayi);
			x++;
			Yazdirma();
		}
		else
		{
			printf("\n Duzgun Bir Secim Yapin ::");
		}
	
    }
    
    
    
    

}

