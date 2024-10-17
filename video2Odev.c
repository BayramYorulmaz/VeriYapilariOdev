#include <stdio.h>
#include <stdlib.h>

struct yapilar
{
	int YapiVerisi;
	struct yapilar * gosterdigi;

};

void main()
{
 
  struct yapilar * Yapi1;
  Yapi1 = (struct yapilar * ) malloc (sizeof (struct yapilar) );
  
   struct yapilar * Yapi2;
  Yapi2 = (struct yapilar * ) malloc (sizeof (struct yapilar) );
  
   struct yapilar * Yapi3;
  Yapi3 = (struct yapilar * ) malloc (sizeof (struct yapilar) );
  
   struct yapilar * Yapi4;
  Yapi4 = (struct yapilar * ) malloc (sizeof (struct yapilar) );
  
  
  
  Yapi1->YapiVerisi = 1;
  Yapi1->gosterdigi = Yapi2;

  
   Yapi2->YapiVerisi = 22;
  Yapi2->gosterdigi = Yapi3;
  
  
   Yapi3->YapiVerisi = 333;
    Yapi3->gosterdigi = Yapi4;
  
  
	Yapi4->YapiVerisi = 4444;
	Yapi4->gosterdigi = NULL ;
  
  
  printf("%d :: %d :: %d :: %d",Yapi1->YapiVerisi , Yapi2->YapiVerisi,Yapi3->YapiVerisi,Yapi4->YapiVerisi);
  

  
}
