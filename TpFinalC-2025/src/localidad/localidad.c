#include "../../includes/includelib.h"

#include "localidad.h"

THIS(obj_Localidad)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_LocalidadImpl(void *self)
{
     obj_Localidad *obj=this(self);      
     // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
     printf("%d - %s\n",obj->getCodpostal(obj),obj->getNombre(obj)); 
}

static int getCodpostalLocalidad_Impl(void *self)
{ return  *((int *) getValue(self,POS_CODPOSTAL_LOC));}
//----------------------------------------------------

static char * getNombreLocalidad_Impl(void *self)
{ return  (char *) getValue(self,POS_NOMBRE_LOC);}
//----------------------------------------------------


static void setCodpostalLocalidad_Impl(void *self,int val)
{ setValue(self,POS_CODPOSTAL_LOC,&val); }
//----------------------------------------------------

static void setNombreLocalidad_Impl(void *self,char * val)
{ setValue(self,POS_NOMBRE_LOC,val); }
//----------------------------------------------------

//----------------------------------------------------
static void destroyInternalLOC_Impl(void *self)
{
	obj_Localidad *obj = this(self);	
	// finalizar cada referencia inicializada - no NULL
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------

//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Localidad(void *self)
{
  obj_Localidad *obj      = this(self);
  obj->ds  			    = &table_Localidad;
  obj->constructor 	    = Localidad_new;
  obj->sizeObj 		    = sizeof(obj_Localidad*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
  
  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_LocalidadImpl;
  // Inicializar handlers de getters y setters
  /// getters
    
	obj->getCodpostal = getCodpostalLocalidad_Impl;
  
	obj->getNombre = getNombreLocalidad_Impl;

  /// setters  
    
	obj->setCodpostal = setCodpostalLocalidad_Impl;
  
	obj->setNombre = setNombreLocalidad_Impl;

  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalLOC_Impl;
  //---- acceso a relaciones  
  
  return obj;
}
//----------------------------------------------------
//constructor de Localidad
obj_Localidad *Localidad_new()
{
  return (obj_Localidad *)init_obj(sizeof(obj_Localidad), init_Localidad);
}
//----------------------------------------------------
int leerOpcionLoc(char *msj, bool clear,bool cancela) 
{
	int size=0,i,opt=0;void *list; 
	char nro[10];
	obj_Localidad *itm,*loc=Localidad_new();	
	size = loc->findAll(loc,&list,NULL);	
	while(true)
	{
		if(clear)
		  system("cls");
		printf("%s\n",msj);
		printf("[ -1 ] - para cancelar \n");
		//listar opciones
		for(i=0;i<size;++i)
		{
			itm = ((obj_Localidad **)list)[i];
			printf("%d ) - %s\n",itm->getCodpostal(itm),itm->getNombre(itm));
		}
		printf(": ");
		fflush(stdin);
		opt = -1;		
		scanf("%d",&opt);
		if(opt==-1) 		
			return -1;		
		if(opt!=-1 || cancela)
		{ 
			if(loc->findbykey(loc,opt)!=NOT_FOUND)
			  break;
			else
			{			
			  if(cancela)  
			    break;
			  else
			  {
			  	printf("Dato ingresado no valido!\n");
			  	system("pause");
			  }
			}
			continue;
		}
	}
	destroyObjList(list,size);
}

