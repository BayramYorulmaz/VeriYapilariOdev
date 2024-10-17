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
	int i = 0;
	
	while ( i < 5 )
	{
	
	int sayi;
	printf("lutfen bir sayi girin ::");
	scanf("%d", &sayi );
	
	SonaEkleme(sayi);
	i++;
	
	}
	Yazdirma();
  
}