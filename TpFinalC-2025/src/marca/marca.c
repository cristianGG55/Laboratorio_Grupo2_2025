#include "../../includes/includelib.h"

#include "marca.h"

THIS(obj_Marca)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_MarcaImpl(void *self)
{
     obj_Marca *obj=this(self);      
     // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
     printf("\n"); 
}

static int getCodigoMarca_Impl(void *self)
{ return  *((int *) getValue(self,POS_CODIGO_MAR));}
//----------------------------------------------------

static char * getDescripcionMarca_Impl(void *self)
{ return  (char *) getValue(self,POS_DESCRIPCION_MAR);}
//----------------------------------------------------


static void setCodigoMarca_Impl(void *self,int val)
{ setValue(self,POS_CODIGO_MAR,&val); }
//----------------------------------------------------

static void setDescripcionMarca_Impl(void *self,char * val)
{ setValue(self,POS_DESCRIPCION_MAR,val); }
//----------------------------------------------------

//----------------------------------------------------
static void destroyInternalMAR_Impl(void *self)
{
	obj_Marca *obj = this(self);	
	// finalizar cada referencia inicializada - no NULL
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------

//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Marca(void *self)
{
  obj_Marca *obj      = this(self);
  obj->ds  			    = &table_Marca;
  obj->constructor 	    = Marca_new;
  obj->sizeObj 		    = sizeof(obj_Marca*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
  
  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_MarcaImpl;
  // Inicializar handlers de getters y setters
  /// getters
    
	obj->getCodigo = getCodigoMarca_Impl;
  
	obj->getDescripcion = getDescripcionMarca_Impl;

  /// setters  
    
	obj->setCodigo = setCodigoMarca_Impl;
  
	obj->setDescripcion = setDescripcionMarca_Impl;

  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalMAR_Impl;
  //---- acceso a relaciones  
  
  return obj;
}
//----------------------------------------------------
//constructor de Marca
obj_Marca *Marca_new()
{
  return (obj_Marca *)init_obj(sizeof(obj_Marca), init_Marca);
}
//----------------------------------------------------

