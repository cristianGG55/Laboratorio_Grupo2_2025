#include "../../includes/includelib.h"

#include "categoria.h"

THIS(obj_Categoria)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_CategoriaImpl(void *self)
{
     obj_Categoria *obj=this(self);      
     // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
     printf("\n"); 
}

static int getCodigoCategoria_Impl(void *self)
{ return  *((int *) getValue(self,POS_CODIGO_CAT));}
//----------------------------------------------------

static char * getDescripcionCategoria_Impl(void *self)
{ return  (char *) getValue(self,POS_DESCRIPCION_CAT);}
//----------------------------------------------------


static void setCodigoCategoria_Impl(void *self,int val)
{ setValue(self,POS_CODIGO_CAT,&val); }
//----------------------------------------------------

static void setDescripcionCategoria_Impl(void *self,char * val)
{ setValue(self,POS_DESCRIPCION_CAT,val); }
//----------------------------------------------------

//----------------------------------------------------
static void destroyInternalCAT_Impl(void *self)
{
	obj_Categoria *obj = this(self);	
	// finalizar cada referencia inicializada - no NULL
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------

//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Categoria(void *self)
{
  obj_Categoria *obj      = this(self);
  obj->ds  			    = &table_Categoria;
  obj->constructor 	    = Categoria_new;
  obj->sizeObj 		    = sizeof(obj_Categoria*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
  
  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_CategoriaImpl;
  // Inicializar handlers de getters y setters
  /// getters
    
	obj->getCodigo = getCodigoCategoria_Impl;
  
	obj->getDescripcion = getDescripcionCategoria_Impl;

  /// setters  
    
	obj->setCodigo = setCodigoCategoria_Impl;
  
	obj->setDescripcion = setDescripcionCategoria_Impl;

  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalCAT_Impl;
  //---- acceso a relaciones  
  
  return obj;
}
//----------------------------------------------------
//constructor de Categoria
obj_Categoria *Categoria_new()
{
  return (obj_Categoria *)init_obj(sizeof(obj_Categoria), init_Categoria);
}
//----------------------------------------------------

