#include <stdio.h>
#include <stdlib.h>

struct yapilar
{
	int YapiVerisi;
	struct yapilar * gosterdigi;

};

struct yapilar * Yapi0 = NULL;
struct yapilar * Yapi1 = NULL;

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
	int sayi, x = 0;
	while(x < 5)
	{
	
	printf("\n lutfen bir sayi girin ::");
	scanf("%d", &sayi );
	BasaEkleme(sayi);
	x++;
	Yazdirma( ) ;
    }

  
}
