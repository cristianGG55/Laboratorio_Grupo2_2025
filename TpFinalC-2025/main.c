#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h> 
#include <string.h>
#include <malloc.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "includes/includes.h"

int main(int argc, char *argv[])
{  
  if(!init_config(argv[POS_CONFIG]))
  	 exit(-1);  
  
  // ejemplo para agregar Localidad nueva.
  setDebug(true);
  // ejemplo para listar todas las localidades en el sistema
  obj_Cliente *cli = Cliente_new();
  
  obj_Localidad *loc;  
  void *list,*itm;
  int i=0,size=0, sizeEnf=0;
  //cli->getLocalidadObj(cli);
  //loc = Localidad_new();  
  /*  
  size = cli->findAll(cli,&list,NULL);    
  for(i=0;i<size;++i)
  {
    itm = ((Object **)list)[i];    
    ((Object *)itm)->toString(itm);
  }
  destroyObjList(list,size);
  destroyObj(cli);
  */
  i=leerEntero("Ingrese edad\n[-1 - corta ingreso]:",true,10,40,-1);
  //printf("Nro leido:%d\n",i);
  //i=leerOpcionLoc("ingrese CP:",true, false);
  /*
  loc = Localidad_new();    
  size = loc->findAll(loc,&list,NULL);    
  for(i=0;i<size;++i)
  {
    itm = ((Object **)list)[i];    
    ((Object *)itm)->toString(itm);
  }
  destroyObjList(list,size);
  destroyObj(loc);
  */
  system("PAUSE");
  return 0;
}
